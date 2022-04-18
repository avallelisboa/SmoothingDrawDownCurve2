#pragma once
#include "../../SmoothingDrawDownCurve/Domain/Admin.h"

class TestAccountCRUDMockUp
{
	private:
		void _cleanUp();
		void _cleanRs(Account* theAccount);
		void _cleanEquities(Account* theAccount);
		void _cleanAverages(Account* theAccount);
		void _fillData();

		std::list<Account*> m_AccountsList;

	public:
		TestAccountCRUDMockUp();
		~TestAccountCRUDMockUp();

		inline std::list<Account*>& GetAccountsList() { return m_AccountsList; }
};

