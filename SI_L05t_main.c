/* include files */
#include "pic.h"

/* function declarations */
void init();
void delayMs(unsigned int ms);

/* function definitions */

void main()
{
   init();
   
   delayMs(1000);
   
   while(1)
   {
      PORTC = 0x0A;
      delayMs(1000);
      PORTC = 0x05;
      delayMs(1000);
   }      
}  

void init()
{
   ANSEL = 0x0F; /* set RC0 to RC3 as digital pins */
   ANSELH = 0x0C ; /* set RC6 and RC7 as digital pins */
   
   TRISC = 0xF0; /* RC4 to RC7 input. RC0 to RC4 output */
   PORTC = 0x00; /* port C pins reset value */
}

void delayMs(unsigned int ms)
{
   unsigned int i,j;
   for(i = 0; i< ms; i++)
   {
      /* delay for 1 ms - empirically determined */
      for(j=0; j<62; j++)
      {
         ;
      }
   }      

}   
  