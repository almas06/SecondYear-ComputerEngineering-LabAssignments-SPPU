#include <iostream>
using namespace std;

struct Node
{
    string Name;
    Node* sections[10];              //Array of type node*
};
class BookCreation
{
public:
    int no_units, no_chapters[10],no_subSect[10];
    Node* CreateTree();              //Create func of return type node*
    void Display(Node *);
};
Node *BookCreation ::CreateTree()
{
    Node* root = new Node();          //Allocating memory for root node 
    cout << "\nEnter name of book : ";
    cin >> root->Name;

    cout << "\nEnter number of units in the book : ";
    cin >> no_units;
    for (int i = 0; i < no_units; i++)
    {
        root->sections[i] = new Node();
        cout << "\nEnter Unit-" << i + 1 << " : ";
        cin >> root->sections[i]->Name;

        cout << "Enter number of sections in Unit-" << i + 1 << " : ";
        cin >> no_chapters[i];
        for (int j = 0; j < no_chapters[i]; j++)
        {
            root->sections[i]->sections[j] = new Node();
            cout << "Section-" << j + 1 << " : ";
            cin >> root->sections[i]->sections[j]->Name;
        }
    }
    cout<<"\n";
    return root;
}
void BookCreation ::Display(Node *r)
{
    if (r != NULL)                         //check if root node is not equal to null
    {
        cout << "-----------------------------\n";
        cout << "\tBook => " << r->Name << "\n";
        cout << "-----------------------------\n";

        for (int i = 0; i < no_units; i++)
        {
            cout << "Unit-" << i + 1 << " => " << r->sections[i]->Name << "\n";
            for (int j = 0; j < no_chapters[i]; j++)
            {
                cout << "Section" << j + 1 << " : " << r->sections[i]->sections[j]->Name << "\n";
            }
            cout << "\n";
        }
        cout<<"---------------------------\n";
    }
    else{
        cout<<"\nSorry! No books to display\n\n";
    }
    
}
int main()
{
    Node *r = NULL;
    int ch;
    BookCreation obj;
    cout << "-------------------------\n";
    cout << "  Group-B Assignment-5\n";
    cout << "-------------------------\n";
    do
    {
        cout << "\t1.Create Tree\n";
        cout << "\t2.Display\n";
        cout << "\t3.Exit\n";
        cout << "Enter choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            r = obj.CreateTree();
            break;
        case 2:
            obj.Display(r);
            break;
        case 3:
            exit(0);
            break;
        default:
            cout << "\nInvalid choice!!\n";
            break;
        }
    } while (ch != 3);
}
