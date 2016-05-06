#ifndef RESOURSCE_GUARD_H
#define RESOURSCE_GUARD_H

class cResource
{
public:
    cResource(const char *name);
    int GetID() const;
    const char * GetName();
    bool operator <(const cResource &x) const;
    bool operator ==(const cResource &x) const;
    bool operator !=(const cResource &x) const;

    static cResource &GetResourceByName(const char *name);

private:
    int m_id;
    std::string m_name;

    static int uniqueID;
    static std::map<std::string, cResource> possibleResources;
    static cResource noResource;
};


#endif