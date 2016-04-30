#ifndef ORDER_GUARD_H
#define ORDER_GUARD_H

class cOrder
{
public:
    virtual void Set(double amount, double price);
    virtual double GetAmount() const;
    virtual double GetPrice() const;

private:
    double m_amount;
    double m_price;
};

class cSellOrder : public cOrder
{
public:
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
    bool operator<(const cOrder & x) const; 
    bool operator>(const cOrder & x) const; 
    bool operator<=(const cOrder & x) const; 
    bool operator>=(const cOrder & x) const; 
    bool operator==(const cOrder & x) const; 
    bool operator!=(const cOrder & x) const; 
};

#endif