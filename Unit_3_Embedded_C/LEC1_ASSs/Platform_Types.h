/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    STD_TYPES.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *  Platform_Types.h
 *
 */ 


#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

#include <stdbool.h>
#include <stdint.h>

	
typedef char                               char_t ;	
typedef int8_t                             sint8  ;
typedef uint8_t                            uint8  ;
typedef int16_t                            sint16 ;
typedef uint16_t                           uint16 ;
typedef int32_t                            sint32 ;
typedef uint32_t                           uint32 ;
typedef int64_t                            sint64 ;
typedef uint64_t                           uint64 ;

typedef volatile int8_t                    vsint8_t  ;
typedef volatile uint8_t                   vuint8_t  ;
typedef volatile int16_t                   vsint16_t ;
typedef volatile uint16_t                  vuint16_t ;
typedef volatile int32_t                   vsint32_t ;
typedef volatile uint32_t                  vuint32_t ;
typedef volatile int64_t                   vsint64_t ;
typedef volatile uint64_t                  vuint64_t ;

typedef float                              float32;
typedef double                             float64;
	
#endif /* PLATFORM_TYPES_H_ */