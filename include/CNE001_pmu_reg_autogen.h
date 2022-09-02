#ifndef _PMU_REG_H_
#define _PMU_REG_H_

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int pmu_nb_ppll_val          :4;  //RW [3:0] DIV= 0000:  2/3 (0.667) speed of PLL clock;
                                                   //DIV= 0001:  1/1 (1.000) speed of PLL clock;
                                                   //DIV= 0010:  1/2 (0.500) speed of PLL clock;
                                                   //DIV= 0011:  1/3 (0.333) speed of PLL clock;
                                                   //DIV= 0100:  1/4 (0.250) speed of PLL clock;
                                                   //DIV= 0101:  1/5 (0.200) speed of PLL clock;
                                                   //DIV= 0110:  1/6 (0.167) speed of PLL clock;
                                                   //DIV= 0111:  1/7 (0.143) speed of PLL clock;
                                                   //DIV= 1000:  1/8 (0.125) speed of PLL clock;
                                                   //DIV= 1001:  2/5 (0.400) speed of PLL clock;
                                                   //DIV= 1010:  1/10 (0.100) speed of PLL clock;
                                                   //DIV= 1011:  2/7 (0.286) speed of PLL clock;
                                                   //DIV= 1100:  1/12 (0.083) speed of PLL clock;
                                                   //DIV= 1101:  1/16 (0.0625) speed of PLL clock;
                                                   //DIV= 1110:  1/32 (0.032) speed of PLL clock;
                                                   //DIV= 1111:  1/64 (0.016) speed of PLL clock;
		unsigned int Reserved1                :28; //[31:4]
	}reg;
}Reg_PMU_NB_CLK_CFG_OFST;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int pmu_pmp_ppll_val         :4;  //RW [3:0] 
		unsigned int Reserved1                :28; //[31:4]
	}reg;
}Reg_PMU_PMP_CLK_CFG_OFST;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int pmu_uart_val          :4;   //RW [3:0]uart clock divider value
		unsigned int Reserved0          :28;   // [31:4]
	}reg;
}Reg_PMU_CCP_UART_CFG_OFST;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int dfs_pll_ok_dly_ref_cnt   :16; //RW [15:0] 
		unsigned int Reserved0                :16; //R [31:16] Reserved
	}reg;
}Reg_PMU_PLL_OK_DLY_CNT_OFST;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int pll_rst_dly_ref_cnt      :12; //RW [11:0]
		unsigned int dfs_pll_pd_dly_ref_cnt   :6;  //RW [17:12]
		unsigned int Reserved0                :2;  //R [19:18]
		unsigned int dfs_pll_rst_dly_ref_cnt  :9;  //RW [28:20]
		unsigned int Reserved                 :2;  //R [30:29]
		unsigned int Reserved2                :1;  //[31]
	}reg;
}Reg_PMU_PLL_DLY_CNT_OFST;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int PMU_EPLL_M               :8;  //RW [7:0] 
		unsigned int PMU_EPLL_N               :20; //RW [27:8] 
		unsigned int PMU_EPLL_OD              :3;  //RW [30:28] 
		unsigned int Reserved1                :1;  //[31]
	}reg;
}Reg_PMU_EPLL_CTRL0_OFST;

typedef union{
    unsigned int uint;
    struct
    {
      unsigned int PMU_EPLL_PU          :1;   //RW [0]
      unsigned int Reserved0          :7;   // [7:1]
      unsigned int PMU_EPLL_RST          :1;   //RW [8]
      unsigned int Reserved1          :23;   // [31:9]Reserved
   }reg;
}Reg_PMU_EPLL_CTRL1_OFST;
/*
typedef union{
    unsigned int uint;
    struct
    {
		unsigned int PMU_EPLL_PU              :1;  //RW [0] 
		unsigned int PMU_EPLL_RST             :1;  //RW [1] 
		unsigned int Reserved0                :30; // [31:2] Reserved
	}reg;
}Reg_PMU_EPLL_CTRL1_OFST;
*/
typedef union{
    unsigned int uint;
    struct
    {
		unsigned int pmu_epll_icpsel          :4;  //RW [3:0]
		unsigned int pmu_epll_fracen          :1;  //RW [4]
		unsigned int pmu_epll_ck2_divn        :3;  //RW [7:5]
		unsigned int pmu_epll_ck1_divn        :3;  //RW [10:8]
		unsigned int pmu_epll_refdly_sel      :3;  //RW [13:11]
		unsigned int pmu_epll_fbdly_sel       :3;  //RW [16:14]
		unsigned int pmu_epll_div_mode        :1;  //RW [17]
		unsigned int pmu_epll_fvco_tune_abs   :4;  //RW [21:18]
		unsigned int pmu_epll_fvco_tune_tc    :4;  //RW [25:22]
		unsigned int Reserved0                :4;  //R  [29:26]
		unsigned int pmu_epll_ck2_en          :1;  //RW [30]
		unsigned int pmu_epll_ck1_en          :1;  //RW [31]
	}reg;
}Reg_PMU_EPLL_CTRL2_OFST;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int PMU_VPLL_M               :8;  //RW [7:0] 
		unsigned int PMU_VPLL_N               :20; //RW [27:8] 
		unsigned int PMU_VPLL_OD              :3;  //RW [30:28] 
		unsigned int Reserved1                :1;  //[31]
	}reg;
}Reg_PMU_VPLL_CTRL0_OFST;

typedef union{
    unsigned int uint;
    struct
    {
      unsigned int PMU_VPLL_PU          :1;   //RW [0]
      unsigned int Reserved0          :7;   // [7:1]
      unsigned int PMU_VPLL_RST          :1;   //RW [8]
      unsigned int Reserved1          :23;   // [31:9]Reserved
   }reg;
}Reg_PMU_VPLL_CTRL1_OFST;
/*
typedef union{
    unsigned int uint;
    struct
    {
		unsigned int PMU_VPLL_PU              :1;  //RW [0] 
		unsigned int PMU_VPLL_RST             :1;  //RW [1] 
		unsigned int Reserved0                :30; // [31:2] Reserved
	}reg;
}Reg_PMU_VPLL_CTRL1_OFST;
*/
typedef union{
    unsigned int uint;
    struct
    {
		unsigned int pmu_vpll_icpsel          :4;  //RW [3:0]
		unsigned int pmu_vpll_fracen          :1;  //RW [4]
		unsigned int pmu_vpll_ck2_divn        :3;  //RW [7:5]
		unsigned int pmu_vpll_ck1_divn        :3;  //RW [10:8]
		unsigned int pmu_vpll_refdly_sel      :3;  //RW [13:11]
		unsigned int pmu_vpll_fbdly_sel       :3;  //RW [16:14]
		unsigned int pmu_vpll_div_mode        :1;  //RW [17]
		unsigned int pmu_vpll_fvco_tune_abs   :4;  //RW [21:18]
		unsigned int pmu_vpll_fvco_tune_tc    :4;  //RW [25:22]
		unsigned int Reserved0                :4;  //R  [29:26]
		unsigned int pmu_vpll_ck2_en          :1;  //RW [30]
		unsigned int pmu_vpll_ck1_en          :1;  //RW [31]
	}reg;
}Reg_PMU_VPLL_CTRL2_OFST;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int PMU_PPLL_M               :8;  //RW [7:0] 
		unsigned int PMU_PPLL_N               :20; //RW [27:8] 
		unsigned int PMU_PPLL_OD              :3;  //RW [30:28] 
		unsigned int Reserved1                :1;  //[31]
	}reg;
}Reg_PMU_PPLL_CTRL0_OFST;

