
/*Implement a class Complex which represents the Complex Number data type. Implement the
following
1. Constructor (including a default constructor which creates the complex number 0+0i).
2. Overload operator+ to add two complex numbers.
3. Overload operator* to multiply two complex numbers.
4. Overload operators << and >> to print and read Complex Numbers.*/


#include <iostream>
using namespace std;

class ComplexNumber
{
    public:

    int real;
    int imag;

    ComplexNumber(int real = 0, int imag = 0 )
    {
        this->real = real;
        this->imag = imag;

    }
    friend istream &operator>>(istream &input , ComplexNumber &obj)
    {
        cout<<"Enter real part :=> ";
        input>>obj.real;

        cout<<"Enter imaginary part :=> ";
        input>>obj.imag;
    }
    ComplexNumber operator+(ComplexNumber c2){
        ComplexNumber c3;
        c3.real = real + c2.real;
        c3.imag = imag + c2.imag;
        return c3;

    }
    ComplexNumber operator*(ComplexNumber n2)
    {
        ComplexNumber mult;
        mult.real = real * n2.real - imag * n2.imag;
        mult.imag = real * n2.imag + imag * n2.real;
        return mult;
    }
    friend ostream &operator<<(ostream &output , ComplexNumber &obj)
    {
        output<<obj.real<<"+"<<obj.imag<<"i";

    }

    
};
int main(){
    ComplexNumber obj1,obj2,obj3;
    cout<<"Complex number 1\n";
    cin>>obj1;
    cout<<"\n\nComplex number 2\n";
    cin>>obj2;

    cout<<"\n----------------\n";
    obj3 = obj1 + obj2;
    cout<<"Sum :=> "<<obj3<<"\n";
    cout<<"-----------------\n\n";

    cout<<"---------------------\n";
    obj3 = obj1 * obj2;
    cout<<"Product :=> "<<obj3<<"\n";
    cout<<"---------------------\n\n";
    
}
