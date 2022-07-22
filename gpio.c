#include "types.h"
#include "gpio.h"
#include "io.h"
#include "printf.h"

void gpio_enable(unsigned int gpio,bool val)
{
	unsigned char val_tmp;
	volatile Reg_Gpio *pRegGpio;
	pRegGpio = (volatile Reg_Gpio *)(GPIO_BASE+gpio);
	val_tmp = val? 1:0;
	if(gpio>GPIO_TYPE_BOUNDARY)
	{
		val_tmp = val? 0:1;
	}
	pRegGpio->GPIO_enable = val_tmp;
}
void gpio_input_enable(unsigned int gpio, bool val)
{
	volatile Reg_Gpio *pRegGpio;
	pRegGpio = (volatile Reg_Gpio *)(GPIO_BASE+gpio);
	pRegGpio->GPIO_IE = val;
}
bool gpio_get_value(unsigned int gpio)
{
	volatile Reg_Gpio *pRegGpio;
	pRegGpio = (volatile Reg_Gpio *)(GPIO_BASE+gpio);
	return pRegGpio->GPIO_data_in;
} 
void gpio_output_enable(unsigned int gpio, bool val)
{
	volatile Reg_Gpio *pRegGpio;
	pRegGpio = (volatile Reg_Gpio *)(GPIO_BASE+gpio);
	pRegGpio->GPIO_OE = val;
}
void gpio_set_Value(unsigned int gpio, bool val)
{
	volatile Reg_Gpio *pRegGpio;
	pRegGpio = (volatile Reg_Gpio *)(GPIO_BASE+gpio);
	pRegGpio->GPIO_OUT = val;
} 
void gpio_pinmux_set(unsigned int gpio, bool val)
{
	volatile Reg_Gpio *pRegGpio;
	pRegGpio = (volatile Reg_Gpio *)(GPIO_BASE+gpio);
	pRegGpio->IP_SL_1 = val;
}
void gpio_set_pullup(unsigned int gpio, bool val)
{
	volatile Reg_Gpio *pRegGpio;
	pRegGpio = (volatile Reg_Gpio *)(GPIO_BASE+gpio);
	pRegGpio->GPIO_PU = val;
}
void gpio_set_pulldown(unsigned int gpio, bool val)
{
	volatile Reg_Gpio *pRegGpio;
	pRegGpio = (volatile Reg_Gpio *)(GPIO_BASE+gpio);
	pRegGpio->GPIO_PD = val;
}
void gpio_set_ts(unsigned int gpio, bool val)
{
	volatile Reg_Gpio *pRegGpio;
	pRegGpio = (volatile Reg_Gpio *)(GPIO_BASE+gpio);
	pRegGpio->GPIO_ST = val;
}
void gpio_driving_strength(unsigned int gpio, unsigned char val)
{
	volatile Reg_Gpio *pRegGpio;
	pRegGpio = (volatile Reg_Gpio *)(GPIO_BASE+gpio);
	pRegGpio->GPIO_DS = (val&0x7);
}

//#define LED_ON
#ifdef LED_ON
unsigned char LedIndexBuf[] = {
	GPIO0,\
	GPIO1,\
	GPIO2,\
	GPIO3,\
	GPIO4,\
	GPIO5,\
	GPIO6,\
	GPIO7,\
	GPIO8,\
	GPIO9,\
	GPIO10,\
	GPIO11,\
	GPIO12,\
	GPIO13,\
	GPIO14,\
	GPIO15,\
	GPIO16,\
	GPIO17,\
	GPIO18,\
	GPIO19,\
	GPIO20,\
	GPIO23,\
	GPIO24
};
void led_water_light_init(void)
{
	int i, ledNum = sizeof(LedIndexBuf);
	for(i=0;i<ledNum;i++)
	{
		gpio_enable(LedIndexBuf[i],1);
		gpio_output_enable(LedIndexBuf[i],1);
		
	}

}

void gpio_walter_light(void)
{
	static int lightIndex=0;
	unsigned int ledNum = sizeof(LedIndexBuf);
	if(lightIndex<ledNum)
	{		
		gpio_set_Value(LedIndexBuf[lightIndex],1);
		lightIndex++;
	}
	else if(lightIndex-ledNum<ledNum)
	{			
		gpio_set_Value(LedIndexBuf[lightIndex-ledNum],0);
		lightIndex++;	
	}
	else
	{
		lightIndex = 0;
	}
	
}
#else
void led_water_light_init(void)
{

}
void gpio_walter_light(void)
{

}
#endif