#ifndef NODE_GUARD_H
#define NODE_GUARD_H

class cResource;

class cNodeIO
{
public:
    cNodeIO(const cResource &resource, double amountMultiplier);
    const cResource & GetResource() const { return m_resource; }
    double GetAmountMultiplier() const { return m_amountMultiplier; }

private:
    const cResource & m_resource;
    double m_amountMultiplier;
};

class cNodeOutput : public cNodeIO 
{
public:
    cNodeOutput(const cResource &resource, double amountMultiplier) : cNodeIO(resource, amountMultiplier) {};
};

class cNodeInput : public cNodeIO 
{
public:
    cNodeInput(const cResource &resource, double amountMultiplier) : cNodeIO(resource, amountMultiplier) {};
};

class cNode
{
public:
    cNode(cPlace & placeOfNode, cPlace & placeOfInputs, cPlace & placeOfOutputs);

    void DoStep();

    void AddNodeInput(const cNodeInput & input);
    void AddNodeOutput(const cNodeOutput & output);

    //cNodeInput & GetNodeInput(const cResource & resource);
    //cNodeOutput & GetNodeOutput(const cResource & resource);

private:
    double m_priceMultiplier;

    //std::map<int, cNodeInput> m_nodeInputs;
    //std::map<int, cNodeOutput> m_nodeOutputs;

    cPlace & m_placeOfNode, m_placeOfInputs, m_placeOfOutputs;
};


#endif