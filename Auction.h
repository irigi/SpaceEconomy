#ifndef AUCTION_GUARD_H
#define AUCTION_GUARD_H

#include <queue>

class cOrder;
class cBuyOrder;
class cSellOrder;

class cAuction
{
public:
    cAuction();

    bool AddBuyOrder(const cBuyOrder &order);
    bool AddSellOrder(const cSellOrder &order);
    const cSellOrder& GetLowestSell() const;
    const cBuyOrder& GetHighestBuy() const;
    void Resolve();

private:
    std::priority_queue<const cBuyOrder> m_buyQ;
    std::priority_queue<const cSellOrder> m_sellQ;

};


#endif