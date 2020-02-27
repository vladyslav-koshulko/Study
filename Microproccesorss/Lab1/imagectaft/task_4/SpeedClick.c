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

char scan_buttons() // ������� ���������� ��������� � ������
{
  char t, d=0;
  DDRA=0;		   // ���� � �������� �� ���� ��� ���������� ������ � ������
  PORTD=0x80;	   // ���. ���. 1 �� ������ PD7 ��� ���������� ��������� ����������
  t=PINA;		   // ���������� �������� � ���� ������
  PORTD=0;		   // ������� �������� ���������� � ����������������� ���������
  DDRA=0xFF;	   // ��������� ����� � �� �����
  DDRG=0x01;	   // ���������� ������ �����������
  PORTG=0;	 	   // ��������� �� ������ PG0 ���. 0
  // �������������� ������, ���������� � ������ ��� �������� �������������
  if((t&0x10)==0) d=1;	
  if((t&0x20)==0) d=2;
  if((t&0x40)==0) d=3;
  if((t&0x80)==0) d=4;
  if((t&0x01)==0) d=5;
  if((t&0x02)==0) d=1;
  if((t&0x04)==0) d=1;
  if((t&0x08)==0) d=1;
  return d;	  // �������� ������������ �� ������� � ���������
}

void segments(int i, int j)
{
 PORTC=i;
 PORTA=~j;
 delay(100);
}

void main()
{
 	char cicle[4][8]={{0b00000000,0b00000000,0b00000000,0b00011000,0b00011000,0b00000000,0b00000000,0b00000000},
    				  {0b00000000,0b00000000,0b00111100,0b00100100,0b00100100,0b00111100,0b00000000,0b00000000},
                      {0b00000000,0b01111110,0b01000010,0b01000010,0b01000010,0b01000010,0b01111110,0b00000000},
                      {0b11111111,0b10000001,0b10000001,0b10000001,0b10000001,0b10000001,0b10000001,0b11111111}};
    char katod[]={0b00000001,0b00000010,0b00000100,0b00001000,0b00010000,0b00100000,0b01000000,0b10000000};
 	char seg[3]={0b00000101, 0b00011010, 0b01100000};
	int item[4]={6,7,1,2};
	char c,t,i,j,k;
	DDRA=0xFF;
    DDRC=0b10000111;
    PORTA=0;
	
    PORTC=0;
	PORTC=5;
	
	PORTC=4;
	
	PORTC=6;
	PORTC=7;
	PORTC=1;
	PORTC=2;
    
	DDRG=0b00000001;
    DDRD=0x80;
    while(1)
    {
	 	t=scan_buttons();
		if(t==0)
		{
		 continue;
		}
		else if(t==1)
		{
		 PORTC=4;
	 	 for(c=0;c<8;c++)
		 {
		 	PORTA=(1<<c);
			delay(100);
		 }
		}
		else if(t==2)
		{
		 for(c=0;c<100;c++)
		 {
		 	PORTC=0b00000001+c;
			delay(c);
		 }
		 for(c=99,i=0;c>=0,i<100;c--,i++)
		 {
		 	PORTC=0b01100100-i;
			delay(c);
		 }
		}
		else if(t==3)
		{
		 PORTC=4;
	 	 for(c=0;c<8;c++)
		 {
		 	PORTA+=0b00000001<<c;
			delay(100);
		 }
		 for(c=0;c<8;c++)
		 {
		 	PORTA+=~0b00000000<<c;
			delay(100);
		 }
		 for(c=0;c<8;c++)
		 {
		 	PORTA+=0b10000000>>c;
			delay(100);
		 }
		 for(c=0;c<8;c++)
		 {
		 	PORTA+=~0b01111111>>c;
			delay(100);
		 }
		}
		else if(t==4)
		{
		 for(i=0;i<4;i++)
  		 {
   		  for(j=0;j<3;j++)
   		  {
   		   segments(item[i],seg[j]);
   		  }
   		  PORTA=0xFF;
  		 }
  		 for(i=3;i>=0;i--)
  		 {
   		  for(j=2;j>=0;j--)
   		  {
   		   segments(item[i],seg[j]);
   		  }
   		  PORTA=0xFF;
  		 }
		}
		else if(t==5)
		{
		 for(i=0;i<4;i++)
         {
        	for(k=0;k<5;k++)
        	{
        		for(j=0;j<8;j++)
        		{
    				PORTC=5;
        			PORTA=cicle[i][j];
        			PORTC=0;
        			PORTA=~katod[j];
        			delay(2);
        		}
         	}
         }
		}
    }   
}