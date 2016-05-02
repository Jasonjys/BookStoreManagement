#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
#include "UImanager.h"

using namespace std;
UImanager::~UImanager()
{
  
}

void UImanager::mainMenu(int* choice)
{
  string str;

  *choice = -1;

cout << "\nMembership terms & conditions: " << endl;
  cout << " - There are 3 types of memberships, bronze, silver and gold." << endl;
  cout << " - If your total purchases reach $100 and above, you will get promoted to silver rank." << endl;
  cout << " - If your total purchases reach $300 and above, you will get promoted to gold rank." << endl;
  cout << " - NOTE: You are not allowed to rank up twice in one transaction.";

  cout << endl << endl << "WELCOME TO THE BOOKSTORE MANAGEMENT SYSTEM" << endl<<endl;
  cout << "  Course Management:" << endl;
  cout << "  ( 1 )  Add course" << endl;
  cout << "  ( 2 )  Delete course" << endl;
  cout << "  ( 3 )  List all courses" << endl << endl;
  cout << "  Textbook Management:" << endl;
  cout << "  ( 4 )  Add textbook" << endl;
  cout << "  ( 5 )  List course textbooks" << endl << endl;
  cout << "  Product Management:" << endl;
  cout << "  ( 6 )  Add product"  << endl;
  cout << "  ( 7 )  Buy a product" << endl; 
  cout << "  ( 8 )  List all products"  << endl;
  cout << "  ( 9 )  View membership status" << endl << endl;

  cout << "  ( 0 )  Exit" << endl << endl;

  while (*choice < 0 || *choice > 9) {
    cout << "Enter your selection:  ";
    *choice = getInt();
  }
}

void UImanager::subMenuBuy(int* choice)
{
  string str;

  *choice = -1;

  cout << "\nWhat product do you want to buy?" << endl;
  cout << "\n  ( 1 )  Book" << endl;
  cout << "  ( 2 )  Laptop" << endl;
  cout << "  ( 3 )  Eraser" << endl;
  cout << "  ( 4 )  Pencil" << endl;
  cout << "  ( 0 )  Return to main menu" << endl << endl;

  while (*choice < 0 || *choice > 4) {
    cout << "Enter your selection:  ";
    *choice = getInt();
  }
}
void UImanager::subMenuAdd(int* choice)
{
  string str;

  *choice = -1;

  cout << "\n  ( 1 )  Add one course" << endl;
  cout << "  ( 2 )  Add multiple courses" << endl;
  cout << "  ( 0 )  Return to main menu" << endl << endl;

  while (*choice < 0 || *choice > 2) {
    cout << "Enter your selection:  ";
    *choice = getInt();
  }
}

void UImanager::subMenuRemove(int* choice)
{
  string str;

  *choice = -1;

  cout << "\n  ( 1 )  Delete one course" << endl;
  cout << "  ( 2 )  Delete multiple courses" << endl;
  cout << "  ( 0 )  Return to main menu" << endl << endl;

  while (*choice < 0 || *choice > 2) {
    cout << "Enter your selection:  ";
    *choice = getInt();
  }
}

void UImanager::subMenuProduct(int* choice)
{
  string str;
  cout << "\n  ( 1 )  Add book" << endl;
  cout << "  ( 2 )  Add laptop" << endl;
  cout << "  ( 3 )  Add Eraser" << endl;
  cout << "  ( 4 )  Add pencil" << endl;
  cout << "  ( 0 )  Return to main menu" << endl << endl;

  while (*choice < 0 || *choice > 4) {
    cout << "Enter your selection:  ";
    *choice = getInt();
  }
}

void UImanager::subProductSearch(int* choice)
{
  string str;
  cout << "\n What product do you want to search for?" << endl;
  cout << "  ( 1 )  Book" << endl;
  cout << "  ( 2 )  Laptop" << endl;
  cout << "  ( 3 )  Eraser" << endl;
  cout << "  ( 4 )  Pencil" << endl;
  cout << "  ( 0 )  Return to main menu" << endl << endl;

  while (*choice < 0 || *choice > 4) {
  cout << "Enter your selection:  ";
  *choice = getInt();
  }
}

bool UImanager::getNumCourse(int& num)
{
  string str = "";
  cout << endl;

  cout << endl << "Enter a number:  ";
  getline(cin, str);
  stringstream ss(str);
  ss >> num;

  if(num < 0)
  {
    cout << endl << "Please enter a positive number";
    return false;
  }

  return true;
}

//getCourseData gets info form the user and dynamically allocate the course 
//object on the heap
void UImanager::getCourseData(Course** course)
{
  string    str = "";
  string    subj, num, name, inst;
  int       enrol;

  cout << endl;

  while (str.length() != 8) {
    cout << "Enter course code (e.g. COMP2404):  ";
    getline(cin, str);
  }
  subj = str.substr(0,4);
  num  = str.substr(4);

  cout << endl << "Enter course name (e.g. Introduction to SE):  ";
  getline(cin, name);

  cout << endl << "Enter instructor name:   ";
  getline(cin, inst);

  cout << endl << "Enter enrolment:   ";
  getline(cin, str);
  stringstream ss(str);
  ss >> enrol;

  Course *tmpcourse = new Course(subj, num, name, inst, enrol);
	
	
  (*course) = tmpcourse;	
}

