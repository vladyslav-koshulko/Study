#include "iom128v.h"
#include "macros.h"

void delay(int ms)
{
 int c1, c2;
 for(c1=0;c1<ms;c1++)
  for(c2=0;c2<970;c2++) NOP();
}

void segments(int i, int j)
{
 PORTC=i;
 PORTA=~j;
}

void main()
{
 char const zero=0b00000000;
 char seg[24]={0b00000000,0b00000000,0b00000000,0b00000000,0b01110111, 0b01100000, 0b00111110, 0b01111010, 0b01101001, 0b01011011, 0b01011111, 0b01110000,	0b01111111, 0b01111011, 0b01111101, 0b01001111,	0b00010111, 0b01101110, 0b00011111, 0b00011101,0b00000000,0b00000000,0b00000000,0b00000000};
 char idecator[4]={6,7,1,2};
 char x,y,z;
 DDRC=0b10000111;    
 DDRA=0xFF;		   
 DDRG=0x01;		   
 PORTG=0;	 	   
 PORTA=0;		   
 PORTC=0;		   
 PORTC=5;		   
 while(1)
 {
  for(y=0;y<20;y++)
  {
   for(x=0;x<4;x++)
   {
   	PORTC=idecator[x];
	PORTA=~seg[y+x];
   }
   delay(200);
  }
 }
}
