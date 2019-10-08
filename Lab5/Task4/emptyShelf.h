// Data Structures Laboratory
// Section 004
// Lab 5
// 10/3/2019
// Group 6
// Group Members: Anh Nguyen and Michael Stephens

#ifndef emptyShelf_h
#define emptyShelf_h

#include <iostream>
#include <exception>
using namespace std;
class emptyShelf : public exception
{
public:
    const char * what () const throw ()
    {
        return "\nERROR: EmptyShelf exception";
    }
};
#endif /* emptyShelf_h */
