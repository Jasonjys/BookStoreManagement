#include <iostream>
using namespace std;
#include <string>

#include "Product.h"


Product::Product(float p, string b)
    : price(p), brand(b)
{ 
}

Product::~Product()
{
}

float    Product::getPrice()   { return price; }

string Product::getBrand()  { return brand; }