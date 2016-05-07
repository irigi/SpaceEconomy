#ifndef ORDER_GUARD_H
#define ORDER_GUARD_H

class cNode;
class cNodeIO;
class cNodeOutput;
class cNodeInput;

class cOrder
{
public:
    cOrder(cNode & sourceNode, cNodeIO & nodeio);
    cOrder & operator=(const cOrder & x); 
    void Set(double amount, double price);    

    double GetAmount() const;
    double GetPrice() const;

    virtual void Resolve(double amount) = 0;

protected:
    cNode & m_sourceNode;
	cNodeIO & m_nodeio;
    double m_amount;
    double m_price;
};

class cSellOrder : public cOrder
{
public:
    cSellOrder(cNode & sourceNode, cNodeOutput & nodeio);

    virtual void Resolve(double amount);

    bool operator<(const cOrder & x) const; 
    bool operator>(const cOrder & x) const; 
    bool operator<=(const cOrder & x) const; 
    bool operator>=(const cOrder & x) const; 
    bool operator==(const cOrder & x) const; 
    bool operator!=(const cOrder & x) const; 
};

class cBuyOrder : public cOrder
{
public:
    cBuyOrder(cNode & sourceNode, cNodeInput & nodeio);

    virtual void Resolve(double amount);

    bool operator<(const cOrder & x) const; 
    bool operator>(const cOrder & x) const; 
    bool operator<=(const cOrder & x) const; 
    bool operator>=(const cOrder & x) const; 
    bool operator==(const cOrder & x) const; 
    bool operator!=(const cOrder & x) const; 
};

#endif