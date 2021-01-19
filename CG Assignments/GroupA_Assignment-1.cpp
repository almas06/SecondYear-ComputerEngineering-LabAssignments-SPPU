/*Write C++ program to draw a concave polygon and fill it with desired color using scan fill
algorithm. Apply the concept of inheritance.*/

#include <iostream>
#include <graphics.h>
#include <stdlib.h>
using namespace std;

class Point
{
public:
    int x, y;
};

class ScanlineFill
{
private:
    Point obj[20];
    int intersection[20], x, y;
    int v, xmin, ymin, xmax, ymax;

public:
    int c;
    void AcceptVertices();
    void Calc_MaxMin();
    void Display();
    void IntersectionPoints(float);
    void Sort(int);
};

void ScanlineFill::AcceptVertices()
{
    int i;
    cout << "\n\t SCAN_FILL ALGORITHM";
    cout << "\n Enter the no of vertices of polygon:";
    cin >> v;
    if (v > 2)
    {
        for (i = 0; i < v; i++) //ACCEPT THE VERTICES
        {
            cout << "\nEnter the co-ordinate no.- " << i + 1 << " : ";
            cout << "\n\tx" << (i + 1) << "=";
            cin >> obj[i].x;
            cout << "\n\ty" << (i + 1) << "=";
            cin >> obj[i].y;
        }
        obj[i].x = obj[0].x;
        obj[i].y = obj[0].y;
        xmin = xmax = obj[0].x;
        ymin = ymax = obj[0].y;
    }
    else
        cout << "\n Enter valid no. of vertices.";
}

//Function for finding max and min
void ScanlineFill::Calc_MaxMin()
{
    for (int i = 0; i < v; i++)
    {
        if (xmin > obj[i].x)
            xmin = obj[i].x;
        if (xmax < obj[i].x)
            xmax = obj[i].x;
        if (ymin > obj[i].y)
            ymin = obj[i].y;
        if (ymax < obj[i].y)
            ymax = obj[i].y;
    }
}

//Function for finding intersection of two points
void ScanlineFill::IntersectionPoints(float z)
{
    int x1, x2, y1, y2, temp;
    c = 0;
    for (int i = 0; i < v; i++)
    {
        x1 = obj[i].x;
        y1 = obj[i].y;
        x2 = obj[i + 1].x;
        y2 = obj[i + 1].y;
        if (y2 < y1)
        {
            temp = x1;
            x1 = x2;
            x2 = temp;
            temp = y1;
            y1 = y2;
            y2 = temp;
        }
        if (z <= y2 && z >= y1)
        {
            if ((y1 - y2) == 0)
                x = x1;
            else // used to make changes in x. so that we can fill our polygon after cerain distance
            {
                x = ((x2 - x1) * (z - y1)) / (y2 - y1);
                x = x + x1;
            }
            if (x <= xmax && x >= xmin)
                intersection[c++] = x;
        }
    }
}

void ScanlineFill::Sort(int z) //SORT FUNCTION
{
    int temp, j, i;

    for (i = 0; i < v; i++)
    {
        line(obj[i].x, obj[i].y, obj[i + 1].x, obj[i + 1].y); // used to make hollow outlines of a polygon
    }
    delay(100);
    for (i = 0; i < c; i += 2)
    {
        line(intersection[i], z, intersection[i + 1], z); // Used to fill the polygon ....
        delay(300);
    }
}
void ScanlineFill::Display()
{
    int ch1;
    char ch = 'y';
    float s, s2;
    do
    {
        cout << "\n\nMENU:";
        cout << "\n\n\t1 . Scan line Fill ";
        cout << "\n\n\t2 . Exit ";
        cout << "\n\nEnter your choice:";
        cin >> ch1;
        switch (ch1)
        {
        case 1:
            s = ymin + 0.01;
            delay(100);
            cleardevice();
            while (s <= ymax)
            {
                IntersectionPoints(s);
                Sort(s);
                s++;
            }
            break;
        case 2:
            exit(0);
        }

    } while (ch1 != 2);
}
int main()
{
    int gd = DETECT, gm, cl;
    initgraph(&gd, &gm, NULL);

    ScanlineFill x;
    x.AcceptVertices();
    x.Calc_MaxMin();

    cout << "\n\tEnter the colour u want:(0-15)->"; //Selecting colour
    cin >> cl;
    setcolor(cl);

    x.Display();
}
