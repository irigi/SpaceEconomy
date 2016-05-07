#include "stdafx.h"

cAuction::cAuction()
{
    cSellOrder sell(cNode::noNode, cNodeOutput::noNodeOutput);
    cBuyOrder buy(cNode::noNode, cNodeInput::noNodeInput);

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

		double sAmount = s_order.GetAmount();
		double bAmount = b_order.GetAmount();

		if (sAmount > bAmount)
		{
			s_order.Resolve(bAmount);
			b_order.Resolve(bAmount);

			m_sellQ.push(s_order);
		}
		else 
		{
			s_order.Resolve(sAmount);
			b_order.Resolve(sAmount);

			m_buyQ.push(b_order);
		}
    }
}