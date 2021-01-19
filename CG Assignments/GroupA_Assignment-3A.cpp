
/*a) Write C++ program to draw the following pattern. Use DDA line and Bresenham‘s circle
drawing algorithm. Apply the concept of encapsulation.*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>

using namespace std;

class DDA_Bresenham
{
public:
    int x1, x2, y1, y2, dx, dy, steps;
    float xInc, yInc, newx, newy;
    int x0 = 0, y0 = 0, R, P0, x, y;

    void DrawLine(int x1, int y1, int x2, int y2)
    {
        dx = x2 - x1;
        dy = y2 - y1;

        int steps = max(abs(dx), abs(dy));

        xInc = dx / float(steps);
        yInc = dy / float(steps);

        newx = x1;
        newy = y1;

        for (int i = 0; i <= steps; i++)
        {
            putpixel(newx, newy, BLUE);
            newx += xInc;
            newy += yInc;
            delay(1);
        }
        delay(2000);
    }

    void DrawCircle(int xc, int yc, int R)
    {
        x = 0;
        y = R;
        P0 = 3 - 2 * R; //Initial decision parameter
        for (x = 0; x <= y; x++)
        {
            if (P0 < 0)
            {
                P0 = P0 + 4 * (x) + 6;
            }

            else
            {
                y--;
                P0 = P0 + 4 * (x - y) + 10;
            }

            putpixel(xc + x, yc + y, RED);
            putpixel(xc - x, yc + y, GREEN);
            putpixel(xc + x, yc - y, BLUE);
            putpixel(xc - x, yc - y, YELLOW);
            putpixel(xc + y, yc + x, LIGHTBLUE);
            putpixel(xc - y, yc + x, WHITE);
            putpixel(xc + y, yc - x, BROWN);
            putpixel(xc - y, yc - x, BLUE);
            delay(5);
        }
        delay(3000);
    }
    void drawTriangle(int xc, int yc, float R)
    {
        float Xa = xc;
        float Ya = yc - R;
        float Xb = xc - 0.8660 * R;
        float Yb = yc + (R / 2);
        float Xc = xc + 0.8660 * R;
        float Yc = yc + (R / 2);
        DrawLine(Xa, Ya, Xc, Yc);
        DrawLine(Xc, Yc, Xb, Yb);
        DrawLine(Xb, Yb, Xa, Ya);
        delay(10000);
    }
};

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    DDA_Bresenham d;
    float radius;
    int xcenter, ycenter;
    cout << "Enter radius : ";
    cin >> radius;
    cout << "Enter xcenter and ycenter\n";
    cout << "xc = ";
    cin >> xcenter;
    cout << "yc = ";
    cin >> ycenter;
    d.DrawCircle(xcenter, ycenter, radius);     //outer circle
    d.DrawCircle(xcenter, ycenter, radius / 2); //inner circle
    d.drawTriangle(xcenter, ycenter, radius);
}
