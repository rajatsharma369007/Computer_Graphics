// this is a program to show different transformation like scaling, reflection, rotation, translation
// Author: Rajat Sharma
// Date: Nov, 2017

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

# define absx(x) x+320
# define absy(y) 240-y

int xarray[10],yarray[10],n_o_v,i;

void coordinates();
void draw();

void main()
{
    int gd=DETECT,gm;
    int ang,c,x1,y1;
    float sx,sy;
    int option,i,tx,ty;
    int x,y;
    char str[60];

    clrscr();
    initgraph(&gd,&gm,"C:\\TurboC3\\bgi");
    coordinates();
    printf("Enter the no. of vertices : ");
    scanf("%d",&n_o_v);

    for(i=0;i<n_o_v;i++)
    {
    printf("Enter the x,y of vertex %d : ",i+1 );
	scanf("%d%d",&xarray[i],&yarray[i]);
    }

    for(i=0;i<n_o_v;i++)
    {
	xarray[i]=absx(xarray[i]);
	yarray[i]=absy(yarray[i]);
    }

    xarray[i]=xarray[0];
	yarray[i]=yarray[0];

    draw();

    printf("\nPress Any Key To Continue...");
    getch();
    closegraph();
    do
    {
	clrscr();
	printf("\n\t\tTransformation Menu\n");
	printf("\n1.Translation\n2.Rotation\n3.Scaling\n4.Reflection\n5.Exit");
	printf("\n\nenter your option : ");
	scanf("%d",&option);
	switch(option)
	{
	    case 1:
		clrscr();
		initgraph(&gd,&gm,"c:\\turboc3\\bgi");
		coordinates();
		draw();
		printf("\nEnter translation values tx,ty : ");
		scanf("%d%d",&tx,&ty);
		for(i=0;i<n_o_v;i++)
		{
		    xarray[i]+=tx;
		    yarray[i]-=ty;
		}
		xarray[i]=xarray[0];
		yarray[i]=yarray[0];
		setcolor(RED);
		draw();
		getch();
		closegraph();
		break;

        case 2:
		clrscr();
		initgraph(&gd,&gm,"c:\\turboc3\\bgi");
		coordinates();
		draw();
		printf("\nEnter rotation  angle in degrees : ");
		scanf("%d",&ang);
		for(i=0;i<n_o_v;i++)
		{
		    int temp= xarray[i]-320;
		    xarray[i]=320+((xarray[i]-320)*cos(ang*0.01744)-(240-yarray[i])*sin(ang*0.01744));
		    yarray[i]=240-((240-yarray[i])*cos(ang*0.01744)+(temp)*sin(ang*0.01744));
		}
		xarray[i]=xarray[0];
		yarray[i]=yarray[0];
		setcolor(RED);
		draw();
		getch();
		closegraph();
		break;

	    case 3:
		clrscr();
		initgraph(&gd,&gm,"c:\\turboc3\\bgi");
		coordinates();
		draw();
		printf("\nEnter scaling values sx,sy : ");
		scanf("%f%f",&sx,&sy);
		for(i=1;i<n_o_v;i++)
		{
		    xarray[i]=xarray[i]*sx+xarray[0]*(1-sx);
		    yarray[i]=yarray[i]*sy+yarray[0]*(1-sy);
		}
		xarray[i]=xarray[0];
		yarray[i]=yarray[0];
		setcolor(RED);
		draw();
		getch();
		closegraph();
		break;
	    case 4:
		clrscr();
		initgraph(&gd,&gm,"c:\\turboc3\\bgi");
		coordinates();
		draw();
		printf("\n1.Y-axis\n2.X-axis\n");
		scanf("%d",&option);
		switch(option)
		{
		    case 1:
			for(i=0;i<n_o_v;i++)
			{
			    x1=xarray[i];
			    y1=yarray[i];
			    xarray[i]=320-(x1-320);
			    yarray[i]=y1;
			}
			xarray[i]=xarray[0];
            yarray[i]=yarray[0];
			setcolor(RED);
			draw();
			getch();
			break;
		    case 2:
			for(i=0;i<n_o_v;i++)
			{
			    x1=xarray[i];
			    y1=yarray[i];
			    xarray[i]=x1;
			    yarray[i]=240-(y1-240);
			}
			xarray[i]=xarray[0];
            yarray[i]=yarray[0];
			setcolor(RED);
			draw();
			getch();
			break;

		}
		closegraph();
		break;
	    case 5:
		exit(0);

		default:
            printf("\nchoose correct option\n");

     	      }
    }while(1);

}

void coordinates()
{
  line(320,0,320,640);
  line(0,240,640,240);
}

void draw()
{
    for(i=0;i<n_o_v;i++)
    {
	line(xarray[i],yarray[i],xarray[i+1],yarray[i+1]);
    }
}
