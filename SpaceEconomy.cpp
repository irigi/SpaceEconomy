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
	cNoStrategy strategy;
    cNode node(cPlace::GetByName("Merkur"), cPlace::GetByName("Merkur"), cPlace::GetByName("Merkur"), cNoStrategy::getInstance());
    cNodeInput nodeI(resource, 1.0);
    node.AddNodeInput(nodeI);
	cNodeOutput nodeO(resource, 1.0, 1.0);
	node.AddNodeOutput(nodeO);

    cSellOrder orderS(node, nodeO);
	cBuyOrder orderB(node, nodeI);

    orderS.Set(100, 10.0);
    auctionEarth.AddSellOrder(orderS);

    orderS.Set(100, 20.0);
    auctionEarth.AddSellOrder(orderS);

	orderS.Set(10, 5.0);
	auctionEarth.AddSellOrder(orderS);

    orderB.Set(100, 7.0);
	auctionEarth.AddBuyOrder(orderB);

	printf("top sell bid %f, amount %f\n", auctionEarth.GetLowestSell().GetPrice(), auctionEarth.GetLowestSell().GetAmount());
	printf("top buy bid %f, amount %f\n", auctionEarth.GetHighestBuy().GetPrice(), auctionEarth.GetHighestBuy().GetAmount());

	auctionEarth.Resolve();

	printf("top sell bid %f, amount %f\n", auctionEarth.GetLowestSell().GetPrice(), auctionEarth.GetLowestSell().GetAmount());
    printf("top buy bid %f, amount %f\n", auctionEarth.GetHighestBuy().GetPrice(), auctionEarth.GetHighestBuy().GetAmount());

    printf("ID of food is %d\n", cResource::GetByName("food").GetID());

    getchar();
}

int main()
{
    InitializeResourceTypes();
    InitializePlaces();

	const long iterations = 5;

	for (int i = 0; i < iterations; ++i)
	{
		for (std::map<std::string, cPlace>::iterator it = cPlace::possiblePlaces.begin(); it != cPlace::possiblePlaces.end(); ++it)
		{
			(*it).second.Clear();
		}

		for (std::map<std::string, cPlace>::iterator it = cPlace::possiblePlaces.begin(); it != cPlace::possiblePlaces.end(); ++it)
		{
			(*it).second.PlanActions();
		}

		for (std::map<std::string, cPlace>::iterator it = cPlace::possiblePlaces.begin(); it != cPlace::possiblePlaces.end(); ++it)
		{
			(*it).second.Resolve();
		}
	}

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
	cPlace::InsertByString("Neptun");
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