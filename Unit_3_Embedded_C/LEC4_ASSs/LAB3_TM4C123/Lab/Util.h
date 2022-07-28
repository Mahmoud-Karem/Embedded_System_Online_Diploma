/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    Util.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Author  : Mahmoud Karem Zamel
 *
 */ 

#ifndef UTIL_H
#define UTIL_H

#define SET_BIT(reg,n)				(reg|=(1<<n))
#define CLR_BIT(reg,n)				(reg&=~(1<<n))
#define TOG_BIT(reg,n)		    	(reg^=(1<<n))
#define	GET_BIT(reg,n)				(((reg)>>(n))&1)
#define IS_BIT_SET(reg,bit)         (reg&(1<<bit))>>bit
#define IS_BIT_CLR(reg,bit)         !((reg&(1<<bit))>>bit)
#define ROR(reg,num)                reg=(reg<<(REGISTER_SIZE-num))|(reg>>(num))
#define ROL(reg,num)                reg= (reg>>(REGISTER_SIZE-num))|(reg<<(num))


#define SET_REG(reg)				((reg)=0XFF)
#define CLR_REG(reg)				((reg)=0X00)
#define TOG_REG(reg)				((reg)~=(reg))  /* ((reg)^=0xFF) */
#define	GET_REG(reg)				(reg)
#define ASSIGN_REG(reg,value)		((reg)=(value))

#define SET_LOW_NIB(reg)			((reg)|=0X0F)
#define CLR_LOW_BIT(reg)			((reg)&=0XF0)
#define TOG_LOW_NIB(reg)			((reg)^=0X0F)
#define	GET_LOW_NIB(reg)			((reg)&0X0F)
#define ASSIGN_LOW_NIB(reg,value)	((reg)=(((reg)&0XF0)|((value)&0x0F)))

#define	GET_HIGH_NIB(reg)			(((reg)&0XF0)>>4)
#define SET_HIGH_NIB(reg)			((reg)|=0XF0)
#define CLR_HIGH_BIT(reg)			((reg)&=0X0F)
#define TOG_HIGH_NIB(reg)		((reg)^=0XF0)
#define ASSIGN_HIGH_NIB(reg)		((reg)=((value<<4)|(reg&0X0F)))

#endif