/*Write C++ program using STL for sorting and searching user defined records such as personal
records (Name, DOB, Telephone number etc) using vector container.*/

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;


class STL
{
public:
    string name, contact, dob, roll;
    vector<STL> vect;
    vector<STL> :: iterator it1;

    int Create();
    void Display(int n);
    void Search();
    void Sort();

    bool operator < (const STL& obj)
    {
        return name < obj.name;
    }
    friend bool operator== (const STL &ob1, const STL &ob2){
        if(ob1.roll==ob2.roll || ob1.name == ob2.name || ob1.dob == ob2.dob || ob1.contact == ob2.contact){
            return true;
        }
        return false;
    }
};

int STL ::Create()
{
    int n;
    cout << "Enter number of students : ";
    cin >> n;
    int p = 1;
    STL temp;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details of student " << p << "\n";
        cout << "Name : ";
        cin >> name;

        cout << "Roll no : ";
        cin >> roll;

        cout << "Contact : ";
        cin >> contact;

        cout << "Date of Birth : ";
        cin >> dob;

        temp.roll=roll;
        temp.name = name;
        temp.contact = contact;
        temp.dob = dob;
        vect.push_back(temp);
        p++;
    }

    return n;
}
void STL ::Display(int n)
{
    cout << "---------------------------------------------------------------\n";
    cout << "ROLL NO\t\tNAME\t\tDOB\t\tCONTACT\n";
    cout << "---------------------------------------------------------------\n";
    for (int i = 0; i < n; i++)
    {
        cout << vect[i].roll << "\t\t" << vect[i].name << "\t\t" << vect[i].dob << "\t\t" << vect[i].contact << "\n";
    }
    cout << "----------------------------------------------------------------\n";
}
void STL ::Search()
{
    STL s;
    string search_key;
    cout << "Enter name to search record : ";
    cin >> search_key;
    s.name=s.roll=s.contact=s.dob=search_key;
    it1 = find(vect.begin(), vect.end(), s);
    if (it1 != vect.end())
    {
        cout << "\nRecord found !\n";
        cout << "-----------------------------------------------------------\n";
        cout << "ROLL NO\t\tNAME\t\tDOB\t\tCONTACT\n";
        cout << "-----------------------------------------------------------\n";
        cout << vect[it1-vect.begin()].roll << "\t\t" << vect[it1-vect.begin()].name << "\t\t" << vect[it1-vect.begin()].dob << "\t\t" << vect[it1-vect.begin()].contact << "\n";
    }
    else
    {
        cout << "\nRecord not found !\n";
    }
}

void STL ::Sort()
{
    sort(vect.begin(), vect.end());
    cout << "Sorted successfully !!\n";
    Display(vect.size());
}
int main()
{
    STL s;
    int n, ch;
    cout << "-----------------------------\n";
    cout << "    Group-C Assignment-6A\n";
    cout << "-----------------------------\n";
    cout << "\t1.Enter data\n";
    cout << "\t2.Display\n";
    cout << "\t3.Search Record\n";
    cout << "\t4.Sort data\n";
    cout << "\t5.Exit\n";

    do
    {
        cout << "\nEnter choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            n = s.Create();
            break;

        case 2:
            s.Display(n);
            break;

        case 3:
            s.Search();
            break;

        case 4:
            s.Sort();
            break;

        case 5:
            exit(0);
        }
    } while (ch != 5);
}
