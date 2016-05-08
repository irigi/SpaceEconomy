#include "stdafx.h"

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