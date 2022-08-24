#include "pmu.h"
#include "dvfs_table.h"
#include "printf.h"
#include "string.h"
#include "timer.h"
#include "io.h"


static DVFS_TABLE c3d_dvfs_table[]	=	{C3D_DVFS_TABLE};
static DVFS_TABLE s3d0_dvfs_table[]	=	{S3D0_DVFS_TABLE};
static DVFS_TABLE s3d1_dvfs_table[]	=	{S3D1_DVFS_TABLE};
static DVFS_TABLE vpp_dvfs_table[]	=	{VPP_DVFS_TABLE};
static VOLTAGE_TABLE   vol_table[]	=	{VOL_TABLE};
static DVFS_LOOKUP_TABLE dvfs_lookup_table_all[8]	=	{LOOKUP_TABLE};
//static unsigned int index_power_table[16] = IDX_POWER_TABLE;
static unsigned int c3d_index_power_table[16] 	= C3D_IDX_POWER_TABLE;
static unsigned int s3d0_index_power_table[16] 	= S3D0_IDX_POWER_TABLE;
static unsigned int s3d1_index_power_table[16] 	= S3D1_IDX_POWER_TABLE;
static unsigned int vpp_index_power_table[16] 	= VPP_IDX_POWER_TABLE;

volatile Reg_PMP_INTERRUPT_STATUS pmp_int_status;

//register point init
volatile Reg_PMU_CLK_MODULE 					*p_clk_module 						=(Reg_PMU_CLK_MODULE*) (CLK_MODULE);
volatile Reg_PMU_DVFS_PERFORMANCE_UP_DOWN_TABLE *p_dvfs_performance_up_down_table 	=(Reg_PMU_DVFS_PERFORMANCE_UP_DOWN_TABLE*) (DVFS_PERFORMANCE_UP_DOWN_TABLE);
volatile Reg_PMU_DVFS_REG_CTRL 					*p_dvfs_reg_ctrl 					=(Reg_PMU_DVFS_REG_CTRL*) (DVFS_REG_CTRL);
volatile Reg_PMU_DVFS_AUTO_EXTERNAL_TRIGGER 	*p_dvfs_auto_external_trigger 		=(Reg_PMU_DVFS_AUTO_EXTERNAL_TRIGGER*) (DVFS_AUTO_EXTERNAL_TRIGGER);
volatile Reg_PMU_DVFS_and_AVS_CMD_FIFO 			*p_dvfs_and_avs_cmd_fifo 			=(Reg_PMU_DVFS_and_AVS_CMD_FIFO*) (DVFS_and_AVS_CMD_FIFO);
volatile Reg_PMU_DVFS_EN_and_AVS_EN 			*p_dvfs_en_and_avs_en 				=(Reg_PMU_DVFS_EN_and_AVS_EN*) (DVFS_EN_and_AVS_EN);
volatile Reg_PMU_PMU 							*p_pmu 								=(Reg_PMU_PMU*) (PMU);
volatile Reg_PMU_DVFS_and_VOLTAGE_TABLE 		*p_dvfs_and_voltage_table 			=(Reg_PMU_DVFS_and_VOLTAGE_TABLE*) (DVFS_and_VOLTAGE_TABLE);
volatile Reg_PMU_RESET_CTRL_AND_POWER_ON 		*p_reset_ctrl_and_power_on 			=(Reg_PMU_RESET_CTRL_AND_POWER_ON*) (RESET_CTRL_AND_POWER_ON);
volatile Reg_PMU_INT 							*p_int 								=(Reg_PMU_INT*) (INT);
volatile Reg_PMP_DFX_PWR 						*P_DFX_PWR							=(Reg_PMP_DFX_PWR*) (DFX_PWR);

volatile DVFS_TASK_STATUS task_status;

unsigned int all_power_budget=0x3fffffff;



