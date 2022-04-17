#include "CppUnitTest.h"
#include "../BusinessLogic/AccountBL.h"
#include "Admin.h"
#include <memory>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestSmoothingDrawDownCurve {
	TEST_CLASS(TestAdmin) {

		TEST_METHOD(TestAccountCount) {
			int expectedCount = 0;
			int countObtained = Admin::Get().GetAccountsCount();
			Assert::AreEqual(expectedCount, countObtained);
		}
		TEST_METHOD(TestAddAccount) {
			int expectedCount = 1;
			Admin::Get().MakeAccount("testaccount");
			int countObtained = Admin::Get().GetAccountsCount();
			Assert::AreEqual(expectedCount, countObtained);
		}

	};
}