typedef union{
    unsigned int uint;
    struct
    {
      unsigned int PMU_PPLL_PU          :1;   //RW [0]
      unsigned int Reserved0          :7;   //R [7:1]
      unsigned int PMU_PPLL_RST          :1;   //RW [8]
      unsigned int Reserved1          :23;   //R [31:9]Reserved
   }reg;
}Reg_PMU_PPLL_CTRL1_OFST;
/*
typedef union{
    unsigned int uint;
    struct
    {
		unsigned int PMU_PPLL_PU              :1;  //RW [0] 
		unsigned int PMU_PPLL_RST             :1;  //RW [1] 
		unsigned int Reserved0                :30; // [31:2] Reserved
	}reg;
}Reg_PMU_PPLL_CTRL1_OFST;
*/

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int pmu_ppll_icpsel          :4;  //RW [3:0]
		unsigned int pmu_ppll_fracen          :1;  //RW [4]
		unsigned int pmu_ppll_ck2_divn        :3;  //RW [7:5]
		unsigned int pmu_ppll_ck1_divn        :3;  //RW [10:8]
		unsigned int pmu_ppll_refdly_sel      :3;  //RW [13:11]
		unsigned int pmu_ppll_fbdly_sel       :3;  //RW [16:14]
		unsigned int pmu_ppll_div_mode        :1;  //RW [17]
		unsigned int pmu_ppll_fvco_tune_abs   :4;  //RW [21:18]
		unsigned int pmu_ppll_fvco_tune_tc    :4;  //RW [25:22]
		unsigned int Reserved0                :4;  //R  [29:26]
		unsigned int pmu_ppll_ck2_en          :1;  //RW [30]
		unsigned int pmu_ppll_ck1_en          :1;  //RW [31]
	}reg;
}Reg_PMU_PPLL_CTRL2_OFST;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int S3D0                     :1;  //RW [0] //vdp_dfs_vpll_cfg[0] S3D0 setting VPLL
		unsigned int S3D1                     :1;  //RW [1] //vdp_dfs_vpll_cfg[1] S3D1 setting VPLL
		unsigned int VPP                      :1;  //RW [2] //vdp_dfs_vpll_cfg[2] VPP  setting VPLL
		unsigned int Reserved0                :1;  // [3] reserved
		unsigned int VDP_VPLL_SW_MODE_EN      :1;  //RW [4] VDP_VPLL SW_MODE EN, if enable default S3VD0 setting VPLL
		unsigned int Reserved2                :27; //[31:5]
	}reg;
}Reg_VDP_DFS_VPLL_CFG_OFST;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int updating_epll            :1;  //RO [0]
		unsigned int updating_vpll            :1;  //RO [1]
		unsigned int updating_ppll            :1;  //RO [2]
		unsigned int PMU_EPLL_OK              :1;  //RO [3]
		unsigned int PMU_VPLL_OK              :1;  //RO [4]
		unsigned int PMU_PPLL_OK              :1;  //RO [5]
		unsigned int Reserved                 :26; //R [31:6]
	}reg;
}Reg_PMU_SOC_PLL_STATUS_OFST;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int clk_switch_dly_ref_cnt   :8;  //RW [7:0] clk_switch_dly_ref_cnt
		unsigned int div_force_parking        :1;  //RW [8] div_force_parking
		unsigned int Reserved0                :20; //R [31:12] Reserved
		unsigned int Reserved2                :3;  //[31:29]
	}reg;
}Reg_PMU_DFS_CLK_DLY_CNT_OFST;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int clk_sel_reg              :1;  //RW [0] pmu_c3d_clk_sel,default epll
		unsigned int clk_en_reg               :1;  //RW [1] pmu_c3d_clk_en
		unsigned int Reserved2                :6;  //RW [7:2] Reserved
		unsigned int p_clk_div_val_reg        :4;  //RW [11:8] pmu_ppll_c3d_val(parking_clk_div)
		unsigned int Reserved1                :4;  //RW [14:11] Reserved
		unsigned int clk_div_val_reg          :4;  //RW [19:16] pmu_epll_c3d_val(main_clk_div)
		unsigned int Reserved0                :12; //R [31:20] Reserved
	}reg;
}Reg_PMU_ECLK_EXT_CLK_CFG_OFST;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int clk_sel_reg              :1;  //RW [0] pmu_s3d0_clk_sel,default vpll
		unsigned int clk_en_reg               :1;  //RW [1] pmu_s3d0_clk_en
		unsigned int Reserved2                :6;  //RW [7:2] Reserved
		unsigned int p_clk_div_val_reg        :4;  //RW [11:8] pmu_ppll_s3d0_val(parking_clk_div)
		unsigned int Reserved1                :4;  //RW [14:11] Reserved
		unsigned int clk_div_val_reg          :4;  //RW [19:16] pmu_vpll_s3d0_val(main_clk_div)
		unsigned int Reserved0                :12; //R [31:20] Reserved
	}reg;
}Reg_PMU_S0CLK_EXT_CLK_CFG_OFST;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int clk_sel_reg              :1;  //RW [0] pmu_s3d1_clk_sel,default vpll
		unsigned int clk_en_reg               :1;  //RW [1] pmu_s3d1_clk_en
		unsigned int Reserved2                :6;  //RW [7:2] Reserved
		unsigned int p_clk_div_val_reg        :4;  //RW [11:8] pmu_ppll_s3d1_val(parking_clk_div)
		unsigned int Reserved1                :4;  //RW [14:11] Reserved
		unsigned int clk_div_val_reg          :4;  //RW [19:16] pmu_vpll_s3d1_val(main_clk_div)
		unsigned int Reserved0                :12; //R [31:20] Reserved
	}reg;
}Reg_PMU_S1CLK_EXT_CLK_CFG_OFST;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int clk_sel_reg              :1;  //RW [0] pmu_vpp_clk_sel,default vpll
		unsigned int clk_en_reg               :1;  //RW [1] pmu_vpp_clk_en
		unsigned int Reserved2                :6;  //RW [7:2] Reserved
		unsigned int p_clk_div_val_reg        :4;  //RW [11:8] pmu_ppll_vpp_val(parking_clk_div)
		unsigned int Reserved1                :4;  //RW [14:11] Reserved
		unsigned int clk_div_val_reg          :4;  //RW [19:16] pmu_vpll_vpp_val(main_clk_div)
		unsigned int Reserved0                :12; //R [31:20] Reserved
	}reg;
}Reg_PMU_VPP_EXT_CLK_CFG_OFST;

typedef union{
    unsigned int uint;
    struct
    {
      unsigned int soc_clk_en_reg          :1;   //RW [0]//assign pmu_csp_mxu0_clk_en = soc_clk_en_reg[0];// move to pmu_center_dfs_ctrl
      unsigned int pmu_nb_clk_en          :1;   //RW [1]
      unsigned int pmu_pmp_clk_en          :1;   //RW [2]
      unsigned int pmu_epll_ref_clk_en          :1;   //RW [3]
      unsigned int pmu_vpll_ref_clk_en          :1;   //RW [4]
      unsigned int pmu_ppll_ref_clk_en          :1;   //RW [5]
      unsigned int PMU_S3VD0_CLKEN          :1;   //RW [6]
      unsigned int PMU_S3VD1_CLKEN          :1;   //RW [7]
      unsigned int PMU_S3VD2_CLKEN          :1;   //RW [8]
      unsigned int PMU_S3VD3_CLKEN          :1;   //RW [9]
      unsigned int PMU_VPP_CLKEN          :1;   //RW [10]
      unsigned int PMU_VPP1_CLKEN          :1;   //RW [11]
      unsigned int pmu_uart_clk_en          :1;   //RW [12]
      unsigned int Reserved          :19;   //R [31:13]
   }reg;
}Reg_PMU_CLK_EN_OFST;