void dvfs_table_init(void)
{
    volatile Reg_PMU_DVFS_and_VOLTAGE_TABLE *pdvfs_table;
	volatile Reg_PMU_DVFS_PERFORMANCE_UP_DOWN_TABLE *pdvfs_up_down_table;
	unsigned int c3d_table_size;
	unsigned int s3d0_table_size;
	unsigned int s3d1_table_size;
	unsigned int vpp_table_size;
	unsigned int vol_table_size;

    pdvfs_table = (volatile Reg_PMU_DVFS_and_VOLTAGE_TABLE*)(DVFS_and_VOLTAGE_TABLE);
	pdvfs_up_down_table = (volatile Reg_PMU_DVFS_PERFORMANCE_UP_DOWN_TABLE*)(DVFS_PERFORMANCE_UP_DOWN_TABLE);


	c3d_table_size = sizeof(c3d_dvfs_table);		
	s3d0_table_size = sizeof(s3d0_dvfs_table);
	s3d1_table_size = sizeof(s3d1_dvfs_table);
	vpp_table_size = sizeof(vpp_dvfs_table);
	vol_table_size = sizeof(vol_table);

	if(c3d_table_size>DVFS_TABLE_SIZE)
		c3d_table_size = DVFS_TABLE_SIZE;
	if(s3d0_table_size>DVFS_TABLE_SIZE)
		s3d0_table_size = DVFS_TABLE_SIZE;
	if(s3d1_table_size>DVFS_TABLE_SIZE)
		s3d1_table_size = DVFS_TABLE_SIZE;
	if(vpp_table_size>DVFS_TABLE_SIZE)
		vpp_table_size = DVFS_TABLE_SIZE;
	if(vol_table_size>VOL_TABLE_SIZE)
		vol_table_size = VOL_TABLE_SIZE;
	
	
	//init DVFS Table
    memcpy32bit((void*)(pdvfs_table->C3D_DVFS_TABLE0_15),(void*)c3d_dvfs_table,c3d_table_size);
	memcpy32bit((void*)(pdvfs_table->S3D0_DVFS_TABLE0_15),(void*)s3d0_dvfs_table,s3d0_table_size);
	memcpy32bit((void*)(pdvfs_table->S3D1_DVFS_TABLE0_15),(void*)s3d1_dvfs_table,s3d1_table_size);
	memcpy32bit((void*)(pdvfs_table->VPP_DVFS_TABLE0_15),(void*)vpp_dvfs_table,vpp_table_size);
	//init voltage table
	memcpy32bit((void*)(pdvfs_table->VOL_MAP_TABLE0_63),(void*)vol_table,vol_table_size);
	//init lookup table
	memcpy32bit((void*)pdvfs_up_down_table->C3D_PERF_UP_TABLE,(void*)dvfs_lookup_table_all,sizeof(dvfs_lookup_table_all));

}
void pmu_init(void)
{
	
	dvfs_table_init();
	//enable dvfs
	p_dvfs_en_and_avs_en->C3D_DVFS_EN.reg.c3d_dvfs_en=1;
	p_dvfs_en_and_avs_en->S3D0_DVFS_EN.reg.s3d0_dvfs_en=0;
	p_dvfs_en_and_avs_en->S3D1_DVFS_EN.reg.s3d1_dvfs_en=0;
	p_dvfs_en_and_avs_en->VPP_DVFS_EN.reg.vpp_dvfs_en=0;
    
	//enable all irq
	p_int->PMP_IRQ_EN_CTRL.uint = 0x1fffffff;
	p_int->PMU_PCU_ASYNC_DELAY_CNT.uint = 0x1f;
   //test:
   /*
    p_int->CPU_IRQ_EN_CTRL.uint=0x1;
	p_int->PCU_IRQ_EN_CTRL.uint=0x2;
	p_int->PMP_IRQ_MASK_CTRL.uint=0x3;
	p_int->CPU_IRQ_MASK_CTRL.uint=0x4;
	p_int->PCU_IRQ_MASK_CTRL.uint=0x5;
	p_int->PMP_IRQ_CLR_CTRL.uint=0x6;
	p_int->CPU_IRQ_CLR_CTRL.uint=0x7;
	p_int->PCU_IRQ_CLR_CTRL.uint=0x8;
	p_int->PMP_INTERRUPT_STATUS.uint=0x9;
	p_int->CPU_INTERRUPT_STATUS.uint=0xa;
	p_int->PCU_INTERRUPT_STATUS.uint=0xb;
	p_int->PCU_IRQ_PREF_BOOST.uint=0xc;
	p_int->PCU_IRQ_PREF_REDUCE.uint=0xd;
	p_int->PMP_PCU_GRNT.uint=0xe;
	p_int->PMP_GPU_PERF_REQ.uint=0xf;
	p_int->CSP_PMU_TS_STATUS.uint=0x10;
	p_int->PCU_MAX_DVFS_CLAMP_VALUE.uint=0x11;
	p_int->PMU_CSP_ASYNC_DELAY_CNT.uint=0x12;
*/

	//disable sub irq
	p_int->PMP_IRQ_EN_CTRL.reg.vpp_dvfs_cmd_pmp_int = 0;
	p_int->PMP_IRQ_EN_CTRL.reg.s3d1_dvfs_cmd_pmp_int = 0;
	p_int->PMP_IRQ_EN_CTRL.reg.s3d0_dvfs_cmd_pmp_int = 0;
	p_int->PMP_IRQ_EN_CTRL.reg.c3d_dvfs_cmd_pmp_int = 0;
	p_int->PMP_IRQ_EN_CTRL.reg.vpp_avs_cmd_pmp_int = 0;
	p_int->PMP_IRQ_EN_CTRL.reg.s3d1_avs_cmd_pmp_int = 0;
	p_int->PMP_IRQ_EN_CTRL.reg.s3d0_avs_cmd_pmp_int = 0;
	p_int->PMP_IRQ_EN_CTRL.reg.c3d_avs_cmd_pmp_int = 0;
    //enable irq enable
	p_int->CPU_IRQ_EN_CTRL.uint = 0x80000000;
	// disable fiq
	p_int->PMP_IRQ_EN_CTRL.reg.c3d_avs_cmd_pmp_int = 0;
	p_int->PMP_IRQ_EN_CTRL.reg.GPU_TEMP_IRQ = 0;
	//mask reg mode int
	p_int->PMP_IRQ_MASK_CTRL.reg.C3D_DVFS_REG_INT=1;
	p_int->PMP_IRQ_MASK_CTRL.reg.S3D0_DVFS_REG_INT=1;
	p_int->PMP_IRQ_MASK_CTRL.reg.S3D1_DVFS_REG_INT=1;
	p_int->PMP_IRQ_MASK_CTRL.reg.VPP_DVFS_REG_INT=1;

	p_dvfs_reg_ctrl->C3D_DVFS_CFG.reg.max_dvfs_idx = 0xf;
	p_dvfs_reg_ctrl->S3D0_DVFS_CFG.reg.max_dvfs_idx = 0xf;
	p_dvfs_reg_ctrl->S3D1_DVFS_CFG.reg.max_dvfs_idx = 0xf;
	p_dvfs_reg_ctrl->VPP_DVFS_CFG.reg.max_dvfs_idx = 0xf;

	p_dvfs_reg_ctrl->C3D_DVFS_CFG.reg.min_dvfs_idx = 0;
	p_dvfs_reg_ctrl->S3D0_DVFS_CFG.reg.min_dvfs_idx = 0;
	p_dvfs_reg_ctrl->S3D1_DVFS_CFG.reg.min_dvfs_idx = 0;
	p_dvfs_reg_ctrl->VPP_DVFS_CFG.reg.min_dvfs_idx = 0;



	//enable ts register
	writel(0x00008020, 0x60000+(0x3007<<2));
	writel(0x3c000000, 0x60000+(0x3008<<2));
	writel(0x00e08001, 0x60000+(0x3005<<2));
	writel(0x00000200, 0x60000+(0x3006<<2));
	writel(0x0fffeda0, 0x60000+(0x3000<<2));
	writel(0x0000cdb6, 0x60000+(0x3001<<2));
	writel(0x0ffd49c2, 0x60000+(0x3002<<2));
	writel(0x000569c0, 0x60000+(0x3003<<2));
	writel(0x0ffb557d, 0x60000+(0x3004<<2));
	writel(0x0000b880, 0x60000+(0x300a<<2));
	writel(0x0280000a, 0x60000+(0x300b<<2));
	writel(0x0000003c, 0x60000+(0x300c<<2));
	writel(0x00000050, 0x60000+(0x300d<<2));
	writel(0x00000064, 0x60000+(0x300e<<2));
    writel(0x00000000, 0x60000+(0x300f<<2));
	writel(0x0008809f, 0x60000+(0x3009<<2));
	
}

