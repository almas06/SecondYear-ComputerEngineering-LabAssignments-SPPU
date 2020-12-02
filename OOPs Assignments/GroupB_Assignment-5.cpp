/*Write a function template for selection sort that inputs, sorts and outputs an integer array and
a float array.*/

#include <iostream>
using namespace std;

template <typename T>
void SelectionSort()
{
    int n;
    cout << "Enter num of elements in array : ";
    cin >> n;

    T arr[n];

    for (int i = 0; i < n; i++)  //Input elements
    { 
        cout << "Enter element " << i + 1 << " : ";
        cin >> arr[i];
    }

    cout << "\n\nBefore sorting\n"; //Print elements before sorting
    cout << "--------------------\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n--------------------\n";

    for (int i = 0; i < n - 1; i++) //Sorting logic
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        T temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    cout << "\n\nAfter sorting\n"; //Print elements after sorting
    cout << "--------------------\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n--------------------\n";
    cout << "\n\n";
}

int main()
{
    cout << "----------------------\n";
    cout << " Group-B Assignment-5\n";
    cout << "----------------------\n";
    cout << "\n*****SELECTION SORT*****\n\n";

    cout << "Integer Sorting\n";
    cout << "Note : Enter integer values\n\n";
    SelectionSort<int>();

    cout << "Floating Sorting\n";
    cout << "Note : Enter floating point values\n\n";
    SelectionSort<float>();
}
