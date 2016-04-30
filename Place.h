#ifndef PLACE_GUARD_H
#define PLACE_GUARD_H

class cPlace
{
public:
    cPlace(const char * name);
    const char * GetName();

private:
    std::string m_name;
};


#endif