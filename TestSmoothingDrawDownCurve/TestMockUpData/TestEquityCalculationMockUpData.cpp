#include "TestEquityCalculationMockUpData.h"

TestEquityCalculationMockUp::TestEquityCalculationMockUp()
{
	_fillData();
}
TestEquityCalculationMockUp::~TestEquityCalculationMockUp()
{
	_cleanUp();
}

//Fill data
void TestEquityCalculationMockUp::_fillOneElementEquity() {
	Equity* eq = new Equity();
	eq->equity = 6;
	oneelement_equities.push_back(eq);
}
void TestEquityCalculationMockUp::_fillManyElementsEquities() {
	Equity* eq = new Equity();
	eq->equity = 2;
	equities.push_back(eq);

	eq = new Equity();
	eq->equity = 1;
	equities.push_back(eq);

	eq = new Equity();
	eq->equity = 3;
	equities.push_back(eq);
}
void TestEquityCalculationMockUp::_fillData() {
	_fillOneElementEquity();
	_fillManyElementsEquities();
}

//Cleanup2
void TestEquityCalculationMockUp::_cleanUp() {
	auto oneElement = oneelement_equities.front();
	delete oneElement;

	auto manyElementsIt = equities.begin();
	while (manyElementsIt != equities.end()) {
		delete (*manyElementsIt);
		manyElementsIt++;
	}
}