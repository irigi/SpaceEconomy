#include "stdafx.h"

cNoStrategy cNoStrategy::instance;
cSupplyDemandStrategy cSupplyDemandStrategy::instance;

// Place supply according to fixed model
void cSupplyDemandStrategy::PlanDemand(cNode & node)
{
	for (std::map<int, cNodeInput>::iterator it = node.GetInputs().begin(); it != node.GetInputs().end(); ++it)
	{
		for (int i = 0; i < BINS; ++i)
		{
			double price = 1.0 + std::pow(1.0 + BIN_MULT, i);

			cBuyOrder b_order(node, (*it).second);

			b_order.Set(amount, price);

			node.GetPlaceOfInputs().GetAuction().AddBuyOrder(b_order);
		}
	}
}

// Based on demand which was aquired in the previous turn, place supply. 
// This way, self-consistency of the model is ensured.
void cSupplyDemandStrategy::PlanSupply(cNode & node)
{
	double amountThatCanBeProduced = 1e69;

	for (std::map<int, cNodeInput>::iterator it = node.GetInputs().begin(); it != node.GetInputs().end(); ++it)
	{
		double amountLimiter = (*it).second.GetCommodityFlow() / (*it).second.GetAmountMultiplier();

		amountThatCanBeProduced = amountThatCanBeProduced > amountLimiter ? amountLimiter : amountThatCanBeProduced;
	}

	amountThatCanBeProduced /= MARGIN;
}

void cSupplyDemandStrategy::PlanActions(cNode & node)
{
	PlanDemand(node);
	PlanSupply(node);
}