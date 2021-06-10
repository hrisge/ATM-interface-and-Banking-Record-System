#include "Functions.h"

void convertToString(const char* arr, std::string& location)
{
	if (arr == nullptr)
		return;
	size_t size = strlen(arr);
	for (size_t i = 0; i < size; i++)
	{
		location = location + arr[i];
	}
}
char* convertToChar(const std::string& str)
{
	char arr[MAX_CHAR_LEN];
	size_t size = str.size();
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = str[i];
	}
	arr[size] = '\0';
	return arr;
}
std::string convertSize_tToString(size_t number)
{
	std::string numberStr;
	if (number == 0)
	{
		numberStr.push_back(number + 48);
		return numberStr;
	}

	while (number != 0)
	{
		size_t num = (number % 10);
		number= number / 10;
		numberStr.push_back(num + 48);
	}
	return numberStr;
}
size_t convertStringToSize_t(const std::string& str)
{
	size_t result = 0;
	size_t sizeOfStr = str.size();
	for (int i = 0; i <sizeOfStr; i++)
	{
		result = 10 * result + (str[i] - 48);
	}
	return result;
}

void copyStringToArr(const std::string& str, char* arr)
{
	size_t sizeOfStr = str.size();
	for (size_t i = 0; i < sizeOfStr; i++)
	{
		arr[i] = str[i];
	}
	arr[sizeOfStr] = '\0';
}

int countLines(const std::string& fileName)
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

