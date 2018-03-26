#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<graphics.h>
int main()
{
	int gd=DETECT,gm,error;
	int x0,y0,k,x1,y1,p0;
	printf("give the starting points\n");
	scanf("%d %d",&x0,&y0);
	printf("give ends points\n");
	scanf("%d %d",&x1,&y1);

	// for initializing the graphic driver
	initgraph(&gd,&gm,"C:\\turboc3\\bgi");
	
	x1-=x0;
	y1-=y0;
	p0=2*y1-x1;	// decision parameter
	
	printf("\tdecision parameter%d ",p0);
	putpixel(x0,y0,10);
	for(k=0;k<x1;k++)
	{
		if(p0<0)
		{
		  x0++;
		  p0+=2*y1;
		  putpixel(x0,y0,10);
		  delay(50);
		}
		else
		{
		  x0++;
		  y0++;
		  p0+=2*y1-2*x1;
		  putpixel(x0,y0,10);
		  delay(50);
		}
	}
	getch();
	closegraph();
	return 0;
}
