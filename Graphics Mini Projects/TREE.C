#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#define round(n) (int)(n+0.5)
int count = 0;
struct points
{
  int x;
  int y;
};
void plotpixel(int x, int y)
{
	putpixel(x + 320, 240 - y, 4);
}
void dda(int x1, int y1, int x2, int y2)
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
}

struct Node
{
	int data;
	int xVal;
	int yVal;
	struct Node *lchild;
	struct Node *rchild;
}*root = NULL;

struct Queue
{
	struct Node *data;
	struct Queue *next;
}*front = NULL, *rear = NULL;
void enQueue(struct Node *key)
{
	if(front == NULL)
	{
		struct Queue *t = (struct Queue *)malloc(sizeof(struct Queue));
		t -> data = key;
		t -> next = NULL;
		front = t;
		rear = t;
	}
	else
	{
		struct Queue *t = (struct Queue *)malloc(sizeof(struct Queue));
		t -> data = key;
		t -> next = NULL;
		rear -> next = t;
		rear = t;
	}

}
struct Node* deQueue()
{
	struct Node *data = NULL;
	struct Queue *p;
	if(front == NULL)
	{
		printf("Empty Queue\n");
	}
	else
	{
		if(front == rear)
		{
			data = front -> data;
			front -> next = NULL;
			free(front);
			front = NULL;
			rear = NULL;
		}
		else
		{
			data = front -> data;
			p = front;
			front = front -> next;
			free(p);
		}
	}
	return data;
}
int isEmptyQueue()
{
	if(front == NULL)
		return 1;
	else
		return 0;
}
/*void display()
{
	struct Queue *p = front;
	if(p == NULL)
	{
		cout << "Nothing to display" << endl;
	}
	else
	{
		while(p)
		{
			cout << p -> data << endl;
			p = p -> next;
		}
	}
}*/
int *a;
int rep[10][10];
struct points *p;
void createTree()
{
	int x, i = 0, j, k;
	//struct points *p;
	int xco, yco;
	struct Node *t = (struct Node *)malloc(sizeof(struct Node));
	printf("Enter no of nodes : \n");
	scanf("%d", &count);
	for(j = 0; j < count; j++)
	{
		for(k = 0; k < count; k++)
		{
			rep[j][k] = 0;
		}
	}
	a = (int *)malloc(count * sizeof(int));
	p = (struct points *)malloc(count * sizeof(struct points));
	printf("Enter the root element :\n");
	scanf("%d", &x);
	t -> data = x;
	t -> xVal = 0;
	t -> yVal = 100;
	t -> lchild = NULL;
	t -> rchild = NULL;
	root = t;
	a[i] = x;
	p[i].x = 0;
	p[i].y = 100;
	j = i;
	i = i + 1;
	//cout << "Hello" << endl;
	enQueue(root);
	//cout << "Hello2" << endl;
	while(!isEmptyQueue())
	{
		struct Node *q = deQueue();
		xco = q -> xVal;
		yco = q -> yVal;
		printf("Enter the lchild of : %d\n", q -> data);
		scanf("%d", &x);
		if(x != -1)
		{
			struct Node *t = (struct Node *)malloc(sizeof(struct Node));
			t -> data = x;
			t -> xVal = xco - 50;
			t -> yVal = yco - 50;
			t -> lchild = t -> rchild = NULL;
			q -> lchild = t;
			//count++;
			a[i] = x;
			p[i].x = xco - 50;
			p[i].y = yco - 50;
			k = i;
			rep[j][k] = 1;
			i = i + 1;
			enQueue(t);
		}
		printf("Enter the rchild of : %d\n", q -> data);
		scanf("%d", &x);
		if(x != -1)
		{
			struct Node *t = (struct Node *)malloc(sizeof(struct Node));;
			t -> data = x;
			t -> xVal = xco + 50;
			t -> yVal = yco - 50;
			t -> lchild = t -> rchild = NULL;
			q -> rchild = t;
		   //	count++;
			a[i] = x;
			p[i].x = xco + 50;
			p[i].y = yco - 50;
			k = i;
			rep[j][k] = 1;
			i = i + 1;
			enQueue(t);
		}
		j++;
	}
}
void preOrder(struct Node *p)
{
	if(p)
	{
		printf("%d\t", p -> data);
		preOrder(p -> lchild);
		preOrder(p -> rchild);
	}
}
void inOrder(struct Node *p)
{
	if(p)
	{
		inOrder(p -> lchild);
		printf("%d\t", p -> data);
		inOrder(p -> rchild);
	}
}
void postOrder(struct Node *p)
{
	if(p)
	{
		postOrder(p -> lchild);
		postOrder(p -> rchild);
		printf("%d\t", p -> data);
	}
}
/*void drawFigure()
{
} */
int main()
{
	int gd = DETECT, gm, i, m, n;
	int *s, x1, y1, x2, y2;
	char snum[5];
	initgraph(&gd, &gm, "c:\\turboc3\\bgi");
	createTree();
	cleardevice();
	s =(int *)malloc(count * sizeof(int));
	for(i = 0; i < count; i++)
	{
		itoa(a[i], snum, 10);
		outtextxy(p[i].x + 320, 240 - p[i].y, snum);
		s[i] = 0;
	}
	for(m = 0; m < count; m++)
	{
		for(n = 0; n < count; n++)
		{
			if(rep[m][n] == 1)
			{
				x1 = p[m].x;
				y1 = p[m].y;
				x2 = p[n].x;
				y2 = p[n].y;
				dda(x1, y1, x2, y2);
			}
		}
	}
	//preOrder(root);
   /*for(i = 0; i < count; i++)
   {
		printf("%d\n", a[i]);
   }
   for(i = 0; i < count; i++)
   {
		printf("%d %d\n", p[i].x, p[i].y);
   } */
	//drawFigure();
	getch();
	closegraph();
	return 0;
}
