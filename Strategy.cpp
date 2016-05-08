#include "stdafx.h"

cNoStrategy cNoStrategy::instance;
cSupplyDemandStrategy cSupplyDemandStrategy::instance;

// Place supply according to fixed model
void cSupplyDemandStrategy::PlanDemand(cNode & node)
{

}

// Based on demand which was aquired in the previous turn, place supply. 
// This way, self-consistency of the model is ensured.
void cSupplyDemandStrategy::PlanSupply(cNode & node)
{

}

void cSupplyDemandStrategy::PlanActions(cNode & node)
{
	PlanDemand(node);
	PlanSupply(node);

	//double inputsCost = 0.0;

	//for (std::map<int, cNodeInput>::iterator it = node.GetInputs().begin(); it != node.GetInputs().end(); ++it)
	//{
	//	inputsCost += (*it).second.GetPrice() * (*it).second.GetAmountMultiplier();
	//}

	//double basicOutputsPrice = inputsCost * MARGIN;

	//for (int i = 0; i < BINS; ++i)
	//{
	//	ggg
	//}

	// model for demand
}