/*
typedef union{
    unsigned int uint;
    struct
    {
		unsigned int pmu_csp_mxu0_clk_en      :1;  //RW [0]
		unsigned int pmu_nb_clk_en            :1;  //RW [1]
		unsigned int pmu_pmp_clk_en           :1;  //RW [2]
		unsigned int pmu_epll_ref_clk_en      :1;  //RW [3]
		unsigned int pmu_vpll_ref_clk_en      :1;  //RW [4]
		unsigned int pmu_ppll_ref_clk_en      :1;  //RW [5]
		unsigned int Reserved                 :26; //R [31:6]
	}reg;
}Reg_PMU_CLK_EN_OFST;
*/
typedef union{
    unsigned int uint;
    struct
    {
      unsigned int soc_clk_en_reg          :16;   //WTC [15:0]write 1 to clr clk_en above
      unsigned int Reserved0          :16;   // [31:16]
   }reg;
}Reg_PMU_CLK_EN_CLR_OFST;
/*
typedef union{
    unsigned int uint;
    struct
    {
		unsigned int soc_clk_en_reg           :17; //WTC [16:0] write 1 to clr clk_en above
		unsigned int Reserved1                :15; //[31:17]
	}reg;
}Reg_PMU_CLK_EN_CLR_OFST;
*/
typedef union{
    unsigned int uint;
    struct
    {
		unsigned int             S1CLK_EXT_SEL:1;  //RW [0] 1: sel external clk  0: PLL clk
		unsigned int             S0CLK_EXT_SEL:1;  //RW [1] 1: sel external clk  0: PLL clk
		unsigned int             VCLK_EXT_SEL :1;  //RW [2] 1: sel external clk  0: PLL clk
		unsigned int             ECLK_EXT_SEL :1;  //RW [3] 1: sel external clk  0: PLL clk
		unsigned int Reserved1                :28; //[31:4]
	}reg;
}Reg_PMU_SOC_CLK_SEL_OFST;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int clk_sel_reg              :2;  //RW [1:0] pmu_csp_mxu0_clk_sel,2'b00: sel epll;  2'b01: sel vpll;1'b10:sel ppll (default);
		unsigned int clk_en_reg               :1;  //RW [2] pmu_csp_mxu0_clk_en
		unsigned int Reserved1                :1;  // [3] Reserved
		unsigned int clk_pdiv_val_reg         :4;  //RW [7:4] pmu_csp_mxu0_ppll_val
		unsigned int clk_vdiv_val_reg         :4;  //RW [11:8] pmu_csp_mxu0_vpll_val 
		unsigned int clk_ediv_val_reg         :4;  //RW [15:12] pmu_csp_mxu0_epll_val 
		unsigned int Reserved0                :16; //RW [31:16] Reserved
	}reg;
}Reg_PMU_CSP_MXU0_PLL_EXT_CLK_CFG_OFST;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int Reserved0                :24; // [23:0] 
		unsigned int max_dvfs_idx             :4;  // [27:24] wire    [ 3:0]  c3d_max_dvfs_idx  = c3d_dvfs_cfg[27:24];
		unsigned int min_dvfs_idx             :4;  //RW [31:28] wire    [ 3:0]  c3d_min_dvfs_idx  = c3d_dvfs_cfg[31:28];
	}reg;
}Reg_C3D_DVFS_CFG;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int Reserved0                :24; // [23:0] 
		unsigned int max_dvfs_idx             :4;  // [27:24] wire    [ 3:0]  s3d0_max_dvfs_idx = s3d0_dvfs_cfg[27:24];
		unsigned int min_dvfs_idx             :4;  //RW [31:28] wire    [ 3:0]  s3d0_min_dvfs_idx = s3d0_dvfs_cfg[31:28];
	}reg;
}Reg_S3D0_DVFS_CFG;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int Reserved0                :24; // [23:0] 
		unsigned int max_dvfs_idx             :4;  // [27:24] wire    [ 3:0]  s3d1_max_dvfs_idx = s3d1_dvfs_cfg[27:24];
		unsigned int min_dvfs_idx             :4;  //RW [31:28] wire    [ 3:0]  s3d1_min_dvfs_idx = s3d1_dvfs_cfg[31:28];
	}reg;
}Reg_S3D1_DVFS_CFG;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int Reserved0                :24; // [23:0] 
		unsigned int max_dvfs_idx             :4;  // [27:24] wire    [ 3:0]  vpp_max_dvfs_idx  = vpp_dvfs_cfg[27:24];
		unsigned int min_dvfs_idx             :4;  //RW [31:28] wire    [ 3:0]  vpp_min_dvfs_idx  = vpp_dvfs_cfg[31:28];
	}reg;
}Reg_VPP_DVFS_CFG;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int min_vol_idx              :6;  //RW [5:0] [5:0] : the min voltage index of c3d/s3d0/s3d1/vpp;
		unsigned int Reserved1                :2;  //RW [7:6] [7:6] : reserved;
		unsigned int max_vol_idx              :6;  //RW [13:8] [13:8] : the max voltage index of c3d/s3d0/s3d1/vpp;
		unsigned int Reserved0                :18; //RW [31:14] [31:14] : reserved;
	}reg;
}Reg_VOL_CLAMP;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int GPU2SB_SVID_VALUE_real   :8;  //R [7:0]
		unsigned int cur_dvfs_idx             :4;  //R [11:8]
		unsigned int volt_ctrl_value          :8;  //R [19:12]
		unsigned int volt_ctrl_slew           :2;  //R [21:20]
		unsigned int Reserved1                :2;  //R [23:22]
		unsigned int volt_ctrl_ps             :2;  //R [25:24]
		unsigned int Reserved0                :2;  //R [27:26]
		unsigned int dvfs_reg_idx             :4;  //RW [31:28]
	}reg;
}Reg_C3D_DVFS_REG_CTRL;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int s3d0_cur_volt_idx        :6;  //R [5:0]
		unsigned int Reserved2                :3;  //R [7:5]
		unsigned int cur_dvfs_idx             :4;  //R [11:8]
		unsigned int volt_ctrl_value          :8;  //R [19:12]
		unsigned int volt_ctrl_slew           :2;  //R [21:20]
		unsigned int Reserved1                :2;  //R [23:22]
		unsigned int volt_ctrl_ps             :2;  //R [25:24]
		unsigned int Reserved0                :2;  //R [27:26]
		unsigned int dvfs_reg_idx             :4;  //RW [31:28]
	}reg;
}Reg_S3D0_DVFS_REG_CTRL;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int s3d1_cur_volt_idx        :6;  //R [5:0]
		unsigned int Reserved2                :2;  //R [7:6]
		unsigned int cur_dvfs_idx             :4;  //R [11:8]
		unsigned int volt_ctrl_value          :8;  //R [19:12]
		unsigned int volt_ctrl_slew           :2;  //R [21:20]
		unsigned int Reserved1                :2;  //R [23:22]
		unsigned int volt_ctrl_ps             :2;  //R [25:24]
		unsigned int Reserved0                :2;  //R [27:26]
		unsigned int dvfs_reg_idx             :4;  //RW [31:28]
	}reg;
}Reg_S3D1_DVFS_REG_CTRL;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int vpp_cur_volt_idx         :6;  //R [5:0]
		unsigned int Reserved2                :3;  //R [7:5]
		unsigned int cur_dvfs_idx             :4;  //R [11:8]
		unsigned int volt_ctrl_value          :8;  //R [19:12]
		unsigned int volt_ctrl_slew           :2;  //R [21:20]
		unsigned int Reserved1                :2;  //R [23:22]
		unsigned int volt_ctrl_ps             :2;  //R [25:24]
		unsigned int Reserved0                :2;  //R [27:26]
		unsigned int dvfs_reg_idx             :4;  //RW [31:28]
	}reg;
}Reg_VPP_DVFS_REG_CTRL;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int c3d_auto_req_cnt_en      :1;  // [0] 
		unsigned int s3d0_auto_req_cnt_en     :1;  // [1] 
		unsigned int s3d1_auto_req_cnt_en     :1;  // [2] 
		unsigned int vpp_auto_req_cnt_en      :1;  //W [3] wire c3d_auto_req_cnt_en   = AUTO_REQ_CNT_EN[0];
                                                   //wire s3d0_auto_req_cnt_en  = AUTO_REQ_CNT_EN[1];
                                                   //wire s3d1_auto_req_cnt_en  = AUTO_REQ_CNT_EN[2];
                                                   //wire  vpp_auto_req_cnt_en = AUTO_REQ_CNT_EN[3];
                                                   //
		unsigned int Reserved1                :28; //[31:4]
	}reg;
}Reg_AUTO_REQ_CNT_EN;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int c3d_auto_req_cnt_en      :1;  // [0] 
		unsigned int s3d0_auto_req_cnt_en     :1;  // [1] 
		unsigned int s3d1_auto_req_cnt_en     :1;  // [2] 
		unsigned int vpp_auto_req_cnt_en      :1;  //W [3] wire c3d_auto_req_cnt_en   = AUTO_REQ_CNT_EN[0];
                                                   //wire s3d0_auto_req_cnt_en  = AUTO_REQ_CNT_EN[1];
                                                   //wire s3d1_auto_req_cnt_en  = AUTO_REQ_CNT_EN[2];
                                                   //wire  vpp_auto_req_cnt_en = AUTO_REQ_CNT_EN[3];
                                                   //
		unsigned int Reserved1                :28; //[31:4]
	}reg;
}Reg_AUTO_REQ_CNT_CLR;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int c3d_auto_req_cnt_max     :16; //W [15:0] DVFS_AUTO boost/reduce req counter for IRQ
		unsigned int Reserved1                :16; //[31:16]
	}reg;
}Reg_C3D_AUTO_REQ_CNT_MAX;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int s3d0_auto_req_cnt_max    :16; //W [15:0] DVFS_AUTO boost/reduce req counter for IRQ
		unsigned int Reserved1                :16; //[31:16]
	}reg;
}Reg_S3D0_AUTO_REQ_CNT_MAX;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int s3d1_auto_req_cnt_max    :16; //W [15:0] DVFS_AUTO boost/reduce req counter for IRQ
		unsigned int Reserved1                :16; //[31:16]
	}reg;
}Reg_S3D1_AUTO_REQ_CNT_MAX;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int vpp_auto_req_cnt_max     :16; //W [15:0] DVFS_AUTO boost/reduce req counter for IRQ
		unsigned int Reserved1                :16; //[31:16]
	}reg;
}Reg_VPP_AUTO_REQ_CNT_MAX;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int VOLT_SCALE_DLY           :32; //RW [31:0] delay for voltage vfs_op_ack
	}reg;
}Reg_VOLT_SCALE_DLY;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int dvfs_auto_ext_wen_req    :1;  //W [0] adjust to the new clamp idx directly, when cur_dix is out of new range.
		unsigned int Reserved1                :31; //[31:1]
	}reg;
}Reg_C3D_DVFS_AUTO_EXT_SET;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int dvfs_auto_ext_wen_req    :1;  //W [0] adjust to the new clamp idx directly, when cur_dix is out of new range.
		unsigned int Reserved1                :31; //[31:1]
	}reg;
}Reg_S3D0_DVFS_AUTO_EXT_SET;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int dvfs_auto_ext_wen_req    :1;  //W [0] adjust to the new clamp idx directly, when cur_dix is out of new range.
		unsigned int Reserved1                :31; //[31:1]
	}reg;
}Reg_S3D1_DVFS_AUTO_EXT_SET;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int dvfs_auto_ext_wen_req    :1;  //W [0] adjust to the new clamp idx directly, when cur_dix is out of new range.
		unsigned int Reserved1                :31; //[31:1]
	}reg;
}Reg_VPP_DVFS_AUTO_EXT_SET;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int dvfs_cmd_in              :32; //W [31:0] write DVFS CMD data
	}reg;
}Reg_C3D_DVFS_CMD_FIFO;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int dvfs_cmd_in              :32; //W [31:0] write DVFS CMD data
	}reg;
}Reg_S3D0_DVFS_CMD_FIFO;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int dvfs_cmd_in              :32; //W [31:0] 
	}reg;
}Reg_S3D1_DVFS_CMD_FIFO;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int dvfs_cmd_in              :32; //W [31:0] 
	}reg;
}Reg_VPP_DVFS_CMD_FIFO;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int avs_cmd_in               :32; //W [31:0] 
	}reg;
}Reg_C3D_AVS_CMD_FIFO;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int avs_cmd_in               :32; //W [31:0] 
	}reg;
}Reg_S3D0_AVS_CMD_FIFO;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int avs_cmd_in               :32; //W [31:0] 
	}reg;
}Reg_S3D1_AVS_CMD_FIFO;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int avs_cmd_in               :32; //W [31:0] 
	}reg;
}Reg_VPP_AVS_CMD_FIFO;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int c3d_dvfs_en              :1;  //RW [0] 
		unsigned int Reserved0                :31; //R [31:1] Reserved
	}reg;
}Reg_C3D_DVFS_EN;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int s3d0_dvfs_en             :1;  //RW [0] 
		unsigned int Reserved0                :31; //R [31:1] Reserved
	}reg;
}Reg_S3D0_DVFS_EN;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int s3d1_dvfs_en             :1;  //RW [0] 
		unsigned int Reserved0                :31; //R [31:1] Reserved
	}reg;
}Reg_S3D1_DVFS_EN;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int vpp_dvfs_en              :1;  //RW [0] 
		unsigned int Reserved0                :31; //R [31:1] Reserved
	}reg;
}Reg_VPP_DVFS_EN;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int vpp_dvfs_reg_tsk_busy    :1;  //R [0]
		unsigned int s3d1_dvfs_tsk_busy       :1;  //R [1]
		unsigned int s3d0_dvfs_tsk_busy       :1;  //R [2]
		unsigned int c3d_dvfs_tsk_busy        :1;  //R [3]
		unsigned int vpp_dvfs_cmd_tsk_busy    :1;  //R [4]
		unsigned int s3d1_dvfs_cmd_tsk_busy   :1;  //R [5]
		unsigned int s3d0_dvfs_cmd_tsk_busy   :1;  //R [6]
		unsigned int c3d_dvfs_cmd_tsk_busy    :1;  //R [7]
		unsigned int vpp_avs_tsk_busy         :1;  //R [8]
		unsigned int s3d1_avs_tsk_busy        :1;  //R [9]
		unsigned int s3d0_avs_tsk_busy        :1;  //R [10]
		unsigned int c3d_avs_tsk_busy         :1;  //R [11]
		unsigned int vpp_avs_cmd_tsk_busy     :1;  //R [12]
		unsigned int s3d1_avs_cmd_tsk_busy    :1;  //R [13]
		unsigned int s3d0_avs_cmd_tsk_busy    :1;  //R [14]
		unsigned int c3d_avs_cmd_tsk_busy     :1;  //R [15]
		unsigned int Reserved                 :16; //R [31:16]
	}reg;
}Reg_TSK_BUSY_STATUS;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int c3d_avs_en               :1;  //W [0] 
		unsigned int Reserved1                :31; //[31:1]
	}reg;
}Reg_C3D_AVS_EN;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int s3d0_avs_en              :1;  //W [0] 
		unsigned int Reserved1                :31; //[31:1]
	}reg;
}Reg_S3D0_AVS_EN;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int s3d1_avs_en              :1;  //W [0] 
		unsigned int Reserved1                :31; //[31:1]
	}reg;
}Reg_S3D1_AVS_EN;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int vpp_avs_en               :1;  //W [0] 
		unsigned int Reserved1                :31; //[31:1]
	}reg;
}Reg_VPP_AVS_EN;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int pmu_sw_fullchip_reset_reg:1;  //RW [0] set pmu_sw_chip_reset_flag
		unsigned int Reserved0                :31; //R [31:1] Reserved
	}reg;
}Reg_PMU_SW_FULLCHIP_RESET_ADDR;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int pmu_sw_fullchip_reset_flag_clr:1;  //RW [0] clear pmu_sw_chip_reset_flag
		unsigned int Reserved0                :31; //R [31:1] Reserved
	}reg;
}Reg_PMU_SW_FULLCHIP_FLAG_ADDR;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int GFX_TOP_RESETB           :1;  //RW [0]
		unsigned int VPP_RESETB_tmp           :1;  //RW [1]
		unsigned int S3VD1_RESETB_tmp         :1;  //RW [2]
		unsigned int S3VD0_RESETB_tmp         :1;  //RW [3]
		unsigned int PEB1_RESETB_tmp          :1;  //RW [4]
		unsigned int PEA1_RESETB_tmp          :1;  //RW [5]
		unsigned int TU1_RESETB_tmp           :1;  //RW [6]
		unsigned int FFU1_RESETB_tmp          :1;  //RW [7]
		unsigned int EUC1_RESETB_tmp          :1;  //RW [8]
		unsigned int PEB0_RESETB_tmp          :1;  //RW [9]
		unsigned int PEA0_RESETB_tmp          :1;  //RW [10]
		unsigned int TU0_RESETB_tmp           :1;  //RW [11]
		unsigned int FFU0_RESETB_tmp          :1;  //RW [12]
		unsigned int EUC0_RESETB_tmp          :1;  //RW [13]
		unsigned int SPTFE_RESETB_tmp         :1;  //RW [14]
		unsigned int SGTBE_RESETB_tmp         :1;  //RW [15]
		unsigned int POOL_RESETB_tmp          :1;  //RW [16]
		unsigned int L2_RESETB_tmp            :1;  //RW [17]
		unsigned int CSP_MXU0_RESETB          :1;  //RW [18]
		unsigned int MXU1_RESETB              :1;  //RW [19]
		unsigned int DIU_RESETB               :1;  //RW [20]
		unsigned int BIU_RESETB               :1;  //RW [21]
		unsigned int PMP_RESETB               :1;  //RW [22]
		unsigned int HOT_WIRE_RESETB_tmp      :1;  //RW [23]
		unsigned int IGA3_RSTB_tmp            :1;  //RW [24]
		unsigned int IGA2_RSTB_tmp            :1;  //RW [25]
		unsigned int IGA1_RSTB_tmp            :1;  //RW [26]
		unsigned int REG_RSTB_tmp             :1;  //RW [27]
		unsigned int Reserved                 :4;  //R [31:28]
	}reg;
}Reg_PMU_PART_SW_RESET_ADDR;

 
typedef union{
    unsigned int uint;
    struct
    {
      unsigned int VPP1_RESETB_tmp               :1;   //RW [0]
      unsigned int UART_RESETn           :1;   //RW [1]
      unsigned int Reserved0          :30;   // [31:2]
   }reg;
}Reg_PMU_PART_SW_RESET_ADDR1     ;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int Reserved1                :32; //[31:0]
	}reg;
}Reg_PMU_PWRUP_DLY_CNT;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int select_hw_sw_seq_reg     :1;  //RW [0] 
		unsigned int Reserved0                :31; //R [31:1] Reserved
	}reg;
}Reg_PMU_SELECT_HW_SW_SEQ_ADDR;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int sw_iso_en_reg            :1;  //RW [0] 
		unsigned int Reserved0                :31; //R [31:1] Reserved
	}reg;
}Reg_PMU_SW_ISO_EN_ADDR;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int sw_refclk_en_reg         :1;  //RW [0] 
		unsigned int Reserved0                :31; //R [31:1] Reserved
	}reg;
}Reg_PMU_SW_REFCLK_EN_ADDR;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int sw_pwren_soc_reg         :1;  //RW [0] 
		unsigned int Reserved0                :31; //R [31:1] Reserved
	}reg;
}Reg_PMU_SW_PWREN_SOC_ADDR;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int sw_pmu_pwr_on_req_reg    :1;  //RW [0] 
		unsigned int Reserved0                :31; //R [31:1] Reserved
	}reg;
}Reg_PMU_SW_PMU_PWR_ON_REQ_ADDR;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int sw_pmu_pwr_off_req_reg   :1;  //RW [0] 
		unsigned int Reserved0                :31; //R [31:1] Reserved
	}reg;
}Reg_PMU_SW_PMU_PWR_OFF_REQ_ADDR;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int SW_RST_AUTO_RLS   :1;  //W [0] 
		unsigned int Reserved0                :31; //R [31:1] Reserved
	}reg;
}Reg_PMU_SW_RST_AUTO_RLS;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int PMU_PART_SW_RST_rls   :1;  //W [0] 
		unsigned int Reserved0                :31; //R [31:1] Reserved
	}reg;
}Reg_PMU_PART_SW_RESET_RLS_ADDR;

