//
//  main.cpp
//  Task3lab2.cpp
//
//  Created by Macbook on 9/17/19.
//  Copyright © 2019 Anh Nguyen. All rights reserved.
//

// Data Structures Laboratory
// Section 004
// Lab 1
// 9/4/2019
// Group 6
// Group Members: Anh Nguyen and Michael Stephens

// This program produces a sales report for DLC, Inc.
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
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
    //product(int, int, double, double);
private:
    double id;
    double units;
    double price;
    double sales;
    string description;
    bool Taxexempt;
};

//Definitions of functions in class
void product::setid(double a){
    id = a;}
double product::getid(){
    return id;}
void product::setunits(double a){
    units = a;}
double product::getunits(){
    return units;}
void product::setprice(double a){
    price = a;}
double product::getprice(){
    return price;}
void product::setsales(double a){
    sales = a;}
double product::getsales(){
    return sales;}
void product::setdescription(string s){
    description = s;}
string product::getdescription(){
    return description;}
void product::settax(bool a){
    Taxexempt = a;}
bool product::gettax(){
    return Taxexempt;}

//Definitions of contructors
product::product(){
    id = 0;
    units = 0;
    price = 0;
    sales = 0;
    description = "";
    Taxexempt = false;
}

product::product(double a, double b, double c, double d, string e, bool f){
    id =a;
    units = b;
    price = c;
    sales = d;
    description = e;
    Taxexempt = f;
}

// Function prototypes
void calcSales(product[] , int);
void showOrder(product[], int);
void dualSort(product[], int);
void showTotals(product[], int);

// NUM_PRODS is the number of products produced.
const int NUM_PRODS = 9;

int main()
{
    //Initialize the vectors for
    product productArray[NUM_PRODS];
    //double arrayNums[35];
    
    
    /*ifstream dataFile;
    dataFile.open("/Users/MACOS/Downloads/Texttask3lab2.txt", ios::in);
    int i = 0;
    
    double a;
    while(dataFile >> a or !dataFile.eof()){
        arrayNums[i] = a;
        i++;
    }
    dataFile.close();*/
    
    ifstream dataFile;
    dataFile.open("/Users/MACOS/Downloads/Task3lab2.cpp/Task3lab2.cpp/Texttask3lab2copy.txt", ios::in);
    int i = 0;
    int j=0;
    double a;
    while(dataFile >> a){
        if(i==0)
            productArray[j].setid(a);
        if(i==1)
            productArray[j].setunits(a);
        if(i==2)
            productArray[j].setprice(a);
        if(i==3)
            productArray[j].setsales(a);
        if(i==3)
        {
            i=0;
            j++;
        }
        else
            i++;
    }
    dataFile.close();
    
    for (int i = 0; i < NUM_PRODS ; i++){
        cout << productArray[i].getid() << endl;
        cout << productArray[i].getunits() << endl;
        cout << productArray[i].getprice() << endl;
        cout << productArray[i].getsales() << endl;
    }
    
    // Calculate each product's sales.
    calcSales(productArray,NUM_PRODS);
    
    // Sort the elements in the sales array in descending
    // order and shuffle the ID numbers in the id array to
    // keep them in parallel.
    dualSort(productArray,NUM_PRODS);
    
    // Set the numeric output formatting.
    cout << setprecision(2) << fixed << showpoint;
    
    // Display the products and sales amounts.
    showOrder(productArray,NUM_PRODS);
    
    // Display total units sold and total sales.
    showTotals(productArray,NUM_PRODS);
    return 0;
}

//****************************************************************
// Definition of calcSales. Accepts units, prices, and sales     *
// arrays as arguments. The size of these arrays is passed       *
// into the num parameter. This function calculates each         *
// product's sales by multiplying its units sold by each unit's  *
// price. The result is stored in the sales array.               *
//****************************************************************
void calcSales(product productArray[],int num)
{
    for(int i=0;i<num;i++)
    {
        double a = productArray[i].getunits();
        double b = productArray[i].getprice();
        productArray[i].setsales(a*b);
    }
}

//***************************************************************
// Definition of function dualSort. Accepts id and sales arrays *
// as arguments. The size of these arrays is passed into size.  *
// This function performs a descending order selection sort on  *
// the sales array. The elements of the id array are exchanged  *
// identically as those of the sales array. size is the number  *
// of elements in each array.                                   *
//***************************************************************

void dualSort(product productArray[],int size)
{
    int i,max,temp;
    double total;
    for(i=0;i<(size-1);i++)
    {
        total=productArray[i].getsales();
        temp=productArray[i].getid();
        max=i;
        for(int j=i+1;j<size;j++)
        {
            if (productArray[j].getsales()>total)
            {
                total=productArray[j].getsales();
                temp=productArray[j].getid();
                max=j;
            }
        }
        productArray[max].setsales(productArray[i].getsales());
        productArray[max].setid(productArray[i].getid());
        productArray[i].setsales(total);
        productArray[i].setid(temp);
    }
}

//****************************************************************
// Definition of showOrder function. Accepts sales and id arrays *
// as arguments. The size of these arrays is passed into num.    *
// The function first displays a heading, then the sorted list   *
// of product numbers and sales.                                 *
//****************************************************************

void showOrder(product productArray[], int num)
{
    cout << "Product Number\tSales\n";
    cout << "----------------------------------\n";
    for (int i=0;i<num;i++)
    {
        double a = productArray[i].getid();
        cout << a << "\t\t$";
        double b = productArray[i].getsales();
        cout << setw(8) << b << endl;
    }
    cout << endl;
}

//*****************************************************************
// Definition of showTotals function. Accepts sales and id arrays *
// as arguments. The size of these arrays is passed into num.     *
// The function first calculates the total units (of all          *
// products) sold and the total sales. It then displays these     *
// amounts.                                                       *
//*****************************************************************

void showTotals(product productArray[], int num)
{
    int total=0;
    double totalSales=0;
    for (int i= 0; i< num; i++)
    {
        double a = productArray[i].getunits();
        total += a;
        double b = productArray[i].getsales();
        totalSales += b;
    }
    cout << "Total units Sold: " << total << endl;
    cout << "Total sales: $" << totalSales << endl;
}
