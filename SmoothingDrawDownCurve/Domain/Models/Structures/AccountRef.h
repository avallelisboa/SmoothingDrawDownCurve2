#pragma once

struct AccountRef {
    size_t index;
    Account* accountPt;
    bool isOpen;
    bool isAddingR;
    bool isPlotting;
    int rToAdd;
};