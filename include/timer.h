#ifndef __TIMER_H_
#define __TIMER_H_

#define SYSMSMAX 0xffffffff
#define TIM_PERIOD 5    //ms

typedef struct {
        volatile unsigned long timer_ir;
        volatile unsigned long timer_tcr;
        volatile unsigned long timer_tc;
        volatile unsigned long timer_pr;
        volatile unsigned long timer_pc;
        volatile unsigned long timer_mr0;
        volatile unsigned long timer_mr1;
        volatile unsigned long timer_mr2;
        volatile unsigned long timer_mr3;
        volatile unsigned long timer_mcr;
}timer_reg, *ptimer_reg;


void init_pmp_timer(unsigned int value);
unsigned long get_pmp_timecount(void);
void start_pmp_timer(void);
void stop_pmp_timer(void);
void clear_pmp_timerint(void);
void pmp_timer_change_tcr(unsigned int value);
void pmp_timer_handler(void);
void pmp_time_deal(void);

void udelay(unsigned int us);
void mdelay(unsigned int ms);

#endif /* __TIMER_H_ */
