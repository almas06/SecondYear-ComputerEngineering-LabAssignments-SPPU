/*Write a C++ program that creates an output file, writes information to it, closes the file, open
it again as an input file and read the information from the file.*/

#include <iostream>
#include <fstream>
#define max 10
using namespace std;

class Student
{
    char name[20];
    string prn;
    float sgpa;

public:
    void InputData()
    {
        cout << "Name : ";
        cin >> name;
        cout << "PRN : ";
        cin >> prn;
        cout << "Sgpa : ";
        cin >> sgpa;
    }
    void Display()
    {
        cout << name << "\t\t" << sgpa << "\t\t" << prn;
    }
};
int main()
{
    Student stud[max];
    fstream file;
    int n;

    cout << "\nWriting information into file...\n\n";
    cout << "How many students information you need to store : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter information of student " << i + 1 << "\n";
        stud[i].InputData();
        file.write((char *)&stud[i], sizeof(stud[i]));
    }
    file.close();

    cout << "\nReading from the file...\n\n";
    cout << "-------------------------------------------\n";
    cout << "Name"
         << "\t\t"
         << "Sgpa"
         << "\t\t"
         << "PRN\n";
    cout << "--------------------------------------------\n";
    for (int i = 0; i < n; i++)
    {
        file.write((char *)&stud[i], sizeof(stud[i]));
        stud[i].Display();
        cout << "\n";
    }
    file.close();
    cout << "\n";
}
