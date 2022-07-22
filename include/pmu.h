#ifndef _PMU_H_
#define _PMU_H_
#include "CNE001_pmu_reg_autogen.h"

#define PMU_DEBUG 0
#define DVFS_TABLE_SIZE 128     //16*8
#define VOL_TABLE_SIZE 512     //64*8

enum ENGIN_INDEX{
    NONE = 0,
    C3D,
    S3D0,
    S3D1,
    VPP
};

#if 0
typedef union{
    unsigned int uint[2];
    struct
    {
        unsigned int OD             :3;     //OD[2:0]
        unsigned int N              :20;    //N[22:3]
        unsigned int reserved       :1;     //[23]
        unsigned int M              :8;     //[31:24]
        unsigned int freq_div       :4;     //Divider[35:32]
        unsigned int vol_index0     :6;     //vol index 0[41:36]
        unsigned int pll_sel        :1;     //PLL_SEL[42]
        unsigned int csp_div        :4;     //CSP_divider[46:43]
        unsigned int reserved       :3;     //[49:47]
        unsigned int parking_div    :4;     //[53:50]
        unsigned int csp_freq       :10;    //[63:54]
    }reg;
}DVFS_TABLE;
#endif

typedef struct{
        unsigned int OD             :3;     //OD[2:0]
        unsigned int N              :20;    //N[22:3]
        unsigned int reserved       :1;     //[23]
        unsigned int M              :8;     //[31:24]
        unsigned int freq_div       :4;     //Divider[35:32]
        unsigned int vol_index0     :6;     //vol index 0[41:36]
        unsigned int pll_sel        :1;     //PLL_SEL[42]
        unsigned int csp_div        :4;     //CSP_divider[46:43]
        unsigned int reserved1      :3;     //[49:47]
        unsigned int parking_div    :4;     //[53:50]
        unsigned int csp_freq       :10;    //[63:54]
}DVFS_TABLE;
typedef struct{
        unsigned int vid            :8;     //svid[7:0]
        unsigned int slew           :2;     //slew[9:8]
        unsigned int reserved       :2;     //[11:10]
        unsigned int ps             :2;     //ps[13:12]
        unsigned int reserved2      :18;    //[31:14]
        unsigned int reserved3      :25;    //[63:32]       
}VOLTAGE_TABLE;
typedef struct{
        unsigned int index0         :4;    
        unsigned int index1         :4;    
        unsigned int index2         :4;    
        unsigned int index3         :4;    
        unsigned int index4         :4;    
        unsigned int index5         :4;    
        unsigned int index6         :4;    
        unsigned int index7         :4;    
        unsigned int index8         :4;    
        unsigned int index9         :4;    
        unsigned int index10         :4;    
        unsigned int index11         :4;    
        unsigned int index12         :4;    
        unsigned int index13         :4;    
        unsigned int index14         :4;    
        unsigned int index15         :4;    
}DVFS_LOOKUP_TABLE;

typedef struct{
        unsigned int boost              :1; //1: can trigger boost irq, 0: boost irq refused or busy
        unsigned int boost_engine_index  :3; //
        unsigned int reduce_engine_index :3; //
}DVFS_TASK_STATUS;



void dvfs_table_init(void);
void pmu_init(void);
void pmu_int_handler(void);
void pmu_fiq_handler(void);

int c3d_dvfs_reg(unsigned char dvfs_idx);
int s3d0_dvfs_reg(unsigned char dvfs_idx);
int s3d1_dvfs_reg(unsigned char dvfs_idx);
int vpp_dvfs_reg(unsigned char dvfs_idx);

void power_budget_boost(unsigned int power);

void c3d_reg_mode_test(void);
void pcu_boost_reduce_test(void);

#endif
