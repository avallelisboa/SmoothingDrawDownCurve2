#include "CppUnitTest.h"
#include "../SmoothingDrawDownCurve/BusinessLogic/AccountBL.h"
#include "TestMockUpData/TestEquityCalculationMockUpData.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestSmoothingDrawDownCurve {
	TEST_CLASS(TestAverageCalculation) {
public:

	TEST_METHOD(TestEquityCalculationWithEmptyList) {
		std::list<Equity*> equities;
		R aR;
		aR.value = 2;
		int actualEquity = calculateEquity(equities, &aR);
		int expectedEquity = 2;
		Assert::AreEqual(expectedEquity, actualEquity);
	}
	TEST_METHOD(TestEquityCalculationWithOneElement) {
		TestEquityCalculationMockUp aMockUp;
		R aR;
		aR.value = -1;
		int actualEquity = calculateEquity(aMockUp.GetOneElementEquities(), &aR);
		int expectedEquity = 5;
		Assert::AreEqual(expectedEquity, actualEquity);
	}
	TEST_METHOD(TestEquityCalculationWithManyElements) {
		TestEquityCalculationMockUp aMockUp;
		R aR;
		aR.value = -1;
		int actualEquity = calculateEquity(aMockUp.GetEquities(), &aR);
		int expectedEquity = 2;
		Assert::AreEqual(expectedEquity, actualEquity);
	}
	};
}