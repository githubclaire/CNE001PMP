#ifndef _PMP_H_
#define _PMP_H_

#ifndef	PMP_BASE
#define PMP_REG_BASE		0x70000
#endif
#define PMP_MIU_DATA_LEN	0x100
#define PMP_SRAM_SIZE   	0xD000 


/* CONFIG */
#define PMP_WFI_REG			0xf000
#define PMP_WFI				0x01

#define PMP_CONFIG			0xf004
#define PMP_WFI_EN			0x04

#define PMP_RESTART			0xf008

/* WDT */
#define PMP_WDT_CBARK		0xf2A0
#define PMP_WDTCBARK_CNT	0x10000

#define PMP_WDT_CBITE		0xf2A4
#define PMP_WDTCBITE_CNT	0x20000

#define PMP_WDMOD			0xf2A8
#define PMP_WDFEED			0xf2AC


#endif
