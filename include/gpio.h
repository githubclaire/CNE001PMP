#ifndef _GPIO_H_
#define _GPIO_H_

#define 	GPIO_BASE 	0xa0000

#define 	GPIO_TYPE_BOUNDARY	0x24

#define 	UART0_RXD	0x0
#define 	UART0_TXD	0x4
#define 	JTAG0_TCK	0x8
#define 	JTAG0_TMS	0xc
#define 	JTAG0_TDI	0x10
#define 	JTAG0_TDO	0x14
#define 	EPRM_DI		0x18
#define 	EPRM_DO		0x1c
#define 	EPRM_CS		0x20
#define 	EPRM_CLK	0x24
#define 	I2C0_SDA	0x28
#define 	I2C0_SCL	0x2c
#define 	PWM4		0x30
#define 	VID0		0x34
#define 	VID1		0x38
#define 	VID2		0x3c
#define 	GPIO0		0x40
#define 	GPIO1		0x44
#define 	GPIO2		0x48
#define 	GPIO3		0x4c
#define 	GPIO4		0x50
#define 	GPIO5		0x54
#define 	GPIO21		0x58
#define 	GPIO22		0x5c
#define 	I2C1_SDA	0x60
#define 	I2C1_SCL	0x64
#define 	GPIO6		0x68
#define 	GPIO7		0x6c
#define 	GPIO8		0x70
#define 	GPIO9		0x74
#define 	GPIO10		0x78
#define 	GPIO11		0x7c
#define 	GPIO12		0x80
#define 	GPIO13		0x84
#define 	GPIO14		0x88
#define 	GPIO15		0x8c
#define 	GPIO16		0x90
#define 	GPIO17		0x94
#define 	GPIO18		0x98
#define 	GPIO19		0x9c
#define 	GPIO20		0xa0
#define 	STRAPPING_OPTIONS		0xa4
#define 	debug_sel_mode 			0xa8
#define 	gpio_irq_type_reg_lo	0xac
#define 	gpio_irq_edge_type_reg	0xb0
#define 	gpio_irq_mask_arm		0xb4
#define 	gpio_irq_stat_reg_arm	0xb8
#define 	gpio_irq_mask_pmp		0xbc
#define 	gpio_irq_stat_reg_pmp	0xc0
#define 	TEST_ECLK				0xc4
#define 	TEST_D0					0xc8
#define 	GPIO23					0xcc
#define 	GPIO24					0xd0
#define 	gpio_irq_type_reg_hi	0xd4

typedef struct 
{
	unsigned int GPIO_enable	:1;
	unsigned int GPIO_SL		:1;
	unsigned int GPIO_DS		:3;
	unsigned int GPIO_PD		:1;
	unsigned int GPIO_PU		:1;
	unsigned int GPIO_ST		:1;
	unsigned int GPIO_OE		:1;
	unsigned int GPIO_OUT		:1;
	unsigned int GPIO_IE		:1;
	unsigned int IP_SL_1		:1;
	unsigned int GPIO_data_in	:1;
	unsigned int reserved		:19;

}Reg_Gpio;

void gpio_enable(unsigned int gpio,bool val);
void gpio_input_enable(unsigned int gpio, bool val);
void gpio_output_enable(unsigned int gpio, bool val);
bool gpio_get_value(unsigned int gpio);
void gpio_set_value(unsigned int gpio, bool val);
void gpio_pinmux_set(unsigned int gpio, bool val);
void gpio_set_pullup(unsigned int gpio, bool val);
void gpio_set_pulldown(unsigned int gpio, bool val);
void gpio_set_ts(unsigned int gpio, bool val);
void gpio_driving_strength(unsigned int gpio, unsigned char val);

void led_water_light_init(void);
void gpio_walter_light(void);

#endif