typedef union{
    unsigned int uint;
    struct
    {
        //unsigned int PMU_PART_SW_RST_rls   :1;  //W [0] 
		unsigned int Reserved0                :32; //R [31:1] Reserved
	}reg;
}Reg_PMU_PART_SW_RESET_RLS_ADDR1;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int PCU_GRNT                 :1;  //R [0] 
		unsigned int Reserved0                :31; //R [31:1] Reserved
	}reg;
}Reg_PMP_PCU_GRNT;

typedef union{
    unsigned int uint;
    struct
    {
      unsigned int GPU_PERF_REQ          :24;   //RW [23:0]the power bugget GFX requested
      unsigned int Reserved0          :8;   //R [31:24]Reserved
   }reg;
}Reg_PMP_GPU_PERF_REQ;
/*
typedef union{
    unsigned int uint;
    struct
    {
		unsigned int GPU_PERF_REQ             :30; //RW [29:0] the power bugget GFX requested
		unsigned int Reserved0                :2;  //R [31:30] Reserved
	}reg;
}Reg_PMP_GPU_PERF_REQ;
*/

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int pmu_pcu_async_delay_cnt  :5;  //RW [4:0] 
		unsigned int Reserved0                :27; //R [31:5] Reserved
	}reg;
}Reg_PMU_PCU_ASYNC_DELAY_CNT;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int pmu_csp_async_delay_cnt  :5;  //RW [4:0] 
		unsigned int Reserved0                :27; //R [31:5] Reserved
	}reg;
}Reg_PMU_CSP_ASYNC_DELAY_CNT;

