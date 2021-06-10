#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

const size_t MAX_CHAR_LEN = 128;

void convertToString(const char*, std::string&);
char* convertToChar(const std::string&);
std::string convertSize_tToString(size_t);
size_t convertStringToSize_t(const std::string&);

int countLines(const std::string&);
void copyNextWordfromAnArr(char*, char*);

void copyStringToArr(const std::string&, char*);