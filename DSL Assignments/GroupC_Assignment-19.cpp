/*Department of Computer Engineering has student's club named 'Pinnacle Club'. Students
of second, third and final year of department can be granted membership on request.
Similarly one may cancel the membership of club. First node is reserved for president of
club and last node is reserved for secretary of club. Write C++ program to maintain club
member‘s information using singly linked list. Store student PRN and Name. Write
functions to:
a) Add and delete the members as well as president or even secretary.
b) Compute total number of members of club
c) Display members
d) Two linked lists exists for two divisions. Concatenate two lists.*/

#include <iostream>
using namespace std;

class PinacleClub
{
public:
    int prn;
    string name;
    PinacleClub *next;

    PinacleClub *Create();
    void Display(PinacleClub *president);
    void Total(PinacleClub *head);
    PinacleClub *InsertAtBegin(PinacleClub *head);
    PinacleClub *InsertAtEnd(PinacleClub *head, PinacleClub *sec);
    PinacleClub *InsertInBetween(PinacleClub *head);
    PinacleClub *DeleteMember(PinacleClub *head);
    PinacleClub *DeletePresident(PinacleClub *head);
    PinacleClub *DeleteSecretary(PinacleClub *head);
    PinacleClub* Concatenate(PinacleClub* head1,PinacleClub* head2);
};
PinacleClub *PinacleClub ::Create()
{
    int n;
    PinacleClub *president;
    PinacleClub *secretary;
    PinacleClub *temp;
    PinacleClub *t;

    president = NULL;

    cout << "\nEnter number of members in Pinacle Club : ";
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        if (president == NULL)
        {
            president = new PinacleClub();
            cout << "Enter name of President : ";
            cin >> president->name;
            cout << "Enter PRN : ";
            cin >> president->prn;
            president->next = NULL;
            t = president;
        }
        else
        {
            temp = new PinacleClub();
            t->next = temp;
            t = t->next;
            cout << "Enter name of member : ";
            cin >> temp->name;
            cout << "Enter PRN : ";
            cin >> temp->prn;
            temp->next = NULL;
        }
    }
    secretary = new PinacleClub();
    t->next = secretary;
    cout << "Enter name of secretary : ";
    cin >> secretary->name;
    cout << "Enter PRN : ";
    cin >> secretary->prn;
    secretary->next = NULL;

    return president;
    cout << "\n";
}
void PinacleClub ::Display(PinacleClub *head)
{
    PinacleClub *p;
    p = head;
    cout << "--------------------\n";
    cout << "   PINACLE CLUB\n";
    cout << "--------------------\n";
    cout << "PRN"
         << "\t"
         << "NAME\n";
    cout << "--------------------\n";

    while (p != NULL)
    {
        cout << p->prn << "\t" << p->name << endl;
        p = p->next;
    }
    cout << "\n";
}
void PinacleClub ::Total(PinacleClub *head)
{
    PinacleClub *p;
    p = head;
    int i = 0;
    while (p != NULL)
    {
        p = p->next;
        i++;
    }
    cout << "\nTotal number of members are :=> " << i;
}
PinacleClub *PinacleClub ::InsertAtEnd(PinacleClub *head, PinacleClub *sec)
{
    PinacleClub *newNode = new PinacleClub();
    PinacleClub *p;
    p = head;
    cout << "Enter name of new secretary : ";
    cin >> newNode->name;
    cout << "Enter prn of new secretary : ";
    cin >> newNode->prn;

    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = newNode;
    return head;
}
PinacleClub *PinacleClub ::InsertAtBegin(PinacleClub *head)
{
    PinacleClub *newNode = new PinacleClub();
    cout << "\nEnter name of new president : ";
    cin >> newNode->name;
    cout << "Enter prn of new president : ";
    cin >> newNode->prn;
    newNode->next = head;
    head = newNode;
    return head;
}
PinacleClub *PinacleClub ::InsertInBetween(PinacleClub *head)
{
    PinacleClub *newNode = new PinacleClub();
    PinacleClub *p;
    p = head;
    int roll;
    cout << "Enter name of new student : ";
    cin >> newNode->name;
    cout << "Enter prn of new student : ";
    cin >> newNode->prn;
    cout << "After which prn you want to insert : ";
    cin >> roll;
    while (p->prn != roll)
    {
        p = p->next;
    }
    newNode->next = p->next;
    p->next = newNode;
    return head;
}
PinacleClub *PinacleClub ::DeletePresident(PinacleClub *head)
{
    PinacleClub *p;
    p = head;
    head = p->next;
    delete p;
    cout << "\nPresident Removed successfully!!\n";

    return head;
}
PinacleClub *PinacleClub ::DeleteMember(PinacleClub *head)
{
    PinacleClub *p;
    PinacleClub *q;
    p = head;
    int roll;
    if (head==NULL)
    {
        cout<<"\nNo members to delete!\n";
        return head;
    }

    cout << "Enter prn you want to delete : ";
    cin >> roll;
    while (p->next->prn != roll)
    {
        p = p->next;
    }
    q = p->next;
    p->next = q->next;
    delete q;
    cout << "Member removed successfully !!\n";
    return head;
}
PinacleClub *PinacleClub ::DeleteSecretary(PinacleClub *head)
{
    PinacleClub *p;
    p = head;
    while (p->next->next != NULL)
    {
        p = p->next;
    }
    delete p->next;
    p->next = NULL;
    cout << "\nSecretary Removed successfully!!\n";
    return head;
}
PinacleClub* PinacleClub :: Concatenate(PinacleClub* head1,PinacleClub* head2)
{
    PinacleClub *head3,*temp,*temp1;
    head3=temp=temp1=NULL;
    temp=head1;
    head3=head1;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp1=head2;
    temp->next=temp1;
    return head3;
    
}

