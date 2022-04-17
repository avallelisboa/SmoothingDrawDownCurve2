#pragma once

#include <list>
#include "../../SmoothingDrawDownCurve/BusinessLogic/AccountBL.h"
#include "../../SmoothingDrawDownCurve//Domain/Models/Account.h"
#include "../../SmoothingDrawDownCurve/Domain/Models/Structures/Equity.h"

class TestAverageCalculationMockUpData
{
	private:
		void _cleanUp();
		void _fillNumberOfElementsEqualsToPeriodsNumberList();
		void _fillNumberOfElementsHigherThanPeriodsNumberList();

	public:
		std::list<Equity*> EmptyListValues;
		std::list<Equity*> OneElementList;
		std::list<Equity*> NumberOfElementsEqualsToPeriodsNumberList;
		std::list<Equity*> NumberOfElementsHigherThanPeriodsNumberList;

		TestAverageCalculationMockUpData();
		~TestAverageCalculationMockUpData();

};