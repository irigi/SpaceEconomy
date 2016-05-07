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

	double GetBuffer() const { return m_buffer; }
	void SetBuffer(double amount) { m_buffer = amount; }
	double GetPrice() const { return m_price; }
	void SetPrice(double price) { m_price = price; }


	static cNodeIO noNodeIO;

private:
    const cResource & m_resource;
    double m_amountMultiplier;

	double m_buffer;
	double m_price;
};

class cNodeOutput : public cNodeIO 
{
public:
	static cNodeOutput noNodeOutput;
    cNodeOutput(const cResource &resource, double amountMultiplier) : cNodeIO(resource, amountMultiplier) {};
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
    cNode(cPlace & placeOfNode, cPlace & placeOfInputs, cPlace & placeOfOutputs, cStrategy & strategy);

    void AddNodeInput(const cNodeInput & input);
    void AddNodeOutput(const cNodeOutput & output);

    cNodeInput & GetNodeInput(const cResource & resource);
    cNodeOutput & GetNodeOutput(const cResource & resource);

	void PlanActions();

	static cNode noNode;

private:
    double m_priceMultiplier;
	cStrategy &m_strategy;

    std::map<int, cNodeInput> m_nodeInputs;
    std::map<int, cNodeOutput> m_nodeOutputs;

    cPlace & m_placeOfNode, m_placeOfInputs, m_placeOfOutputs;
};


#endif