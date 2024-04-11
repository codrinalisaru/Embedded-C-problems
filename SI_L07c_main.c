/* include files */
#include "pic.h"

/* contant and macro defines */
#define LED       RC1
#define ON        1
#define OFF       0

/* variables */
volatile unsigned int counter;

/* function declarations */
void init();

/* function definitions */

void main()
{
   init();
   
   while(1)
   {
      /* switch LED after m seconds */
      if(counter == 4)
      {
         if(LED == ON)
         {
            LED = OFF;
         }
         else
         {
            LED = ON;
         }
         counter = 0; /* reset counter */   
      }   
   }      
}  

void init()
{
   ANSEL = 0x0F; /* set RC0 to RC3 as digital pins */
   ANSELH = 0x0C ; /* set RC6 and RC7 as digital pins */
   
   TRISC = 0xF0; /* RC4 to RC7 input. RC0 to RC4 output */
   PORTC = 0x00; /* port C pins reset value */
   
   /* timer 1 settings */
   TMR1L = 0xDB;
   TMR1H = 0x0B;
   T1CON = 0b00110000;
   
   /* interrupt settings */
   GIE = 1; /* global interrupt enable */
   PEIE = 1; /* peripheral interrupt enable */
   TMR1IF = 0; /* clear TMR1 interrupt flag */
   TMR1IE = 1; /* TMR1 interrupt enabled */
   
   /* start TMR1 */
   TMR1ON = 1;
   
   /* variable intializations */
   counter = 0;
}

/* Interrupt function */
void interrupt isr(void)
{
   /* check if TMR1 interrupt enable and flag are set */
	if((TMR1IE == 1) && (TMR1IF == 1)) 
   {
		TMR1L = 0xDB;
		TMR1H = 0x0B;
		counter ++;		/* increment counter every 500ms */
		TMR1IF=0;		/* clear TMR1 interrupt flag*/
	}
}
  
  