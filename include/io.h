#ifndef _PMP_IO_H_
#define _PMP_IO_H_

#define writel(val, addr)  (*(volatile unsigned int*)(addr) = (val))
#define readl(addr)  (*(volatile unsigned int*)(addr))
#define writeb(val, addr)  (*(volatile unsigned char*)(addr) = (val))
#define readb(addr)  (*(volatile unsigned char*)(addr))
#endif