typedef union{
    unsigned int uint;
    struct
    {
      unsigned int GPU_TEMP          :20;   //R [19:0]gpu temperature
      unsigned int GPU_TEMP_IRQ_reg          :6;   //R [25:20]the gpu temperature interrupt, if GPU_TEMP_IRQ_reg[5] = 1, pmu send this interrupt to pcu with the temperature information
      unsigned int Reserved0          :6;   //R [31:26]Reserved
 
   }reg;
}Reg_CSP_PMU_TS_STATUS;
/*
typedef union{
    unsigned int uint;
    struct
    {
		unsigned int GPU_TEMP_IRQ_reg         :5;  //R [4:0] 
		unsigned int GPU_TEMP                 :11; //R [15:5] 
		unsigned int Reserved0                :16; //R [31:16] Reserved
	}reg;
}Reg_CSP_PMU_TS_STATUS;
*/
typedef union{
    unsigned int uint;
    struct
    {
		unsigned int GPU_TEMP_IRQ             :6;  //RW [5:0]
		unsigned int pcu_grnt_wen             :1;  //RW [6]
		unsigned int pcu_max_dvfs_clamp_wen   :1;  //RW [7]
		unsigned int vpp_perf_reduce          :1;  //RW [8]
		unsigned int vpp_perf_boost           :1;  //RW [9]
		unsigned int s3d1_perf_reduce         :1;  //RW [10]
		unsigned int s3d1_perf_boost          :1;  //RW [11]
		unsigned int s3d0_perf_reduce         :1;  //RW [12]
		unsigned int s3d0_perf_boost          :1;  //RW [13]
		unsigned int c3d_perf_reduce          :1;  //RW [14]
		unsigned int c3d_perf_boost           :1;  //RW [15]
		unsigned int VPP_DVFS_REG_INT         :1;  //RW [16]
		unsigned int S3D1_DVFS_REG_INT        :1;  //RW [17]
		unsigned int S3D0_DVFS_REG_INT        :1;  //RW [18]
		unsigned int C3D_DVFS_REG_INT         :1;  //RW [19]
		unsigned int vpp_dvfs_cmd_pmp_int     :1;  //RW [20]
		unsigned int s3d1_dvfs_cmd_pmp_int    :1;  //RW [21]
		unsigned int s3d0_dvfs_cmd_pmp_int    :1;  //RW [22]
		unsigned int c3d_dvfs_cmd_pmp_int     :1;  //RW [23]
		unsigned int vpp_avs_cmd_pmp_int      :1;  //RW [24]
		unsigned int s3d1_avs_cmd_pmp_int     :1;  //RW [25]
		unsigned int s3d0_avs_cmd_pmp_int     :1;  //RW [26]
		unsigned int c3d_avs_cmd_pmp_int      :1;  //RW [27]
		unsigned int vr_hot_int               :1;  //RW [28]
		unsigned int Reserved                 :3;  //RW [31:29]
	}reg;
}Reg_PMP_IRQ_EN_CTRL;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int cpu_irq_en_ctrl          :32; //RW [31:0] 
	}reg;
}Reg_CPU_IRQ_EN_CTRL;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int pcu_irq_en_ctrl          :32; //RW [31:0] 
	}reg;
}Reg_PCU_IRQ_EN_CTRL;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int GPU_TEMP_IRQ             :6;  //RW [5:0]
		unsigned int pcu_grnt_wen             :1;  //RW [6]
		unsigned int pcu_max_dvfs_clamp_wen   :1;  //RW [7]
		unsigned int vpp_perf_reduce          :1;  //RW [8]
		unsigned int vpp_perf_boost           :1;  //RW [9]
		unsigned int s3d1_perf_reduce         :1;  //RW [10]
		unsigned int s3d1_perf_boost          :1;  //RW [11]
		unsigned int s3d0_perf_reduce         :1;  //RW [12]
		unsigned int s3d0_perf_boost          :1;  //RW [13]
		unsigned int c3d_perf_reduce          :1;  //RW [14]
		unsigned int c3d_perf_boost           :1;  //RW [15]
		unsigned int VPP_DVFS_REG_INT         :1;  //RW [16]
		unsigned int S3D1_DVFS_REG_INT        :1;  //RW [17]
		unsigned int S3D0_DVFS_REG_INT        :1;  //RW [18]
		unsigned int C3D_DVFS_REG_INT         :1;  //RW [19]
		unsigned int vpp_dvfs_cmd_pmp_int     :1;  //RW [20]
		unsigned int s3d1_dvfs_cmd_pmp_int    :1;  //RW [21]
		unsigned int s3d0_dvfs_cmd_pmp_int    :1;  //RW [22]
		unsigned int c3d_dvfs_cmd_pmp_int     :1;  //RW [23]
		unsigned int vpp_avs_cmd_pmp_int      :1;  //RW [24]
		unsigned int s3d1_avs_cmd_pmp_int     :1;  //RW [25]
		unsigned int s3d0_avs_cmd_pmp_int     :1;  //RW [26]
		unsigned int c3d_avs_cmd_pmp_int      :1;  //RW [27]
		unsigned int vr_hot_int               :1;  //RW [28]
		unsigned int Reserved                 :3;  //RW [31:29]
	}reg;
}Reg_PMP_IRQ_MASK_CTRL;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int cpu_irq_mask_ctrl        :32; //RW [31:0] 
	}reg;
}Reg_CPU_IRQ_MASK_CTRL;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int pcu_irq_mask_ctrl        :32; //RW [31:0] 
	}reg;
}Reg_PCU_IRQ_MASK_CTRL;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int GPU_TEMP_IRQ             :6;  //W [5:0]
		unsigned int pcu_grnt_wen             :1;  //W [6]
		unsigned int pcu_max_dvfs_clamp_wen   :1;  //W [7]
		unsigned int vpp_perf_reduce          :1;  //W [8]
		unsigned int vpp_perf_boost           :1;  //W [9]
		unsigned int s3d1_perf_reduce         :1;  //W [10]
		unsigned int s3d1_perf_boost          :1;  //W [11]
		unsigned int s3d0_perf_reduce         :1;  //W [12]
		unsigned int s3d0_perf_boost          :1;  //W [13]
		unsigned int c3d_perf_reduce          :1;  //W [14]
		unsigned int c3d_perf_boost           :1;  //W [15]
		unsigned int VPP_DVFS_REG_INT         :1;  //W [16]
		unsigned int S3D1_DVFS_REG_INT        :1;  //W [17]
		unsigned int S3D0_DVFS_REG_INT        :1;  //W [18]
		unsigned int C3D_DVFS_REG_INT         :1;  //W [19]
		unsigned int vpp_dvfs_cmd_pmp_int     :1;  //W [20]
		unsigned int s3d1_dvfs_cmd_pmp_int    :1;  //W [21]
		unsigned int s3d0_dvfs_cmd_pmp_int    :1;  //W [22]
		unsigned int c3d_dvfs_cmd_pmp_int     :1;  //W [23]
		unsigned int vpp_avs_cmd_pmp_int      :1;  //W [24]
		unsigned int s3d1_avs_cmd_pmp_int     :1;  //W [25]
		unsigned int s3d0_avs_cmd_pmp_int     :1;  //W [26]
		unsigned int c3d_avs_cmd_pmp_int      :1;  //W [27]
		unsigned int vr_hot_int               :1;  //W [28]
		unsigned int Reserved                 :3;  //W [31:29]
	}reg;
}Reg_PMP_IRQ_CLR_CTRL;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int cpu_irq_clr_ctrl         :32; //W [31:0] 
	}reg;
}Reg_CPU_IRQ_CLR_CTRL;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int pcu_irq_clr_ctrl         :32; //W [31:0] 
	}reg;
}Reg_PCU_IRQ_CLR_CTRL;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int GPU_TEMP_IRQ             :6;  //R [5:0]
		unsigned int pcu_grnt_wen             :1;  //R [6]
		unsigned int pcu_max_dvfs_clamp_wen   :1;  //R [7]
		unsigned int vpp_perf_reduce          :1;  //R [8]
		unsigned int vpp_perf_boost           :1;  //R [9]
		unsigned int s3d1_perf_reduce         :1;  //R [10]
		unsigned int s3d1_perf_boost          :1;  //R [11]
		unsigned int s3d0_perf_reduce         :1;  //R [12]
		unsigned int s3d0_perf_boost          :1;  //R [13]
		unsigned int c3d_perf_reduce          :1;  //R [14]
		unsigned int c3d_perf_boost           :1;  //R [15]
		unsigned int VPP_DVFS_REG_INT         :1;  //R [16]
		unsigned int S3D1_DVFS_REG_INT        :1;  //R [17]
		unsigned int S3D0_DVFS_REG_INT        :1;  //R [18]
		unsigned int C3D_DVFS_REG_INT         :1;  //R [19]
		unsigned int vpp_dvfs_cmd_pmp_int     :1;  //R [20]
		unsigned int s3d1_dvfs_cmd_pmp_int    :1;  //R [21]
		unsigned int s3d0_dvfs_cmd_pmp_int    :1;  //R [22]
		unsigned int c3d_dvfs_cmd_pmp_int     :1;  //R [23]
		unsigned int vpp_avs_cmd_pmp_int      :1;  //R [24]
		unsigned int s3d1_avs_cmd_pmp_int     :1;  //R [25]
		unsigned int s3d0_avs_cmd_pmp_int     :1;  //R [26]
		unsigned int c3d_avs_cmd_pmp_int      :1;  //R [27]
		unsigned int vr_hot_int               :1;  //R [28]
		//unsigned int Reserved                 :3;  //R [31:29]
		unsigned int sb2gpu_timeout_int          :1;   //R [29]
        unsigned int sb2gpu_rsd_fail_int          :1;   //R [30]
        unsigned int GFX_NB_CLEAR_DATA_INT          :1;   //R [31]
	}reg;
}Reg_PMP_INTERRUPT_STATUS;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int GPU_TEMP_IRQ             :6;  //R [5:0]
		unsigned int pcu_grnt_wen             :1;  //R [6]
		unsigned int pcu_max_dvfs_clamp_wen   :1;  //R [7]
		unsigned int vpp_perf_reduce          :1;  //R [8]
		unsigned int vpp_perf_boost           :1;  //R [9]
		unsigned int s3d1_perf_reduce         :1;  //R [10]
		unsigned int s3d1_perf_boost          :1;  //R [11]
		unsigned int s3d0_perf_reduce         :1;  //R [12]
		unsigned int s3d0_perf_boost          :1;  //R [13]
		unsigned int c3d_perf_reduce          :1;  //R [14]
		unsigned int c3d_perf_boost           :1;  //R [15]
		unsigned int VPP_DVFS_REG_INT         :1;  //R [16]
		unsigned int S3D1_DVFS_REG_INT        :1;  //R [17]
		unsigned int S3D0_DVFS_REG_INT        :1;  //R [18]
		unsigned int C3D_DVFS_REG_INT         :1;  //R [19]
		unsigned int vpp_dvfs_cmd_cpu_int     :1;  //R [20]
		unsigned int s3d1_dvfs_cmd_cpu_int    :1;  //R [21]
		unsigned int s3d0_dvfs_cmd_cpu_int    :1;  //R [22]
		unsigned int c3d_dvfs_cmd_cpu_int     :1;  //R [23]
		unsigned int vpp_avs_cmd_cpu_int      :1;  //R [24]
		unsigned int s3d1_avs_cmd_cpu_int     :1;  //R [25]
		unsigned int s3d0_avs_cmd_cpu_int     :1;  //R [26]
		unsigned int c3d_avs_cmd_cpu_int      :1;  //R [27]
		unsigned int vr_hot_int              :1;  //R [28]
		//unsigned int Reserved                 :3;  //R [31:29]
		unsigned int sb2gpu_timeout_int          :1;   //R [29]
        unsigned int sb2gpu_rsd_fail_int          :1;   //R [30]
        unsigned int GFX_NB_CLEAR_DATA_INT          :1;   //R [31]
	}reg;
}Reg_CPU_INTERRUPT_STATUS;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int GPU_TEMP_IRQ_5           :1;  //R [0]
		unsigned int pcu_irq_pref_boost       :1;  //R [1]
		unsigned int pcu_irq_pref_reduce      :1;  //R [2]
		unsigned int Reserved                 :29; //R [31:3]
	}reg;
}Reg_PCU_INTERRUPT_STATUS;

