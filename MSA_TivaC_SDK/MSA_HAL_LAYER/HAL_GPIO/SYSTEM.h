/*
 * SYSTEM.h
 *
 *  Created on: 11 Oct 2018
 *      Author: Mahmoud
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_

#include "HW_SYSTEM.h"
#include "HW_TYPES" //to get the set_reg_bit func

#define SYSTEM_ERRORS_BASE 0x100

typedef enum
{
    NO_SYS_ERROR =SYSTEM_ERRORS_BASE,
    SYS_ERROR_INV_PARAMS,
}system_errors_t;

typedef enum
{
 LOWEST_MODULE_NUMB_VAL=0x00,
 ///////////////////////////GPIO_PORTS
 GPIO_PORT_A=0x00,
 GPIO_PORT_B=0x01,
 GPIO_PORT_C=0x02,
 GPIO_PORT_D=0x03,
 GPIO_PORT_E=0x04,
 GPIO_PORT_F=0x05,
 ///////////////////////////UDMA
 UDMA_MODULE=0x00,
 ///////////////////////////end
 HIGHEST_MODULE_NUMB_VAL=0x05,  //must be set by hand to the highest val!!!
}module_numb_t;
typedef enum
{
 LOWEST_MODULE_NAME_VAL=0x00,
 GPIO   =0x00,
 UDMA   =0x40,
 ADC    =0x30,
 HIGHEST_MODULE_NAME_VAL=0x50,  //must be set by hand to the highest val!!!
}module_name_t;

system_errors_t  enable_module(module_name_t module_name ,module_numb_t module_numb);
system_errors_t disable_module(module_name_t module_name ,module_numb_t module_numb);

/*
system_errors_t enable_module(create_the_def_enum module_add and etc);
system_errors_t disable_module(create_the_def_enum module_add and etc);
*/

#endif /* SYSTEM_H_ */
