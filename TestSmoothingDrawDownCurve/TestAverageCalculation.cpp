#include "CppUnitTest.h"
#include "../SmoothingDrawDownCurve/BusinessLogic/AccountBL.h"
#include "TestMockUpData/TestAverageCalculationMockUpData.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestSmoothingDrawDownCurve{
	TEST_CLASS(TestAverageCalculation){
	public:
		TEST_METHOD(TestAverageCalculationWithEmptyList){
			TestAverageCalculationMockUpData data;
			float average = calculateAverage(data.EmptyListValues, 14);
			Assert::AreEqual(0.0f, average);
		}
		TEST_METHOD(TestAverageCalculationWithOneElement){
			TestAverageCalculationMockUpData data;
			float average = calculateAverage(data.OneElementList, 14);
			Assert::AreEqual(0.0f, average);
		}
		TEST_METHOD(TestAverageCalculationWithNumberOfElementsEqualToPeriodsNumber){
			TestAverageCalculationMockUpData data;
			float average = calculateAverage(data.NumberOfElementsEqualsToPeriodsNumberList, 14);
			Assert::AreEqual(0.2857143f, average);
		}
		TEST_METHOD(TestAverageCalculationWithNumberOfElementsHigherThanPeriodsNumber){
			TestAverageCalculationMockUpData data;
			float average = calculateAverage(data.NumberOfElementsHigherThanPeriodsNumberList, 14);
			Assert::AreEqual(0.5f, average);
		}
	};
}