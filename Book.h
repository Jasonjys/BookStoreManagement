#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

using namespace std;

#include "defs.h"
#include "Product.h"

//The book class derived from Product class and it has a title, author, isbn 
//edition and year as its data members
class Book : public Product{

public:
    Book(int=0, string="", string="", string="", string="", int=1, int=0);
    string  getTitle();
    string  getAuthors();
    string  getISBN();
    int     getEdition();
    int     getYear();
    virtual string generateString();
    virtual string getData();

private:
    string    title;
    string    authors;
    string    isbn;
    int       edition;
    int       year;
};

#endif