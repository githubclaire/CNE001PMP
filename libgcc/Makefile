ifneq ($(O),)
OBJTREE := $(O)/
else
OBJTREE :=
endif

include $(TOPDIR)/config.mk

TARGET := $(OBJTREE)libgcc.o

SOBJS := _lshrdi3.o _udivsi3.o _divsi3.o
COBJS := div0.o div64.o ctype.o printf.o
_OBJS :=
DEBUG := 1

ifneq ($(DEBUG),)
_OBJS += $(SOBJS) $(COBJS)
CFLAGS += -DDEBUG
endif

OBJS := $(addprefix $(OBJTREE),$(_OBJS))

$(TARGET) : $(OBJS)
	@echo "[LD] $@"
	$(ECHO_DETAIL)$(call cmd_link_o_target, $^)

include $(TOPDIR)/rule.mk
sinclude $(OBJS:.o=.d)
