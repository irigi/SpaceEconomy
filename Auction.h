#ifndef AUCTION_GUARD_H
#define AUCTION_GUARD_H

class cOrder;
class cBuyOrder;
class cSellOrder;
class cNode;
class cPlace;

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

    static cPlace noPlace;
    static cNode noNode;

};


#endif