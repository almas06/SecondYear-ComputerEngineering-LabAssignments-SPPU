/*In any language program mostly syntax error occurs due to unbalancing delimiter such as
(),{},[]. Write C++ program using stack to check whether given expression is well
parenthesized or not.*/

#include <iostream>
using namespace std;

int top = -1;
char stack[10];

void push(char val)
{
    if (top >= 10)
        cout << "Stack Overflow" << endl;
    else
    {
        top++;
        stack[top] = val;
    }
}
char pop()
{
    if (top <= -1)
        cout << "Stack Underflow" << endl;
    else
    {
        char x = stack[top];
        top--;
        return x;
    }
}
int balancedParanthesis(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            push(str[i]);
        }
        else if (str[i] == ')')
        {
            if (top == -1)
            {
                return 0;
            }
            else
            {
                pop();
            }
        }
    }
    if (top == -1)
    {
        cout << "\nAbove expression is balanced!!\n";
    }
    else
    {
        cout << "\nOops...Above expression is unbalanced!!\n";
    }
}
int main()
{
    cout << "--------------------------\n";
    cout << " Group-D Assignment-26\n";
    cout << "--------------------------\n";
    string input;

    cout << "Enter expression : ";
    cin >> input;

    balancedParanthesis(input);
}
