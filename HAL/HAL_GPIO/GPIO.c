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

#define PORTS_NO 6
static uint8_t ports_state[6]={0};  //the ports are all undefined at first.
gpio_errors_t InitGpioPort(gpio_module_cfg_t* module_obj)
{
    if(  (module_obj->obj_base >= BASE_A) && (module_obj->obj_base <= BASE_F) &&
        ((module_obj->obj_res_type >=PULL_UP_RES) && (module_obj->obj_res_type <= OPNDRAIN_RES)) &&
        ((module_obj->obj_current_value >= CURRENT_EQU_2MA) && (module_obj->obj_current_value <= CURRENT_EQU_8MA)) &&
        ((module_obj->obj_slr_select == SLR_OFF)||(module_obj->obj_slr_select == SLR_ON)) &&
        ((module_obj->obj_af_select == AFSELECT_OFF)||(module_obj->obj_af_select == AFSELECT_ON))
      )
    {
        //ENABLING THE GPIO MODULE PORT
        if(module_obj->obj_base == BASE_A)      enable_module(GPIO, GPIO_PORT_A);
        else if (module_obj->obj_base == BASE_B)enable_module(GPIO, GPIO_PORT_B);
        else if (module_obj->obj_base == BASE_C)enable_module(GPIO, GPIO_PORT_C);
        else if (module_obj->obj_base == BASE_D)enable_module(GPIO, GPIO_PORT_D);
        else if (module_obj->obj_base == BASE_E)enable_module(GPIO, GPIO_PORT_E);
        else if (module_obj->obj_base == BASE_F)enable_module(GPIO, GPIO_PORT_F);
        else{/* can't come here :P */}
        //SETTING THE GPIO MODULE PORT DIRECTION
        HW_WRITE_REG(module_obj->obj_base+GPIO_DIRECTION_OFFSET,module_obj->obj_data_direction);
        //IF NEEDED AN ALTERNATIVE FUNCTION, SETTING THE GPIO MODULE PORT ALTERNATIVE FUNCTION ACTIVE
        HW_WRITE_REG(module_obj->obj_base+GPIO_ALTERNATE_FUNC_SEL_OFFSET,module_obj->obj_af_select);    //NEEDED TO USE THIS>>REVISE THE AFSELECT SECTION OF THE GPIO
        //SETTING THE GPIO MODULE PORT CURRENT VALUE
        HW_WRITE_REG(module_obj->obj_base+module_obj->obj_current_value,0xff);  //NOTICE for THE WHOLE PORT
        //SETTING THE GPIO MODULE PORT PULL-UP OR PULL-DWN OR OPNDRAIN
        HW_WRITE_REG(module_obj->obj_base+module_obj->obj_res_type,0xff);  //NOTICE ENABLING THE WHOLE PORT
        //SETTING THE GPIO MODULE PORT SELW RATE CONTROL
        HW_WRITE_REG(module_obj->obj_base+GPIO_SLEW_RATE_CONTROL_SEL_OFFSET,0xff);  //NOTICE ENABLING THE WHOLE PORT
        //SETTING THE GPIO MODULE PIN AS DIGITAL OUTPUT/INPUT or ANALOG IN/OUTs
        HW_WRITE_REG(module_obj->obj_base+module_obj->obj_sig_mode,0xff);  //NOTICE ENABLING THE WHOLE PORT
        //SETTING THE GPIO MODULE PORT AS ANALOG IF AVAILABLE OUTPUT/INPUT
        //HW_WRITE_REG(module_obj->obj_base+GPIO_ANALOG_MODE_SEL_OFFSET,0xff);  //NOTICE ENABLING THE WHOLE PORT

    }
    else
    {
        return INVALID_GPIO_PARAMS;
    }
    return NO_GPIO_ERRORS;
}

