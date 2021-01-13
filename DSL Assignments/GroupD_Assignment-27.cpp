/*Implement C++ program for expression conversion as infix to postfix and its evaluation
using stack based on given conditions:
1. Operands and operator, both must be single character.
2. Input Postfix expression must be in a desired format.
3. Only '+', '-', '*' and '/ ' operators are expected.*/

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

int precedence(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
int isoperator(char ch)
{
    if (ch == '*' || ch == '/' || ch == '+' || ch == '-')
        return 1;
    else
    {
        return 0;
    }
}
int evaluate(char op, int op1, int op2){
    switch(op){
        case '+': return op1 + op2;break;
        case '-': return op1 - op2;break;
        case '*': return op1 * op2;break;
        case '/': return op1 / op2;break;
        default: cout<<"Operator Unsupported\n";
    }
}

int evalPostfix(string p){ 
    for(char& a : p){
        if(isoperator(a)){
            int op2 = pop();  
            int op1 = pop();
            int ans = evaluate(a, op1, op2);
            push(ans); 
        }
        else{
            push(a - '0');
        }
    }
    return pop();
}

void ConversionToPostfix(string s)
{
    string postfix;
    for (int i = 0; i < s.length(); i++)
    {
        char ans = s[i];
        if (!isoperator(ans))
        {
            postfix += ans;
        }
        else
        {
            if (precedence(ans) > precedence(stack[top]))
            {
                push(ans);
            }
            else
            {
                postfix += pop();
                push(ans);
            }
        }
    }
    while (top != -1)
    {
        postfix += pop();
    }
    cout << "Converted Infix expression is :" << postfix << endl;
    cout<<"Evaluating Postfix...\n";
    cout<<"Ans:"<<evalPostfix(postfix)<<"\n";
}

int main()
{
    cout << "----------------------------\n";
    cout << "Group-D Assignment-27\n";
    cout << "----------------------------\n";
    cout << "Infix to Postfix Conversion\n";
    string infix;
    cout << "\nEnter the expression: ";
    cin >> infix;
    cout << "\nConverting to Postfix...\n";
    ConversionToPostfix(infix);
}
