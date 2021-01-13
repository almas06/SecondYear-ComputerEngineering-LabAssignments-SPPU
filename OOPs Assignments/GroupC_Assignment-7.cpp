/*Write a program in C++ to use map associative container. The keys will be the names of states
and the values will be the populations of the states. When the program runs, the user is
prompted to type the name of a state. The program then looks in the map, using the state
name as an index and returns the population of the state.*/

#include <iostream>
#include <map>
using namespace std;

map<string, int> InputMapData()
{
    map<string, int> statePopulation;
    map<string, int>::iterator itr;
    string state;
    int population;
    int n;
    cout << "Enter number of states you want : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter state" << i + 1 << " : ";
        cin >> state;
        cout << "Enter population of state" << i + 1 << " : ";
        cin >> population;
        statePopulation.insert({state, population});
        cout << "\n";
    }
    return statePopulation;
}
void Display(map<string, int> statepop)
{
    map<string, int>::iterator itr;
    cout << "---------------------------------------\n";
    cout << "State\t\t\tPopulation"
         << "\n";
    cout << "---------------------------------------\n";
    for (itr = statepop.begin(); itr != statepop.end(); itr++)
    {

        cout << itr->first << "\t\t\t" << itr->second << endl;
    }
    cout << "---------------------------------------\n";
}
void FindPopulation(map<string, int> statepop)
{
    map<string, int>::iterator itr;
    string st;
    cout << "Enter state for which you want to find population : ";
    cin >> st;
    itr = statepop.find(st);
    if (itr == statepop.end())
        cout << "\nOops!!...State not present in map\n\n";
    else
    {
        cout << "---------------------------------------\n";
        cout << "State\t\t\tPopulation\n";
        cout << "---------------------------------------\n";
        cout << itr->first << "\t\t\t" << itr->second;
        cout << "\n---------------------------------------\n";
    }
}
int main()
{
    cout<<"-------------------------\n";
    cout<<"  Group-C Assignment-7\n";
    cout<<"-------------------------\n";
    map<string, int> obj;
    int ch;
    do
    {
        cout << "\t1.Input Map Data\n";
        cout << "\t2.Display\n";
        cout << "\t3.Find Population of state\n";
        cout << "\t4.Exit\n";
        cout << "Enter choice : ";
        cin >> ch;
        cout << "\n";
        switch (ch)
        {
        case 1:
            obj = InputMapData();
            break;

        case 2:
            Display(obj);
            break;

        case 3:
            FindPopulation(obj);
            break;

        case 4:
            exit(0);
            break;

        default:
            cout << "\nEnter valid input\n";
        }
    } while (ch != 4);
}
