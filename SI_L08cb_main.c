/* include files */
#include "pic.h"

/* contant and macro defines */
#define LED       RC2
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
      if(counter == 125)
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
   
   /* timer 2 settings */
   TMR2 = 0x00; /* reset TMR2 counter */
   PR2 = 0xF9; /* overflow value */
   T2CON = 0b00001010; /* TMR 2 settings */
   
   /* interrupt settings */
   GIE = 1; /* global interrupt enable */
   PEIE = 1; /* peripheral interrupt enable */
   TMR2IF = 0; /* clear TMR2 interrupt flag */
   TMR2IE = 1; /* TMR2 interrupt enabled */
   
   /* start TMR2 */
   TMR2ON = 1;
   
   /* variable intializations */
   counter = 0;
}

/* Interrupt function */
void interrupt isr(void)
{
   /* check if TMR2 interrupt enable and flag are set */
   if((TMR2IE == 1) && (TMR2IF == 1)) 
   {
      counter++;		/* increment counter every 500ms */
      TMR2IF=0;		/* clear TMR2 interrupt flag */
   }
}
  
  