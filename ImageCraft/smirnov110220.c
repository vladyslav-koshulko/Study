#include "iom128v.h"
#include "macros.h"
void delay(int t)
{
	int c2;
    int c1;
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
	char t;
    char seg[10]={0b01110111,0b01100000,0b00111110,0b01111010,0b01101001,0b01011011,0b01011111,0b01110000,0b01111111,0b01111011};
    char segment[6]={0b00010000,0b00100000,0b01000000,0b00000010,0b00000100,0b00000001};
    char A[8][4]={{0,0,0,0},{0,0,0,0b01111010},{0,0,0b01111010,0b01111010},{0,0b01111010,0b01111010,0b00111110},{0b01111010,0b01111010,0b00111110,0b01100000},{0b01111010,0b00111110,0b01100000,0},{0b00111110,0b01100000,0,0},{0b01100000,0,0,0}};
    int cnt;
	DDRA=0b11111111;
    DDRC=0b10000111;
    DDRG=0b00000001;
    while(1)
    {
    	/*for(t=0;t<8;t++)
        {
        	PORTC=6;
            PORTA=~A[t][0];
            PORTC=7;
            PORTA=~A[t][1];
            PORTC=1;
            PORTA=~A[t][2];
            PORTC=2;
            PORTA=~A[t][3];
        	delay(500);
         }*/
    	/*for(t=0;t<6;t++)
        {
        	PORTC=6;
            PORTA=~segment[t];
            PORTC=7;
            PORTA=~segment[t];
            PORTC=1;
            PORTA=~segment[t];
            PORTC=2;
            PORTA=~segment[t];
            delay(1000);
         }*/
    	/*for(cnt=0;cnt<=9999;cnt++)
        {
        	PORTC=6;
            PORTA=~seg[cnt/1000];
            PORTC=7;
            PORTA=~seg[(cnt%1000)/100];
            PORTC=1;
            PORTA=~seg[(cnt%100)/10];
            PORTC=2;
            PORTA=~seg[cnt%10];
            delay(20);
    	}*/
    	/*PORTC=6;
        PORTA=~0b01111010;
        PORTC=7;
        PORTA=~0b01111010;
        PORTC=1;
        PORTA=~0b00111110;
        PORTC=2;
        PORTA=~0b01100000;
        delay(100);*/
    	/*PORTA=0b00000001;
        delay(1000);
        PORTA=0b00000010;
        delay(1000);
        PORTA=0b00001000;
        delay(1000);*/
        /*for(t=0;t<255;t++)
        {
        	PORTA=0b00000001;
        	delay(255-t);
            PORTA=0b00001000;
            delay(t);
        }
        for(t=0;t<255;t++)
        {
        	PORTA=0b00001000;
            delay(255-t);
            PORTA=0b00000010;
            delay(t);
        }
        for(t=0;t<255;t++)
        {
        	PORTA=0b00000010;
            delay(255-t);
            PORTA=0b00000001;
            delay(t);
        }*/
        /*PORTA=0b00001010;
        delay(1000);
        PORTA=0b00001011;
        delay(1000);*/
        /*for(t=0;t<255;t++)
        {
        	PORTA=0;
            delay(t);
            PORTA=0b11111111;
            delay(255-t);
        }
        for(;t>0;t--)
        {
        	PORTA=0;
            delay(t);
            PORTA=0b11111111;
            delay(255-t);
        }*/
    }
}