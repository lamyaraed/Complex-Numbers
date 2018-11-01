#include <iostream>
#include "math.h"
using namespace std;


class complex
{
private:
    double real, imaginary;

public:

    complex();
    complex(double r, double i);
    complex(double real_part);



    friend complex operator+(complex n1, complex n2);
    friend complex operator-(complex n1, complex n2);
    friend complex operator*(complex n1, complex n2);
    friend bool operator==(complex n1, complex n2);
    friend ostream& operator<< (ostream& out, complex n1);
    friend istream& operator>> (istream& in, complex n1);

};

int main()
{
    complex num1(5,3);
    complex num2(3,2);
    complex num3;
    bool x;
    num3=num1-num2;
    cout<<num3;
    num3=num1+num2;
    cout << num3;
    num3=num1*num2;
    cout << num3;
    x = (num1==num2);
    cout << x;

    return 0;
}

complex::complex(double r, double im)
    {
        real=r;
        imaginary=im;

    }
complex::complex(double real_part)
{
    real=real_part;
    imaginary=0;
}
complex::complex()
{
    real=0;
    imaginary=0;
}
complex operator+(complex n1, complex n2)
{
    complex n3;
    n3.real=n1.real+n2.real;
    n3.imaginary=n1.imaginary+n2.imaginary;

    return n3;
}


complex operator-(complex n1, complex n2)
{
    complex n3;
    n3.real=n1.real-n2.real;
    n3.imaginary=n1.imaginary-n2.imaginary;

    return n3;
}
complex operator*(complex n1, complex n2)
{
    complex n3;
    n3.real=(n1.real*n2.real)-(n1.imaginary*n2.imaginary);
    n3.imaginary = (n1.real*n2.imaginary)+ (n1.imaginary*n2.real);

    return n3;
}
bool operator==(complex n1, complex n2)
{
    if ((n1.real==n2.real)&& (n1.imaginary==n2.imaginary))
    {
        return true;
    }
    else
        return false;
}
ostream& operator<< (ostream& out, complex n1)
{
    out<<n1.real<<"+"<<n1.imaginary<<"*i"<<endl;

     return out;
}
istream& operator>> (istream& in, complex n1)
{
    cout<<"enter the real number: ";
    in>>n1.real;
    cout<<"enter the imaginary number: ";
    in>>n1.imaginary;

 return in;
}
