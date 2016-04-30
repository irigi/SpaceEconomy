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

class cNodeOutput : public cNodeIO {};
class cNodeInput : public cNodeIO {};

class cNode
{
public:
    cNode(cPlace & placeOfNode, cPlace & placeOfInputs, cPlace & placeOfOutputs);

    void DoStep();

    void AddNodeInput(const cNodeInput & input);
    void AddNodeOutput(const cNodeOutput & output);

private:
    double m_priceMultiplier;

    std::vector<cNodeInput> m_nodeInputs;
    std::vector<cNodeOutput> m_nodeOutputs;

    cPlace & placeOfNode, placeOfInputs, placeOfOutputs;
};


#endif