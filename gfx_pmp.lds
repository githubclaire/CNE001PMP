OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(_start)

SECTIONS
{
	. = 0x0;
	. = ALIGN(4);
	.text :
	{
		*(.start)
		*(.text)
	}

	. = ALIGN(4);
	.rodata : {
		*(SORT_BY_ALIGNMENT(SORT_BY_NAME(.rodata*)))
	}

	. = ALIGN(4);
	.data :
	{
		*(.data)
	}
	
	. = ALIGN(4);
	
	__pmp_cmd_start = .;
	.pmp_cmd :
	{
		*(.pmp_cmd)
	}
	__pmp_cmd_end = .; 

	. = ALIGN(4);
	__bss_start = .;
	.bss :
	{
		*(.bss .bss.*)
	}
	. = ALIGN(4);
	__bss_end = .;
}
