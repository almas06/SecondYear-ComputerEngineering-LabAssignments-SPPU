#include <iostream>
#include <limits>
#include <string>
using namespace std;
#define maxx 10

struct queue
{
    string itemname;
    string orderno;
};
class PizzaParlour
{
public:
    int front = 0 ;int rear = 0;
    queue customer[maxx];
    void PlaceOrder();
    void DeliverOrder();
    void ShowOrders();
};
void PizzaParlour :: PlaceOrder()
{
    if ((rear + 1) % maxx == front)
    {
        cout << "\nOrders are full!!!\n\n";
    }
    else{
        cout<<"-------------MENU CARD-----------------\n";
        cout<<"-> Pepperoni pizza\t\t395/-\n";
        cout<<"-> Multigrain pizza\t\t200/-\n";
        cout<<"-> Margherita Pizza\t\t195/-\n";
        cout<<"-> PaneerCheeze Pizza\t\t395/-\n";
        cout<<"-> Cheese & Corn\t\t295/-\n";
        cout<<"-> Mexican Pizza\t\t395/-\n";
        cout<<"-> Mini Mushroom Pizza\t\t245/-\n";
        cout<<"-> Greek Style Pizza\t\t450/-\n";
        cout<<"-> Wholegrain Pizza\t\t200/-\n";
        cout<<"------------------------------------------\n";
        rear = (rear + 1) % maxx;
        
        cout<<"Enter item you want to place order for : ";
        cin.ignore( std::numeric_limits<streamsize>::max(), '\n' );
        getline(cin,customer[rear].itemname);
        

        cout<<"Enter order no. : ";
        cin>>customer[rear].orderno;
    }
}
void PizzaParlour :: DeliverOrder()
{
    if (front == rear)
    {
        cout << "\nNo orders left to deliver!!!\n\n";
    }
    else
    {
        front = (front + 1) % maxx;
        string p = customer[front].orderno;
        cout << "\nOrder no " << p << " delivered successfully!!!\n\n";
    }
}
void PizzaParlour ::ShowOrders()
{
    if(front==rear)
    {
        cout<<"\nNo orders left!!\n\n";
    }
    else{
    cout<<"Orders placed are : \n";
    cout << "-------------------------------\n";
    cout << "Name\t\t"
         << "Order no."
         << "\n";
    cout << "-------------------------------\n";
    for (int i = (front+1)%maxx; i <= rear; i++)
    {

        cout << customer[i].itemname << "\t\t" << customer[i].orderno << "\n";
    }
    cout << "-------------------------------\n";
    }
}
int main()
{
    cout<<"---------------------------\n";
    cout<<"Group-E Assignment-32\n";
    cout<<" Trendo Pizza Parlor\n";
    cout<<"---------------------------\n";
    PizzaParlour j;
    int ch;
    do
    {
        cout << "\t1.Place Order\n";
        cout << "\t2.Deliver Order\n";
        cout << "\t3.Show Orders\n";
        cout << "\t4.Exit\n";
        cout << "Enter choice : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            j.PlaceOrder();
            break;

        case 2:
            j.DeliverOrder();
            break;

        case 3:
            j.ShowOrders();
            break;

        case 4:
            exit(0);
            break;

        default:
            cout << "Enter valid choice!!\n";
        }
    } while (ch != 4);
}
