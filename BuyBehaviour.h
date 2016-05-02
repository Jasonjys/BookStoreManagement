#ifndef BUYBEHAVIOUR_B_H
#define BUYBEHAVIOUR_B_H

#include "Product.h"

//BuyBehaviour has a pure virctual function "buy"
//BronzeBuy gets no dicount and save the index of the product to the output parameter
//SilverBuy gets 10% dicount and save the index of the product to the output parameter
//GoldBuy gets 25% dicount and save the index of the product to the output parameter
class BuyBehaviour
{
  public:
    virtual bool buy(Product**, int&, string&, int&, float&, float&) = 0;
    virtual ~BuyBehaviour();
};

class BronzeBuy : public BuyBehaviour
{
  public:
    virtual bool buy(Product**, int&, string&, int&, float&, float&);
    ~BronzeBuy();
};

class SilverBuy : public BuyBehaviour
{
  public:
    virtual bool buy(Product**, int&, string&, int&, float&, float&);
    ~SilverBuy();
};

class GoldBuy : public BuyBehaviour
{
  public:
    virtual bool buy(Product**, int&, string&, int&, float&, float&);
    ~GoldBuy();
};


#endif
