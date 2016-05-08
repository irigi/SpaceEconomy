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
	void Clear();

private:
    std::priority_queue<cBuyOrder> m_buyQ;
    std::priority_queue<cSellOrder> m_sellQ;

};


#endif