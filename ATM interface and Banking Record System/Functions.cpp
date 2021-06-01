#include "Functions.h"

std::string convertToString(const char* arr)
{
	size_t size = strlen(arr);
	std::string s = "";
	for (size_t i = 0; i < size; i++)
	{
		s = s + arr[i];
	}
	return s;
}