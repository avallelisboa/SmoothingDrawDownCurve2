#pragma once
#include <iostream>

struct UpdateAccountResult {
	std::string errorMessage;
	bool wasUpdated;
};