#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

const size_t MAX_CHAR_LEN = 128;

void convertToString(const char*, std::string&);
char* convertToChar(const std::string&);
std::string convertSize_tToString(size_t);

int countLines(const char*);
void copyNextWordfromAnArr(char*, char*);

void copyStringToArr(const std::string&, char*);