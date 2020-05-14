#include <iostream>
#include <cstring>

#include "own/string.h"

namespace own {

String::String(int val) : len(val), pCh(new char[len + 1])
{
    if (val == 0) pCh[0] = '\0';
    std::cout << "String::String(int val) : len = " << len << std::endl;
}

String::String(char Ch) : len(1), pCh(new char[len + 1])
{
    pCh[0] = Ch;
    pCh[1] = '\0';
    std::cout << "String::String(char Ch) : len(2)" << std::endl;
}

String::String(const char* S) : len(strlen(S)), pCh(new char[len + 1])
{
    strcpy(pCh, S);
    std::cout << "String::String(const char* S) : len(strlen(S))" << std::endl;
}

String::String(const String& from) : len(from.len), pCh(new char[from.len + 1])
{
    strcpy(pCh, from.pCh);
    std::cout << "String::String(const String& from)" << std::endl;
}

String::~String()
{
    delete[] pCh;
    std::cout << "String::~String()" << std::endl;
}

void String::show(void) const
{
    std::cout << "pCh = " << pCh << std::endl;
    std::cout << "len = " << len << std::endl;
}

char* String::getStr() const
{
    return pCh;
}

int String::getLen() const
{
    return len;
}

char String::getChar(int pos) const
{
    if (pos < len) {
        return pCh[pos];
    } else {
        return '\0';
        std::cout << "Error: Position out of range" << std::endl;
    }
}

}
