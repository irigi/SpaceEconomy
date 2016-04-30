// SpaceEconomy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

std::vector<cPlace> possiblePlaces;

void Test()
{
    for(unsigned int i = 0; i < possiblePlaces.size(); ++i)
    {
        printf("%s\n", possiblePlaces.at(i).GetName());
    }

    //cAuction auctionEarth;
    //cSellOrder order;

    //order.Set(100, 10.0);
    //auctionEarth.AddSellOrder(order);

    //order.Set(100, 20.0);
    //auctionEarth.AddSellOrder(order);

    //printf("top bid %f\n", auctionEarth.GetLowestSell().GetPrice());

    //order.Set(100, 30.0);

    //printf("top bid %f\n", auctionEarth.GetHighestBuy().GetPrice());
    getchar();
}

int _tmain(int argc, _TCHAR* argv[])
{
    InitializeResourceTypes();
    InitializePlaces();

    Test();


	return 0;
}

void InitializePlaces()
{
    cPlace Merkur = cPlace("Merkur");
    possiblePlaces.push_back(Merkur);

    cPlace Venuse = cPlace("Venuse");
    possiblePlaces.push_back(Venuse);

    cPlace Zeme = cPlace("Zeme");
    possiblePlaces.push_back(Zeme);

    cPlace Mesic = cPlace("Mesic");
    possiblePlaces.push_back(Mesic);

    cPlace Mars = cPlace("Mars");
    possiblePlaces.push_back(Mars);

    cPlace Ceres = cPlace("Ceres");
    possiblePlaces.push_back(Ceres);

    cPlace Jupiter = cPlace("Jupiter");
    possiblePlaces.push_back(Jupiter);

    cPlace Saturn = cPlace("Saturn");
    possiblePlaces.push_back(Saturn);

    cPlace Uran = cPlace("Uran");
    possiblePlaces.push_back(Uran);

    cPlace Neptun = cPlace("Neptun");
    possiblePlaces.push_back(Neptun);

    cPlace Pluto = cPlace("Pluto");
    possiblePlaces.push_back(Pluto);
}