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

class cTestingStrategy : cStrategy
{
public:
	static cStrategy & getInstance() { return instance; }
	virtual void PlanActions(cNode & node);

private:
	static cTestingStrategy instance;
};



#endif