//notice to be used along with other init func.s but to complete
gpio_errors_t InitGpioPin(gpio_module_cfg_t* module_obj,gpio_module_pin_no_t module_pin_numb)
{
    if(  (module_obj->obj_base >= BASE_A) && (module_obj->obj_base <= BASE_F) &&
         (module_pin_numb >= PIN_ZERO) && (module_pin_numb <= PIN_SEVEN) &&
        ((module_obj->obj_res_type >=PULL_UP_RES) && (module_obj->obj_res_type <= OPNDRAIN_RES)) &&
        ((module_obj->obj_current_value >= CURRENT_EQU_2MA) && (module_obj->obj_current_value <= CURRENT_EQU_8MA)) &&
        ((module_obj->obj_slr_select == SLR_OFF)||(module_obj->obj_slr_select == SLR_ON)) &&
        ((module_obj->obj_af_select == AFSELECT_OFF)||(module_obj->obj_af_select == AFSELECT_ON))
      )
    {
        //ENABLING THE GPIO MODULE PORT
        if(module_obj->obj_base == BASE_A)      enable_module(GPIO, GPIO_PORT_A);
        else if (module_obj->obj_base == BASE_B)enable_module(GPIO, GPIO_PORT_B);
        else if (module_obj->obj_base == BASE_C)enable_module(GPIO, GPIO_PORT_C);
        else if (module_obj->obj_base == BASE_D)enable_module(GPIO, GPIO_PORT_D);
        else if (module_obj->obj_base == BASE_E)enable_module(GPIO, GPIO_PORT_E);
        else if (module_obj->obj_base == BASE_F)enable_module(GPIO, GPIO_PORT_F);
        else{/* can't come here :P */}
        //SETTING THE GPIO MODULE PIN DIRECTION
        if(module_obj->obj_data_direction == OUTPUT)
            HW_SET_REG_BIT(module_obj->obj_base+GPIO_DIRECTION_OFFSET,module_pin_numb);
        else
            HW_CLR_REG_BIT(module_obj->obj_base+GPIO_DIRECTION_OFFSET,module_pin_numb);

        //IF NEEDED AN ALTERNATIVE FUNCTION, SETTING THE GPIO MODULE PIN ALTERNATIVE FUNCTION ACTIVE
        if(AFSELECT_ON == module_obj->obj_af_select)
        {
            HW_SET_REG_BIT(module_obj->obj_base+GPIO_ALTERNATE_FUNC_SEL_OFFSET,module_pin_numb);
            //the remaining control registers
            //gpiopctl adc udma
            //to be done later in the new sdk
        }
        else
            HW_CLR_REG_BIT(module_obj->obj_base+GPIO_ALTERNATE_FUNC_SEL_OFFSET,module_pin_numb);
        //SETTING THE GPIO MODULE PIN CURRENT VALUE
        HW_SET_REG_BIT(module_obj->obj_base+module_obj->obj_current_value,module_pin_numb);
        //SETTING THE GPIO MODULE PIN PULL-UP OR PULL-DWN OR OPNDRAIN
        HW_SET_REG_BIT(module_obj->obj_base+module_obj->obj_res_type,module_pin_numb);
        //SETTING THE GPIO MODULE PIN SELW RATE CONTROL but notice since it's only with 8mA >>will "if" it
        if(CURRENT_EQU_8MA == module_obj->obj_current_value)
            HW_SET_REG_BIT(module_obj->obj_base+GPIO_SLEW_RATE_CONTROL_SEL_OFFSET,module_pin_numb);
        //SETTING THE GPIO MODULE PIN AS DIGITAL OUTPUT/INPUT or ANALOG IN/OUTs
        HW_SET_REG_BIT(module_obj->obj_base+module_obj->obj_sig_mode,module_pin_numb);
        //SETTING THE GPIO MODULE PIN AS ANALOG IF AVAILABLE OUTPUT/INPUT
        //HW_SET_REG_BIT(module_obj->obj_base+GPIO_ANALOG_MODE_SEL_OFFSET,module_pin_numb);

    }
    else
    {
        return INVALID_GPIO_PARAMS;
    }
    return NO_GPIO_ERRORS;
}

