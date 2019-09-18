// Data Structures Laboratory
// Section 004
// Lab 2
// 9/17/2019
// Group 6
// Group Members: Anh Nguyen and Michael Stephens

// This program produces a sales report for DLC, Inc.
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include "product.h"
//#include "product.cpp"
using namespace std;


// NUM_PRODS is the number of products produced.
const int NUM_PRODS = 9;

int main()
{
    //Initialize the vectors for
    product productArray[NUM_PRODS];
    
    

    ifstream dataFile;
    dataFile.open("/Users/MACOS/Downloads/Texttask3lab2copy.txt", ios::in);
    int i = 0;
    int j = 0;
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
