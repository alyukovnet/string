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

char String::getChar(int index) const
{
    if (index >= 0 && index < len) {
        std::cout << "char String::getChar(int index)" << std::endl;
        return pCh[index];
    }
    return '\0';
}

char& String::operator[](int index)
{
    if (index >= 0 && index < len) {
        std::cout << "char& String::operator[](int index)" << std::endl;
        return pCh[index];
    }
    return pCh[0];
}

String String::operator~()
{
    int i, j;
    char tmp;
    for (i = 0, j = len - 1; i < len / 2; i++, j--) {
        tmp = pCh[i];
        pCh[i] = pCh[j];
        pCh[j] = tmp;
    }
    std::cout << "String String::operator~()" << std::endl;
    return *this;
}

String operator+(const String& pobj1, const String& pobj2)
{
    //IdentStr tmp(pobj1);
    String tmp(pobj1.getLen() + pobj2.getLen());
    //strcpy_s(tmp.pCh,tmp.len+1, pobj1.GetStr());
    int i = 0,j=0;
    while (tmp[i++] = pobj1.getStr()[j++]);
    //strcat_s(tmp.pCh,tmp.len+1, pobj2.GetStr());
    --i; //i = pobj1.GetLen();
    j = 0;
    //while (tmp[i++] = pobj2[j++];
    std::cout << "IdentStr operator + (const IdentStr pobj1,const IdentStr pobj2)" << std::endl;
    return tmp;
}

}
