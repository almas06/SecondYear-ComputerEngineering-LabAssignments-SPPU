/*Write C++ program to implement Cohen Southerland line clipping algorithm.*/

#include <iostream>
#include <graphics.h>
using namespace std;

int left_ = 1;
int right_ = 2;
int bottom_ = 4;
int top_ = 3;

int checkCode(int x, int y)
{
    int code = 0;
    if (x < 0)
    {
        code = left_;
    }
    if (x > 400)
    {
        code = right_;
    }
    if (y < 0)
    {
        code = top_;
    }
    if (y > 300)
    {
        code = bottom_;
    }
    return code;
}
void CohenSutherlandClipping(int x1, int x2, int y1, int y2)
{
    int code1 = checkCode(x1, y1);
    int code2 = checkCode(x2, y2);

    if (code1 == 0 && code2 == 0)
    {
        line(x1, y1, x2, y2);
        delay(5000);
    }
    else if (code1 != 0 && code2 != 0)
    {
        if (code1 && code2)
        {
            cout << "Line invisible!!!\n";
        }
        delay(5000);
    }
    else
    {
        int code_out, x, y;
        if (code1 != 0)
            code_out = code1;
        else
            code_out = code2;

        //y = y1 + slope * (x - x1),
        //x = x1 + (1 / slope) * (y - y1)
        if (code_out && right_)
        {
            y = y1 + (y2 - y1) * (400 - x1) / (x2 - x1);
            x = 400;
        }
        else if (code_out && left_)
        {
            y = y1 + (y2 - y1) * (0 - x1) / (x2 - x1);
            x = 0;
        }
        else if (code_out & top_)
        {
            x = x1 + (x2 - x1) * (0 - y1) / (y2 - y1);
            y = 0;
        }
        else if (code_out & bottom_)
        {
            x = x1 + (x2 - x1) * (300 - y1) / (y2 - y1);
            y = 300;
        }

        if (code_out == code1)
        {
            x1 = x;
            y1 = y;
            CohenSutherlandClipping(x1, x2, y1, y2);
        }
        else
        {
            x2 = x;
            y2 = y;
            CohenSutherlandClipping(x1, x2, y1, y2);
        }
        delay(5000);
    }
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    //Clipping Window
    line(0, 0, 400, 0);
    line(0, 0, 0, 300);
    line(0, 300, 400, 300);
    line(400, 0, 400, 300);

    int x1, x2, y1, y2;
    cout << "Enter Coordinates of line\n";
    cout << "x1 : ";
    cin >> x1;
    cout << "x2 : ";
    cin >> x2;
    cout << "y1 : ";
    cin >> y1;
    cout << "y2 : ";
    cin >> y2;

    CohenSutherlandClipping(x1, x2, y1, y2);
}
