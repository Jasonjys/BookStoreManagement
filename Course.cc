#include <string>
#include <sstream>
#include "Course.h"

Course::Course(string s, string nu, string na, string i, int e)
{
	subj  = s;
	num   = nu;
	name  = na;
	instr = i;
	enrol = e;
	books = new BookArray();
}

Course::~Course()
{
	delete books;
}

string Course::getCode()      { return subj + num; }
string Course::getName()      { return name; }
string Course::getInstr()     { return instr; }
int    Course::getEnrol()     { return enrol; }
BookArray* Course::getBookArray() {return books;}

bool Course::operator==(string& str)
{
	return getCode() == str;
}


int Course::getNumBooks()  { return books->getSize(); }

void Course::addBook(Book* b)  
{ 
	books->add(b);
}

void Course::BooksString(string& output)
{
	if(getNumBooks() == 0)
	{
		output = "\nThis course has no textbook\n";
		return;
	}

	for(int i = 0; i<getNumBooks(); i++)
	{
		int editionint = books->getBook(i)->getEdition();
		int yearint = books->getBook(i)->getYear();
		string edtion;
		string year;
		stringstream ss;
		stringstream ff;

		ss << editionint;
		edtion = ss.str();
		ff << yearint;
		year = ff.str();
		
		output += "\nTitle: " + books->getBook(i)->getTitle()
		+ "\nAuthors: " + books->getBook(i)->getAuthors()
		+ "\nISBN: " + books->getBook(i)->getISBN()
		+ "\nEdition: " + edtion
		+ "\nYear: " + year
		+ "\n___________________________________";
	}
}

string& operator+=(string& outStr, Course& course)
{
	int enrolint  = course.getEnrol();
	int numBookint = course.getNumBooks();
	string enrol;
	string numBook;
	stringstream ss;
	stringstream ff;
	ss << enrolint;
	enrol = ss.str();
	ff << numBookint;
	numBook = ff.str();

	string code   = course.getCode();
	string name   = course.getName();
	string instr  = course.getInstr();
	
	
	outStr += "Course code: " + code + "\nCourse name: " 
	+ name + "\nInstructor: " + instr + "\nEnrolment: " 
	+ enrol + "\nNumber of Textbooks: " 
	+ numBook + "\n\n";

	//cout << "in course" + outStr << endl;
	return outStr;
}