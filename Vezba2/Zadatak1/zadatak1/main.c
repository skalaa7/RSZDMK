#include <avr/io.h>
#include <avr/interrupt.h>
unsigned long milliss = 0;
ISR(TIMER0_COMPA_vect)
{
 milliss++; //sistemsko vreme
}
int main()
{
 unsigned long t0;
 DDRB |= 1 << 5;


 //inicijalizacija tajmera 0:
 TCCR0A = 0x02; //tajmer 0: CTC mod
 TCCR0B = 0x03; //tajmer 0: fclk = fosc/64
 OCR0A = 249; //perioda tajmera 0: 250 Tclk (OCR0A + 1 = 250)
 TIMSK0 = 0x02; //dozvola prekida tajmera 0
 //usled dostizanja vrednosti registra OCR0A
 sei(); //I = 1 (dozvola prekida)

 while(1)
 {
 PORTB |= 1 << 5;
 t0 = milliss;
 while ((milliss - t0) < 1000); //pauza 500ms
 PORTB &= ~(1 << 5);
 t0 = milliss;
 while ((milliss - t0) < 1000); //pauza 500ms
 }
 return 0;
}

