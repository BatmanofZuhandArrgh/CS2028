//
//  Task1.cpp
//  Lab3
//
//  Created by Macbook on 9/18/19.
//  Copyright © 2019 Anh Nguyen. All rights reserved.
//

# include "task1.h"
# include<iostream>
# include <cmath>
#define PI 3.14159265

using namespace std;
//Complex::Complex()=default;

Complex::Complex()
{
    real=0;
    imaginary=0;
}

Complex::Complex(double x, double y)
{
    x=real;
    y=imaginary;
}

Complex::Complex(double x)
{
    x=real;
    imaginary=0;
}

void Complex::print()
{
    cout<<real<<"+"<<imaginary<<"i"<<endl;
}

double Complex::getReal()
{
    return real;
}

double Complex::getImaginary()
{
    return imaginary;
}

void Complex::setReal(double x)
{
    real=x;
}

void Complex::setImaginary(double y)
{
    imaginary=y;
}

double Complex::getlength()
{
    return sqrt(imaginary*imaginary+real*real);
}

double Complex::getPhi()
{
    return (atan2(imaginary, real) *180.0 / PI);
}

Complex Complex::operator +(Complex &c)
{
    Complex add;
    add.real=real+c.real;
    add.imaginary=imaginary+c.imaginary;
    return add;
}

Complex Complex::operator -(Complex &c)
{
    Complex sub;
    sub.real=real-c.real;
    sub.imaginary=imaginary-c.imaginary;
    return sub;
}

Complex Complex::operator *(Complex &c)
{
    Complex mult;
    mult.real=real*c.real-imaginary*c.imaginary;
    mult.imaginary=real*c.imaginary-c.real*imaginary;
    return mult;
}

Complex Complex::operator /(Complex &c)
{
    Complex div;
    div.real=(real*c.real+imaginary*c.imaginary)/(c.real*c.real+c.imaginary*c.imaginary);
    div.imaginary=(imaginary*c.real+real*c.imaginary)/(c.real*c.real+c.imaginary*c.imaginary);
    return div;
}

bool Complex::operator ==(Complex &c)
{
    return ((imaginary==c.imaginary)&&(real==c.real));
}

