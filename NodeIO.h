#ifndef NODEIO_GUARD_H
#define NODEIO_GUARD_H

class cResource;

class cNodeIO
{
public:
	cNodeIO(const cResource &resource, double amountMultiplier);
	const cResource & GetResource() const { return m_resource; }
	double GetAmountMultiplier() const { return m_amountMultiplier; }

	double GetCommodityFlow() const { return m_CommodityFlow; }
	void SetCommodityFlow(double amount) { m_CommodityFlow = amount; }
	double GetCashFlow() const { return m_CashFlow; }
	void SetCashFlow(double price) { m_CashFlow = price; }
	void Clear();

	static cNodeIO noNodeIO;

private:
	const cResource & m_resource;
	double m_amountMultiplier;

	double m_CommodityFlow;
	double m_CashFlow;
};

class cNodeOutput : public cNodeIO
{
public:
	static cNodeOutput noNodeOutput;

	double GetBasicPrice() const { return m_basicPrice; }
	cNodeOutput(const cResource &resource, double amountMultiplier, double basicPrice) :
		cNodeIO(resource, amountMultiplier), m_basicPrice(basicPrice) {}

private:
	double m_basicPrice;
};

class cNodeInput : public cNodeIO
{
public:
	static cNodeInput noNodeInput;
	cNodeInput(const cResource &resource, double amountMultiplier) : cNodeIO(resource, amountMultiplier) {};
};

#endif