#ifndef LAPTOP_H
#define LAPTOP_H

#include <iostream>
#include <string>

using namespace std;

#include "defs.h"
#include "Product.h"


//Comment Section:
//Laptop is a product. It has a screen size and a hard drive size as its data members
class Laptop : public Product{

  public:
    Laptop(float=1200, string="Apple", string="15", string="1000");
    ~Laptop();
    string  getScreenSize();
    string  getHardDriveSize();
    virtual string getData();
    virtual string generateString();

  private:
    string    screenSize;
    string    hardDriveSize;
};

#endif

