#include "stdafx.h"

cOrder::cOrder(cNode & sourceNode) :
    m_sourceNode(sourceNode)
{
}

cOrder & cOrder::operator=(const cOrder & x)
{
    m_amount = x.GetAmount();
    m_price = x.GetPrice();

    return *this;
}

void cOrder::Set(double amount, double price)
{
    m_amount = amount;
    m_price = price;
}

double cOrder::GetAmount() const
{
    return m_amount;
}

double cOrder::GetPrice() const
{
    return m_price;
}

cSellOrder::cSellOrder(cNode & sourceNode) :
    cOrder(sourceNode)
{
}

bool cSellOrder::operator<(const cOrder & x) const
{
    return this->GetPrice() > x.GetPrice();
}

bool cSellOrder::operator>(const cOrder & x) const
{
    return this->GetPrice() < x.GetPrice();
}


bool cSellOrder::operator<=(const cOrder & x) const
{
    return this->GetPrice() >= x.GetPrice();
}


bool cSellOrder::operator>=(const cOrder & x) const
{
    return this->GetPrice() <= x.GetPrice();
}


bool cSellOrder::operator==(const cOrder & x) const
{
    return this->GetPrice() == x.GetPrice();
}


bool cSellOrder::operator!=(const cOrder & x) const
{
    return this->GetPrice() != x.GetPrice();
}

void cSellOrder::Resolve(double amount)
{
    if(amount > m_amount)
    {
        amount = m_amount;
    }

    //m_sourceNode.SetResourceAmount();
}

cBuyOrder::cBuyOrder(cNode & sourceNode) :
    cOrder(sourceNode)
{
}

bool cBuyOrder::operator<(const cOrder & x) const
{
    return this->GetPrice() < x.GetPrice();
}

bool cBuyOrder::operator>(const cOrder & x) const
{
    return this->GetPrice() > x.GetPrice();
}


bool cBuyOrder::operator<=(const cOrder & x) const
{
    return this->GetPrice() <= x.GetPrice();
}


bool cBuyOrder::operator>=(const cOrder & x) const
{
    return this->GetPrice() >= x.GetPrice();
}


bool cBuyOrder::operator==(const cOrder & x) const
{
    return this->GetPrice() == x.GetPrice();
}


bool cBuyOrder::operator!=(const cOrder & x) const
{
    return this->GetPrice() != x.GetPrice();
}

void cBuyOrder::Resolve(double amount)
{
    if(amount > m_amount)
    {
        amount = m_amount;
    }

    //m_sourceNode.SetResourceAmount();
}