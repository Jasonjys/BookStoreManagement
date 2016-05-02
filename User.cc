#include <iostream>
using namespace std;
#include <string>

#include "User.h"

User::User() : totalPurchases(0.0), membershipStatus("Bronze")
{
  buyB = new BronzeBuy;
}

User::~User() 
{ 
  delete buyB;
}

void User::setTotal(float newTotal)
{
  totalPurchases = newTotal;
}

float User::getTotal() { return totalPurchases; }

void User::setBuy(BuyBehaviour* b)
{
  delete buyB;
  buyB = b;
}

string User::getMembership() { return membershipStatus; }

void User::changeStats()
{
  if(membershipStatus == "Bronze")
  {
    setBuy(new SilverBuy);
    membershipStatus = "Silver";
  }
  else if(membershipStatus == "Silver")
  {
    setBuy(new GoldBuy);
    membershipStatus = "Gold";
  }
}

bool User::buy(Product** arr, int& size, string& input, int& index, float& total, float& discountedPrice)
{
  return buyB->buy(arr, size, input, index, total, discountedPrice);
}

string User::membership()
{
  string str;
  string discount;

  if (membershipStatus == "Bronze") 
    discount = "0%";

  if (membershipStatus == "Silver")
    discount ="10%";

  if (membershipStatus == "Gold")
    discount ="25%";

  str = "\nYou are a " + membershipStatus + " member! You will have " + discount + " off every purchase.";
  return str;
}
