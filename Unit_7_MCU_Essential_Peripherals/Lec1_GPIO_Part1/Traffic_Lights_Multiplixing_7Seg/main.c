#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

#include "DIO_interface.h"
#include "SSD_interface.h"
#include "LED_interface.h"

int main(void){

	LED_Type R_Led = {LED_PORTD , LED_PIN0 ,ACTIVE_HIGH};
	LED_Type Y_Led = {LED_PORTD , LED_PIN1 ,ACTIVE_HIGH};
	LED_Type G_Led = {LED_PORTD , LED_PIN2 ,ACTIVE_HIGH};
	SSD_Type SSD1  = {SSD_COMMON_CATHODE,SSD_PORTA,SSD_PORTC,SSD_PIN0};
	SSD_Type SSD2  = {SSD_COMMON_CATHODE,SSD_PORTA,SSD_PORTC,SSD_PIN1};

	// INITIALIZATION
	LED_voidInit(R_Led);
	LED_voidInit(Y_Led);
	LED_voidInit(G_Led);
	SSD_voidInitialDataPort  ( SSD1 );
	SSD_voidInitialDataPort  ( SSD2 );



	while(1){

		LED_voidOn(R_Led);
		LED_voidOff(G_Led);
		LED_voidOff(Y_Led);
		for (u8 j=0 ; j<60 ;j++ )
		{
			for (u8 i=0 ; i<10 ;i++ )
					{
						SSD_voidDisable( SSD1 );
						SSD_voidEnable( SSD2 );
						SSD_voidSendNumber(SSD1, j/10%10); //to get msb of count
						_delay_ms(10);
						SSD_voidDisable( SSD2 );
						SSD_voidEnable( SSD1 );
						SSD_voidSendNumber(SSD1, j%10); //to get lsb of count
						_delay_ms(10);
					}
		}
		/****************************************************************************************/
		LED_voidOn(Y_Led);
		LED_voidOff(G_Led);
		LED_voidOff(R_Led);
		for (u8 j=0 ; j<10 ;j++ )
				{
					for (u8 i=0 ; i<10 ;i++ )
							{
								SSD_voidDisable( SSD1 );
								SSD_voidEnable( SSD2 );
								SSD_voidSendNumber(SSD1, j/10%10); //to get msb of count
								_delay_ms(10);
								SSD_voidDisable( SSD2 );
								SSD_voidEnable( SSD1 );
								SSD_voidSendNumber(SSD1, j%10); //to get lsb of count
								_delay_ms(10);
							}
				}
		/****************************************************************************************/
		LED_voidOn(G_Led);
		LED_voidOff(Y_Led);
		LED_voidOff(R_Led);
		for (u8 j=0 ; j<60 ;j++ )
				{
					for (u8 i=0 ; i<10 ;i++ )
							{
								SSD_voidDisable( SSD1 );
								SSD_voidEnable( SSD2 );
								SSD_voidSendNumber(SSD1, j/10%10); //to get msb of count
								_delay_ms(10);
								SSD_voidDisable( SSD2 );
								SSD_voidEnable( SSD1 );
								SSD_voidSendNumber(SSD1, j%10); //to get lsb of count
								_delay_ms(10);
							}
				}
	}
	return 0;
}
