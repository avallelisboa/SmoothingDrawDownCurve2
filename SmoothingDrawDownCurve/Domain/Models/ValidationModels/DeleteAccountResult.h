#pragma once
#include <iostream>

struct DeleteAccountResult {
	std::string errorMessage;
	bool wasDeleted;
};
