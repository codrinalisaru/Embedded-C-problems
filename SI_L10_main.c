/* include files */
#include "pic.h"

/* contant and macro defines */
#define LED       RC2
#define ON        1
#define OFF       0

#define THRESHOLD 3000 /* threshold for turning the LED ON */
#define ADC_TO_mV 5 /* rounded from 4.88 */

#define TMR1_HIGH 0x0B
#define TMR1_LOW  0xDB

/* variables */
volatile unsigned int ADCValue, lastADCValue;
volatile unsigned int milliVolts;

/* function declarations */
void init();

/* function definitions */

void main()
{
   init();

   while(1)
   {
      /* check if last ADC value is different from current read - only if true execute code */
      if(ADCValue != lastADCValue)
      {
         milliVolts = ADCValue * ADC_TO_mV; /* convert from ADC value to mV */
         /* turn LED ON if greater than set threshold */
         if(milliVolts >= THRESHOLD)
         {
            LED = ON;
         }
         else
         {
            LED = OFF;
         }
         /* save last ADC value */
         lastADCValue = ADCValue;      
      }   
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
   
   /* ADC configuration */
   ADCON0 = 0x80; /* right justify; Vref = Vdd; AN0; module turned off */
   ADCON1 = 0x40; /* Fosc/4 */
   ADON = 1; /* turn module on */
 
   /* interrupt settings */
   GIE = 1; /* global interrupt enable */
   PEIE = 1; /* peripheral interrupt enable */
   TMR1IF = 0; /* clear TMR1 interrupt flag */
   TMR1IE = 1; /* TMR1 interrupt enabled */
   ADIF = 0; /* clear ADC iISR flag */
   ADIE = 1; /* enable ADC ISR */
   
   /* start TMR1 and TMR 2 */
   TMR1ON = 1;

   /* initialize variables */
   lastADCValue = 0;
   ADCValue = 0;
   milliVolts = 0;

}

/* Interrupt function */
void interrupt isr(void)
{
   /* check if TMR1 interrupt enable and flag are set */
	if((TMR1IE == 1) && (TMR1IF == 1)) 
   {
      TMR1L += TMR1_LOW;
      TMR1H += TMR1_HIGH;

      ADCON0 |= 0x02; /* set GO bit to start ADC conversion */

      TMR1IF = 0;		/* clear TMR1 interrupt flag*/
   }
	else if((ADIE == 1) && (ADIF == 1))
   {
      ADCValue = (ADRESH << 8) + ADRESL;
      ADIF = 0; /* clear ADC ISR flag */
   }  	
}
  
  