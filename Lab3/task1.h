//
//  Task1.hpp
//  Lab3
//
//  Created by Macbook on 9/18/19.
//  Copyright © 2019 Anh Nguyen. All rights reserved.
//

#include <stdio.h>
#ifndef TASK1_H
#define TASK1_H
#include <iostream>
# include <cmath>

#define PI 3.14159265

class Complex
{
public:
    
    Complex();
    Complex(double x, double y);
    Complex(double x);
    
    double getReal();
    double getImaginary();
    void setReal(double x);
    void setImaginary(double y);
    void print();
    //friend ostream &operator<<(ostream &output, Complex &c);
    Complex operator+(Complex &c);
    Complex operator-(Complex &c);
    Complex operator*(Complex &c);
    Complex operator/(Complex &c);
    bool operator==(Complex &c);
    double getlength();
    double getPhi();
private:
    double real,imaginary;
    
};

#endif /* Task1_hpp */
