/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    SPI_cofig.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mahmoud Karem Zamel
 *  Date    : 11/7/2021
 *  Vertion : V01
 *  Layer   : MCAL
 * 
 */ 
 
#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

/* Write it in a pair DIOx,PINx */
#define MSPI1_SLAVE_PIN   DIOA,PIN0

/*
    #$# for TFT :-
	
	CPOL=1 / CPHA=1 / Pre=CLK/2 / SPI Enable / MSB first

*/

#define MSPI1_STATUS          MSPI_ENABLE

#define MSPI1_CLOCK_MODE     MSPI_MODE3   //for TFT

#define MSPI1_MASTER_SLAVE   MSPI_MASTER

#define MSPI1_PRESCALLER     MSPI_FPCLK_DIVIDED_BY_2

#define MSPI1_DATA_ORDER     MSPI_MSB_FIRST //for TFT

#define MSPI1_SS_MANAGE      HW_SLAVE_MANAGEMENT

#define MSPI1_DATA_SIZE      MSPI_8BIT_DATA

#define MSPI1_INT_STATUS     MSPI_INT_DISABLE


#endif