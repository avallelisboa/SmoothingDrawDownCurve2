#pragma once
//Align data in single bytes boundaries to avoid padding
#pragma pack(push, 1)
struct AccountFile {
	int index;
	char name[20];
};
#pragma pack(pop)