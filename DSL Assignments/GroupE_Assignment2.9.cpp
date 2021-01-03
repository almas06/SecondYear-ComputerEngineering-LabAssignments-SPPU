/*Queues are frequently used in computer programming, and a typical example is the
creation of a job queue by an operating system. If the operating system does not use
priorities, then the jobs are processed in the order they enter the system. Write C++
program for simulating job queue. Write functions to add job and delete job from queue.*/

#include <iostream>
#define max 100
using namespace std;

struct queue
{
    string name;
    string profile;
};
class JobQueue
{
public:
    int front = -1, rear = -1;
    queue obj[max];
    void AddJob();
    void DeleteJob();
    void Display();
};
void JobQueue ::AddJob()
{
    if ((rear + 1) % max == front)
    {
        cout << "Job queue is full!!!\n";
    }
    else
    {
        if (rear == -1 && front == -1)
        {
            front=0;
            rear++;
            cout << "Enter name of person : ";
            cin >> obj[rear].name;
            cout << "Enter job profile : ";
            cin >> obj[rear].profile;
        }
        else
        {
            rear = (rear + 1) % max;
            cout << "Enter name of person : ";
            cin >> obj[rear].name;
            cout << "Enter job profile : ";
            cin >> obj[rear].profile;
        }
    }
}
void JobQueue ::DeleteJob()
{
    if (rear == -1 && front == -1)
    {
        cout << "\nJob Queue is Empty!!!\n\n";
    }
    else
    {
        string n = obj[front].name;
        string p = obj[front].profile;
        cout << "Job profile of " << n << " deleted successfully!!!\n";
        front++;
    }
}
void JobQueue ::Display()
{
    cout << "-------------------------------\n";
    cout << "Name\t\t"
         << "Profile"
         << "\n";
    cout << "-------------------------------\n";
    for (int i = front; i <= rear; i++)
    {

        cout << obj[i].name << "\t\t" << obj[i].profile << "\n";
    }
    cout << "-------------------------------\n";
}
int main()
{
    JobQueue j;
    int ch;
    do
    {
        cout << "\t1.Add Job\n";
        cout << "\t2.Delete Job\n";
        cout << "\t3.Display\n";
        cout << "\t4.Exit\n";
        cout << "Enter choice : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            j.AddJob();
            break;

        case 2:
            j.DeleteJob();
            break;

        case 3:
            j.Display();
            break;

        case 4:
            exit(0);
            break;

        default:
            cout << "Enter valid choice!!\n";
        }
    } while (ch != 4);
}
