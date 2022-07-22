/*
 * serial support for elite800-based development kit
 */
#include <serial.h>
#include <vic.h>
#include <io.h>
#include "pmp.h"
#include "printf.h"
#include "timer.h"

static PUART_REG pUart_Reg = (PUART_REG)BA_UART0;

unsigned char debug_flag = 1;
/*
 * Function purpose:
 * UART initialization
 */
int serial_init()
{
	serial_setbrg(0);
	return 0;
}

/*
 * Function purpose:
 * Output character data through UART
 */
void serial_putc(const char c)
{	
	pUart_Reg->URTDR = c;
	while (1) {
		if ((pUart_Reg->URUSR & URUSR_TXDBSY) == 0)     /* TX data not busy */
			break;
	}
	// if (c == '\n')
	// 	serial_putc('\r');
}

/*
 * Function purpose:
 * Output string data through UART
 */
void serial_puts(const char *s)
{
	if(debug_flag == 1)
	{
		while (*s)
		{
			if(*s=='\n')
			{ 
				serial_putc(*s++);
				serial_putc('\r');
			}
			else
			{
				serial_putc(*s++);
			}			
		}
	}
}

/*
 * Function purpose:
 * Require character data from UART
 */
int serial_getc(void)
{
	while (!(pUart_Reg->URUSR & URUSR_RXDRDY)) {
	}
	return pUart_Reg->URRDR & 0xff;
}
int serial_getc_timeout(long time)
{
	while (!(pUart_Reg->URUSR & URUSR_RXDRDY)) {
		
		if(time-- == 0){
			break;
		}
	}
	if(time==-1)
		return -1;
	return pUart_Reg->URRDR & 0xff;
}
int serial_getc_n(void)
{
	if ((pUart_Reg->URUSR & URUSR_RXDRDY)) {
		return pUart_Reg->URRDR & 0xff;
	}
	else
		return -1;
	
}



/*
 * Function purpose:
 * Uart baud rate setting and initialization
 * Note:
 * Relative settings according to UART/IrDA
 * Programmer Guide Revision 0.13
 */
void serial_setbrg(unsigned int port)
{
	unsigned long TmpDiv = 0;
	unsigned long TmpBkr = 0;
	unsigned long baudrate = BR_115K2;
	unsigned int cnt = 0;

	switch (baudrate) {

	case BR_57K6:
		TmpDiv = UART_BR_57K6;
		TmpBkr = UART_BK_57K6;
		break;

	case BR_38K4:
		TmpDiv = UART_BR_38K4;
		TmpBkr = UART_BK_38K4;
		break;

	case BR_19K2:
		TmpDiv = UART_BR_19K2;
		TmpBkr = UART_BK_19K2;
		break;

	case BR_9K6:
		TmpDiv = UART_BR_9K6;
		TmpBkr = UART_BK_9K6;
		break;

	case BR_115K2:
	default:
		if (port == 0) {
			TmpDiv = UART_BR_115K2;
			TmpBkr = UART_BR_115K2;
		} else {
			TmpDiv = UART_HIGH_SPEED_BR_115K2;
			TmpBkr = UART_HIGH_SPEED_BK_115K2;
		}

		break;
	}

	pUart_Reg->URDIV = TmpDiv;
	pUart_Reg->URBKR = TmpBkr;

	/* Disable TX,RX */
	pUart_Reg->URLCR = 0;

	/* Disable all interrupt */
	pUart_Reg->URIER = 0;

	/* Reset Tx,Rx Fifo until all zeros */
	cnt = 0;
	while ((pUart_Reg->URFCR) & (URFCR_TXFRST | URFCR_RXFRST)) {
		/* Reset TX,RX Fifo */
		pUart_Reg->URFCR = URFCR_TXFRST | URFCR_RXFRST;
		udelay(10);
		if(cnt++ > 40) break ;
	}

	/* Disable Fifo */
	pUart_Reg->URFCR &= (~URFCR_FIFOEN);

	/* 8-N-1 */
	pUart_Reg->URLCR |= (URLCR_DLEN8B & ~URLCR_STBLEN2b & ~URLCR_PYTEN);

	/* Enable TX,RX */
	pUart_Reg->URLCR |= URLCR_RXEN | URLCR_TXEN;

	/* Clear all interrupt status until all zeros */
	cnt = 0;
	while (pUart_Reg->URISR) {
		pUart_Reg->URISR = pUart_Reg->URISR;
		udelay(10);
		if(cnt++ > 40) break ;
	}
	pUart_Reg->URIER = URIER_RXDF;
	pUart_Reg->URDIV =  0x10007;
	//printf("please change baud rate to 115200\n");
	pUart_Reg->URDIV = UART_BR_115K2;

}
void uart_intr_handler(void) {
	if(pUart_Reg -> URISR & URISR_RXDF)
	{
		serial_putc(serial_getc());	
	}
}