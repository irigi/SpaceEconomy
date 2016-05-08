#include "stdafx.h"

cOrder::cOrder(cNode & sourceNode, cNodeIO & nodeio) :
    m_sourceNode(sourceNode), m_nodeio(nodeio)
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

cSellOrder::cSellOrder(cNode & sourceNode, cNodeOutput & nodeio) :
    cOrder(sourceNode, nodeio)
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

	m_nodeio.SetCommodityFlow(m_nodeio.GetCommodityFlow() + amount);
	m_nodeio.SetCashFlow(m_nodeio.GetCashFlow() + m_price*amount);
	m_amount -= amount;
}

cBuyOrder::cBuyOrder(cNode & sourceNode, cNodeInput & nodeio) :
    cOrder(sourceNode, nodeio)
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

	m_nodeio.SetCommodityFlow(m_nodeio.GetCommodityFlow() + amount);
	m_nodeio.SetCashFlow(m_nodeio.GetCashFlow() + m_price*amount);
	m_amount -= amount;
}