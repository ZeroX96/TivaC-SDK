/*
 * HW_TYPES.h
 *
 *  Created on: 18 Oct 2018
 *      Author: Mahmoud
 */

#ifndef HW_TYPES_H_
#define HW_TYPES_H_

/** HW_WRITE_REG
 *
 *  \brief  Macro to write a value to a 32 bit register.
 *
 *  \param  address  32bit register address.
 *  \param  value    value to write to the 32bit register.
 *
 */
#define HW_WRITE_REG(add,val)       ((*(volatile int32 *)add)=val)
/** HW_READ_REG
 *
 *  \brief  Macro to read a 32 bit register.
 *
 *  \param  address  32bit register address.
 *
 */
#define HW_READ_REG(add)            (*(volatile int32 *)add)

/**
 *
 *  \brief  Macro to set a bit in a 32bit register.
 *
 *  \param  addr  32bit register address.
 *
 */
#define HW_SET_REG_BIT(add,bit)     ((*(volatile int32 *)add) |= (1<<bit))

/**
 *
 *  \brief  Macro to clear a bit in a 32 bit register.
 *
 *  \param  addr  32bit register address.
 *  \param  bit   the bit number to be cleared.
 *
 */
#define HW_CLR_REG_BIT(add,bit)     ((*(volatile int32 *)add) &=~(1<<bit))


/**
 *
 *  \brief  Macro to read a bit in a 32 bit register.
 *
 *  \param  addr  32bit register address.
 *  \param  bit   the bit number to be read.
 */
#define HW_READ_REG_BIT(add,bit)     ((*(volatile int32 *)add) & (1<<bit))

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                       Global Variables Declarations                        */
/* ========================================================================== */

/* None */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

#endif /* HW_TYPES_H_ */
