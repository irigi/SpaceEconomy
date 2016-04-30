// SpaceEconomy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



int _tmain(int argc, _TCHAR* argv[])
{
    cAuction auctionEarth;
    cSellOrder order;

    order.Set(100, 10.0);
    auctionEarth.AddSellOrder(order);

    order.Set(100, 20.0);
    auctionEarth.AddSellOrder(order);

    printf("top bid %f\n", auctionEarth.GetLowestSell().GetPrice());

    order.Set(100, 30.0);

    printf("top bid %f\n", auctionEarth.GetHighestBuy().GetPrice());
    getchar();


	return 0;
}

