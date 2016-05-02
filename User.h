#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

#include "Product.h"
#include "BuyBehaviour.h"

using namespace std;


//User class has a BuyBehaviour and user switch buy behaviour if their membership rank up
// - There are 3 types of memberships, bronze, silver and gold.
// - If user's total purchases reach $100 and above, he/she will get promoted to silver rank.
// - If user's total purchases reach $300 and above, he/she will get promoted to gold rank.
// - NOTE: User is not allowed to rank up twice in one transaction.

//Bronze user gets on discount.
//Silver user gets 10% off.
//Gold user gets 25% off.

//When the user wants to buy a product, he/she can search the product by their brand and if
//the user wants to buy a book, he/she can search books by title
class User
{
	public:
		User();
		~User();
		bool buy(Product**, int&, string&, int&, float&, float&);
		void searchProduct();
		void setBuy(BuyBehaviour*);
		void changeStats();
		string getMembership();
		void setTotal(float);
		float getTotal();
		string membership();

	protected:
		float totalPurchases;
		string membershipStatus;
		BuyBehaviour* buyB;
};

#endif