typedef union{
    unsigned int uint;
    struct
    {
		//unsigned int Reserved0                :1;  // [0] 
		unsigned int pcu_irq_pref_boost       :1;  //W [1] PMP wirte 1 to trigger PCU_PREF_BOOST IRQ
		unsigned int Reserved2                :31; //[31:2]
	}reg;
}Reg_PCU_IRQ_PREF_BOOST;

typedef union{
    unsigned int uint;
    struct
    {
		//unsigned int Reserved0                :2;  // [1:0] 
		unsigned int pcu_irq_pref_reduce      :1;  //W [2] PMP wirte 1 to trigger PCU_PREF_REDUCE IRQ
		unsigned int Reserved2                :31; //[31:1]
	}reg;
}Reg_PCU_IRQ_PREF_REDUCE;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int MAX_DVFS_CLAMP           :30; //R [29:0] the bugget PCU allocated
		unsigned int Reserved1                :2;  //[31:30]
	}reg;
}Reg_PCU_MAX_DVFS_CLAMP_VALUE;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int select_value_reg         :1;  //RW [0] 
		unsigned int Reserved0                :31; //R [31:1] Reserved
	}reg;
}Reg_PMU_VOL_ARB_SEL_VALUE_ADDR;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int sb2gpu_timeout_enable    :1;  //RW [0] timeout counter enable for sb2gpu
                                                   //1 = enable 0 = disable
		unsigned int Reserved0                :31; //R [31:1] Reserved
	}reg;
}Reg_PMU_VOL_ARB_TIMEOUT_ENABLE;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int sb2gpu_timeout_clr       :1;  //RW [0] clear timeout counter to 0
		unsigned int Reserved0                :31; //R [31:1] Reserved
	}reg;
}Reg_PMU_VOL_ARB_TIMEOUT_CLR;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int PMU_PMP_LS_B_reg         :1;  //RW [0] 
		unsigned int Reserved0                :31; //R [31:1] Reserved
	}reg;
}Reg_PMU_PMP_LS_ADDR;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int ht_slave_address         :3;  //RW [2:0] hotwire salve address
		unsigned int Reserved0                :1;  //R [3] Reserved
		unsigned int ht_en                    :1;  //RW [4] hotwire slave enable 
                                                   //1=enable  0=disable
		unsigned int Reserved2                :27; //[31:5]
	}reg;
}Reg_PMU_HT_CFG;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int PMU_S3VD1_CLKEN          :32; //O [31:0] 
	}reg;
}Reg_PMU_S3VD1_CLKEN;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int GFX_NB_CLEAR_DONE_reg    :1;  //RW [0] 
		unsigned int Reserved1                :31; //[31:1]
	}reg;
}Reg_GFX_NB_CLEAR_DONE_ADDR;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int MXU_ADB_CLK_EN           :1;  //RW [0] 
		unsigned int Reserved1                :31; //[31:1]
	}reg;
}Reg_MXU_ADB_CLK_EN;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int pmu_ts_async_delay_cnt   :5;  //RW [4:0] use this delay to sync tempsensor value
		unsigned int Reserved1                :27; //[31:5]
	}reg;
}Reg_PMU_TS_ASYNC_DELAY_CNT;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int source_clk_test_div      :2;  //RW [1:0] 
		unsigned int Reserved2                :2;  // [3:2] 
		unsigned int source_clk_test_sel      :2;  //RW [5:4] 
		unsigned int Reserved1                :2;  // [7:6] 
		unsigned int  source_clk_test_en      :1;  //RW [8] 1:enable 0:disable
		unsigned int Reserved0                :3;  //RW [11:9] 
		unsigned int Reserved4                :20; //[31:12]
	}reg;
}Reg_SOURCE_CLK_TEST_CFG;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int POUT_IOUT_FLAG_reg      :1;  //RW [1:0] 
		unsigned int Reserved0                :31;  // [3:2] 
	}reg;
}Reg_POUT_IOUT_FLAG;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int PCU_ACTIVE_INT_reg      :1;  //RW [1:0] 
		unsigned int Reserved0                :31;  // [3:2] 
	}reg;
}Reg_PCU_ACTIVE_INT;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int CSP_TEMP_IRQ_CLR_CTRL_reg                :5;  // [5:0] 
		//unsigned int CSP_TEMP_IRQ_CLR_CTRL_reg      :1;  //RW [6] 
		unsigned int Reserved1                :26;  // [31:6] 
	}reg;
}Reg_CSP_TEMP_IRQ_CLR_CTRL;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int PCU_ACTIVE_INT_CLR_ARISE      :1;  //RW [1:0] 
		unsigned int PCU_ACTIVE_INT_CLR_FALL      :1;  //RW [1:0]
		unsigned int Reserved0                :30;  // [3:2] 
	}reg;
}Reg_PCU_ACTIVE_INT_CLR;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int PMU_SRAM_LS_PIN      :1;  //RW [1:0] 
		unsigned int PMU_SRAM_DS_PIN      :1;  //RW [1:0]
		unsigned int PMU_SRAM_RM3_PIN      :1;  //RW [1:0]
		unsigned int Reserved0                :30;  // [3:2] 
	}reg;
}Reg_PMU_LS_DS_RM3_ADDR;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int PMP_SRAM_LS_PIN      :1;  //RW [1:0] 
		unsigned int PMP_SRAM_DS_PIN      :1;  //RW [1:0]
		unsigned int PMP_SRAM_RM3_PIN      :1;  //RW [1:0]
		unsigned int Reserved0                :30;  // [3:2] 
	}reg;
}Reg_PMP_LS_DS_RM3_ADDR;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int BIU_SRAM_LS_PIN      :1;  //RW [1:0] 
		unsigned int BIU_SRAM_DS_PIN      :1;  //RW [1:0]
		unsigned int BIU_SRAM_RM3_PIN      :1;  //RW [1:0]
		unsigned int Reserved0                :30;  // [3:2] 
	}reg;
}Reg_BIU_LS_DS_RM3_ADDR;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int DIU_SRAM_LS_PIN      :1;  //RW [1:0] 
		unsigned int DIU_SRAM_DS_PIN      :1;  //RW [1:0]
		unsigned int Reserved0                :30;  // [3:2] 
	}reg;
}Reg_DIU_LS_DS_RM3_ADDR;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int SW_ISO_ON_OFF_DLY_REG      :4;  //RW [1:0]
		unsigned int Reserved0                :28;  // [3:2] 
	}reg;
}Reg_SW_ISO_ON_OFF_DLY;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int gfx_pwr_status_reg      :1;  //RW [1:0]
		unsigned int Reserved0                :30;  // [3:2] 
	}reg;
}Reg_GFX_PWR_STATUS;

typedef union{
    unsigned int uint;
    struct
    {
		unsigned int SW_GFX_PWR_UP_DN_reg      :1;  //RW [1:0]
		unsigned int Reserved0                :30;  // [3:2] 
	}reg;
}Reg_SW_GFX_PWR_UP_DN;

typedef union {
	unsigned int uint;
	struct
	{
		unsigned int SW_INT2CPU_STS : 1;  //RW [0] //write 1 : generate interrupt,
		unsigned int Reserved1 : 31; //[31:1]
	}reg;
}Reg_SW_INT2CPU_STS;

