// Data Structures Laboratory
// Section 004
// Lab 2
// 9/17/2019
// Group 6
// Group Members: Anh Nguyen and Michael Stephens

#ifndef product_cpp
#define product_cpp

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include "product.h"
#include <string>
//#include "Task3Lab2.cpp"
using namespace std;


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

#endif /* product_h */
