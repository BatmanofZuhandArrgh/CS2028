#include <iostream>
#include "task1.h"
#include <string>
# include <cmath>
# define PI 3.14159265
using namespace std;



int main()
{
    double x,y,x2,y2;
    string op;
    cout<<"Enter x and y: ";
    cin>>x>>y;
    cout<<"Enter x2 and y2: ";
    cin>>x2>>y2;

    Complex a;
    Complex b;
    
    a.setReal(x);
    a.setImaginary(y);
    b.setReal(x2);
    b.setImaginary(y2);
    bool cont = true;
    
    while(cont){
    cout<<"What operation to perform (+, -, *, /, ==): ";
    cin>>op;

    if(op=="+")
        (a+b).print();
    else if(op=="-")
        (a-b).print();
    else if(op=="*")
        (a*b).print();
    else if(op=="/")
        (a/b).print();
    else if(op=="==")
        cout<<"Are they equal (True/False): "<<(a==b)<<endl;
        cout << "Would you like to continue????? Input Y or N" << endl;
        string yesorno;
        cin >> yesorno;
        if (yesorno == "Y")
            cont = true;
        else if (yesorno == "N")
            cont = false;
        else{
            cout << "Oof, you got 1 chance, you're out!" << endl;
            cont = false;}
    }
    cout<<"Length of First Complex Number: "<<a.getlength()<<endl;
    cout<<"Phi of First Complex Number: "<<a.getPhi() << "degrees." <<endl;
    cout<<"Length of Second Complex Number: "<<b.getlength()<<endl;
    cout<<"Phi of Second Complex Number: "<<b.getPhi()<< "degrees." <<endl;
    
    
    return 42;
}

