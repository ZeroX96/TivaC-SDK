/*
 * SysResetCtrl.h
 *
 *  Date	: Sep 2, 2019
 *  Author  : MahmoudSaad.ZeroX-86
 *  Email   : msammamsa10@gmail.com
 *  Github  : github.com/zerox-86
 *  LinkedIn: www.linkedin.com/in/zerox86
 *  FaceBook: www.facebook.com/ZeroX86.MSA
 */
/*NOTEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEES
    Reset Sources
        The TM4C123GH6PM microcontroller has six sources of reset:
        1. Power-on reset (POR) (see page 214).
        2. External reset input pin (RST) assertion (see page 215).
        3. A brown-out detection that can be caused by any of the following events:
            =VDD under BOR0. The trigger value is the highest VDD voltage level for BOR0.
            =VDD under BOR1. The trigger value is the highest VDD voltage level for BOR1.
        4. Software-initiated reset (with the software reset registers) (see page 217).
        5. A watchdog timer reset condition violation (see page 217).
        6. MOSC failure (see page 218).
    At any reset that resets the core, the user has the opportunity to direct the core to execute the ROM
        Boot Loader or the application in Flash memory by using any GPIO signal as configured in the Boot
        Configuration (BOOTCFG) register
    At any reset that resets the core, the user has the opportunity to direct the core to execute the ROM
        Boot Loader or the application in Flash memory by using any GPIO signal as configured in the Boot
        Configuration (BOOTCFG) register.
    At reset, the following sequence is performed:
        1. The BOOTCFG register is read. If the EN bit is clear, the ROM Boot Loader is executed.
        2. In the ROM Boot Loader, the status of the specified GPIO pin is compared with the specified
        polarity. If the status matches the specified polarity, the ROM is mapped to address 0x0000.0000
        and execution continues out of the ROM Boot Loader.
        3. f then EN bit is set or the status doesn't match the specified polarity, the data at address
        0x0000.0004 is read, and if the data at this address is 0xFFFF.FFFF, the ROM is mapped to
        address 0x0000.0000 and execution continues out of the ROM Boot Loader.
        4. If there is data at address 0x0000.0004 that is not 0xFFFF.FFFF, the stack pointer (SP) is loaded
        from Flash memory at address 0x0000.0000 and the program counter (PC) is loaded from
        address 0x0000.0004. The user application begins executing.
*/
#ifndef MSA_HAL_LAYER_SYSTEM_SYSRESETCTRL_H_
#define MSA_HAL_LAYER_SYSTEM_SYSRESETCTRL_H_



#endif /* MSA_HAL_LAYER_SYSTEM_SYSRESETCTRL_H_ */
