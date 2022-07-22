#include "printf.h"
#include "pmp.h"
#include "io.h"
#include "string.h"
#include "timer.h"
#include "gpio.h"


#define PMP_TIMER_BASE (PMP_REG_BASE+0xf100)

static volatile unsigned long pmp_timecount=0;

volatile ptimer_reg pmptimer = (volatile ptimer_reg)PMP_TIMER_BASE;

extern unsigned int pmp_clock;
extern unsigned int pcie_credit_patch;

void init_pmp_timer(unsigned int value){
	pmptimer->timer_mcr = ((0x1)|(0x1<<1));	
	pmptimer->timer_pr = pmp_clock*1000-1;
	pmptimer->timer_mr0 = value;
	pmptimer->timer_tcr =0x03;
}

unsigned long get_pmp_timecount(void)
{
    return pmp_timecount*TIM_PERIOD;
}
void pmp_timer_change_tcr(unsigned int value)
{
	pmptimer->timer_mr0 = value;
}

void clear_pmp_timerint(void)
{
	pmptimer->timer_ir = 0xf;
}

void stop_pmp_timer(void)
{
	pmptimer->timer_tcr = 0x0;
}
void start_pmp_timer(void)
{
    pmptimer->timer_tcr = 0x03;
}

void pmp_timer_handler(void)
{
    clear_pmp_timerint();
    pmp_timecount++;
}


void udelay(unsigned int us)    //1us 27M 1us devitaion: 30%
{
    unsigned int l;
    l = pmp_clock*us/4;
    asm volatile (
        "1: subs %0, %0, #1\n"
        "   bhi 1b"
        ::"r"(l):
            );
}

void mdelay(unsigned int ms)   //1ms 27M 1ms devitaion : 0.037%
{
    unsigned int l;
    l = pmp_clock*250*ms;
    asm volatile (
        "1: subs %0, %0, #1\n"
        "   bhi 1b"
        ::"r"(l):
            );
}