int main()
{
    PinacleClub obj,obj1,obj2;
    PinacleClub *president;
    PinacleClub *secretary;
    PinacleClub *h1,*h2,*h3;
    h1=h2=h3=NULL;
    president = NULL;
    int ch;
    cout << "-------------------\n";
    cout << "  PINACLE CLUB\n";
    cout << "-------------------\n";
    do
    {
        cout << "\t1.Create Club\n";
        cout << "\t2.Display Members of Club\n";
        cout << "\t3.Insert Members\n";
        cout << "\t4.Delete Members\n";
        cout << "\t5.Total members\n";
        cout << "\t6.Concatenate SE-A & SE-B Club\n";
        cout << "\t7.Exit\n";
        cout << "Enter choice :=> ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            president = obj.Create();
            break;
            cout<<"\n";
        case 2:
            obj.Display(president);
            break;
            cout<<"\n";
        case 3:
            cout << "\t1) Insert at Beginning \n";
            cout << "\t2) Insert at End\n";
            cout << "\t3) Insert in Between\n";
            int c;
            cout << "Enter choice : ";
            cin >> c;
            switch (c)
            {
            case 1:
                president = obj.InsertAtBegin(president);
                break;
            case 2:
                president = obj.InsertAtEnd(president, secretary);
                break;
            case 3:
                president = obj.InsertInBetween(president);
                break;
            }
            break;
            cout<<"\n";
        case 4:
            cout << "\t1) Delete President\n";
            cout << "\t2) Delete Member\n";
            cout << "\t3) Delete Secretary\n";
            int d;
            cout << "Enter choice : ";
            cin >> d;
            switch (d)
            {
            case 1:
                president = obj.DeletePresident(president);
                break;
            case 2:
                president = obj.DeleteMember(president);
                break;
            case 3:
                president = obj.DeleteSecretary(president);
                break;
            }
            break;
            cout<<"\n";
        case 5:
            obj.Total(president);
            cout << "\n\n";
            break;
            cout<<"\n";
        case 6:
            cout<<"\nEnter SE-A details\n";
            h1 = obj1.Create();
            cout<<"\nEnter SE-B details\n";
            h2 = obj2.Create();
            h3 = obj.Concatenate(h1,h2);
            obj.Display(h3);
            break;
        case 7:
            exit(0);
            break;
        }
    } while (ch != 7);

    return 0;
}
