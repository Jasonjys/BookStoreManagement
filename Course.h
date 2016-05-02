#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>

using namespace std;

#include "defs.h"
#include "BookArray.h"

class Course {

	friend string& operator+=(string&, Course&);
	public:
		Course(string="", string="", string="", string="", int=0);
		~Course();
		string  getCode();
		string  getName();
		string  getInstr();
		int     getEnrol();
		int     getNumBooks();
		void    addBook(Book*);
		void    BooksString(string&);
		bool    operator==(string&);
		BookArray* getBookArray();



	private:
		string    subj;
		string    num;
		string    name;
		string    instr;
		int       enrol;
		BookArray *books;
};

#endif

