#ifndef PENCIL_H
#define PENCIL_H

#include <iostream>

using namespace std;

#include "defs.h"
#include "Product.h"
 
//Comment section:
//pencil is a product and it has a leadType(e.g. 2H/HB/2B) and a color as its data members
class Pencil : public Product {
	
	public:
		Pencil(float=0, string="Unknown", string="Unknown", string="Unknown");
		~Pencil();
		string getLeadType();
		string getColor();
		virtual string getData();
		virtual string generateString();

	private:
		string leadType;
		string color;
};

#endif