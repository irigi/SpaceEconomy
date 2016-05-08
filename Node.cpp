#include "stdafx.h"

cNode cNode::noNode(cPlace::noPlace, cPlace::noPlace, cPlace::noPlace, cNoStrategy::getInstance());

void cNode::Clear()
{
	m_strategy.PlanActions(*this);

	for (std::map<int, cNodeInput>::iterator it = m_nodeInputs.begin(); it != m_nodeInputs.end(); ++it)
	{
		(*it).second.Clear();
	}

	for (std::map<int, cNodeOutput>::iterator it = m_nodeOutputs.begin(); it != m_nodeOutputs.end(); ++it)
	{
		(*it).second.Clear();
	}
}

void cNode::PlanActions()
{
	m_strategy.PlanActions(*this);
}

cNode::cNode(cPlace & placeOfNode, cPlace & placeOfInputs, cPlace & placeOfOutputs, cStrategy & strategy)
    : m_placeOfNode(placeOfNode), m_placeOfInputs(placeOfInputs), m_placeOfOutputs(placeOfOutputs), m_strategy(strategy)
{
}

void cNode::AddNodeInput(const cNodeInput & input)
{
    m_nodeInputs.insert(std::pair<int, cNodeInput>(input.GetResource().GetID(), input));
}

void cNode::AddNodeOutput(const cNodeOutput & output)
{
    m_nodeOutputs.insert(std::pair<int, cNodeOutput>(output.GetResource().GetID(), output));
}

