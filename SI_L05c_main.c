/* include files */
#include "pic.h"

/* variables */
unsigned char portRead; /* for reading the port C pin values */

/* function declarations */
void init();

/* function definitions */

void main()
{
   init();
   portRead = PORTC & 0xF0; /* use mask for reading only RC4 - RC7 pins */
   PORTC = 0x0F; /* set RC0 to RC3 - turn on LEDS */
   
   while(1)
   {
      ;
   }      
}  

void init()
{
   ANSEL = 0x0F; /* set RC0 to RC3 as digital pins */
   ANSELH = 0x0C ; /* set RC6 and RC7 as digital pins */
   
   TRISC = 0xF0; /* RC4 to RC7 input. RC0 to RC4 output */
   PORTC = 0x00; /* port C pins reset value */
}
  