int c3d_dvfs_reg(unsigned char dvfs_idx)
{
	unsigned int i;
	//wait dvfs reg mode free
	i=0;
	while(p_pmu->TSK_BUSY_STATUS.reg.c3d_dvfs_tsk_busy)
	{
		udelay(1);
		i++;
		if(i>=1000)
		{
			return -1;
		}
	}

	p_dvfs_reg_ctrl->C3D_DVFS_REG_CTRL.reg.dvfs_reg_idx=dvfs_idx;

	//wait dvfs reg mode switch finished
	i=0;
	while(p_int->PMP_INTERRUPT_STATUS.reg.C3D_DVFS_REG_INT==0)
	{
		udelay(1);
		i++;
		if(i>=1000)
		{
			return -1;
		}
	}
	if(p_int->PMP_INTERRUPT_STATUS.reg.C3D_DVFS_REG_INT)
	{
		p_int->PMP_IRQ_CLR_CTRL.reg.C3D_DVFS_REG_INT=1;
	}
	return 0;
}
int s3d0_dvfs_reg(unsigned char dvfs_idx)
{
	unsigned int i;
	//wait dvfs reg mode free
	i=0;
	while(p_pmu->TSK_BUSY_STATUS.reg.s3d0_dvfs_tsk_busy)
	{
		udelay(1);
		i++;
		if(i>=1000)
		{
			return -1;
		}
	}

	p_dvfs_reg_ctrl->S3D0_DVFS_REG_CTRL.reg.dvfs_reg_idx=dvfs_idx;

	//wait dvfs reg mode switch finished
	i=0;
	while(p_int->PMP_INTERRUPT_STATUS.reg.S3D0_DVFS_REG_INT==0)
	{
		udelay(1);
		i++;
		if(i>=1000)
		{
			return -1;
		}
	}
	if(p_int->PMP_INTERRUPT_STATUS.reg.S3D0_DVFS_REG_INT)
	{
		p_int->PMP_IRQ_CLR_CTRL.reg.S3D0_DVFS_REG_INT=1;
	}
	return 0;
}
int s3d1_dvfs_reg(unsigned char dvfs_idx)
{
	unsigned int i;
	//wait dvfs reg mode free
	i=0;
	while(p_pmu->TSK_BUSY_STATUS.reg.s3d1_dvfs_tsk_busy)
	{
		udelay(1);
		i++;
		if(i>=1000)
		{
			return -1;
		}
	}

	p_dvfs_reg_ctrl->S3D1_DVFS_REG_CTRL.reg.dvfs_reg_idx=dvfs_idx;

	//wait dvfs reg mode switch finished
	i=0;
	while(p_int->PMP_INTERRUPT_STATUS.reg.S3D1_DVFS_REG_INT==0)
	{
		udelay(1);
		i++;
		if(i>=1000)
		{
			return -1;
		}
	}
	if(p_int->PMP_INTERRUPT_STATUS.reg.S3D1_DVFS_REG_INT)
	{
		p_int->PMP_IRQ_CLR_CTRL.reg.S3D1_DVFS_REG_INT=1;
	}
	return 0;
}
int vpp_dvfs_reg(unsigned char dvfs_idx)
{
	unsigned int i;
	//wait dvfs reg mode free
	i=0;
	while(p_pmu->TSK_BUSY_STATUS.reg.vpp_dvfs_reg_tsk_busy )
	{
		udelay(1);
		i++;
		if(i>=1000)
		{
			return -1;
		}
	}

	p_dvfs_reg_ctrl->VPP_DVFS_REG_CTRL.reg.dvfs_reg_idx=dvfs_idx;

	//wait dvfs reg mode switch finished
	i=0;
	while(p_int->PMP_INTERRUPT_STATUS.reg.VPP_DVFS_REG_INT==0)
	{
		udelay(1);
		i++;
		if(i>=1000)
		{
			return -1;
		}
	}
	if(p_int->PMP_INTERRUPT_STATUS.reg.VPP_DVFS_REG_INT)
	{
		p_int->PMP_IRQ_CLR_CTRL.reg.VPP_DVFS_REG_INT=1;
	}
	return 0;
}

