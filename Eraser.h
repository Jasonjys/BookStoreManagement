#ifndef ERASER_H
#define ERASER_H

#include <iostream>

using namespace std;

#include "defs.h"
#include "Product.h"

//Comment Section:
//Eraser is a product and it has material and shape as its data members
class Eraser : public Product {
	
	public:
		Eraser(float=0, string="Unknown", string="Unknown", string="Unknown");
		~Eraser();
		string getMaterial();
		string getShape();
		virtual string generateString();
		virtual string getData();

	private:
		string material;
		string shape;
};

#endif