//setting the pins directions notice the val should reflects the needed configs
gpio_errors_t InitGpiochannels(gpio_module_cfg_t* module_obj,uint8_t channels_val)
{
    if(  (module_obj->obj_base >= BASE_A) && (module_obj->obj_base <= BASE_F) &&
        ((module_obj->obj_res_type >=PULL_UP_RES) && (module_obj->obj_res_type <= OPNDRAIN_RES)) &&
        ((module_obj->obj_current_value >= CURRENT_EQU_2MA) && (module_obj->obj_current_value <= CURRENT_EQU_8MA)) &&
        ((module_obj->obj_slr_select == SLR_OFF)||(module_obj->obj_slr_select == SLR_ON)) &&
        ((module_obj->obj_af_select == AFSELECT_OFF)||(module_obj->obj_af_select == AFSELECT_ON))
      )
    {
        //ENABLING THE GPIO MODULE PORT
        if(module_obj->obj_base == BASE_A)      enable_module(GPIO, GPIO_PORT_A);
        else if (module_obj->obj_base == BASE_B)enable_module(GPIO, GPIO_PORT_B);
        else if (module_obj->obj_base == BASE_C)enable_module(GPIO, GPIO_PORT_C);
        else if (module_obj->obj_base == BASE_D)enable_module(GPIO, GPIO_PORT_D);
        else if (module_obj->obj_base == BASE_E)enable_module(GPIO, GPIO_PORT_E);
        else if (module_obj->obj_base == BASE_F)enable_module(GPIO, GPIO_PORT_F);
        else{/* can't come here :P */}
        //SETTING THE GPIO MODULE PORT DIRECTION according to the val that reflects the needed configs
        HW_WRITE_REG(module_obj->obj_base+GPIO_DIRECTION_OFFSET,channels_val);
        //IF NEEDED AN ALTERNATIVE FUNCTION, SETTING THE GPIO MODULE PORT ALTERNATIVE FUNCTION ACTIVE
        HW_WRITE_REG(module_obj->obj_base+GPIO_ALTERNATE_FUNC_SEL_OFFSET,channels_val);    //NEEDED TO USE THIS>>REVISE THE AFSELECT SECTION OF THE GPIO
        //SETTING THE GPIO MODULE PORT CURRENT VALUE
        HW_WRITE_REG(module_obj->obj_base+module_obj->obj_current_value,channels_val);  //NOTICE for THE WHOLE PORT
        //SETTING THE GPIO MODULE PORT PULL-UP OR PULL-DWN OR OPNDRAIN
        HW_WRITE_REG(module_obj->obj_base+module_obj->obj_res_type,channels_val);  //NOTICE ENABLING THE WHOLE PORT
        //SETTING THE GPIO MODULE PORT SELW RATE CONTROL
        HW_WRITE_REG(module_obj->obj_base+GPIO_SLEW_RATE_CONTROL_SEL_OFFSET,channels_val);  //NOTICE ENABLING THE WHOLE PORT
        //SETTING THE GPIO MODULE PORT AS DIGITAL OUTPUT/INPUT
        HW_WRITE_REG(module_obj->obj_base+module_obj->obj_sig_mode,channels_val);  //NOTICE ENABLING THE WHOLE PORT
        //SETTING THE GPIO MODULE PORT AS ANALOG IF AVAILABLE OUTPUT/INPUT
        //HW_WRITE_REG(module_obj->obj_base+GPIO_ANALOG_MODE_SEL_OFFSET,channels_val);  //NOTICE ENABLING THE WHOLE PORT

    }
    else
    {
        return INVALID_GPIO_PARAMS;
    }
    return NO_GPIO_ERRORS;
}

gpio_errors_t Write2GpioPort(gpio_module_cfg_t* module_obj,uint8_t value)
{
    if(module_obj != NULL)
    {
        HW_WRITE_REG(module_obj->obj_base+GPIO_DATA_OFFSET,value);
    }
    else
    {
        return INVALID_GPIO_PARAMS;
    }
return NO_GPIO_ERRORS;
}
gpio_errors_t Write2GpioPin(gpio_module_cfg_t* module_obj,gpio_module_pin_no_t module_pin_numb,gpio_data_val_t value)
{
    if(module_obj != NULL)
    {
        if(value == HIGH)
            HW_SET_REG_BIT(module_obj->obj_base+GPIO_DATA_OFFSET,module_pin_numb);
        else
            HW_CLR_REG_BIT(module_obj->obj_base+GPIO_DATA_OFFSET,module_pin_numb);
    }
    else
    {
        return INVALID_GPIO_PARAMS;
    }
return NO_GPIO_ERRORS;
}
gpio_errors_t Read4mGpioPort(gpio_module_cfg_t* module_obj,uint32_t *data_in)
{
    if(module_obj != NULL)
    {
        *data_in=HW_READ_REG(module_obj->obj_base+GPIO_DATA_OFFSET);
    }
    else
    {
        return INVALID_GPIO_PARAMS;
    }
return NO_GPIO_ERRORS;
}

gpio_errors_t Read4mGpioPin(gpio_module_cfg_t* module_obj,gpio_module_pin_no_t module_pin_numb,uint32_t *data_in)
{
    if(module_obj != NULL)
    {

        *data_in=HW_READ_REG_BIT(module_obj->obj_base+GPIO_DATA_OFFSET,module_pin_numb);
    }
    else
    {
        return INVALID_GPIO_PARAMS;
    }
return NO_GPIO_ERRORS;
}
gpio_errors_t DeInitGpioPort()
{
    if(module_obj != NULL)
    {
        //DISABLING THE GPIO MODULE PORT and that's enough!
        if(module_obj->obj_base == BASE_A)      disable_module(GPIO, GPIO_PORT_A);
        else if (module_obj->obj_base == BASE_B)disable_module(GPIO, GPIO_PORT_B);
        else if (module_obj->obj_base == BASE_C)disable_module(GPIO, GPIO_PORT_C);
        else if (module_obj->obj_base == BASE_D)disable_module(GPIO, GPIO_PORT_D);
        else if (module_obj->obj_base == BASE_E)disable_module(GPIO, GPIO_PORT_E);
        else if (module_obj->obj_base == BASE_F)disable_module(GPIO, GPIO_PORT_F);
        else{/* can't come here :P */}
    }
    else
    {
        return INVALID_GPIO_PARAMS;
    }
    return NO_GPIO_ERRORS;
}
