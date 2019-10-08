// Data Structures Laboratory
// Section 004
// Lab 5
// 10/3/2019
// Group 6
// Group Members: Anh Nguyen and Michael Stephens

#ifndef fullShelf_h
#define fullShelf_h

#include <iostream>
#include <exception>
using namespace std;
class fullShelf : public exception
{
public:
    const char * what () const throw ()
    {
        return "\nERROR: FullShelf exception";
    }
};

#endif /* fullShelf_h */
