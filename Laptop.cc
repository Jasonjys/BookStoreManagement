#include <sstream>
#include "Laptop.h"

Laptop::Laptop(float p, string b, string s, string hd)
		:Product(p,b)
{
	screenSize = s;
	hardDriveSize = hd;
}

Laptop::~Laptop(){}

string Laptop::getData()        { return screenSize; }
string Laptop::getScreenSize() { return screenSize; }
string Laptop::getHardDriveSize() { return hardDriveSize; }

string Laptop::generateString() {
	string output;
	string priceStr;	
	stringstream ss;

	ss << price;
	priceStr = ss.str();

	output += "\nPrice: " + priceStr
	+ "\nBrand: " + brand
	+ "\nScreen size: " + screenSize
	+ "\nHard drive size: " + hardDriveSize
	+ "\n___________________________________";

	return output;
}