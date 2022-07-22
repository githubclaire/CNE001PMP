PMP_VERSION ?= "_v_1_0_21"
TIME := $(shell env LANG=en_US date +"%F_%H-%M-%S")

# Set to 0 to keep the bin size as it is
#make BIN_SIZE_BYTE=16*1024
BIN_SIZE_BYTE ?= 0
BIN_SIZE = $(shell echo $$(($(BIN_SIZE_BYTE))))

BIN_DIR ?= bin

ifneq ($(O),)
OBJTREE := $(O)/
else
OBJTREE := 
endif


TOPDIR = $(shell pwd)
export TOPDIR
include $(TOPDIR)/config.mk

DEBUG ?= 1
VERBOSE ?=

_EXECUTEABLE := pmp
EXECUTABLE := pmp

# Variables in makefile are always expanded.
ifneq ($(PMP_VERSION),)
BINARY := $(EXECUTABLE)$(PMP_VERSION).bin
BINARY_W_TIME := $(EXECUTABLE)$(PMP_VERSION)_$(TIME).bin
else
BINARY := $(EXECUTABLE).bin
BINARY_W_TIME := $(EXECUTABLE)_$(TIME).bin
endif

LDSCRIPT := $(_EXECUTEABLE).lds
DEBUG_MAP := $(EXECUTABLE).map
DEBUG_LST := $(EXECUTABLE).lst

TEXT_BASE = 0x70000
FINAL_LDFLAGS = $(LDFLAGS) -Wl,-T$(LDSCRIPT),-Map,$(DEBUG_MAP) -Ttext $(TEXT_BASE)

CFLAGS += -DTEXT_BASE=$(TEXT_BASE)

SUBDIRS := libgcc

ifneq ($(DEBUG),)
CFLAGS += -DDEBUG
endif

ifeq ($(VERBOSE),)
ECHO_DETAIL := @
export ECHO_DETAIL
endif

SOBJS = start.o
#gpio.o loop_core.o 
COBJS = main.o serial.o timer.o string.o interrupt.o pmu.o
SUBOBJS = $(foreach dir, $(SUBDIRS), $(dir)/$(dir).o)
TIMESTAMP_FILE = include/timestamp_autogenerated.h

_OBJS = $(SOBJS) $(COBJS) $(SUBOBJS)
OBJS = $(addprefix $(OBJTREE),$(_OBJS))

COMPILE_BY = $(shell whoami)
COMPILE_HOST=`hostname`
.PHONY: all clean $(SUBDIRS)
all:
	echo "" > $(TIMESTAMP_FILE)
	env LANG=en_US date +'#define PMP_DATE "%b %d %C%y"' > $(TIMESTAMP_FILE)
	date +'#define PMP_TIME "%T"' >> $(TIMESTAMP_FILE)
	echo "#define PMP_VERSION" '"'$(PMP_VERSION)'"' >> $(TIMESTAMP_FILE)
  	#echo "#define COMPILE_BY" '"'$(COMPILE_BY)'"' >> $(TIMESTAMP_FILE)
	echo "#define COMPILE_BY" '"'$(COMPILE_BY)@$(COMPILE_HOST)'"' >> $(TIMESTAMP_FILE)

	$(MAKE) all_1

	@if [ "$(BIN_SIZE)" -gt "0" ]; then \
		truncate --size=">$(BIN_SIZE)" --no-create $(BINARY); \
		bin_truc_size=$$(wc -c $(BINARY) | awk '{print $$1}'); \
		if [ $$bin_truc_size -gt $(BIN_SIZE) ]; then \
			echo "[WARN] File too big!!\texpected size=$(BIN_SIZE), actual size=$$bin_truc_size"; \
		fi; \
	fi;
	@bin_name=$(BINARY_W_TIME);echo [CP] $$bin_name;cp $(BINARY) $$bin_name
	@mkdir -p $(BIN_DIR);echo [MV] Move all bin files to $(BIN_DIR)/;mv *.bin $(BIN_DIR)


all_1:  $(OBJTREE) $(SUBDIRS)
	@list='$(SUBDIRS)'; for subdir in $$list; do \
		if [ "$(O)" = "" ]; then \
			$(MAKE) -C $$subdir O= ;\
		else \
			$(MAKE) -C $$subdir O=$(abspath $(OBJTREE)/$$subdir); \
		fi; \
	done; \
	$(MAKE) default
default: $(BINARY) $(DEBUG_LST)

$(OBJTREE):
	@find . -type d | xargs -i mkdir -p $(OBJTREE)/{}

$(BINARY) : $(EXECUTABLE)
	@echo "[OBJCOPY] $@"
	$(ECHO_DETAIL)$(OBJCOPY) --gap-fill 0xff -S -O binary $< $@

$(DEBUG_LST) : $(EXECUTABLE)
	@echo "[OBJDUMP] $@"
	$(ECHO_DETAIL)$(OBJDUMP) -D $< > $@

$(EXECUTABLE) : $(OBJS) $(LDSCRIPT)
	@echo "[LD] $@"
	$(ECHO_DETAIL)$(LD) $(FINAL_LDFLAGS) $(OBJS) -o $@

clean:
	@rm -f $(BINARY) $(EXECUTABLE) $(DEBUG_LST) $(DEBUG_MAP) *.o *.d; \
	list='$(SUBDIRS)'; for subdir in $$list; do \
		rm -f $$subdir/*.o $$subdir/*.d;\
	done

help:
	@echo "Here are targets you can make:"
	@echo "all: the default target"
	@echo "clean: clean the output"

include $(TOPDIR)/rule.mk
sinclude $(OBJS:.o=.d)
