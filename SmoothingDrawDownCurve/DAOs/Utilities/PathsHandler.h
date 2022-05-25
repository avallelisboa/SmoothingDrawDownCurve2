#pragma once
#include <filesystem>

std::filesystem::path getFullName(std::filesystem::path& thePath, std::filesystem::path& fileName);
std::filesystem::path getFileName(const char* accountName, const char* fileName);