#pragma once

#include <list>
#include "../../SmoothingDrawDownCurve/BusinessLogic/AccountBL.h"
#include "../../SmoothingDrawDownCurve//Domain/Models/Account.h"
#include "../../SmoothingDrawDownCurve/Domain/Models/Structures/Equity.h"

class TestAverageCalculationMockUpData
{
	private:
		std::list<Equity*> m_EmptyListValues;
		std::list<Equity*> m_OneElementList;
		std::list<Equity*> m_NumberOfElementsEqualsToPeriodsNumberList;
		std::list<Equity*> m_NumberOfElementsHigherThanPeriodsNumberList;

		void _cleanUp();
		void _fillNumberOfElementsEqualsToPeriodsNumberList();
		void _fillNumberOfElementsHigherThanPeriodsNumberList();

	public:
		inline std::list<Equity*>& GetEmptyListValues() { return m_EmptyListValues; }
		inline std::list<Equity*>& GetOneElementList() { return m_OneElementList; }
		inline std::list<Equity*>& GetNumberOfElementsEqualsToPeriodsNumberList() { return  m_NumberOfElementsEqualsToPeriodsNumberList; }
		inline std::list<Equity*>& GetNumberOfElementsHigherThanPeriodsNumberList() { return m_NumberOfElementsHigherThanPeriodsNumberList;  }

		TestAverageCalculationMockUpData();
		~TestAverageCalculationMockUpData();
};