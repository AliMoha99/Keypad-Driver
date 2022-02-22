/*
 * main1.c
 *
 *  Created on: Jul 17, 2020
 *      Author: MeGa
 */

#include<avr/io.h>
#include<util/delay.h>
#include"KEYPAD.h"

#define Key_Pad          1
#define seven_segement_task   0

#if Key_Pad




//void seven_segment_init(void);
//void display_4_Digits_7Segment(unsigned int number);


int main()
{
	DDRC=0xff;
    DDRB=0Xff;
    PORTC=0x00000000;

	unsigned char key=0;

	key_pad_init();
	//seven_segment_init();

	while(1)
	{


		key=key_pad_Scan();

	//	display_4_Digits_7Segment(key);
		PORTB=key;
		_delay_ms(300);
	}




	return 0;
#endif
}



/*
void seven_segment_init(void)
{

	DDRB=0x0F;
	DDRC=0b00111100;


}

void display_4_Digits_7Segment(unsigned int number)
{

	unsigned char digit1=0,digit2=0,digit3=0,digit4=0;
	unsigned int temp=0;


	digit4=number/1000;
	temp=number%1000;

	digit3=temp/100;
	temp=temp%100;

	digit2=temp/10;

	digit1=temp%10;


	if(number>1000)
	{


		PORTC &=~(1<<PC5);
		PORTC |=(1<<PC4);
		PORTC |=(1<<PC3);
		PORTC |=(1<<PC2);
		PORTB = digit4;
		_delay_ms(5);

	}

	if(number>100)
	{

		PORTC |=(1<<PC5);
		PORTC &=~(1<<PC4);
		PORTC |=(1<<PC3);
		PORTC |=(1<<PC2);

		PORTB = digit3;
		_delay_ms(5);
	}

	if(number>10)
	{

		PORTC |=(1<<PC5);
		PORTC |=(1<<PC4);
		PORTC &=~(1<<PC3);
		PORTC |=(1<<PC2);

		PORTB = digit2;
		_delay_ms(5);
	}


	PORTC |=(1<<PC5);
	PORTC |=(1<<PC4);
	PORTC |=(1<<PC3);
	PORTC &=~(1<<PC2);
	PORTB = digit1;
	_delay_ms(5);


}









#endif



#if seven_segement_task

int main()
{
	unsigned char count=0;

	DDRD=0x00;

	DDRB=0x0F;
	DDRC=0b00111100;

	PORTC=0b00110000;

	while(0)
	{

		if((PIND&(1<<PD2)))
		{
			count++;
			if(count>99)   count=0;
			_delay_ms(200);
		}
		if((PIND&(1<<PD3)))
		{
			if(count<=0)   count=100;
			count--;

			_delay_ms(200);
		}

		PORTC=0b00111000;
		PORTB=count%10;
		_delay_ms(1);
		PORTC=0b00110100;
		PORTB=count/10;
		_delay_ms(1);


	}


	//count 1 second
	while(1)
	{

		count++;
		if(count>99)   count=0;

		for(int i=0;i<500;i++)
		{
			PORTC=0b00111000;
			PORTB=count%10;
			_delay_ms(1);
			PORTC=0b00110100;
			PORTB=count/10;
			_delay_ms(1);
		}

	}



*/
//	return 0;

//#endif

