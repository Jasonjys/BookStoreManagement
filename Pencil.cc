#include <sstream>
#include "Pencil.h"

Pencil::Pencil(float p, string b, string lt, string c)
		:Product(p,b)
{
	leadType = lt;
	color = c;
}

Pencil::~Pencil()
{
	
}

string Pencil::getData()    {return leadType;}
string Pencil::getLeadType()    { return leadType; }
string Pencil::getColor()  { return color; }


string Pencil::generateString() {
	string output;
	string priceStr;	
	stringstream ss;

	ss << price;
	priceStr = ss.str();

	output += "\nPrice: " + priceStr
	+ "\nBrand: " + brand
	+ "\nLead type: " + leadType
	+ "\nColor: " + color
	+ "\n___________________________________";

	return output;
}