#pragma once
#include "Average.h"
#include "Equity.h"
#include "R.h"

struct AccountDataToAdd {
	R* r;
	Equity* equity;
	Average* average;
};