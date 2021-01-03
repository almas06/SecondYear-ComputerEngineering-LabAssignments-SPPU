/*A double-ended queue (deque) is a linear list in which additions and deletions may be
made at either end. Obtain a data representation mapping a deque into a one-
dimensional array. Write C++ program to simulate deque with functions to add and
delete elements from either end of the deque.*/

#include <iostream>
using namespace std;
#define max 10

class Dequeue
{
public:
    string rollno[max];
    int rear = -1, front = -1;
    void InputRoll();
    void AddRear();
    void AddFront();
    void DeleteRear();
    void DeleteFront();
    void Display();
};
void Dequeue ::Display()
{
    cout << "-----------------\n";
    cout << "  PRN List\n";
    cout << "------------------\n";
    for (int i = 0; i < max; i++)
    {

        cout << rollno[i] << endl;
    }
    cout << "-------------------\n";
}
void Dequeue ::AddFront()
{
    if ((rear + 1) % max == front)
    {
        cout << "Queue is full!!!\n";
    }
    else
    {
        if (rear == -1 && front == -1)
        {
            front++;
            rear = 0;
            cout << "Enter rollno of student : ";
            cin >> rollno[front];
        }
        else if(front==0)
        {
            front = max-1;
            cout << "Enter rollno of student : ";
            cin >> rollno[front];
        }
        else{
            front--;
            cout << "Enter rollno of student : ";
            cin >> rollno[front];
        }
    }
}
void Dequeue ::AddRear()
{
    if (rear!=front+1 && rear!=-1)
    {
        cout << "Queue is full!!!\n";
    }
    else
    {
        if (rear == -1 && front == -1)
        {
            front=0;
            rear++;
            cout << "Enter rollno of student : ";
            cin >> rollno[rear];
        }
        else if(rear==0)
        {
            rear++;
            cout << "Enter rollno of student : ";
            cin >> rollno[rear];
        }
        else{
            rear++;
            cout << "Enter rollno of student : ";
            cin >> rollno[rear];
        }
    }
}
void Dequeue ::DeleteFront()
{
    if (front == -1)
    {
        cout << "No element to delete at front end!!!\n\n";
    }
    else if(front==max-1)
    {
        string n = rollno[front];
        cout << "PRN " << n << " deleted successfully!!!\n";
        front=0;
    }
    else if(front==0)
    {
        string n = rollno[front];
        cout << "PRN " << n << " deleted successfully!!!\n";
        front--;
    }
    else
    {
        string n = rollno[front];
        cout << "PRN " << n << " deleted successfully!!!\n";
        front++;
    }
    
}
void Dequeue ::DeleteRear()
{
    if (rear == -1)
    {
        cout << "No element to delete at rear end!!!\n\n";
    }
    else
    {
        string n = rollno[rear];
        cout << "PRN " << n << " deleted successfully!!!\n";
        rear--;
    }
}

int main()
{
    cout<<"----------------------------\n";
    cout<<"  Group-E Assignment-31\n";
    cout<<"----------------------------\n";
    Dequeue d;
    int ch;
    do
    {
        cout << "\t1.Add in Front\n";
        cout << "\t2.Add at Rear\n";
        cout << "\t3.Delete from Front\n";
        cout << "\t4.Delete at Rear\n";
        cout << "\t5.Display\n";
        cout << "\t6.Exit\n";
        cout << "Enter choice : ";
        cin >> ch;
        cout<<"\n";
        switch (ch)
        {
        case 1:
            d.AddFront();
            break;

        case 2:
            d.AddRear();
            break;

        case 3:
            d.DeleteFront();
            break;

        case 4:
            d.DeleteRear();
            break;

        case 5:
            d.Display();
            break;

        case 6:
            exit(0);
            break;

        default:
            cout << "Enter valid choice!!\n";
        }
    } while (ch != 6);
}