unsigned char power_to_index(unsigned int power)
{
	int i;
	unsigned int power_buf;
	for(i=0;i<16;i++)
	{
		power_buf = c3d_index_power_table[i];
					//s3d0_index_power_table[i]+\
					//s3d1_index_power_table[i]+\
					//vpp_index_power_table[i];	
		if(power_buf>power)
		{
			return --i;
		}
	}

	return 15;	
}

void power_budget_boost(unsigned int power)
{
  
	//1. update GPU_PERF_REQ
	if(power > p_int->PCU_MAX_DVFS_CLAMP_VALUE.reg.MAX_DVFS_CLAMP)
	{
		p_int->PMP_GPU_PERF_REQ.uint = power;
	}		
	else
	{
		return;
	}
	
	//2. tell pcu gpu required power
	p_int->PCU_IRQ_PREF_BOOST.reg.pcu_irq_pref_boost = 1;
	//clear boost to 0, boost enter busy status
	task_status.boost = 0;
  
}
void power_budget_reduce(unsigned int power)
{
	//1. update GPU_PERF_REQ
	if(power < p_int->PCU_MAX_DVFS_CLAMP_VALUE.reg.MAX_DVFS_CLAMP)
	{
		p_int->PMP_GPU_PERF_REQ.uint= power;
	}		
	else
	{
		return;
	}	
	//2. tell pcu gpu reduce power
	p_int->PCU_IRQ_PREF_REDUCE.reg.pcu_irq_pref_reduce = 1;
}