//getPencilData gets info form the user and dynamically allocate the pencil 
//object on the heap
void UImanager::getPencilData(Pencil** pencil)
{
  string    str = "";
  string    leadType, color, brand;
  float       price;

  cout << endl;
  
  cout << endl << "Enter price:  ";
  getline(cin, str);
  stringstream xx(str);
  xx >> price;

  cout << endl << "Enter brand:   ";
  getline(cin, brand);

  cout << endl << "Enter leadtype (e.g. 2B/2H/HB):  ";
  getline(cin, leadType);

  cout << endl << "Enter color:   ";
  getline(cin, color);

  Pencil *tmppencil = new Pencil(price, brand, leadType, color);
  
  (*pencil) = tmppencil; 
}

//getEraserData gets info form the user and dynamically allocate the eraser 
//object on the heap
void UImanager::getEraserData(Eraser** eraser)
{
  string    str = "";
  string    material, brand, shape;
  float       price;

  cout << endl;
  
  cout << endl << "Enter price:  ";
  getline(cin, str);
  stringstream xx(str);
  xx >> price;

  cout << endl << "Enter brand:   ";
  getline(cin, brand);

  cout << endl << "Enter material (e.g. rubber/vinyl/synthetic/gum):   ";
  getline(cin, material);

  cout << endl << "Enter shape:   ";
  getline(cin, shape);

  Eraser *tmpEraser = new Eraser(price, brand, material, shape);
  
  (*eraser) = tmpEraser; 
}

//getLaptopData gets info form the user and dynamically allocate the laptop 
//object on the heap
void UImanager::getLaptopData(Laptop** laptop)
{
  string    str = "";
  string    screenSize, brand, hardDriveSize;
  float       price;

  cout << endl;
  
  cout << endl << "Enter price:  ";
  getline(cin, str);
  stringstream xx(str);
  xx >> price;

  cout << endl << "Enter brand:   ";
  getline(cin, brand);

  cout << endl << "Enter screen size in inch (e.g. 13/15/17):   ";
  getline(cin, screenSize);

  cout << endl << "Enter hard drive size in gigabytes:   ";
  getline(cin, hardDriveSize);

  Laptop *tempLaptop = new Laptop(price, brand, screenSize, hardDriveSize);
  
  (*laptop) = tempLaptop;
}

void UImanager::printCourses(Dlist<Course*> *list)
{
  cout << endl << endl << "ALL COURSES:" << endl << endl;
  string outStr;
  outStr << *list;

  cout << outStr << endl;
}

void UImanager::pause()
{
  string str;

  cout << endl << "\nPress enter to continue...";
  getline(cin, str);
}

int UImanager::getInt()
{
  string str;
  int    num;

  getline(cin, str);
  stringstream ss(str);
  ss >> num;

  return num;
}

string UImanager::getCourseCode()
{
	string str = "";

  cout << endl;

  while (str.length() != 8) {
    cout << "Enter course code (e.g. COMP2404):  ";
    getline(cin, str);
  }

  return str;
}

//getBookData gets info form the user and dynamically allocate the book 
//object on the heap
void UImanager::getBookData(Book** book)
{
	string    str = "";
  string    title, authors, isbn, brand;
  int       edition, year;
  float price;

  cout << endl;
	
  cout << endl << "Enter price:  ";
  getline(cin, str);
  stringstream xx(str);
  xx >> price;

  cout << endl << "Enter brand:   ";
  getline(cin, brand);

	cout << endl << "Enter title:  ";
  getline(cin, title);

  cout << endl << "Enter author name:   ";
  getline(cin, authors);

  cout << endl << "Enter isbn:   ";
	getline(cin, isbn);

	cout << endl << "Enter edition:    ";
  getline(cin, str);
  stringstream ss(str);
  ss >> edition;

	cout << endl << "Enter year:    ";
  getline(cin, str);
  stringstream ff(str);
  ff >> year;
	
	Book *tmpbook = new Book(price, brand, title, authors, isbn, edition, year);
	
	(*book) = tmpbook;

}


void UImanager::cDeletedMessage()
{
  cout << endl << "The course is now deleted!" << endl;
}
void UImanager::cAddedMessage()
{
  cout << endl << "The course is now added!" << endl;
}

void UImanager::cNotExist()
{
  cout << endl << "Course does not exist" << endl;
}

void UImanager::listBooks(Course* course)
{
  string bookString;
	course->BooksString(bookString);
  cout << bookString;
}

void UImanager::coutString(string& output)
{
  cout << output;
}

string UImanager::getString(string data, string type){
  string str;
  cout<< endl << "\nPlease enter the " + data + " of the " + type + " you want:" << endl;

  getline(cin, str);
  return str;
}

void UImanager::purchased(float& price)
{
  string priceStr;

  stringstream ss;
  ss << price;
  priceStr = ss.str();

  cout << "\nYou have purchased this product for $" + priceStr + ":" << endl;
}

void UImanager::purchasedFailed()
{
  cout << "\nWe couldn't find the product you are looking for" << endl;
}

void UImanager::promoted()
{
  cout << "\n\nCongratulations! You have been promoted. (You can check your membership status on the main menu)" << endl;
}