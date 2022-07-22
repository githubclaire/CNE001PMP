#ifndef _CPU_H_
#define _CPU_H_

#define MODE_USR        0x10
#define MODE_FIQ        0x11
#define MODE_IRQ        0x12
#define MODE_SVC        0x13
#define MODE_ABT        0x17
#define MODE_UND        0x1b
#define MODE_SYS        0x1f

#define I_BIT           0x80
#define F_BIT           0x40

#define UND_STACK_SIZE  0x100
#define SVC_STACK_SIZE  0x800
#define ABT_STACK_SIZE  0x100
#define FIQ_STACK_SIZE  0x100
#define IRQ_STACK_SIZE  0x200
#define USR_STACK_SIZE  0x100
#define SYS_STACK_SIZE  0x100

#define STACK_TOP       (TEXT_BASE + PMP_SRAM_SIZE)
#define STACK_BOTTOM    (STACK_TOP - UND_STACK_SIZE - SVC_STACK_SIZE - ABT_STACK_SIZE - FIQ_STACK_SIZE - IRQ_STACK_SIZE - USR_STACK_SIZE - SYS_STACK_SIZE)

#define PMU_REG_BASE 			0x80000
#define SUS_LPS_ENABLE			0xE180
#define SUS_LPS_STATUS			0xE188
#define SUS_CLK_SEL				0x9114
#define PMU_INTP_STATUS_VSUS	0xc49c
#define INTER_WAKEUP_MASK_EN	0xC6B0
#define INTER_WAKEUP_MASK_CLR	0xC6B4
#define MIU_RDY_STATUS			0xC1C8
#define INTER_WAKEUP_IRQ_STATUS 0xc6b8

#define PMU_x86_PMP_WBUF        0xE000
#define PMU_MBIRQ_GEN			0xE080
#define PMU_MBIRQ_STATUS		0xE084
#define PMU_MESSAGE_CNT 		0xE088
#define PMU_PMP_x86_WBUF        0xE08C

#define MIU_RDY 				0x101

#define VSOC_REG_BASE 			0xd8390000
#define PMU_INTERMODULE_RESET	0xC490

#define MIU0_MEM_CFG					0xd200
#define MIU0_MEM_BASE				0xd000
#define PMU_MAILBOX_RESET	(1 << 2)
#define MAIL_TO_CORE_GEN	(1 << 4)
#define ARM_TO_PMP_MAIL_STAT	(1 << 0)
#define PMP_TO_ARM_MAIL_STAT  (1 << 4)
#endif