void pmu_int_handler(void) {
	unsigned char idx=0;

	if(p_int->PMP_INTERRUPT_STATUS.reg.pcu_grnt_wen)
	//if(p_int->PMP_PCU_GRNT.reg.PCU_GRNT)
	{
		//clear status
		p_int->PMP_IRQ_CLR_CTRL.reg.pcu_grnt_wen=1;
		//update task status
		//task_status.boost = p_int->PMP_PCU_GRNT.reg.PCU_GRNT;

	}
	else if(p_int->PMP_INTERRUPT_STATUS.reg.pcu_max_dvfs_clamp_wen)
	{
		//clear status
		p_int->PMP_IRQ_CLR_CTRL.reg.pcu_max_dvfs_clamp_wen=1;
		task_status.boost = p_int->PMP_PCU_GRNT.reg.PCU_GRNT;

		//used max power
		all_power_budget = c3d_index_power_table[p_dvfs_reg_ctrl->C3D_DVFS_CFG.reg.max_dvfs_idx]+\
						   s3d0_index_power_table[p_dvfs_reg_ctrl->S3D0_DVFS_CFG.reg.max_dvfs_idx]+\
						   s3d1_index_power_table[p_dvfs_reg_ctrl->S3D1_DVFS_CFG.reg.max_dvfs_idx]+\
						   vpp_index_power_table[p_dvfs_reg_ctrl->VPP_DVFS_CFG.reg.max_dvfs_idx];	

		idx = power_to_index(p_int->PCU_MAX_DVFS_CLAMP_VALUE.reg.MAX_DVFS_CLAMP);
			p_dvfs_reg_ctrl->C3D_DVFS_CFG.reg.max_dvfs_idx = idx;
			p_dvfs_reg_ctrl->S3D0_DVFS_CFG.reg.max_dvfs_idx = idx;
			p_dvfs_reg_ctrl->S3D1_DVFS_CFG.reg.max_dvfs_idx = idx;
			p_dvfs_reg_ctrl->VPP_DVFS_CFG.reg.max_dvfs_idx = idx;



		if(all_power_budget > p_int->PCU_MAX_DVFS_CLAMP_VALUE.reg.MAX_DVFS_CLAMP)
		{
			//reduce
			if(p_dvfs_reg_ctrl->C3D_DVFS_CFG.reg.min_dvfs_idx > idx)
			{
				if(idx>0)
				{
					p_dvfs_reg_ctrl->C3D_DVFS_CFG.reg.min_dvfs_idx = idx-1;
					p_dvfs_reg_ctrl->S3D0_DVFS_CFG.reg.min_dvfs_idx = idx-1;
					p_dvfs_reg_ctrl->S3D1_DVFS_CFG.reg.min_dvfs_idx = idx-1;
					p_dvfs_reg_ctrl->VPP_DVFS_CFG.reg.min_dvfs_idx = idx-1;
				}
				else
				{
					p_dvfs_reg_ctrl->C3D_DVFS_CFG.reg.min_dvfs_idx = 0;
					p_dvfs_reg_ctrl->S3D0_DVFS_CFG.reg.min_dvfs_idx = 0;
					p_dvfs_reg_ctrl->S3D1_DVFS_CFG.reg.min_dvfs_idx = 0;
					p_dvfs_reg_ctrl->VPP_DVFS_CFG.reg.min_dvfs_idx = 0;
				}
			}
		}

	}
	else if(p_int->PMP_INTERRUPT_STATUS.reg.vpp_perf_reduce)
	{
		//clear status
		p_int->PMP_IRQ_CLR_CTRL.reg.vpp_perf_reduce=1;

		if(p_dvfs_reg_ctrl->VPP_DVFS_CFG.reg.min_dvfs_idx>0)
		{
			p_dvfs_reg_ctrl->VPP_DVFS_CFG.reg.min_dvfs_idx-=1;
		}

	}
	else if(p_int->PMP_INTERRUPT_STATUS.reg.vpp_perf_boost)
	{
		//clear status
		p_int->PMP_IRQ_CLR_CTRL.reg.vpp_perf_boost=1;

		if(p_dvfs_reg_ctrl->VPP_DVFS_CFG.reg.max_dvfs_idx<0xf)
		{
			// all power for boosting one step 
			all_power_budget = 	c3d_index_power_table[p_dvfs_reg_ctrl->C3D_DVFS_CFG.reg.max_dvfs_idx+1]+\
								s3d0_index_power_table[p_dvfs_reg_ctrl->S3D0_DVFS_CFG.reg.max_dvfs_idx+1]+\
								s3d1_index_power_table[p_dvfs_reg_ctrl->S3D1_DVFS_CFG.reg.max_dvfs_idx+1]+\
								vpp_index_power_table[p_dvfs_reg_ctrl->VPP_DVFS_CFG.reg.max_dvfs_idx+1];
			power_budget_boost(all_power_budget);
		}

	}
	else if(p_int->PMP_INTERRUPT_STATUS.reg.s3d1_perf_reduce)
	{
		//clear status
		p_int->PMP_IRQ_CLR_CTRL.reg.s3d1_perf_reduce=1;
		if(p_dvfs_reg_ctrl->S3D1_DVFS_CFG.reg.min_dvfs_idx>0)
		{
			p_dvfs_reg_ctrl->S3D1_DVFS_CFG.reg.min_dvfs_idx-=1;
		}

	}
	else if(p_int->PMP_INTERRUPT_STATUS.reg.s3d1_perf_boost)
	{
		//clear status
		p_int->PMP_IRQ_CLR_CTRL.reg.s3d1_perf_boost=1;

		if(p_dvfs_reg_ctrl->S3D1_DVFS_CFG.reg.max_dvfs_idx<0xf)
		{
			// all power for boosting one step 
			all_power_budget = 	c3d_index_power_table[p_dvfs_reg_ctrl->C3D_DVFS_CFG.reg.max_dvfs_idx+1]+\
								s3d0_index_power_table[p_dvfs_reg_ctrl->S3D0_DVFS_CFG.reg.max_dvfs_idx+1]+\
								s3d1_index_power_table[p_dvfs_reg_ctrl->S3D1_DVFS_CFG.reg.max_dvfs_idx+1]+\
								vpp_index_power_table[p_dvfs_reg_ctrl->VPP_DVFS_CFG.reg.max_dvfs_idx+1];
			power_budget_boost(all_power_budget);
		}

	}
	else if(p_int->PMP_INTERRUPT_STATUS.reg.s3d0_perf_reduce)
	{
		//clear status
		p_int->PMP_IRQ_CLR_CTRL.reg.s3d0_perf_reduce=1;
		if(p_dvfs_reg_ctrl->S3D0_DVFS_CFG.reg.min_dvfs_idx>0)
		{
			p_dvfs_reg_ctrl->S3D0_DVFS_CFG.reg.min_dvfs_idx-=1;
		}
	}
	else if(p_int->PMP_INTERRUPT_STATUS.reg.s3d0_perf_boost)
	{
		//clear status
		p_int->PMP_IRQ_CLR_CTRL.reg.s3d0_perf_boost=1;

		if(p_dvfs_reg_ctrl->S3D0_DVFS_CFG.reg.max_dvfs_idx<0xf)
		{
			// all power for boosting one step 
			all_power_budget = 	c3d_index_power_table[p_dvfs_reg_ctrl->C3D_DVFS_CFG.reg.max_dvfs_idx+1]+\
								s3d0_index_power_table[p_dvfs_reg_ctrl->S3D0_DVFS_CFG.reg.max_dvfs_idx+1]+\
								s3d1_index_power_table[p_dvfs_reg_ctrl->S3D1_DVFS_CFG.reg.max_dvfs_idx+1]+\
								vpp_index_power_table[p_dvfs_reg_ctrl->VPP_DVFS_CFG.reg.max_dvfs_idx+1];
			power_budget_boost(all_power_budget);
		}

	}
	else if(p_int->PMP_INTERRUPT_STATUS.reg.c3d_perf_reduce)
	{
		//clear status
		p_int->PMP_IRQ_CLR_CTRL.reg.c3d_perf_reduce=1;

		if(p_dvfs_reg_ctrl->C3D_DVFS_CFG.reg.min_dvfs_idx>0)
		{
			p_dvfs_reg_ctrl->C3D_DVFS_CFG.reg.min_dvfs_idx-=1;
		}
	}
	else if(p_int->PMP_INTERRUPT_STATUS.reg.c3d_perf_boost)
	{
		//clear status
		p_int->PMP_IRQ_CLR_CTRL.reg.c3d_perf_boost=1;

		if(p_dvfs_reg_ctrl->C3D_DVFS_CFG.reg.max_dvfs_idx<0xf)
		{
			// all power for boosting one step 
			all_power_budget = 	c3d_index_power_table[p_dvfs_reg_ctrl->C3D_DVFS_CFG.reg.max_dvfs_idx+1]+\
								s3d0_index_power_table[p_dvfs_reg_ctrl->S3D0_DVFS_CFG.reg.max_dvfs_idx+1]+\
								s3d1_index_power_table[p_dvfs_reg_ctrl->S3D1_DVFS_CFG.reg.max_dvfs_idx+1]+\
								vpp_index_power_table[p_dvfs_reg_ctrl->VPP_DVFS_CFG.reg.max_dvfs_idx+1];
			power_budget_boost(all_power_budget);
		}

	}
	// else if(p_int->PMP_INTERRUPT_STATUS.reg.VPP_DVFS_REG_INT)
	// {
	// 	//clear status
	// 	p_int->PMP_IRQ_CLR_CTRL.reg.VPP_DVFS_REG_INT=1;

	// }
	// else if(p_int->PMP_INTERRUPT_STATUS.reg.S3D1_DVFS_REG_INT)
	// {
	// 	//clear status
	// 	p_int->PMP_IRQ_CLR_CTRL.reg.S3D1_DVFS_REG_INT=1;

	// }
	// else if(p_int->PMP_INTERRUPT_STATUS.reg.S3D0_DVFS_REG_INT)
	// {
	// 	//clear status
	// 	p_int->PMP_IRQ_CLR_CTRL.reg.S3D0_DVFS_REG_INT=1;

	// }
	// else if(p_int->PMP_INTERRUPT_STATUS.reg.C3D_DVFS_REG_INT)
	// {
	// 	//clear status
	// 	p_int->PMP_IRQ_CLR_CTRL.reg.C3D_DVFS_REG_INT=1;

	// }
	

}
void pmu_fiq_handler(void) {

}

