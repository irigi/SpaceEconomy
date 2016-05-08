#ifndef STRATEGY_GUARD_H
#define STRATEGY_GUARD_H

class cNode;

class cStrategy
{
public:
	virtual void PlanActions(cNode & node) = 0;
};

class cNoStrategy : cStrategy
{
public:
	static cStrategy & getInstance() { return instance; }
	virtual void PlanActions(cNode & node) { };

private:
	static cNoStrategy instance;
};

class cSupplyDemandStrategy : cStrategy
{
public:
	static cStrategy & getInstance() { return instance; }
	virtual void PlanActions(cNode & node);


	void PlanSupply(cNode & node);
	void PlanDemand(cNode & node);

private:
	static cSupplyDemandStrategy instance;
};



#endif
