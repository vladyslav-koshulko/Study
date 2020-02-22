#include "iom128v.h"
#include "macros.h"
void delay(int t)
{
	int c1,c2;
	for(c1=0;c1<t;c1++)
    {
    	for(c2=0;c2<970;c2++)
        {
        	NOP();
        }
    }
}
void main()
{
 	char c;
	DDRC=0b11111111;
    while(1)
    {
	 	for(c=0;c<100;c++)
		{
		 	PORTC=0b00000001+c;
			delay(50);
		}
		for(c=0;c<100;c++)
		{
		 	PORTC=0b01100100-c;
			delay(50);
		}
    }
}