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
product::product(double a, double b, double c, double d, string e, bool f){
    id =a;
    units = b;
    price = c;
    sales = d;
    description = e;
    Taxexempt = f;
}

// Function prototypes
void calcSales(product, int);
void showOrder(product, int);
void dualSort(product, int);
void showTotals(product, int);

// NUM_PRODS is the number of products produced.
const int NUM_PRODS = 9;

int main()
{
    //Initialize the vectors for
    product productArray[NUM_PRODS];
    double arrayNums[35];
    
    
    ifstream dataFile;
    dataFile.open("/Users/MACOS/Downloads/Texttask3lab2.txt", ios::in);
    int i = 0;
    
    string a;
    while(dataFile >> a or !dataFile.eof()){
        cout << a << endl;
        i++;
    }
    dataFile.close();
    
    for (int i = 0; i<36; i++){
        cout << arrayNums[i]<< endl;
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
        productArray[i].sales=productArray[i].units*productArray[i].price;
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
        total=productArray[i].sales;
        temp=productArray[i].id;
        max=i;
        for(int j=i+1;j<size;j++)
        {
            if (productArray[j].sales>total)
            {
                total=productArray[j].sales;
                temp=productArray[j].id;
                max=j;
            }
        }
        productArray[max].sales=productArray[i].sales;
        productArray[max].id=productArray[i].id;
        productArray[i].sales=total;
        productArray[i].id=temp;
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
        cout << productArray[i].id << "\t\t$";
        cout << setw(8) << productArray[i].sales << endl;
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
        total += productArray[i].units;
        totalSales += productArray[i].sales;
    }
    cout << "Total units Sold: " << total << endl;
    cout << "Total sales: $" << totalSales << endl;
}
