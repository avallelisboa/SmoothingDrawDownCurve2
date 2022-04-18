#include "TestAccountCRUDMockUp.h"

void TestAccountCRUDMockUp::_cleanUp()
{
	auto it = m_AccountsList.begin();
	while (it != m_AccountsList.end()) {
		_cleanRs(*it);
		_cleanEquities(*it);
		_cleanAverages(*it);
	}
}

void TestAccountCRUDMockUp::_cleanRs(Account* theAccount)
{
	auto rit = theAccount->GetRsList().begin();
	auto endit = theAccount->GetRsList().end();
	while (rit != endit) {
		delete (*rit);
		rit++;
	}
}

void TestAccountCRUDMockUp::_cleanEquities(Account* theAccount)
{
	auto eit = theAccount->GetEquitiesList().begin();
	auto endit = theAccount->GetEquitiesList().end();
	while (eit != endit) {
		delete(*eit);
		eit++;
	}
}

void TestAccountCRUDMockUp::_cleanAverages(Account* theAccount)
{
	auto mit = theAccount->GetMovingAverage().begin();
	auto endit = theAccount->GetMovingAverage().end();
	while (mit != endit) {
		delete(*mit);
		mit++;
	}
}

void TestAccountCRUDMockUp::_fillData()
{

}

TestAccountCRUDMockUp::TestAccountCRUDMockUp()
{
	_fillData();
}

TestAccountCRUDMockUp::~TestAccountCRUDMockUp()
{
	_cleanUp();
}
