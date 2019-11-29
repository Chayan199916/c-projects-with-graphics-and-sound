
#include<stdio.h>
#include<graphics.h>
#include<dos.h>
#define HEIGHT getmaxx()
#define WIDTH getmaxy()
int s = 10;
int isContinue=1,d=3,del=500;

void ChangeOption()
{
   switch(getch())
   {
	case 'a'://wind to left
	case 'A':
	d=-5;
	s = 20;
	break;

	case 'd'://wind to right
	case 'D':
	d=5;
	s = 20;
	break;

	case 's'://no wind
	case 'S':
	d=0;
	s = 20;
	break;

	case 'w'://increase rain speed
	case 'W':
	if(del!=100)
		del-=200;
	if(s != 100)
		s += 10;
	break;

	case 'X'://decrease rain speed
	case 'x':
	if(del!=1000)
		del+=200;
	if(s != 20)
		s -= 10;
	break;

	case ' '://stop raining
	isContinue=0;
	break;
   }
}

void main()
{
  int gd=DETECT,gm,xr,yr,i;
  initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
  do
  {
	textcolor(0);
	printf("CHANGE WIND DIRECTION:");
	printf(" S(s): No wind  A(a) : right - left   D(d): left - right\n");
	printf("CHANGE SPEED:  ");
	printf("W(w): Speed Up  X(x): Speed Down Space: Stop Rain");
	for(i=10;i<300;i++)
	{
		xr=rand()%640;
		yr=rand()%345;
		line(xr,yr,xr+d,yr+5);
	}
	sound(s);
	delay(del);
	clrscr();
	cleardevice();
	if(kbhit())
		ChangeOption();
  }while(isContinue);
  nosound();
}


