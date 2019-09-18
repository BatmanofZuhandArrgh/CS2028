// Data Structures Laboratory
// Section 004
// Lab 2
// 9/17/2019
// Group 6
// Group Members: Anh Nguyen and Michael Stephens

#ifndef product_h
#define product_h

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class product
{
public:
    void setid(double);
    double getid();
    void setunits(double);
    double getunits();
    void setprice(double);
    double getprice();
    void setsales(double);
    double getsales();
    void setdescription(string);
    string getdescription();
    void settax(bool);
    bool gettax();
    product();
    product(double, double, double, double, string, bool);
private:
    double id;
    double units;
    double price;
    double sales;
    string description;
    bool Taxexempt;
};

// Function prototypes
void calcSales(product[] , int);
void showOrder(product[], int);
void dualSort(product[], int);
void showTotals(product[], int);
#endif 

