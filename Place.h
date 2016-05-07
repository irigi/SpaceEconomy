#ifndef PLACE_GUARD_H
#define PLACE_GUARD_H

class cPlace
{
public:
    cPlace(const char * name);
    const char * GetName();

	static cPlace &GetByName(const char *name);
	static void InsertByString(const char *str);
	static cPlace noPlace;
	static std::map<std::string, cPlace> possiblePlaces;

private:
    std::string m_name;
};


#endif