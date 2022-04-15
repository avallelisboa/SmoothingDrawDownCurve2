#include "pch.h"
#include "CppUnitTest.h"
#include "../SmoothingDrawDownCurve/BusinessLogic/AccountBL.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestSmoothingDrawDownCurve{
	TEST_CLASS(TestAverageCalculation){
	public:
		TEST_METHOD(TestAverageCalculationWithEmptyList){
			std::list<int> values;
			float average = calculateAverage(values, 14);
			Assert::AreEqual(0.0f, average);
		}
		TEST_METHOD(TestAverageCalculationWithOneElement){
			std::list<int> values;
			values.push_back(0);
			float average = calculateAverage(values, 14);
			Assert::AreEqual(0.0f, average);
		}
		TEST_METHOD(TestAverageCalculationWithNumberOfElementsEqualToPeriodsNumber){
			std::list<int> values;
			values.push_back(-1);values.push_back(-1);values.push_back(-1);
			values.push_back(-1);values.push_back(-1);values.push_back(-1);
			values.push_back(-1);values.push_back(-1);
			values.push_back(2);values.push_back(2);values.push_back(2);
			values.push_back(2);values.push_back(2);values.push_back(2);
			
			float average = calculateAverage(values, 14);
			Assert::AreEqual(0.2857143f, average);
		}
		TEST_METHOD(TestAverageCalculationWithNumberOfElementsHigherThanPeriodsNumber){
			std::list<int> values;
			values.push_back(-1); values.push_back(-1); values.push_back(-1);
			values.push_back(-1); values.push_back(-1); values.push_back(-1);
			values.push_back(-1); values.push_back(-1);
			values.push_back(2); values.push_back(2); values.push_back(2);
			values.push_back(2); values.push_back(2); values.push_back(2);
			values.push_back(2);

			float average = calculateAverage(values, 14);
			Assert::AreEqual(0.5f, average);
		}
	};
}
