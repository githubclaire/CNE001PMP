#ifndef _PMP_VIC_H
#define _PMP_VIC_H

/* vector IRQ list */
#define VIC_SOURCE_WDT			0	/* Watch dog */
#define VIC_SOURCE_TIMER		1 	/* Timer */
#define VIC_SOURCE_PMU_FIQ			2   /* UART  */  
#define VIC_SOURCE_PMU_INT         3   /* IIC0  */


#define VIC_SOURCE_MAX			(VIC_SOURCE_PMU_INT + 1)  

/* VIC */
#define VIC_IRQSTATUS	    0xf300
#define VIC_FIQSTATUS	    0xf304
#define VIC_RAWINTR		    0xf308
#define VIC_INTSELECT	    0xf30C
#define VIC_INTENABLE	    0xf310
#define VIC_SOFTINT		    0xf314
#define VIC_SOFTINTCLR	    0xf318
#define VIC_INTCLEAR	    0xf31C
#define VIC_VEC_ADDR	    0xf320
#define VIC_DEFVEC_ADDR	    0xf324
#define VIC_VEC_ADDR0	    0xf328
#define VIC_VEC_CNTL0		0xf348

extern void init_wdt(void);
extern void init_secure_timer(void);
extern void pmu_stm_intr_handler(void);
extern void mailbox_intr_handler(void);
extern void init_vic(void);


#endif 
