#pragma once
#include "../../SmoothingDrawDownCurve/BusinessLogic/AccountBL.h"

class TestEquityCalculationMockUp{
public:
	TestEquityCalculationMockUp();
	~TestEquityCalculationMockUp();

	inline std::list<Equity*>& GetEquities() { return equities; }
	inline std::list<Equity*>& GetOneElementEquities() { return oneelement_equities; }
private:
	std::list<Equity*> equities;
	std::list<Equity*> oneelement_equities;

	void _fillOneElementEquity();
	void _fillManyElementsEquities();
	void _fillData();
	void _cleanUp();
};