/*
 * AVR-VGA.c
 *
 * Created: 2021-03-08 오후 5:04:22
 * Author : user
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRB = 0xFF;
	volatile unsigned int V_CNT = 0;
	volatile unsigned int H_CNT = 0;
    /* Replace with your application code */
    while (1) 
    {
		V_CNT++;
		//VISIBLE = V_CNT == 200 ? 0:VISIBLE; //약 1ms;
		if(V_CNT == 600)
		{
			_delay_us(26);
			PORTB &= 0xFE; //V_SNYC pulse
			_delay_us(105);
			PORTB |= 0x01; //V_SNYC pulse
			_delay_us(607);
			V_CNT = 0;
		}
		H_CNT = 0;
		while(1)
		{
			if (H_CNT == 100)
			{
				break;
			}
			H_CNT++;
		}
    }
}

