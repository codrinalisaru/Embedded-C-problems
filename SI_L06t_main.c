/* include files */
#include "pic.h"

/* constant and macro defines */
#define PUSH      RA3
#define LED       RC0
#define ON        1
#define OFF       0
#define PRESSED   0

/* variables */
unsigned char counter;

/* function declarations */
void init();
void delayMs(unsigned int ms);

/* function definitions */

void main()
{
   init();
   LED = OFF;
   /* delay before entering infinite loop */
   delayMs(1000);
   while(1)
   {
      /* check if push button has been pressed */
      if(PUSH == PRESSED)
      {
         delayMs(10); /* 10ms delay */
         if(PUSH == PRESSED) /* if push button is still pressed  */
         {
            PORTC = 1 << counter;
            counter++;
            counter %= 4; //  if (counter==4) counter=0;
            delayMs(1000);     
         }
      } 
   }      
}  

void init()
{
   ANSEL = 0x0F; /* set RC0 to RC3 as digital pins */
   ANSELH = 0x0C ; /* set RC6 and RC7 as digital pins */
   
   TRISA = 0xFF; /* set all pins on port A as input */
   TRISC = 0xF0; /* RC4 to RC7 input. RC0 to RC4 output */
   PORTC = 0x00; /* port C pins reset value */	
   
   /* variables initialization */
   counter = 0;
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
  