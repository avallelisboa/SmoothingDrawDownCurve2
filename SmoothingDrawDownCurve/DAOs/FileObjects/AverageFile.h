#pragma once
//Align data in single bytes boundaries to avoid padding
#pragma pack(push, 1)
struct AverageFile {
	int accountIndex;
	int index;
	float value;
};
#pragma pack(pop)