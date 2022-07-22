1. PMP Version
    PMP3C06Aa.bin
    PMP 3C 06 A a.bin
     |  |  |  | |____bootleg Version, only for bootleg, normal release no this section.
     |  |  |  |______PMP Version, base at Timing Version
     |  |  |_________Timing Version
     |  |____________Channel num: 1C->1MIU, 2C->2MIU, 3C->3MIU
     |_______________PMP binary file
    Run build script can generate 1C 2C and 3C binary file at the same time if the timing_table_xxx.h is available.
    Timing Version is decided by the macro definition 'TIMING_VERSION' in the timing_table_xxx.h.
    PMP version is decided by the veriable 'PMP_SUB_VERSION' in buildxxx.sh
2. Build pmp binary file
    run buildxxx.sh script to build pmp binary file
        build.sh:       800MHz TimingTable
        build1200.sh:   120000MHz TimingTable
        build1600.sh:   1600MHz TimingTable
        716_build.sh:   build pmp for 716 board
3. build.sh Config
    build script has two veriable to config:
        PMP_SUB_VERSION:    PMP Verison,
        TIMING_MCLK:        Timing MCLK,
4. timing_table_xxx.h
    naming rule:
        timing_table-716-1200-1channel.h
              |       |    |      |______Timing table MIU num: 1channel, 2channel, 3channel
              |       |    |_____________MCLK frequency, if MCLK which equal to 800 will no this section.
              |       |__________________board vender, 716 is for 716 board, zhaoxin board will no this section
              |__________________________Indecate this head file is timing table.
    format:
        timing_table_xxx.h file has four macro definition to config, if add or update a new timing table file, those definiton must be added and updated.
            #define CHANNEL_MCLK_CLK 1593
            #define DDR_TYPE "ddr4"
            #define TIMING_TIME "2020-03-30"
            #define TIMING_VERSION "07"
