#include "TestAverageCalculationMockUpData.h"

TestAverageCalculationMockUpData::TestAverageCalculationMockUpData()
{
	OneElementList.push_back(0);
	_fillNumberOfElementsEqualsToPeriodsNumberList();
	_fillNumberOfElementsHigherThanPeriodsNumberList();
}

TestAverageCalculationMockUpData::~TestAverageCalculationMockUpData()
{
	_cleanUp();
}

void TestAverageCalculationMockUpData::_cleanUp()
{

	auto oneElementListIt = OneElementList.begin();
	delete (*oneElementListIt);
	oneElementListIt++;

	auto numberOfElementsEqualsToPeriodsNumberListIt = NumberOfElementsEqualsToPeriodsNumberList.begin();
	while (numberOfElementsEqualsToPeriodsNumberListIt != NumberOfElementsEqualsToPeriodsNumberList.end()) {
		delete (*numberOfElementsEqualsToPeriodsNumberListIt);
		numberOfElementsEqualsToPeriodsNumberListIt++;
	}

	auto numberOfElementsHigherThanPeriodsNumberListIt = NumberOfElementsHigherThanPeriodsNumberList.begin();
	while (numberOfElementsHigherThanPeriodsNumberListIt != NumberOfElementsHigherThanPeriodsNumberList.end()) {
		delete (*numberOfElementsHigherThanPeriodsNumberListIt);
		numberOfElementsHigherThanPeriodsNumberListIt++;
	}
}

void TestAverageCalculationMockUpData::_fillNumberOfElementsEqualsToPeriodsNumberList()
{
	Equity* eq = new Equity();
	eq->equity = -1;
	NumberOfElementsEqualsToPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = -1;
	NumberOfElementsEqualsToPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = -1;
	NumberOfElementsEqualsToPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = -1;
	NumberOfElementsEqualsToPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = -1;
	NumberOfElementsEqualsToPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = -1;
	NumberOfElementsEqualsToPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = -1;
	NumberOfElementsEqualsToPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = -1;
	NumberOfElementsEqualsToPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = 2;
	NumberOfElementsEqualsToPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = 2;
	NumberOfElementsEqualsToPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = 2;
	NumberOfElementsEqualsToPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = 2;
	NumberOfElementsEqualsToPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = 2;
	NumberOfElementsEqualsToPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = 2;
	NumberOfElementsEqualsToPeriodsNumberList.push_back(eq);
}

void TestAverageCalculationMockUpData::_fillNumberOfElementsHigherThanPeriodsNumberList()
{
	Equity* eq = new Equity();
	eq->equity = -1;
	NumberOfElementsHigherThanPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = -1;
	NumberOfElementsHigherThanPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = -1;
	NumberOfElementsHigherThanPeriodsNumberList.push_back(eq); eq = new Equity();
	eq->equity = -1;
	NumberOfElementsHigherThanPeriodsNumberList.push_back(eq); eq = new Equity();
	eq->equity = -1;
	NumberOfElementsHigherThanPeriodsNumberList.push_back(eq); eq = new Equity();
	eq->equity = -1;
	NumberOfElementsHigherThanPeriodsNumberList.push_back(eq); eq = new Equity();
	eq->equity = -1;
	NumberOfElementsHigherThanPeriodsNumberList.push_back(eq); eq = new Equity();
	eq->equity = -1;
	NumberOfElementsHigherThanPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = 2;
	NumberOfElementsHigherThanPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = 2;
	NumberOfElementsHigherThanPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = 2;
	NumberOfElementsHigherThanPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = 2;
	NumberOfElementsHigherThanPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = 2;
	NumberOfElementsHigherThanPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = 2;
	NumberOfElementsHigherThanPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = 2;
	NumberOfElementsHigherThanPeriodsNumberList.push_back(eq);
}