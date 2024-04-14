/* include files */
#include "pic.h"

/* contant and macro defines */
#define PIN       RC3
#define ON        1
#define OFF       0

#define TMR1_HIGH 0xF6
#define TMR1_LOW  0x3B

#define TMR2_PR   0x7D /* value for 2ms */

/* function declarations */
void init();

/* function definitions */

void main()
{
   init();

   while(1)
   {
      ; /* further development */  
   }      
}  

void init()
{
   ANSEL = 0x0F; /* set RC0 to RC3 as digital pins */
   ANSELH = 0x0C; /* set RC6 and RC7 as digital pins */
   
   TRISC = 0xF0; /* RC4 to RC7 input. RC0 to RC4 output */
   PORTC = 0x00; /* port C pins reset value */
   
   /* timer 1 settings */
   TMR1L = TMR1_LOW;
   TMR1H = TMR1_HIGH;
   T1CON = 0b00110000; /* 1:8 prescalar */
   
   /* timer 2 settings */
   TMR2 = 0x00; /* reset TMR2 counter */
   PR2 = TMR2_PR; /* overflow value */
   T2CON = 0b00000010; /* post-scalar 1:1, pre-scalar 1:16 */
   
   /* interrupt settings */
   GIE = 1; /* global interrupt enable */
   PEIE = 1; /* peripheral interrupt enable */
   TMR1IF = 0; /* clear TMR1 interrupt flag */
   TMR1IE = 1; /* TMR1 interrupt enabled */
   TMR2IF = 0; /* clear TMR2 interrupt flag */
   TMR2IE = 1; /* TMR2 interrupt enabled */
   
   /* start TMR1 and TMR 2 */
   TMR1ON = 1;
   TMR2ON = 1;
   
   /* initially, set PIN to 1 */
   PIN = ON;
   
}

/* Interrupt function */
void interrupt isr(void)
{
   /* check if TMR1 interrupt enable and flag are set */
	if((TMR1IE == 1) && (TMR1IF == 1)) 
   {
		TMR1L = TMR1_LOW;
		TMR1H = TMR1_HIGH;
		TMR2 = 0x00;   /* reset TMR2 counter */
		TMR2ON = 1;    /* start TMR2 */
      PIN = ON;      /* set pin high */
		TMR1IF = 0;		/* clear TMR1 interrupt flag*/
	}
	/* check if TMR2 interrupt enable and flag are set */
   if((TMR2IE == 1) && (TMR2IF == 1)) 
   {
      TMR2ON = 0;    /* turn off TMR2 */
      PIN = OFF;     /* set pin low */
      TMR2IF=0;		/* clear TMR2 interrupt flag */
   }
}
  
  