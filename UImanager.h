#ifndef UIMANAGER_H
#define UIMANAGER_H

#include "Dlist.h"
#include "Pencil.h"
#include "Eraser.h"
#include "Laptop.h"

#define TEST_MODE

//The UI class deals with all the output and the input from the console
class UImanager {
	public:
		~UImanager();
		void mainMenu(int*);
		void subMenuAdd(int*);
		void subMenuRemove(int*);
		void subMenuProduct(int*);
		void subProductSearch(int*);
		void subMenuBuy(int*);
		void getCourseData(Course**);
		void getPencilData(Pencil**);
		void getEraserData(Eraser**);
		void getLaptopData(Laptop**);
		void printCourses(Dlist<Course*>*);
		void coutString(string&);
		void pause();
		bool getNumCourse(int&);
		string getCourseCode();
		void getBookData(Book**);
		void listBooks(Course*);
		void cDeletedMessage();
		void cAddedMessage();
		void cNotExist();
		string getString(string, string);
		void purchased(float&);
		void purchasedFailed();
		void promoted();
	private:
		int getInt();
};

#endif
