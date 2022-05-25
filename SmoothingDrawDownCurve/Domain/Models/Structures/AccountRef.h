#pragma once

struct AccountRef {
    size_t index;
    Account* accountPt;
    bool isOpen;
    bool isAddingR;
    bool mustBeDeleted;
    bool isPlotting;
    int rToAdd;
};