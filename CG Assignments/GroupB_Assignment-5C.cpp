/*a) Write C++ program to generate snowflake using concept of fractals.
OR
b) Write C++ program to generate Hilbert curve using concept of fractals.
OR
c) Write C++ program to generate fractal patterns by using Koch curves.*/

#include <iostream>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>
using namespace std;

void KochCurve(int x1, int y1, int x2, int y2, int it)
{
    float angle = 60 * M_PI / 180;
    int x3 = (2 * x1 + x2) / 3;
    int y3 = (2 * y1 + y2) / 3;

    int x4 = (x1 + 2 * x2) / 3;
    int y4 = (y1 + 2 * y2) / 3;

    int x = x3 + (x4 - x3) * cos(angle) + (y4 - y3) * sin(angle);
    int y = y3 - (x4 - x3) * sin(angle) + (y4 - y3) * cos(angle);

    if (it > 0)
    {
        KochCurve(x1, y1, x3, y3, it - 1);
        KochCurve(x3, y3, x, y, it - 1);
        KochCurve(x, y, x4, y4, it - 1);
        KochCurve(x4, y4, x2, y2, it - 1);
    }
    else
    {

        line(x1, y1, x3, y3);
        delay(30);
        line(x3, y3, x, y);
        delay(30);
        line(x, y, x4, y4);
        delay(30);
        line(x4, y4, x2, y2);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    int x1, y1,x2, y2 ,it;
    cout<<"------------------------------\n";
    cout<<"    GroupB Assignment-5\n";
    cout<<"------------------------------\n";
    cout<<"Enter initial values of x and y coordinates\n";
    cout<<"x1 : ";
    cin>>x1;
    cout<<"x2 : ";
    cin>>x2;
    cout<<"y1 : ";
    cin>>y1;
    cout<<"y2 : ";
    cin>>y2;
    cout<<"Enter number of iteraions : ";
    cin>>it;
    KochCurve(x1, y1, x2, y2, it);
    getch();
    return 0;
}
