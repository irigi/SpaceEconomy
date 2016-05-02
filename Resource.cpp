#include "stdafx.h"

int cResource::uniqueID = 0;

cResource::cResource()
{
    m_id = uniqueID;
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