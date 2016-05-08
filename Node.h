#ifndef NODE_GUARD_H
#define NODE_GUARD_H

class cResource;
class cStrategy;

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

class cNode
{
public:
	static cNode noNode;
    cNode(cPlace & placeOfNode, cPlace & placeOfInputs, cPlace & placeOfOutputs, cStrategy & strategy);

    void AddNodeInput(const cNodeInput & input);
    void AddNodeOutput(const cNodeOutput & output);

    cNodeInput & GetNodeInput(const cResource & resource);
    cNodeOutput & GetNodeOutput(const cResource & resource);

	std::map<int, cNodeInput> & GetInputs() { return m_nodeInputs;  }
	std::map<int, cNodeOutput> & GetOutputs() { return m_nodeOutputs; }

	void PlanActions();
	void Clear();

	double GetNodeSize() const { return m_nodeSize;  }
	void SetNodeSize(double size) { m_nodeSize = size; }

private:
    double m_nodeSize;
	cStrategy &m_strategy;

    std::map<int, cNodeInput> m_nodeInputs;
    std::map<int, cNodeOutput> m_nodeOutputs;

    cPlace & m_placeOfNode, m_placeOfInputs, m_placeOfOutputs;
};


#endif