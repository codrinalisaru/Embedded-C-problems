// aprinde ledul 1 (varianta 1)
# include "pic.h"
void main()
{
	// setez portul C sa fie de iesire OUT
	TRISC = 0;
	// setez ultimul bit pe 1
	PORTC=1;
}
