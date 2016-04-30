#include "stdafx.h"

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