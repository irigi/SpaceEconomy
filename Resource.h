#ifndef RESOURSCE_GUARD_H
#define RESOURSCE_GUARD_H

class cResource
{
public:
    cResource(const char *name);
    int GetID() const;
    const std::string & GetName();
    bool operator <(const cResource &x) const;
    bool operator ==(const cResource &x) const;
    bool operator !=(const cResource &x) const;

    static cResource &GetByName(const char *name);
    static void InsertByString(const char *str);
	static cResource noResource;

private:
    int m_id;
    std::string m_name;

    static int uniqueID;
    static std::map<std::string, cResource> possibleResources;
};


#endif