#include "stdafx.h"

cPlace::cPlace(const char * name)
    : m_name(name)
{
}

const char * cPlace::GetName()
{
    return m_name.c_str();
}
