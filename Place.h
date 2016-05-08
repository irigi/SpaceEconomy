#ifndef PLACE_GUARD_H
#define PLACE_GUARD_H

class cAuction;
class cNode;

class cPlace
{
public:
    cPlace(const char * name);
    const char * GetName();

	void AddNode(cNode & node);
	void Resolve();
	void Clear();
	void PlanActions();

	static cPlace &GetByName(const char *name);
	static void InsertByString(const char *str);
	static cPlace noPlace;
	static std::map<std::string, cPlace> possiblePlaces;

private:
    std::string m_name;
	cAuction m_auction;
	std::vector<cNode> m_nodes;
};


#endif