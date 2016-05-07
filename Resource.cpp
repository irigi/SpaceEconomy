#include "stdafx.h"

int cResource::uniqueID = 0;

cResource cResource::noResource("no resource");

std::map<std::string, cResource> cResource::possibleResources;

void cResource::InsertByString(const char *str)
{
	cResource::possibleResources.insert(std::pair<std::string, cResource>(std::string(str), cResource(str)));
}

cResource & cResource::GetByName(const char *name)
{
    std::map<std::string, cResource>::iterator it = possibleResources.find(name);
    if (it != possibleResources.end())
    {
        return (*it).second;
    }
    else
    {
        printf("Resource not found by name.\n");
        return noResource;
    }

    return noResource;
}

cResource::cResource(const char *name)
{
    m_id = uniqueID;
    m_name = name;
    ++uniqueID;
}

const std::string & cResource::GetName()
{
	return m_name;
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