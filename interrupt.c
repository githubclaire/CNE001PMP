#include "pmp.h"
#include "cpu.h"
#include "vic.h"
#include "io.h"
#include "printf.h"
#include "timer.h"
#include "serial.h"
#include "pmu.h"


#define DEBUG 1 
#ifdef DEBUG
#define irq_dbg(fmt, args...) \
	printf("\e[32m""%s:%d "fmt"\n\e[m", __func__ , __LINE__,##args)
#else
#define irq_dbg(fmt, args...) 
#endif

extern void delay(unsigned int counter);

void set_vic_enable(unsigned int value) {
	writel(~0x0, PMP_REG_BASE + VIC_INTCLEAR);
	writel(value, PMP_REG_BASE + VIC_INTENABLE);
}

void init_vic(void) {
	unsigned int i = 0;
	//irq_dbg();

	/* enable the vector IRQ */
	for(i = 0; i < VIC_SOURCE_MAX; i++) {
			writel((1 << 5) | i, PMP_REG_BASE + VIC_VEC_CNTL0 + (i<<2));
	}
	/* interrupt type(fiq, irq) select, 0 for irq */
	//only VIC_SOURCE_FIQ require fiq
	writel((1<<VIC_SOURCE_PMU_FIQ), PMP_REG_BASE + VIC_INTSELECT);

	/* enable interrupt */
	set_vic_enable((1<<VIC_SOURCE_PMU_FIQ)|(1 << VIC_SOURCE_TIMER)|(1 << VIC_SOURCE_PMU_INT));
}

void feed_wdt(void) {
	writel(0xAA, PMP_REG_BASE + PMP_WDFEED);
	writel(0x55, PMP_REG_BASE + PMP_WDFEED);
}
void init_wdt(void) {
	writel(PMP_WDTCBARK_CNT, PMP_REG_BASE + PMP_WDT_CBARK);
	writel(PMP_WDTCBITE_CNT, PMP_REG_BASE + PMP_WDT_CBITE);	
	writel(0x03, PMP_REG_BASE + PMP_WDMOD);	
	feed_wdt();
}


void wdt_intr_handler(void) {
	irq_dbg();
	feed_wdt();
	writel(0xf, PMP_REG_BASE + PMP_WDMOD);
}



void main_irq_handler(void) {

	unsigned int irq_stat = readl(PMP_REG_BASE + VIC_IRQSTATUS);
	//printf("irq_stat:%d \n",irq_stat);

	if(irq_stat & (1 << VIC_SOURCE_WDT))
		wdt_intr_handler();
	if(irq_stat & (1 << VIC_SOURCE_TIMER)){
		//printf("VIC_SOURCE_TIMER\n");
		pmp_timer_handler();
	}
	if(irq_stat&(1<<VIC_SOURCE_PMU_FIQ))
	{
		pmu_fiq_handler();
	}
	if(irq_stat&(1<<VIC_SOURCE_PMU_INT))
	{
		pmu_int_handler();
	}	
}
