// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <queue>
#include <map>
#include <vector>
#include <iostream>

#include "Resource.h"
#include "Order.h"
#include "Auction.h"
#include "Place.h"
#include "Node.h"


extern std::vector<cResource> possibleResources;
extern void InitializeResourceTypes();

extern std::vector<cPlace> possiblePlaces;
extern void InitializePlaces();


// TODO: reference additional headers your program requires here
