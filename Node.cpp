#include "stdafx.h"

cNodeIO::cNodeIO(const cResource &resource, double amountMultiplier)
    : m_resource(resource), m_amountMultiplier(amountMultiplier)
{
}

void cNode::DoStep()
{
}

void cNode::AddNodeInput(const cNodeInput & input)
{
    m_nodeInputs.push_back(input);
}

void cNode::AddNodeOutput(const cNodeOutput & output)
{
    m_nodeOutputs.push_back(output);
}