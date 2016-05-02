#ifndef BOOK_ARRAY_H
#define BOOK_ARRAY_H

#include "Book.h"

//The book array class has an array of book pointers
//Data members:
//An array of book pointers
//A size

//Member Functions:
//add function
//get function
//get size function
class BookArray
{
public:
	BookArray();
	~BookArray();
	void add(Book*);
	Book* getBook(int);
	int  getSize();
private:
	int  size;
	Book *books[MAX_BOOKS];
};

#endif
