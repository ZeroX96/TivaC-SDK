/*
 *  types.h
 *  Created on: 10 Oct 2018
 *  Author: Mahmoud
 */
#if 0   //cancelled>>>will use the standard stdint.h    //18-8/19
#ifndef TYPES_H_
#define TYPES_H_

typedef enum
{
    FALSE,TRUE,
}tenum_bool;
    typedef tenum_bool          bool_t;
    typedef   signed char       int8_t;
    typedef unsigned char       uint8_t;
    typedef          short      int16_t;
    typedef unsigned short      uint16_t;
    typedef          int        int32_t;
    typedef unsigned int        uint32_t;
    typedef          long long  int64_t;
    typedef unsigned long long  uint64_t;

#endif /* TYPES_H_ */
