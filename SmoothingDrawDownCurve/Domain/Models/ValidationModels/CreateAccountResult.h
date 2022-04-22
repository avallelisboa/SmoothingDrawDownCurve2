#pragma once
#include <iostream>

struct CreateAccountResult {
	std::string errorMessage;
	bool wasCreated;
};