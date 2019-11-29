#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
# define round(n) (int)(n+0.5)
void plotpixel(int a, int b)
{
	putpixel(a + 320, 240 - b, 4);
}
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
	dda(x1, y1, x2, y2);
	dda(x2, y2, x3, y3);
	dda(x1, y1, x3, y3);
}
void drawRectangle(int x1, int y1)
{
	dda(x1, y1, -x1, y1);
	dda(x1, -y1, x1, y1);
	dda(-x1, -y1, x1, -y1);
	dda(-x1, y1, -x1, -y1);
}
int dda(int x1, int y1, int x2, int y2)
{
	float xx, yy, xinc, yinc;
   //	int delx, dely, dx1, dy1,
	int i, step, dx, dy;
	dx = x2 - x1;
	dy = y2 - y1;
 /*	delx=x2-x1;
	dely=y2-y1;
		if(delx<0)
			dx1=-delx;
		else
			dx1=delx;
		if(dely<0)
			dy1=-dely;
		else
			dy1=dely;
		if(dx1>dy1)
			step=dx1;
		else
			step=dy1;
   */
	step = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	xinc = (float)dx/(float)step;
	yinc = (float)dy/(float)step;
	xx = x1;
	yy = y1;
	for(i = 0; i <= step; i++)
	{
		plotpixel(round(xx), round(yy));
		xx += xinc;
		yy += yinc;
	}
	return step;
}
void drawAxes()
{
	int i, j;
	for(i = 0; i < getmaxx(); i++)
	{
		putpixel(i, getmaxy()/2, 2);
	}
	for(j = 0; j < getmaxy(); j++)
	{
		putpixel(getmaxx()/2, j, 2);
	}
}
int main()
{
	int gd = DETECT, gm;
  //	int var1 = getmaxx()/2, var2 = getmaxy()/2;
	initgraph(&gd, &gm, "c:\\turboc3\\bgi");
	drawAxes();
	drawTriangle(50, 100, 200, 100, 125, 150);
	drawTriangle(50, -100, 200, -100, 125, -150);
	drawTriangle(-50, 100, -200, 100, -125, 150);
	drawTriangle(-50, -100, -200, -100, -125, -150);
	//rectangle(-125 + var1, 125 + var2, 125 + var1, -125 + var2);
	drawRectangle(-125, 125);
	getch();
	closegraph();
	return 0;
}