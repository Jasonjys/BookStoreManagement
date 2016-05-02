#include <sstream>
#include "Book.h"

Book::Book(int p, string b, string t, string a, string i, int e, int y)
:Product(p,b)
{
	title   = t;
	authors = a;
	isbn    = i;
	edition = e;
	year    = y;
}

string Book::getData()     { return title; }
string Book::getTitle()    { return title; }
string Book::getAuthors()  { return authors; }
string Book::getISBN()     { return isbn; }
int    Book::getEdition()  { return edition; }
int    Book::getYear()     { return year; }

string Book::generateString() {
	string output;

	string editionStr;
	string yearStr;
	string priceStr;

	stringstream ss;
	stringstream ff;
	stringstream xx;

	xx << price;
	priceStr = xx.str();

	ss << edition;
	editionStr = ss.str();

	ff << year;
	yearStr = ff.str();
	
	output += "\nPrice: " + priceStr
	+ "\nBrand: " + brand
	+ "\nTitle: " + title
	+ "\nAuthors: " + authors
	+ "\nISBN: " + isbn
	+ "\nEdition: " + editionStr
	+ "\nYear: " + yearStr
	+ "\n___________________________________";

	return output;
}