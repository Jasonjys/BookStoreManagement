#include <sstream>
#include "Eraser.h"

Eraser::Eraser(float p, string b, string m, string s)
		:Product(p,b)
{
	material = m;
	shape = s;
}

Eraser::~Eraser()
{

}

string Eraser::getMaterial() { return material; }
string Eraser::getShape() { return shape; }
string Eraser::getData()    {return material;}

string Eraser::generateString() {
	string output;
	string priceStr;
	stringstream ss;

	ss << price;
	priceStr = ss.str();

	output += "\nPrice: " + priceStr
	+ "\nBrand: " + brand
	+ "\nMaterial: " + material
	+ "\nShape: " + shape
	+ "\n___________________________________";

	return output;
}