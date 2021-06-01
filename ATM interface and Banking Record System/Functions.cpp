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

int countLines(const char* fileName)
{
	std::ifstream f(fileName);
	if (!f.is_open())
		return -1;
	int linesCount = 0;

	while (!f.eof())
	{
		char buff[1024];
		f.getline(buff, 1024);
		linesCount++;
	}
	f.close();

	return linesCount;
}
void copyNextWordfromAnArr(char* dest, char* source)
{
	size_t i = 0;
	while (source[i] != ' ') {
		if (source[i] == '\0') {
			break;
		}
		dest[i] = source[i];
		i++;

	}

	dest[i] = '\0';
	size_t j = strlen(source);
	size_t k = 0;
	i++;
	while (i < j) {
		source[k] = source[i];
		i++;
		k++;
	}
	source[k] = '\0';
}