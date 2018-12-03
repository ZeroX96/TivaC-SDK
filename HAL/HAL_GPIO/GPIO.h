/*
 * GPIO.h
 *
 *  Created on: 9 Oct 2018
 *      Author: Mahmoud
 */

#ifndef GPIO_H_
#define GPIO_H_
#include "HW_GPIO.h"
#define GPIO_ERRORS_BASE 50

typedef enum
{
    NO_GPIO_ERRORS       =1+GPIO_ERRORS_BASE,
    INVALID_GPIO_PARAMS  =2+GPIO_ERRORS_BASE,
    INVALID_GPIO_PIN     =3+GPIO_ERRORS_BASE,
}gpio_errors_t;

typedef enum
{
    INPUT,
    OUTPUT,
}gpio_data_dir_t;
typedef enum
{
    LOW,
    HIGH,
}gpio_data_val_t;

typedef enum
{
    PULL_UP_RES,
    PULL_DWN_RES,
    OPNDRAIN_RES,
}gpio_res_t;            //

typedef enum
{
    CURRENT_EQU_2MA,
    CURRENT_EQU_4MA,
    CURRENT_EQU_8MA,
}gpio_current_val_t;    //GPIO Current Drive Select
typedef enum
{
    SLR_OFF,
    SLR_ON,
}gpio_SLR_select_t;     //GPIO Slew Rate Control Select


typedef struct
{
    gpio_bases_t        obj_base;
    gpio_SLR_select_t   obj_slr_select;
    gpio_current_val_t  obj_current_value;
    gpio_data_dir_t     obj_data_direction;
    gpio_res_t          obj_res_type;
}gpio_module_cfg_t;

gpio_errors_t InitGpioPort(gpio_module_cfg_t    module_obj,gpio_bases_t         port_base,
                           gpio_SLR_select_t    slwRateSel,  gpio_data_dir_t      port_direction,
                           gpio_res_t           res_type,   gpio_current_val_t   output_current,
                          );
gpio_errors_t InitGpioPin();
gpio_errors_t ReInitGpioPort(specific_configs_and_the_unchanged_put_Zero);
gpio_errors_t ReInitGpioPin(specific_configs_and_the_unchanged_put_Zero);
gpio_errors_t Write2GpioPort();
gpio_errors_t Write2GpioPin();
gpio_errors_t Read4mGpioPort();
gpio_errors_t Read4mGpioPin();
gpio_errors_t DeInitGpioPort();



#endif /* GPIO_H_ */
