/*
 * GPIO.c
 *
 *  Created on: 9 Oct 2018
 *      Author: Mahmoud
 * Mahmoud
 * /HAL_GPIO/GPIO.c
 */
#include "GPIO.h"
#define DATA_REG_3FC 0x3fx
/*
#define GPIO_DATA_REG (*(volatile uint32_t *)REG_BASE+DATA_OFFSET+3fc)

GPIO_DATA_REG |= (1<<pin_no);
*/
/*HW_TYPES_FUNCTIONS
****
*   HW_WRITE_REG(add,val)
*   HW_READ_REG(add)
*   HW_SET_REG_BIT(add,bit)
*   HW_CLR_REG_BIT(add,bit)
*   HW_READ_REG_BIT(add,bit)
*/

#define PORTS_NO 6
static uint8_t ports_state[6]={0};  //the ports are all undefined at first.
gpio_errors_t InitGpioPort(gpio_module_cfg_t    module_obj,gpio_bases_t         port_base,
                           gpio_SLR_select_t    slwRateSel,  gpio_data_dir_t      port_direction,
                           gpio_res_t           res_type,   gpio_current_val_t   output_current,
                          );{
    gpio_errors_t ret_val=NO_GPIO_ERRORS;
    if( (port_base == BASE_A || port_base == BASE_B || port_base == BASE_C || port_base == BASE_D || port_base == BASE_E || port_base == BASE_F) &&
            ((port_direction == INPUT || (port_direction == OUTPUT)) && (res_type ==PULL_UP_RES,res_type == PULL_DWN_RES || res_type == OPNDRAIN_RES) &&
            ((output_current >= CURRENT_EQU_2MA) && (output_current <= CURRENT_EQU_8MA)) && ((slwRateSel == SLR_OFF)||(slwRateSel == SLR_ON))
            )
    {

    }
    else
    {
        ret_val =INVALID_GPIO_PARAMS;
    }
    return ret_val;

}
gpio_errors_t InitGpioPin();
gpio_errors_t ReInitGpioPort(specific_configs_and_the_unchanged_put_Zero);
gpio_errors_t ReInitGpioPin(specific_configs_and_the_unchanged_put_Zero);
gpio_errors_t Write2GpioPort();
gpio_errors_t Write2GpioPin();
gpio_errors_t Read4mGpioPort();
gpio_errors_t Read4mGpioPin();
gpio_errors_t DeInitGpioPort();
