// SpaceEconomy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void Test()
{

    for(std::map<std::string, cPlace>::iterator it = cPlace::possiblePlaces.begin(); it != cPlace::possiblePlaces.end(); it++)
    {
        printf("%s\n", (*it).second.GetName());
    }

    cResource resource("test");
    cAuction auctionEarth;
    cNode node(cPlace::GetByName("Merkur"), cPlace::GetByName("Merkur"), cPlace::GetByName("Merkur"));
    cNodeInput nodeIO(resource, 1.0);
    node.AddNodeInput(nodeIO);
    cSellOrder order(node);

    order.Set(100, 10.0);
    auctionEarth.AddSellOrder(order);

    order.Set(100, 20.0);
    auctionEarth.AddSellOrder(order);

    printf("top bid %f\n", auctionEarth.GetLowestSell().GetPrice());

    order.Set(100, 30.0);

    printf("top bid %f\n", auctionEarth.GetHighestBuy().GetPrice());

    printf("ID of food is %d\n", cResource::GetByName("food").GetID());

    getchar();
}

int main()
{
    InitializeResourceTypes();
    InitializePlaces();

    Test();

	return 0;
}

void InitializePlaces()
{
	cPlace::InsertByString("Merkur");
	cPlace::InsertByString("Venuse");
	cPlace::InsertByString("Zeme");
	cPlace::InsertByString("Mars");
	cPlace::InsertByString("Ceres");
	cPlace::InsertByString("Jupiter");
	cPlace::InsertByString("Saturn");
	cPlace::InsertByString("Uran");
	cPlace::InsertByString("Pluto");

}

void InitializeResourceTypes()
{
	cResource::InsertByString("water");
	cResource::InsertByString("oxygen");
	cResource::InsertByString("nitrogen");
	cResource::InsertByString("iron");
	cResource::InsertByString("food");
	cResource::InsertByString("work");
}