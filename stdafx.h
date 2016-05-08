// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <vector>

#include "Resource.h"
#include "Order.h"
#include "Auction.h"
#include "Place.h"
#include "Strategy.h"
#include "Node.h"

extern void InitializeResourceTypes();
extern void InitializePlaces();

#define MARGIN		1.2
#define BINS		10
#define BIN_MULT	0.1


// TODO: reference additional headers your program requires here
