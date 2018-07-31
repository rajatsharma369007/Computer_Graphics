// this is program to draw a circle using midpoint circle algorithm
// Author: Rajat Sharma
// Date: oct, 2017

#include<stdio.h>
#include<graphics.h>
 
void drawcircle(int x0, int y0, int radius)
{
    int x = radius;
    int y = 0;
    int p = 0;

    while (x >= y)
    {
    putpixel(x0 + x, y0 + y, 7);
    delay(10);
    putpixel(x0 + y, y0 + x, 7);
    delay(10);
    putpixel(x0 - y, y0 + x, 7);
    delay(10);
    putpixel(x0 - x, y0 + y, 7);
    delay(10);
    putpixel(x0 - x, y0 - y, 7);
    delay(10);
    putpixel(x0 - y, y0 - x, 7);
    delay(10);
    putpixel(x0 + y, y0 - x, 7);
    delay(10);
    putpixel(x0 + x, y0 - y, 7);
    delay(10);
    if (p <= 0)
    {
		y += 1;
		p += 2*y + 1;
    }

    if (p > 0)
    {
		x -= 1;
		p -= 2*x + 1;
    }
    }
}

int main()
{
    int gdriver=DETECT, gmode, x, y, r;
    initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");

    printf("Enter radius of circle: ");
    scanf("%d", &r);

    printf("Enter co-ordinates of center(x and y): ");
    scanf("%d%d", &x, &y);
    drawcircle(x, y, r);
    getch();
    closegraph();
    return 0;
}
