/*
 * SysCtrl.h
 *
 *  Date	: Sep 1, 2019
 *  Author  : MahmoudSaad.ZeroX-86
 *  Email   : msammamsa10@gmail.com
 *  Github  : github.com/zerox-86
 *  LinkedIn: www.linkedin.com/in/zerox86
 *  FaceBook: www.facebook.com/ZeroX86.MSA
 */
/*
 * System Control Module,SYS_CTRL_
 * =SYS_CTRL_[reset control, NMI operation, power control, clock control,low-power modes];
 * =SYS_CTRL_=SysClkCtrl
 *
 *          =
 *
 *NOTEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
 *
 *Several read-only registers provide software with information on the microcontroller ,
 *      such as version,part number, memory sizes, and peripherals present on the device.
 *The Device Identification 0(DID0) (page 238) and Device Identification 1 (DID1) (p240)
 *      registers provide details about the device's version, package, temperature range.
 *The Peripheral Present registers starting at System Control offset 0x300, such as the
 *      Watchdog Timer Peripheral Present (PPWD) register,provide information on how many
 *      of each type of module are included on the device.
 *information about the capabilities of the on-chip peripherals are provided
 *      at offset 0xFC0 in each peripheral's register space in the Peripheral
 *      Properties registers, such as the GPTM Peripheral Properties (GPTMPP) register.
 *
 *Main Oscillator (MOSC). The main oscillator provides a frequency-accurate clock source by
        one of two means:
        =an external single-ended clock source is connected to the OSC0 input pin, or
        =an external crystal is connected across the OSC0 input and OSC1 output pins. If the PLL is being
        used, the crystal value must be one of the supported frequencies between 5 MHz to 25 MHz
        (inclusive). If the PLL is not being used, the crystal may be any one of the supported frequencies
        between 4 MHz to 25 MHz. The single-ended clock source range is as specified in Table
        24-13 on page 1374. The supported crystals are listed in the XTAL bit field in the RCC register
        (see page 254). Note that the MOSC provides the clock source for the USB PLL and must be
        connected to a crystal or an oscillator.
 *
 * */
#ifndef MSA_HAL_LAYER_SYSTEM_SYSCTRL_H_
#define MSA_HAL_LAYER_SYSTEM_SYSCTRL_H_
/*
 * The SysResetCtrl.h File
 * =
 * =
 *
 */
#include "SysResetCtrl.h"

#endif /* MSA_HAL_LAYER_SYSTEM_SYSCTRL_H_ */
