/*Write C++ program to draw man walking in the rain with an umbrella. Apply the concept of
polymorphism.*/

#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>

int main()
{
    int gd = DETECT, gm;
    int maxx, maxy, j, i;

    initgraph(&gd, &gm, NULL);
    for (i = 0; i < 500; i += 5)
    {
        line(0, 380, 640, 380); //platform

        if (i % 2 == 0)
        {
            line(25 + i, 380, 35 + i, 340); //leftleg
            line(45 + i, 380, 35 + i, 340); //right leg
            line(35 + i, 310, 25 + i, 330); //left hand
            delay(20);
        }
        else
        {
            line(35 + i, 380, 35 + i, 340);
            line(35 + i, 310, 40 + i, 330);
            delay(20);
        }

        line(35 + i, 340, 35 + i, 310); //body
        circle(35 + i, 300, 10);        //head
        line(35 + i, 310, 50 + i, 330); // hand
        line(50 + i, 330, 50 + i, 280); //umbrella stick
        line(15 + i, 280, 85 + i, 280); //umbrella right

        arc(50 + i, 280, 180, 0, 35); //umbrella body
        arc(55 + i, 330, 0, 180, 5);  //umbrella handle
    
        //rain
        maxx = getmaxx();
        maxy = getmaxy();
        for (j = 0; j < 100; j++)
        {
            outtextxy((rand()%maxx), (rand()%maxy)-130,(char*)"|");
            setcolor(WHITE);
        }

        delay(280);
        cleardevice();
    }

    getch();
}
