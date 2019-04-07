#include<reg51.h>
void delay(unsigned int z);
void main()
{
	unsigned int seg[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80};
	unsigned char x;
//	unsigned int i;
	P1=0x00;
	while(1)
	{
		for(x=0;x<10;x++)
		{
			P1=seg[x];
			//for(i=0;i<60000;i++);
			delay(100);
		}
	}
}
void delay(unsigned int z)
{
	int k,j;
	for(k=0;k<z;k++)
	for(j=0;j<1275;j++);
}