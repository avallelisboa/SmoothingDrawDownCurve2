#pragma once
//Align data in single bytes boundaries to avoid padding
#pragma pack(push, 1)
struct RFile {
	int accountIndex;
	int index;
	int value;
};
#pragma pack(pop)