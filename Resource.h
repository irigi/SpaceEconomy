#ifndef RESOURSCE_GUARD_H
#define RESOURSCE_GUARD_H

class cResource
{
public:
    cResource();
    int GetID() const;
    bool operator <(const cResource &x) const;
    bool operator ==(const cResource &x) const;
    bool operator !=(const cResource &x) const;

private:
    int m_id;

    static int uniqueID;
};


#endif