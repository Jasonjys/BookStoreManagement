#include <iostream>
using namespace std;

#include "BuyBehaviour.h"
#include "Product.h"

BuyBehaviour::~BuyBehaviour() {}
BronzeBuy::~BronzeBuy() {}
SilverBuy::~SilverBuy() {}
GoldBuy::~GoldBuy() {}

bool BronzeBuy::buy(Product** products, int& size, string& input, int& output, float& totalPurchase, float& discountedPrice)
{
	float discount = 0;
	for (int i=0; i<size; i++) 
	{
		if(products[i]->getData() == input)
		{
			float price = products[i]->getPrice();
			discountedPrice = price - (price * discount);
			totalPurchase +=  discountedPrice;
			output = i;
			return true;
		}
		else
		{
			if(products[i]->getBrand() == input)
			{
				float price = products[i]->getPrice();
				discountedPrice = price - (price * discount);
				totalPurchase +=  discountedPrice;
				output = i;
				return true;
			}
		}
	}
	return false;
}

bool SilverBuy::buy(Product** products, int& size, string& input, int& output, float& totalPurchase, float& discountedPrice)
{
	float discount = 0.1;
	for (int i=0; i<size; i++) 
	{
		if(products[i]->getData() == input)
		{
			float price = products[i]->getPrice();
			discountedPrice = price - (price * discount);
			totalPurchase +=  discountedPrice;
			output = i;
			return true;
		}
		else
		{
			if(products[i]->getBrand() == input)
			{
				float price = products[i]->getPrice();
				discountedPrice = price - (price * discount);
				totalPurchase +=  discountedPrice;
				output = i;
				return true;
			}
		}
	}
	return false;
}

bool GoldBuy::buy(Product** products, int& size, string& input, int& output, float& totalPurchase, float& discountedPrice)
{
	float discount = 0.25;
	for (int i=0; i<size; i++) 
	{
		if(products[i]->getData() == input)
		{
			float price = products[i]->getPrice();
			discountedPrice = price - (price * discount);
			totalPurchase +=  discountedPrice;
			output = i;
			return true;
		}
		else
		{
			if(products[i]->getBrand() == input)
			{
				float price = products[i]->getPrice();
				discountedPrice = price - (price * discount);
				totalPurchase +=  discountedPrice;
				output = i;
				return true;
			}
		}
	}
	return false;
}
