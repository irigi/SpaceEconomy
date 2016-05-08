#include "stdafx.h"

cNode cNode::noNode(cPlace::noPlace, cPlace::noPlace, cPlace::noPlace, cNoStrategy::getInstance());

cNodeIO cNodeIO::noNodeIO(cResource::noResource, 1.0);
cNodeOutput cNodeOutput::noNodeOutput(cResource::noResource, 1.0, 1.0);
cNodeInput cNodeInput::noNodeInput(cResource::noResource, 1.0);

cNodeIO::cNodeIO(const cResource &resource, double amountMultiplier)
    : m_resource(resource), m_amountMultiplier(amountMultiplier)
{
}

void cNodeIO::Clear()
{
	m_CashFlow = 0.0;
	m_CommodityFlow = 0.0;
}

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

cNodeInput & cNode::GetNodeInput(const cResource & resource)
{
	std::map<int, cNodeInput>::iterator it = m_nodeInputs.find(resource.GetID());
	if (it != m_nodeInputs.end())
	{
		return (*it).second;
	}
	else
	{
		printf("Input node not found by name.\n");
		return cNodeInput::noNodeInput;
	}
}

cNodeOutput & cNode::GetNodeOutput(const cResource & resource)
{
	std::map<int, cNodeOutput>::iterator it = m_nodeOutputs.find(resource.GetID());
	if (it != m_nodeOutputs.end())
	{
		return (*it).second;
	}
	else
	{
		printf("Output node not found by name.\n");
		return cNodeOutput::noNodeOutput;
	}
}