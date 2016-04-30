#include "stdafx.h"

cAuction::cAuction()
{
    cSellOrder sell;
    cBuyOrder buy;

    sell.Set(0.0, 1e79);
    buy.Set(0.0, 0.0);

    AddBuyOrder(buy);
    AddSellOrder(sell);
}

bool cAuction::AddBuyOrder(const cBuyOrder &order)
{
    m_buyQ.push(order);
    
    return true;
}

bool cAuction::AddSellOrder(const cSellOrder &order)
{
    m_sellQ.push(order);

    return true;
}

const cSellOrder& cAuction::GetLowestSell() const
{
    return m_sellQ.top();
}
    
const cBuyOrder& cAuction::GetHighestBuy() const
{
    return m_buyQ.top();
}

void cAuction::Resolve()
{
    while(GetLowestSell().GetPrice() <= GetHighestBuy().GetPrice())
    {
        cSellOrder s_order = m_sellQ.top();
        cBuyOrder b_order = m_buyQ.top();
        m_sellQ.pop();
        m_buyQ.pop();
    }
}