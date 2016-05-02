
#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

using namespace std;

#include "defs.h"

//Comment Section:
//The Base class is called Product every product has a price and a brand
//The pure virtual function "type" returns the string says the type of the product
//The pure virtual function "generateString" returns the string of all the product infomation based on the type of the product
class Product{

  public:
    Product(float=0,string="unknown");
    virtual~Product();
    float  getPrice();
    string  getBrand();
    virtual string generateString() = 0;
    virtual string getData() = 0;

  protected:
    float   price;
    string  brand;
};

#endif

