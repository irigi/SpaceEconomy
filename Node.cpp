#include "stdafx.h"

cNodeIO::cNodeIO(const cResource &resource, double amountMultiplier)
    : m_resource(resource), m_amountMultiplier(amountMultiplier)
{
}

cNode::cNode(cPlace & placeOfNode, cPlace & placeOfInputs, cPlace & placeOfOutputs)
    : m_placeOfNode(placeOfNode), m_placeOfInputs(placeOfInputs), m_placeOfOutputs(placeOfOutputs)
{
}

void cNode::DoStep()
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