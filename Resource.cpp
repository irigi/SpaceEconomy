#include "stdafx.h"

int cResource::uniqueID = 0;

cResource cResource::noResource("no resource");

std::map<std::string, cResource> cResource::possibleResources;

cResource & cResource::GetResourceByName(const char *name)
{
    std::string nameAsStr(name);

    std::map<std::string, cResource>::iterator it = possibleResources.find(nameAsStr);
    if (it != possibleResources.end())
    {
        return (*it).second;
    }
    else
    {
        printf("Resource not found by name.\n");
        return noResource;
    }
}

cResource::cResource(const char *name)
{
    m_id = uniqueID;
    m_name = name;
    ++uniqueID;
}

int cResource::GetID() const
{
    return m_id;
}

bool cResource::operator <(const cResource &x) const
{
    return m_id < x.m_id;
}

bool cResource::operator ==(const cResource &x) const
{
    return m_id == x.m_id;
}

bool cResource::operator !=(const cResource &x) const
{
    return m_id != x.m_id;
}