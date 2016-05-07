#include "stdafx.h"

void cResource::InsertByString(const char *str)
{
    //cResource::possibleResources.insert(std::pair<std::string, cResource>(std::string(str), cResource(str)));
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