typedef union {
	unsigned int uint;
	struct
	{
		unsigned int SW_INT2PCU_EN : 1;  //RW [0] //1=enable interrupt;
		unsigned int Reserved1 : 31; //[31:1]
	}reg;
}Reg_SW_INT2CPU_EN;

typedef union {
	unsigned int uint;
	struct
	{
		unsigned int SW_INT2CPU_CLR : 1;  //RW [0] //write 1 to clear SW_INT2PCU_STS;
		unsigned int Reserved1 : 31; //[31:1]
	}reg;
}Reg_SW_INT2CPU_CLR;

/**************************************************************************************************
*************************************Register Group Struct*****************************************
**************************************************************************************************/
typedef struct
{
	Reg_PMU_NB_CLK_CFG_OFST						PMU_NB_CLK_CFG_OFST;                    //4000             
	Reg_PMU_PMP_CLK_CFG_OFST						PMU_PMP_CLK_CFG_OFST;                   //4004             
	//unsigned int										PMU_CSP_MXU0_CLK_CFG_OFST;              //4008 
	Reg_PMU_CCP_UART_CFG_OFST                     PMU_CCP_UART_CFG_OFST;                 //4008
	Reg_PMU_PLL_OK_DLY_CNT_OFST					PMU_PLL_OK_DLY_CNT_OFST;                //400c             
	Reg_PMU_PLL_DLY_CNT_OFST						PMU_PLL_DLY_CNT_OFST;                   //4010             
	Reg_PMU_EPLL_CTRL0_OFST							PMU_EPLL_CTRL0_OFST;                    //4014             
	Reg_PMU_EPLL_CTRL1_OFST							PMU_EPLL_CTRL1_OFST;                    //4018             
	Reg_PMU_VPLL_CTRL0_OFST							PMU_VPLL_CTRL0_OFST;                    //401c             
	Reg_PMU_VPLL_CTRL1_OFST							PMU_VPLL_CTRL1_OFST;                    //4020             
	Reg_PMU_PPLL_CTRL0_OFST							PMU_PPLL_CTRL0_OFST;                    //4024             
	Reg_PMU_PPLL_CTRL1_OFST							PMU_PPLL_CTRL1_OFST;                    //4028             
	Reg_VDP_DFS_VPLL_CFG_OFST						VDP_DFS_VPLL_CFG_OFST;                  //402c             
	Reg_PMU_SOC_PLL_STATUS_OFST                                 PMU_SOC_PLL_STATUS_OFST;                //4030             
	Reg_PMU_DFS_CLK_DLY_CNT_OFST					PMU_DFS_CLK_DLY_CNT_OFST;               //4034             
	Reg_PMU_ECLK_EXT_CLK_CFG_OFST					PMU_ECLK_EXT_CLK_CFG_OFST;              //4038             
	Reg_PMU_S0CLK_EXT_CLK_CFG_OFST					PMU_S0CLK_EXT_CLK_CFG_OFST;             //403c             
	Reg_PMU_S1CLK_EXT_CLK_CFG_OFST					PMU_S1CLK_EXT_CLK_CFG_OFST;             //4040             
	Reg_PMU_VPP_EXT_CLK_CFG_OFST					PMU_VPP_EXT_CLK_CFG_OFST;               //4044             
	Reg_PMU_CLK_EN_OFST							PMU_CLK_EN_OFST;                        //4048             
	Reg_PMU_CLK_EN_CLR_OFST						PMU_CLK_EN_CLR_OFST;                    //404c             
	Reg_PMU_SOC_CLK_SEL_OFST						PMU_SOC_CLK_SEL_OFST;                   //4050             
	Reg_PMU_CSP_MXU0_PLL_EXT_CLK_CFG_OFST			PMU_CSP_MXU0_PLL_EXT_CLK_CFG_OFST;      //4054             
	Reg_PMU_EPLL_CTRL2_OFST							PMU_EPLL_CTRL2_OFST;                    //4058             
	Reg_PMU_VPLL_CTRL2_OFST							PMU_VPLL_CTRL2_OFST;                    //405c             
	Reg_PMU_PPLL_CTRL2_OFST							PMU_PPLL_CTRL2_OFST;                    //4060             
	//unsigned int										PMU_S3VD1_CLKEN;                        //4064             
}Reg_PMU_CLK_MODULE;

typedef struct
{
	unsigned int                                                C3D_PERF_UP_TABLE[2];                   //MMIO8080~8084    
	unsigned int                                                C3D_PERF_DN_TABLE[2];                   //MMIO8088~808c    
	unsigned int                                                S3D0_PERF_UP_TABLE[2];                  //MMIO8090~8094    
	unsigned int                                                S3D0_PERF_DN_TABLE[2];                  //MMIO8098~809c    
	unsigned int                                                S3D1_PERF_UP_TABLE[2];                  //MMIO80a0~80a4    
	unsigned int                                                S3D1_PERF_DN_TABLE[2];                  //MMIO80a8~80ac    
	unsigned int                                                VPP_PERF_UP_TABLE[2];                   //MMIO80b0~80b4    
	unsigned int                                                VPP_PERF_DN_TABLE[2];                   //MMIO80b8~80bc    
}Reg_PMU_DVFS_PERFORMANCE_UP_DOWN_TABLE;

typedef struct
{
	Reg_C3D_DVFS_CFG							C3D_DVFS_CFG;                           //80c0             
	Reg_S3D0_DVFS_CFG							S3D0_DVFS_CFG;                          //80c4             
	Reg_S3D1_DVFS_CFG							S3D1_DVFS_CFG;                          //80c8             
	Reg_VPP_DVFS_CFG							VPP_DVFS_CFG;                           //80cc             
	Reg_VOL_CLAMP								VOL_CLAMP;                              //80d0             
	Reg_C3D_DVFS_REG_CTRL						C3D_DVFS_REG_CTRL;                      //80d4             
	Reg_S3D0_DVFS_REG_CTRL						S3D0_DVFS_REG_CTRL;                     //80d8             
	Reg_S3D1_DVFS_REG_CTRL						S3D1_DVFS_REG_CTRL;                     //80dc             
	Reg_VPP_DVFS_REG_CTRL						VPP_DVFS_REG_CTRL;                      //80e0             
	Reg_AUTO_REQ_CNT_EN						AUTO_REQ_CNT_EN;                        //80e4             
	Reg_AUTO_REQ_CNT_CLR						AUTO_REQ_CNT_CLR;                       //80e8             
	Reg_C3D_AUTO_REQ_CNT_MAX					C3D_AUTO_REQ_CNT_MAX;                   //80ec             
	Reg_S3D0_AUTO_REQ_CNT_MAX					S3D0_AUTO_REQ_CNT_MAX;                  //80f0             
	Reg_S3D1_AUTO_REQ_CNT_MAX					S3D1_AUTO_REQ_CNT_MAX;                  //80f4             
	Reg_VPP_AUTO_REQ_CNT_MAX					VPP_AUTO_REQ_CNT_MAX;                   //80f8             
	Reg_VOLT_SCALE_DLY							VOLT_SCALE_DLY;                         //80fc             
}Reg_PMU_DVFS_REG_CTRL;

typedef struct
{
	Reg_C3D_DVFS_AUTO_EXT_SET						C3D_DVFS_AUTO_EXT_SET;                  //8100             
	Reg_S3D0_DVFS_AUTO_EXT_SET						S3D0_DVFS_AUTO_EXT_SET;                 //8104             
	Reg_S3D1_DVFS_AUTO_EXT_SET						S3D1_DVFS_AUTO_EXT_SET;                 //8108             
	Reg_VPP_DVFS_AUTO_EXT_SET						VPP_DVFS_AUTO_EXT_SET;                  //810c             
	Reg_C3D_DVFS_CMD_FIFO							C3D_DVFS_CMD_FIFO;                      //8110             
}Reg_PMU_DVFS_AUTO_EXTERNAL_TRIGGER;

typedef struct
{
	Reg_S3D0_DVFS_CMD_FIFO						S3D0_DVFS_CMD_FIFO;                     //8114             
	Reg_S3D1_DVFS_CMD_FIFO						S3D1_DVFS_CMD_FIFO;                     //8118             
	Reg_VPP_DVFS_CMD_FIFO						VPP_DVFS_CMD_FIFO;                      //811c             
	Reg_C3D_AVS_CMD_FIFO						C3D_AVS_CMD_FIFO;                       //8120             
	Reg_S3D0_AVS_CMD_FIFO						S3D0_AVS_CMD_FIFO;                      //8124             
	Reg_S3D1_AVS_CMD_FIFO						S3D1_AVS_CMD_FIFO;                      //8128             
	Reg_VPP_AVS_CMD_FIFO						VPP_AVS_CMD_FIFO;                       //812c             
}Reg_PMU_DVFS_and_AVS_CMD_FIFO;

typedef struct
{
	Reg_C3D_DVFS_EN							C3D_DVFS_EN;                            //8900             
	Reg_S3D0_DVFS_EN						S3D0_DVFS_EN;                           //8904             
	Reg_S3D1_DVFS_EN						S3D1_DVFS_EN;                           //8908             
	Reg_VPP_DVFS_EN							VPP_DVFS_EN;                            //890c             
	Reg_C3D_AVS_EN							C3D_AVS_EN;                             //8910             
	Reg_S3D0_AVS_EN							S3D0_AVS_EN;                            //8914             
	Reg_S3D1_AVS_EN							S3D1_AVS_EN;                            //8918             
	Reg_VPP_AVS_EN							VPP_AVS_EN;                             //891c             
}Reg_PMU_DVFS_EN_and_AVS_EN;

