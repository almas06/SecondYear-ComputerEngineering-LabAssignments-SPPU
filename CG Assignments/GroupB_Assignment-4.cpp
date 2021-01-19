/*a) Write C++ program to draw 2-D object and perform following basic transformations, Scaling
b) Translation c) Rotation. Apply the concept of operator overloading.*/
#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

void Display(int n, float new_ans[][3])
{
    float maxx, maxy;
    int i=0;
    maxx = getmaxx();
    maxy = getmaxy();
    maxx = maxx / 2;
    maxy = maxy / 2;

    //draw polygon
    while (i < n - 1)
    {
        line(maxx + new_ans[i][0], maxy - new_ans[i][1], maxx + new_ans[i + 1][0], maxy - new_ans[i + 1][1]);
        i++;
    }
    i = n - 1;
    line(maxx + new_ans[i][0], maxy - new_ans[i][1], maxx + new_ans[0][0], maxy - new_ans[0][1]);
    delay(1000);

    //draw X-Y axis
    setcolor(WHITE);
    line(0, maxy, maxx * 2, maxy);
    line(maxx, 0, maxx, maxy * 2);
}

void Multiply(int n, float trans[][3], float orig_mat[][3], float ans[][3])
{
    int i, j, k;
    for (i = 0; i < n; i++)
        for (j = 0; j < 3; j++)
            ans[i][j] = 0;

    for (i = 0; i < n; i++)
        for (j = 0; j < 3; j++)
            for (k = 0; k < 3; k++)
                ans[i][j] += (orig_mat[i][k] * trans[k][j]);
}

void Translation(int n, float orig_mat[][3], float tx, float ty)
{
    float trans[10][3], ans[10][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            trans[i][j] = 0;
    trans[0][0] = 1;
    trans[1][1] = 1;
    trans[2][2] = 1;
    trans[2][0] = tx;
    trans[2][1] = ty;

    Multiply(n, trans, orig_mat, ans);
    setcolor(YELLOW);
    Display(n, ans);
}

void Scaling(int n, float orig_mat[][3], float sx, float sy)
{
    float scal_mat[10][3], ans[10][3];
    int i = 0, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            scal_mat[i][j] = 0;
    scal_mat[0][0] = sx;
    scal_mat[1][1] = sy;
    scal_mat[2][2] = 1;
    Multiply(n, scal_mat, orig_mat, ans);
    setcolor(YELLOW);
    Display(n, ans);
}
void Rotation(int n, float orig_mat[][3], float angle)
{
    int i = 0, j;
    float rotat_mat[10][3], xp, yp, ans[10][3];
    xp = orig_mat[0][0];
    yp = orig_mat[0][1];

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            rotat_mat[i][j] = 0;

    float A = (angle * 3.14) / 180;
    rotat_mat[0][0] = rotat_mat[1][1] = cos(A);
    rotat_mat[0][1] = sin(A); //anticlockwise
    rotat_mat[1][0] = -sin(A);
    rotat_mat[2][0] = (-xp * cos(A)) + (yp * sin(A)) + xp;
    rotat_mat[2][1] = (-xp * sin(A)) - (yp * cos(A)) + yp;
    rotat_mat[2][2] = 1;

    Multiply(n, rotat_mat, orig_mat, ans);
    setcolor(YELLOW);
    Display(n, ans);
}

int main()
{
    int i, ch, n, gd, gm;
    gd = DETECT;
    float orig_mat[10][3], tx, ty, sx, sy, angle;
    initgraph(&gd, &gm, NULL);
    cout << "\nEnter the number of vertices: ";
    cin >> n;

    for (i = 0; i < n; i++)
    {
        cout << "Enter the co-ordinates of vertex " << i + 1 << ":";
        cin >> orig_mat[i][0] >> orig_mat[i][1];
        orig_mat[i][2] = 1;
    }

    do
    {
        cout << "\n-------------------------\n";
        cout << "  Group B-Assignment-4\n";
        cout << "  2-D Transformations\n";
        cout << "\n-------------------------\n";
        cout << "\t1.Translation\n\t2.Scaling\n\t3.Rotation\n\t4.Exit\n";
        cout << "Enter choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nEnter translation factors tx and ty:";
            cin >> tx >> ty;
            cleardevice();
            setcolor(CYAN);
            Display(n, orig_mat);
            Translation(n, orig_mat, tx, ty);
            break;

        case 2:
            cout << "\nEnter the scaling factors sx and sy:";
            cin >> sx >> sy;
            cleardevice();
            setcolor(CYAN);
            Display(n, orig_mat);
            Scaling(n, orig_mat, sx, sy);
            break;

        case 3:
            cout << "\nEnter the angle for rotation: ";
            cin >> angle;
            cleardevice();
            setcolor(CYAN);
            Display(n, orig_mat);
            Rotation(n, orig_mat, angle);
            break;

        case 4:
            exit(0);
            break;

        default:
            cout << "\nEnter valid choice !";
            break;
        }

    } while (ch != 4);
}
