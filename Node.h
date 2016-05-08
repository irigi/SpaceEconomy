#ifndef NODE_GUARD_H
#define NODE_GUARD_H

class cResource;
class cStrategy;

class cNode
{
public:
	static cNode noNode;
    cNode(cPlace & placeOfNode, cPlace & placeOfInputs, cPlace & placeOfOutputs, cStrategy & strategy);

    void AddNodeInput(const cNodeInput & input);
    void AddNodeOutput(const cNodeOutput & output);

	cPlace & GetPlaceOfNode() { return m_placeOfNode; }
	cPlace & GetPlaceOfInputs() { return m_placeOfInputs; }
	cPlace & GetPlaceOfOutputs() { return m_placeOfOutputs; }

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