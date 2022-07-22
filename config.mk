COMPILE = arm-none-linux-gnueabi-
CC = $(COMPILE)gcc
LD = $(COMPILE)gcc
OBJCOPY = $(COMPILE)objcopy
OBJDUMP = $(COMPILE)objdump
AR = $(COMPILE)ar

MCPU = -mcpu=arm7tdmi
MARCH = -march=armv4t

INCLUDE = $(TOPDIR)/include/

CFLAGS = -c -I $(INCLUDE) -Os -Wall -Wshadow -ffreestanding -fno-common \
	 -fno-builtin -Wstrict-prototypes -marm -mabi=aapcs-linux \
	 -fno-stack-protector -mno-thumb-interwork -msoft-float \
	 -mno-unaligned-access $(MCPU) $(MARCH)

LDFLAGS = -nostdlib -marm -fno-common $(MCPU) $(MARCH)

$(OBJTREE)%.o : %.c
	@echo "[CC] $@"
	$(ECHO_DETAIL)$(CC) $(CFLAGS) $< -o $@

$(OBJTREE)%.o : %.S 
	@echo "[CC] $@"
	$(ECHO_DETAIL)$(CC) $(CFLAGS) -D__ASSEMBLY__ $< -o $@ 

# If the list of objects to link is empty, just create an empty built-in.o
cmd_link_o_target = $(if $(strip $1),\
		      $(LD) $(LDFLAGS) -r -o $@ $1,\
		      rm -f $@; $(AR) rcs $@ )
