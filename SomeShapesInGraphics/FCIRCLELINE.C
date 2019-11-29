#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define round(n) (int)(n + 0.5)
int sign(int n)
{
	if(n > 0)
		return 1;
	else if(n == 0)
		return 0;
	else
		return -1;
}
void drawXy()
{
	int i;
	for(i = 0; i < getmaxx(); i++)
	{
		putpixel(i, getmaxy() / 2, 4);
		delay(10);
	}
	for(i = 0; i < getmaxy(); i++)
	{
		putpixel(getmaxx() / 2, i, 4);
		delay(10);
	}
}
void plotPixel(int x, int y)
{
	putpixel(x + 320, 240 - y, 8);
}
void dda(int x1, int y1, int x2, int y2)
{
	int dx, dy, step;
	float xx, yy, xinc, yinc;
	dx = x2 - x1;
	dy = y2 - y1;
	step = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	xinc = (float)(dx) / (float)(step);
	yinc = (float)(dy) / (float)(step);
	xx = x1;
	yy = y1;
	while(step)
	{
		plotPixel(round(xx), round(yy));
		xx = xx + xinc;
		yy = yy + yinc;
		step--;
	}
}
void bresenham(int x1, int y1, int x2, int y2)
{
	int delx, dely, dx, dy, p, s1, s2, temp, interchange, i, xx, yy;
   /*	delx = x2 - x1;
	dely = y2 - y1;
	if(delx < 0)
		dx = -delx;
	else
		dx = delx;
	if(dely < 0)
		dy = -dely;
	else
		dy = dely;  */
	if(x1 == x2)
	{
		for(i = y1; i <= y2; i++)
		{
			plotPixel(x1, i);
		}
	}
		dx = abs(x2 - x1);
		dy = abs(y2 - y1);
		s1 = sign(x2 - x1);
		s2 = sign(y2 - y1);
		p = 2 * dy - dx;
		xx = x1;
		yy = y1;
		if(dx < dy)
		{
			temp = dx;
			dx = dy;
			dy = temp;
			interchange = 1;
		}
		else
			interchange = 0;
		for(i = 0; i <= dx; i++)
		{
			plotPixel(xx, yy);
			while(p >= 0)
			{
				if(interchange == 1)
					xx = xx + s1;
				else
					yy = yy + s2;
				p = p - 2 * dx;
			}
			if(interchange == 1)
				yy = yy + s2;
			else
				xx = xx + s1;
			p = p + 2 * dy;
		}

}
void bresCircle(int x, int y, int r)
{
	int xk = 0;
	int yk = r;
	double d, p;
	while(yk > 0)
	{
		d = ((xk + 1) * (xk + 1) + (yk - 1) * (yk - 1)) - r * r;
		plotPixel(xk + x, yk + y);
		plotPixel(xk + x, -yk + y);
		plotPixel(-xk + x, yk + y);
		plotPixel(-xk + x, -yk + y);
		if(d < 0)
		{
			p = ((xk + 1) * (xk + 1) + (yk - 0.5) * (yk - 0.5)) - r * r;
			if(p < 0)
			{
				xk += 1;
			}
			else
			{
				xk += 1;
				yk -= 1;
			}
		}
		else
		{
			p = ((xk + 0.5) * (xk + 0.5) + (yk - 1) * (yk - 1)) - r * r;
			if(p < 0)
			{
				xk += 1;
				yk -= 1;
			}
			else
			{
				yk -= 1;
			}
		}
	}
}
int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "c:\\turboc3\\bgi");
	drawXy();
	dda(-50, 50, 50, 50);
	dda(-50, 50, -50, -50);
	dda(50, 50, 50, -50);
	dda(-50, -50, 50, -50);
	dda(-50, 50, 50, -50);
	dda(-50, -50, 50, 50);
	bresenham(-100, 100, 100, 100);
	bresenham(-100, 100, -100, -100);
	bresenham(100, 100, 100, -100);
	bresenham(-100, -100, 100, -100);
	bresenham(-100, 100, 100, -100);
	bresenham(-100, -100, 100, 100);
	bresCircle(100, 100, 50);
	bresCircle(-100, 100, 50);
	bresCircle(100, -100, 50);
	bresCircle(-100, -100, 50);
	getch();
	closegraph();
	return 0;
}