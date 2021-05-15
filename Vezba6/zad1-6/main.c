/**
* @file main.c
* @brief Aplikacija koja implementira ogranicen broj treptanja diode
* @author Ime Prezime
* @date 14-05-2021
* @version 1.0
*/

#include <util/delay.h>
#include <stdint.h>
#include <stdlib.h>
#include "../usart/usart.h"

int8_t changeCapital(int8_t str);

/**
* main - funkcija koja implementiran glavni deo aplikacije
* @return Nema povratnu vrednost
*/
int main()
{
	int8_t len;
	int8_t str[64];
	usartInit(9600);

	while(1)
	{
		usartPutString("Napisite nesto: \r\n");
		while (!usartAvailable())
		;
		_delay_ms(100);
        len=usartGetString(str);
        for(int i=0;i<len;i++)
        {
        	str[i]=changeCapital(str[i]);
        }
        usartPutString(str);
        usartPutString("\r\n");



	}

	return 0;
}
//zad1
/*usartPutString("Unesite svoje ime i prezime: \r\n");
		while (!usartAvailable())
		;
		_delay_ms(100);
        usartGetString(str);
        usartPutString("Zdravo, ");
        usartPutString(str);
        usartPutString(". :) \r\n");*/
//zad2
/*
 */
  int8_t changeCapital(int8_t str)
{
	if((str>96)&&(str<123))
	{
		str=str-32;
	}
	return str;

}
  //zad2
  /*

	int8_t len;
   main
	usartPutString("Napisite nesto: \r\n");
		while (!usartAvailable())
		;
		_delay_ms(100);
        len=usartGetString(str);
        for(int i=0;i<len;i++)
        {
        	str[i]=changeCapital(str[i]);
        }
        usartPutString(str);
        usartPutString("\r\n");

*/
