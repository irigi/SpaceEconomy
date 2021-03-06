#include "stdafx.h"

std::map<std::string, cPlace> cPlace::possiblePlaces;

cPlace cPlace::noPlace("No Place");

void cPlace::InsertByString(const char *str)
{
	cPlace::possiblePlaces.insert(std::pair<std::string, cPlace>(std::string(str), cPlace(str)));
}

cPlace & cPlace::GetByName(const char *name)
{
	std::map<std::string, cPlace>::iterator it = possiblePlaces.find(name);
	if (it != possiblePlaces.end())
	{
		return (*it).second;
	}
	else
	{
		printf("Place not found by name.\n");
		return noPlace;
	}

	return noPlace;
}


cPlace::cPlace(const char * name)
    : m_name(name)
{
}

const char * cPlace::GetName()
{
    return m_name.c_str();
}

void cPlace::AddNode(cNode & node)
{
	m_nodes.push_back(node);
}

void cPlace::Resolve()
{
	m_auction.Resolve();
}

void cPlace::Clear()
{
	for (std::vector<cNode>::iterator it = m_nodes.begin(); it != m_nodes.end(); ++it)
	{
		(*it).Clear();
	}

	m_auction.Clear();
}

void cPlace::PlanActions()
{
	for (std::vector<cNode>::iterator it = m_nodes.begin(); it != m_nodes.end(); ++it)
	{
		(*it).PlanActions();
	}
}