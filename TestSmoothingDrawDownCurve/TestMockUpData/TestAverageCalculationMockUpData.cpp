#include "TestAverageCalculationMockUpData.h"

TestAverageCalculationMockUpData::TestAverageCalculationMockUpData()
{
	m_OneElementList.push_back(0);
	_fillNumberOfElementsEqualsToPeriodsNumberList();
	_fillNumberOfElementsHigherThanPeriodsNumberList();
}

TestAverageCalculationMockUpData::~TestAverageCalculationMockUpData()
{
	_cleanUp();
}

void TestAverageCalculationMockUpData::_cleanUp()
{

	auto oneElementListIt = m_OneElementList.begin();
	delete (*oneElementListIt);
	oneElementListIt++;

	auto numberOfElementsEqualsToPeriodsNumberListIt = m_NumberOfElementsEqualsToPeriodsNumberList.begin();
	while (numberOfElementsEqualsToPeriodsNumberListIt != m_NumberOfElementsEqualsToPeriodsNumberList.end()) {
		delete (*numberOfElementsEqualsToPeriodsNumberListIt);
		numberOfElementsEqualsToPeriodsNumberListIt++;
	}

	auto numberOfElementsHigherThanPeriodsNumberListIt = m_NumberOfElementsHigherThanPeriodsNumberList.begin();
	while (numberOfElementsHigherThanPeriodsNumberListIt != m_NumberOfElementsHigherThanPeriodsNumberList.end()) {
		delete (*numberOfElementsHigherThanPeriodsNumberListIt);
		numberOfElementsHigherThanPeriodsNumberListIt++;
	}
}

void TestAverageCalculationMockUpData::_fillNumberOfElementsEqualsToPeriodsNumberList()
{
	Equity* eq = new Equity();
	eq->equity = -1;
	m_NumberOfElementsEqualsToPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = -1;
	m_NumberOfElementsEqualsToPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = -1;
	m_NumberOfElementsEqualsToPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = -1;
	m_NumberOfElementsEqualsToPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = -1;
	m_NumberOfElementsEqualsToPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = -1;
	m_NumberOfElementsEqualsToPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = -1;
	m_NumberOfElementsEqualsToPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = -1;
	m_NumberOfElementsEqualsToPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = 2;
	m_NumberOfElementsEqualsToPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = 2;
	m_NumberOfElementsEqualsToPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = 2;
	m_NumberOfElementsEqualsToPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = 2;
	m_NumberOfElementsEqualsToPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = 2;
	m_NumberOfElementsEqualsToPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = 2;
	m_NumberOfElementsEqualsToPeriodsNumberList.push_back(eq);
}

void TestAverageCalculationMockUpData::_fillNumberOfElementsHigherThanPeriodsNumberList()
{
	Equity* eq = new Equity();
	eq->equity = -1;
	m_NumberOfElementsHigherThanPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = -1;
	m_NumberOfElementsHigherThanPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = -1;
	m_NumberOfElementsHigherThanPeriodsNumberList.push_back(eq); eq = new Equity();
	eq->equity = -1;
	m_NumberOfElementsHigherThanPeriodsNumberList.push_back(eq); eq = new Equity();
	eq->equity = -1;
	m_NumberOfElementsHigherThanPeriodsNumberList.push_back(eq); eq = new Equity();
	eq->equity = -1;
	m_NumberOfElementsHigherThanPeriodsNumberList.push_back(eq); eq = new Equity();
	eq->equity = -1;
	m_NumberOfElementsHigherThanPeriodsNumberList.push_back(eq); eq = new Equity();
	eq->equity = -1;
	m_NumberOfElementsHigherThanPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = 2;
	m_NumberOfElementsHigherThanPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = 2;
	m_NumberOfElementsHigherThanPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = 2;
	m_NumberOfElementsHigherThanPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = 2;
	m_NumberOfElementsHigherThanPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = 2;
	m_NumberOfElementsHigherThanPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = 2;
	m_NumberOfElementsHigherThanPeriodsNumberList.push_back(eq);
	eq = new Equity();
	eq->equity = 2;
	m_NumberOfElementsHigherThanPeriodsNumberList.push_back(eq);
}