typedef struct
{
	//unsigned int									PMU_CFG_REG;                            //8140             
	unsigned int									PMU_VRM_IOUT;                           //8144             
	Reg_TSK_BUSY_STATUS							TSK_BUSY_STATUS;                        //8148             
	unsigned int									VF_TSK_REGISTER;                        //814c             
	unsigned int									Reserved;                        //8150             
	Reg_PMU_VOL_ARB_TIMEOUT_ENABLE			PMU_VOL_ARB_TIMEOUT_ENABLE;             //8154             
	Reg_PMU_VOL_ARB_TIMEOUT_CLR				PMU_VOL_ARB_TIMEOUT_CLR;                //8158             
}Reg_PMU_PMU;

typedef struct
{
	unsigned int                                                C3D_DVFS_TABLE0_15[32];                 //MMIO8400~847c    
	unsigned int                                                S3D0_DVFS_TABLE0_15[32];                //MMIO8480~84fc    
	unsigned int                                                S3D1_DVFS_TABLE0_15[32];                //MMIO8500~857c    
	unsigned int                                                VPP_DVFS_TABLE0_15[32];                 //MMIO8580~85fc    
	unsigned int                                                VOL_MAP_TABLE0_63[128];                 //MMIO8600~87fc    
}Reg_PMU_DVFS_and_VOLTAGE_TABLE;

typedef struct
{
	Reg_PMU_SW_FULLCHIP_RESET_ADDR						PMU_SW_FULLCHIP_RESET_ADDR;             //8800             
	Reg_PMU_SW_FULLCHIP_FLAG_ADDR						PMU_SW_FULLCHIP_FLAG_ADDR;              //8804             
	Reg_PMU_PART_SW_RESET_ADDR						PMU_PART_SW_RESET_ADDR;                 //8808             
	//Reg_PMU_PWRUP_DLY_CNT								PMU_PWRUP_DLY_CNT;                      //880c             
	Reg_PMU_PART_SW_RESET_ADDR1                      PMU_PART_SW_RESET_ADDR1;                //880C
	Reg_PMU_SELECT_HW_SW_SEQ_ADDR					PMU_SELECT_HW_SW_SEQ_ADDR;              //8810             
	Reg_PMU_SW_ISO_EN_ADDR							PMU_SW_ISO_EN_ADDR;                     //8814             
	Reg_PMU_SW_REFCLK_EN_ADDR							PMU_SW_REFCLK_EN_ADDR;                  //8818             
	Reg_PMU_SW_PWREN_SOC_ADDR						PMU_SW_PWREN_SOC_ADDR;                  //881c             
	Reg_PMU_SW_PMU_PWR_ON_REQ_ADDR					PMU_SW_PMU_PWR_ON_REQ_ADDR;             //8820             
	Reg_PMU_SW_PMU_PWR_OFF_REQ_ADDR					PMU_SW_PMU_PWR_OFF_REQ_ADDR;            //8824             
	unsigned int											reserved0;                   //8828   
	Reg_PMU_SW_RST_AUTO_RLS							PMU_SW_RST_AUTO_RLS;                    //882c
	Reg_PMU_PART_SW_RESET_RLS_ADDR					PMU_PART_SW_RESET_RLS_ADDR;                    //8830
	Reg_PMU_PART_SW_RESET_RLS_ADDR1					PMU_PART_SW_RESET_RLS_ADDR1;                    //8834
	
}Reg_PMU_RESET_CTRL_AND_POWER_ON;

typedef struct
{
	Reg_PMP_IRQ_EN_CTRL							PMP_IRQ_EN_CTRL;                        //8854             
	Reg_CPU_IRQ_EN_CTRL							CPU_IRQ_EN_CTRL;                        //8858             
	Reg_PCU_IRQ_EN_CTRL							PCU_IRQ_EN_CTRL;                        //885c             
	Reg_PMP_IRQ_MASK_CTRL						PMP_IRQ_MASK_CTRL;                      //8860             
	Reg_CPU_IRQ_MASK_CTRL						CPU_IRQ_MASK_CTRL;                      //8864             
	Reg_PCU_IRQ_MASK_CTRL						PCU_IRQ_MASK_CTRL;                      //8868             
	Reg_PMP_IRQ_CLR_CTRL						PMP_IRQ_CLR_CTRL;                       //886c             
	Reg_CPU_IRQ_CLR_CTRL						CPU_IRQ_CLR_CTRL;                       //8870             
	Reg_PCU_IRQ_CLR_CTRL						PCU_IRQ_CLR_CTRL;                       //8874             
	Reg_PMP_INTERRUPT_STATUS					PMP_INTERRUPT_STATUS;                   //8878             
	Reg_CPU_INTERRUPT_STATUS					CPU_INTERRUPT_STATUS;                   //887c             
	Reg_PCU_INTERRUPT_STATUS					PCU_INTERRUPT_STATUS;                   //8880             
	Reg_PCU_IRQ_PREF_BOOST						PCU_IRQ_PREF_BOOST;                     //8884             
	Reg_PCU_IRQ_PREF_REDUCE					PCU_IRQ_PREF_REDUCE;                    //8888             
	unsigned int									reserved1[13];                          //MMIO888c~88bc
	Reg_PMP_PCU_GRNT							PMP_PCU_GRNT;                           //88c0             
	Reg_PMP_GPU_PERF_REQ						PMP_GPU_PERF_REQ;                       //88c4             
	Reg_CSP_PMU_TS_STATUS						CSP_PMU_TS_STATUS;                      //88c8             
	Reg_PCU_MAX_DVFS_CLAMP_VALUE				PCU_MAX_DVFS_CLAMP_VALUE;               //88cc             
	Reg_PMU_PCU_ASYNC_DELAY_CNT				PMU_PCU_ASYNC_DELAY_CNT;                //88d0            
	Reg_PMU_CSP_ASYNC_DELAY_CNT				PMU_CSP_ASYNC_DELAY_CNT;                //88d4 
	Reg_PMU_PMP_LS_ADDR						PMU_PMP_LS_ADDR;                        //88d8             
	Reg_PMU_HT_CFG								PMU_HT_CFG;                             //88dc             
	unsigned int									PMU_CSP_DVFS_REAL_ACK_CFG;              //88e0             
	Reg_GFX_NB_CLEAR_DONE_ADDR				GFX_NB_CLEAR_DONE_ADDR;                 //88e4             
	unsigned int									reserved2[14];                          //MMIO88e8~891c    
	Reg_MXU_ADB_CLK_EN							MXU_ADB_CLK_EN;                         //8920             
	Reg_PMU_TS_ASYNC_DELAY_CNT					PMU_TS_ASYNC_DELAY_CNT;                 //8924             
	Reg_SOURCE_CLK_TEST_CFG					SOURCE_CLK_TEST_CFG;                    //8928 
	Reg_POUT_IOUT_FLAG							POUT_IOUT_FLAG;                    //892c
	
	Reg_CSP_TEMP_IRQ_CLR_CTRL                   CSP_TEMP_IRQ_CLR_CTRL;                  //8930
	Reg_PCU_ACTIVE_INT                          PCU_ACTIVE_INT;                         //8934
	Reg_PCU_ACTIVE_INT_CLR                   PCU_ACTIVE_INT_CLR;                       //8938
	unsigned int                              Reserved5;                              //893c
	Reg_SW_INT2CPU_STS                      SW_INT2CPU_STS;                               //8940
	Reg_SW_INT2CPU_EN                       SW_INT2CPU_EN;                               //8944
	Reg_SW_INT2CPU_CLR                     Reg_SW_INT2CPU_CLR;                               //8948
	Reg_PMU_LS_DS_RM3_ADDR                   PMU_LS_DS_RM3_ADDR;                      //894C
	Reg_PMP_LS_DS_RM3_ADDR                   PMP_LS_DS_RM3_ADDR;                      //8950
	Reg_BIU_LS_DS_RM3_ADDR                   BIU_LS_DS_RM3_ADDR;                     //8954
	Reg_DIU_LS_DS_RM3_ADDR                   DIU_LS_DS_RM3_ADDR;                     //8958
}Reg_PMU_INT;

typedef struct{
	Reg_GFX_PWR_STATUS                      GFX_PWR_STATUS;             //9040
	Reg_SW_GFX_PWR_UP_DN                    SW_GFX_PWR_UP_DN;          //9044
	Reg_SW_ISO_ON_OFF_DLY                   SW_ISO_ON_OFF_DLY;          //9048
}Reg_PMP_DFX_PWR;

/**************************************************************************************************
************************************ Base Addr Definition *****************************************
**************************************************************************************************/


#define PMU_BASE									0x60000
#define CLK_MODULE									(PMU_BASE+0x4000)
#define DVFS_PERFORMANCE_UP_DOWN_TABLE			(PMU_BASE+0x8080)
#define DVFS_REG_CTRL								(PMU_BASE+0x80c0)
#define DVFS_AUTO_EXTERNAL_TRIGGER				(PMU_BASE+0x8100)
#define DVFS_and_AVS_CMD_FIFO						(PMU_BASE+0x8114)
#define DVFS_EN_and_AVS_EN							(PMU_BASE+0x8900)
#define PMU											(PMU_BASE+0x8144)
#define DVFS_and_VOLTAGE_TABLE					(PMU_BASE+0x8400)
#define RESET_CTRL_AND_POWER_ON					(PMU_BASE+0x8800)
#define INT											(PMU_BASE+0x8854)
#define DFX_PWR											(PMU_BASE+0x9040)


#endif
