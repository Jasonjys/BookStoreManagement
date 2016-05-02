#ifndef BMS_CONTROL_H
#define BMS_CONTROL_H

#include "defs.h"
#include "UImanager.h"
#include "Dlist.h"
#include "Product.h"
#include "User.h"

//Data members:
//BMScontrol class has a view and a dlist
//It has a c-style array contains an array of product pointers
//size if for keep track of the size of the array
//It has a user(the person who is using the program)

//Member functions:
//addProduct function takes a product pointer and add it into the product array
//removeProduct function takes a product pointer and remove it from the product array
//checkCourse function takes an array of product pointers and a course code to check if it exist
//generateString function takes a string and writes all the product info to that string
//clearnUp function loops through the product array and deallocates all the objects

class BMScontrol {
public:
    BMScontrol();
    ~BMScontrol();
    void launch();

private:
    UImanager*   view;
    Dlist<Course*>* courses;
    Product* products[MAX_PRODUCTS];
    User* user;
    int size;
    void addProduct(Product*);
    void deleteProduct(Product*);
    void generateString(string&);
    void cleanUp();
    bool checkCourse(string&, Course**);
};

#endif