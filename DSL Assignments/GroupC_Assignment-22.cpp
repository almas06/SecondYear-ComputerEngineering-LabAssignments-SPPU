/*Second year Computer Engineering class, set A of students like Vanilla Ice-cream and set
B of students like butterscotch ice-cream. Write C++ program to store two sets using
linked list. compute and display-
a) Set of students who like both vanilla and butterscotch
b) Set of students who like either vanilla or butterscotch or not both
c) Number of students who like neither vanilla nor butterscotch*/

#include <iostream>
using namespace std;

class Node
{
public:
    int roll_no;
    Node *next;

    Node *InputVanilla();
    Node *InputButterscotch();
    Node *Both_Icecreams(Node *head1, Node *head2);
    void Display(Node *head);
    void OnlyVanilla(Node *head1, Node *head2);
    void OnlyButterscotch(Node *head1, Node *head2);
};

Node *Node ::InputVanilla()
{
    int n;
    Node *head1;
    Node *temp;
    Node *t;
    head1 = NULL;

    cout << "\nEnter number of Students who like vanilla icecream: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        if (head1 == NULL)
        {
            head1 = new Node();
            cout << "Enter roll no : ";
            cin >> head1->roll_no;
            head1->next = NULL;
            t = head1;
        }
        else
        {
            temp = new Node();
            t->next = temp;
            t = t->next;
            cout << "Enter roll no : ";
            cin >> temp->roll_no;
            temp->next = NULL;
        }
    }
    return head1;
}
Node *Node ::InputButterscotch()
{
    int n;
    Node *head2;
    Node *temp;
    Node *t;
    head2 = NULL;

    cout << "\nEnter number of Students who like butterscotch icecream: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        if (head2 == NULL)
        {
            head2 = new Node();
            cout << "Enter roll no : ";
            cin >> head2->roll_no;
            head2->next = NULL;
            t = head2;
        }
        else
        {
            temp = new Node();
            t->next = temp;
            t = t->next;
            cout << "Enter roll no : ";
            cin >> temp->roll_no;
            temp->next = NULL;
        }
    }
    return head2;
}
Node *Node ::Both_Icecreams(Node *head1, Node *head2)
{
    Node *p;
    Node *q;
    Node *temp;
    Node *t;
    Node *head3 = NULL;
    p = head1;
    while (p != NULL)
    {
        q = head2;
        while (q != NULL)
        {
            if (head3 == NULL && p->roll_no == q->roll_no)
            {
                head3 = new Node();
                head3->roll_no = p->roll_no;
                head3->next = NULL;
                t = head3;
                
            }
            else if (p->roll_no == q->roll_no)
            {
                temp = new Node();
                t->next = temp;
                t = t->next;
                temp->roll_no = p->roll_no;
                temp->next = NULL;
            }
            q = q->next;
        }
        p = p->next;
    }
    return head3;
}
void Node ::OnlyVanilla(Node *head1, Node *head2)
{
    Node *cur1 = head1;
    Node *cur2 = head2;
    int found = 0;
    while (cur2)
    {
        while (cur1)
        {
            if (cur2->roll_no == cur1->roll_no)
            {
                found = 1;
                break;
            }
            else
            {
                cur1 = cur1->next;
            }
        }
        if (found == 1)
        {
            cur2 = cur2->next;
            found = 0;
        }
        else
        {
            cout << cur2->roll_no << " ";
            cur2 = cur2->next;
        }
        cur1 = head1;
    }
}
void Node ::OnlyButterscotch(Node *head1, Node *head2)
{
    Node *cur1 = head1;
    Node *cur2 = head2;
    int found = 0;
    int n = 0;
    while (cur1)
    {
        while (cur2)
        {
            if (cur1->roll_no == cur2->roll_no)
            {
                found = 1;
                break;
            }
            else
            {
                cur2 = cur2->next;
            }
        }
        if (found == 1)
        {
            cur1 = cur1->next;
            found = 0;
        }
        else
        {
            n++;
            cout << cur1->roll_no << " ";
            cur1 = cur1->next;
        }
        cur2 = head2;
    }
}

void Node ::Display(Node *head)
{
    Node *r;
    for (r = head; r != NULL; r = r->next)
    {
        cout << r->roll_no << " ";
        cout << "\n";
    }
}
int main()
{
    Node obj;
    Node *head11;
    Node *head22;
    Node *head33;
    Node *head44;
    int n;
    int ch;
    cout << "-----------------------------------\n";
    cout << "     Group-C Assignment-22\n";
    cout << "-----------------------------------\n";

    do
    {
        cout << "\t1.Input vanilla students\n";
        cout << "\t2.Input butterscotch students\n";
        cout << "\t3.Display\n";
        cout << "\t4.Students who like both icecreams\n";
        cout << "\t5.Students who like either icecreams\n";
        cout << "\t6.Exit\n";
        cout << "Enter choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            head11 = obj.InputVanilla();
            break;

        case 2:
            head22 = obj.InputButterscotch();
            break;

        case 3:
            cout << "Vanilla Icecream\n";
            obj.Display(head11);
            cout << "Butterscotch Icecream\n";
            obj.Display(head22);
            break;

        case 4:
            cout << "\nStudents who like both icecreams\n";
            head33 = obj.Both_Icecreams(head11, head22);
            obj.Display(head33);
            break;

        case 5:
            cout << "\nStudents who like either vanilla or butterscoth icecream\n";
            obj.OnlyVanilla(head11, head22);
            obj.OnlyButterscotch(head11, head22);
            cout << "\n";
            break;

        case 6:
            exit(0);
            break;

        default:
            cout << "\nEnter a valid input !\n";
        }
    } while (ch != 7);
}
