/*!
\file
\brief Реализация методов класса "Строка-идентификатор"

Данный файл содержит в себе реализации методов производного
от "Строка" класса "Строка-идентификатор"
*/
#include <iostream>
#include <cstring>

#include "own/string.h"
#include "own/identstr.h"

namespace own {

IdentStr::IdentStr(int val) : String(val)
{
    std::cout << "IdentStr::IdentStr(int val) : String(val), val = " << val << std::endl;
}

IdentStr::IdentStr(const char* Str) : String(Str)
{
    if (!((pCh[0] >= 'a' && pCh[0] <= 'z') || (pCh[0] >= 'A'&& pCh[0] <= 'Z') || (pCh[0] == '_'))) {
        std::cout << "Bad symbol, pCh[0] = " << pCh[0] << std::endl;
        delete[] pCh;
        len = 0;
        pCh = new char[len + 1];
        pCh[0] = '\0';
        return;
    }
    for (int i = 1; i < len; i++) {
        if (!((pCh[i] >= 'a' && pCh[i] <= 'z') || (pCh[i] >= 'A' && pCh[i] <= 'Z') || (pCh[i] >= '0' && pCh[i] <= '9') || (pCh[i] == '_'))) {
            std::cout << "Bad String, pCh[" << i << "] = " << pCh[i] << std::endl;
            delete[] pCh;
            len = 0;
            pCh = new char[len + 1];
            pCh[0] = '\0';
            return;
        }
    }
    std::cout << "IdentStr::IdentStr(char* Str) : String(Str)" << std::endl;
}

IdentStr::IdentStr(const IdentStr& from) : String(from)
{
    std::cout << "IdentStr::IdentStr(const IdentStr& from) : String(from)" << std::endl;
}

IdentStr::~IdentStr()
{
    std::cout << "IdentStr::~IdentStr()" << std::endl;
}

int IdentStr::getDigitsNum()
{
    int digitsNum = 0;
    for (int i = 1; i < len; i++) {
        if (pCh[i] >= '0' && pCh[i] <= '9') {
            digitsNum++;
        }
    }
    return digitsNum;
}

IdentStr& IdentStr::operator=(const IdentStr& S)
{
    if (&S != this) {
        delete[] pCh;
        len = strlen(S.pCh);
        pCh = new char[len + 1];
        strcpy(pCh, S.pCh);
    }
    std::cout << "IdentStr& IdentStr::operator=(const IdentStr& S)" << std::endl;
    return *this;
}

IdentStr operator&(const IdentStr& pobj1, const IdentStr& pobj2)
{
    bool check[256];
    memset(check,0,256);
    for (int i = 0; i < pobj1.len; i++) {
        check[pobj1.pCh[i]] = true;
    }
    char* tmp2 = new char[pobj2.len];
    int j = 0;
    for (int i = 0; i < pobj2.len; i++) {
        if (!check[pobj2.pCh[i]]) {
            tmp2[j++] = pobj2.pCh[i];
        }
    }
    IdentStr tmp(pobj1.len + j);
    int i = 0;
    j = 0;
    while (tmp.pCh[i++] = pobj1.pCh[j++]);
    i = pobj1.len;
    j = 0;
    while (tmp.pCh[i++] = tmp2[j++]);
    std::cout << "IdentStr operator&(const IdentStr& pobj1, const IdentStr& pobj2)" << std::endl;
    delete[] tmp2;
    return tmp;
}

IdentStr operator&(const IdentStr& pobj1, const char* pobj2)
{
    if (pobj1.len == 0) {
        IdentStr tmp(pobj2);
        return tmp;
    }
    int pobj2len = strlen(pobj2);

    bool check[256];
    memset(check,0,256);
    for (int i = 0; i < pobj1.len; i++) {
        check[pobj1.pCh[i]] = true;
    }
    char* tmp2 = new char[pobj2len];
    int j = 0;
    for (int i = 0; i < pobj2len; i++) {
        if (!((pobj2[i] >= 'a' && pobj2[i] <= 'z') || (pobj2[i] >= 'A' && pobj2[i] <= 'Z') ||
        (pobj2[i] >= '0' && pobj2[i] <= '9') || (pobj2[i] == '_'))) {
            std::cout << "Bad String, pobj2[" << i << "] = " << pobj2[i] << std::endl;
            IdentStr tmp(0);
            return tmp;
        }

        if (!check[pobj2[i]]) {
            tmp2[j++] = pobj2[i];
        }
    }
    IdentStr tmp(pobj1.len + j);

    int i = 0;
    j = 0;
    while (tmp.pCh[i++] = pobj1.pCh[j++]);
    i = pobj1.len;
    j = 0;
    while (tmp.pCh[i++] = tmp2[j++]);
    std::cout << "IdentStr operator&(const IdentStr& pobj1, const char* pobj2)" << std::endl;
    delete[] tmp2;
    return tmp;
}

IdentStr operator&(const char* pobj1, const IdentStr& pobj2)
{
    IdentStr tmp1(pobj1);
    if (tmp1.len == 0) {
        return IdentStr(0);
    }
    return tmp1 & pobj2;
}

}
