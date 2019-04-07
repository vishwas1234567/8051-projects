#include<reg51.h>
sbit mt1=P0^0;
sbit mt2=P0^1;
sbit red=P0^2;
sbit green=P0^3;
sbit buzzer=P0^4;
sbit sw1=P0^5;
void TX(unsigned char x)
{
	SBUF=x;
	while(TI==0);
	TI=0;
}
unsigned char RX()
{
	unsigned char y;
	while (RI==0)
	y=SBUF;
	RI=0;
	return y;
}
void string(unsigned char *s)
{
	while (*s!=0)
	{
		TX(*s);
		s++;
	
	}
}
void main()
{
unsigned char a;
SCON=0x50;
TMOD=0x20;
TR1=1;
TH1=0xFD;
while(1)
{
	a=RX();
	if(a=='a')
	{
		mt1=1;
		green=1;
		mt2=1;
		red=0;
		buzzer=0;
	}
	sw1=1;
	while(1)
	{
	if (sw1==0)
		{
			buzzer=1;
			red=1;
			mt1=0;
			mt2=0;
		}
	
	else
	{
		red=0;
		green=0;
		
	}
	TX(a);
	string("GOUTHAM\n HARSHITA\n VISHWAS\n");
	while(1);
}
	}
}
