#include "Plotting.h"

float getEquity(void* data, int i)
{
    std::list<Equity*>* p_equities = (std::list<Equity*>*)data;
    auto it = p_equities->begin();
    int count = 0;
    while (count < i) {
        it++;
    }
    return (float)((*it)->equity);
}

float getAverage(void* data, int i)
{
    std::list<Average*>* p_movingaverage = (std::list<Average*>*)data;
    auto it = p_movingaverage->begin();
    int count = 0;
    while (count < i) {
        it++;
    }
    return (*it)->average;
}