//c3d reg mode test
void c3d_reg_mode_test(void)
{
	static unsigned char reg_idx=0;
	
	if(c3d_dvfs_reg(reg_idx)==0)
			reg_idx++;
	if(reg_idx >= 16)
	{
		reg_idx=0;
	}
}

		

//pcu boost and reduce test
void pcu_boost_reduce_test(void)
{
	static unsigned char pcu_boost_reduce_index=0;
	
	if(pcu_boost_reduce_index<16)
	{
		if(task_status.boost)
		{
				power_budget_boost(c3d_index_power_table[pcu_boost_reduce_index]);
				//power_budget_boost(c3d_index_power_table[pcu_boost_reduce_index]);
				pcu_boost_reduce_index++;
		}
		else
		{
			if(pcu_boost_reduce_index<3)
			{
				pcu_boost_reduce_index=32-3;
			}
			else
			{
				pcu_boost_reduce_index = 32 -pcu_boost_reduce_index;
			}
		}
		
	}
	else if(pcu_boost_reduce_index<32)
	{
		power_budget_reduce(c3d_index_power_table[32-pcu_boost_reduce_index-1]);
		pcu_boost_reduce_index++;
	}
	else
	{
		pcu_boost_reduce_index=0;
		task_status.boost=1;
	}

	
/*
    if(pcu_boost_reduce_index<16){
	  if(pcu_boost_reduce_index>=0){
	    if(task_status.boost==1)
		{
			power_budget_boost(c3d_index_power_table[pcu_boost_reduce_index]);
			//power=c3d_index_power_table[pcu_boost_reduce_index];
			//printf("pcu_boost_reduce_index is %d\n",pcu_boost_reduce_index);
			pcu_boost_reduce_index++;
			
			//printf("power is %x\n",power);
			
		}
	    else{
			if(pcu_boost_reduce_index>0){
		    power_budget_reduce(c3d_index_power_table[pcu_boost_reduce_index]);
			//power=c3d_index_power_table[pcu_boost_reduce_index];
			//printf("pcu_boost_reduce_index is %d\n",pcu_boost_reduce_index);
			pcu_boost_reduce_index--;
			//printf("power is %x\n",power);
			}
			else{
				task_status.boost=1;
			}
	    } 
	 }
	}
	else{
        pcu_boost_reduce_index=15;
		task_status.boost=0;    
	}

*/	  
     

}