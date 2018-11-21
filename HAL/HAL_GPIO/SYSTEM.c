/*
 * SYSTEM.c
 *
 *  Created on: 11 Oct 2018
 *      Author: Mahmoud
 * /HAL_GPIO/SYSTEM.c
 * Mahmoud
 */
#include "SYSTEM.h"


system_errors_t  enable_module(module_name_t module_name ,module_bit_t module_bit)
{
    system_errors_t ret_val=NO_SYS_ERROR;
    if( ( (module_name >= LOWEST_MODULE_NAME_VAL) && (module_name <= HIGHEST_MODULE_NAME_VAL) ) &&
        ( ( module_bit >= LOWEST_MODULE_BIT_VAL ) && ( module_bit <= HIGHEST_MODULE_BIT_VAL ) )
       )
            {
                switch (module_name) {
                case GPIO:
                    HW_SET_REG_BIT(GPIO_CGC_REG,module_bit);
                    break;
                case UDMA:
                    //donothing_till_now:D
                    break;
                default: //do_nothing :D
                    break;
                }

            }
    else
        {
            ret_val=SYS_ERROR_INV_PARAMS;
        }
    return ret_val;
}

system_errors_t  disable_module(module_name_t module_name ,module_bit_t module_bit)
{
    system_errors_t ret_val=NO_SYS_ERROR;
    if( ( (module_name >= LOWEST_MODULE_NAME_VAL) && (module_name <= HIGHEST_MODULE_NAME_VAL) ) &&
        ( ( module_bit >= LOWEST_MODULE_BIT_VAL ) && ( module_bit <= HIGHEST_MODULE_BIT_VAL ) )
       )
            {
                switch (module_name) {
                case GPIO:
                    HW_CLR_REG_BIT(GPIO_CGC_REG,module_bit);
                    break;
                case UDMA:
                    //donothing_till_now:D
                    break;
                default: //do_nothing :D
                    break;
                }

            }
    else
        {
            ret_val=SYS_ERROR_INV_PARAMS;
        }
    return ret_val;
}
