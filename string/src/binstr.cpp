/*!
\file
\brief Реализация методов класса "Битовая строка"

Данный файл содержит в себе реализации методов производного
от "Строка" класса "Битовая строка"
*/
#include <iostream>
#include <cstring>

#include "own/string.h"
#include "own/binstr.h"

namespace own {

BinStr::BinStr(int val) : String(val)
{
    std::cout << "BinStr::BinStr(int val) : Stroka(val), val=" << val << std::endl;
}

BinStr::BinStr(const char* Str) : String(Str)
{
    if (!((pCh[0] >= '0' && pCh[0] <= '9'))) {
        std::cout << "Bad symbol, pCh[0]=" << pCh[0] << std::endl;
        if (pCh) delete[] pCh;
        len = 0;
        pCh = new char[len + 1];
        pCh[0] = '\0';
        return;
    }

    for (int i = 1; i < len; i++) {
        if(!(pCh[i] >= '0'&& pCh[i] <= '9')) {
            std::cout << "Bad string, pCh[" << i << "]=" << pCh[i] << std::endl;
            if (pCh) delete[] pCh;
            len = 0;
            pCh = new char[len + 1];
            pCh[0] = '\0';
            return;
        }
    }
    std::cout << "BinStr::BinStr( char* Str):String(Str)" << std::endl;
    //cout << "fun1=" << fun1() << endl;
}

BinStr::BinStr(const BinStr& from) : String(from)
{
    std::cout << "BinStr::BinStr(const BinStr& from) : String(from)" << std::endl;
}

BinStr::~BinStr()
{
    std::cout << "BinStr::~BinStr()" << std::endl;
}

int BinStr::getSign() const
{
    if (pCh[0] == '1')
        return SIGN::NEGATIVE;
    else
        return SIGN::POSITIVE;
}

bool BinStr::isPositive() const
{
    return getSign() == SIGN::POSITIVE;
}

bool BinStr::isNegative() const
{
    return getSign() == SIGN::NEGATIVE;
}

int BinStr::getUnsignedNum() const
{
    int tmp = 0;
    for (int i = 0; i < len; i++) {
        tmp *= 2;
        tmp += pCh[i]-'0';
    }
    return tmp;
}

int BinStr::getNum() const
{
    int tmp = 0;
    if (isPositive()) {
        for (int i = 0; i < len; i++) {
            tmp *= 2;
            tmp += pCh[i]-'0';
        }
    } else {
        for (int i = 0; i < len; i++) {
            tmp *= 2;
            tmp += '1'-pCh[i];
        }
        tmp = -tmp - 1;
    }
    return tmp;
}

BinStr& BinStr::operator=(const BinStr& Ds)
{
    if (&Ds != this) {
        delete[] pCh;
        len = strlen(Ds.pCh);
        pCh = new char[len + 1];
        strcpy(pCh, Ds.pCh);
    }
    std::cout << "BinStr& BinStr::operator=(const BinStr& Ds)" << std::endl;
    return *this;
}

BinStr operator^(const BinStr& pobj1, const BinStr& pobj2) {
    if (pobj1.len >= pobj2.len) {
        BinStr tmp(pobj1.len);
        int i = pobj1.len - 1;
        int j = pobj2.len - 1;
        for (; j>=0; i--, j--) {
            tmp.pCh[i] = (pobj1.pCh[i] == pobj2.pCh[j]) ? '0' : '1';
        }
        for (; i>=0; i--) {
            tmp.pCh[i] = pobj1.pCh[i];
        }
        return tmp;
    } else {
        BinStr tmp(pobj2.len);
        int i = pobj2.len - 1;
        int j = pobj1.len - 1;
        for (; j>=0; i--, j--) {
            tmp.pCh[i] = (pobj2.pCh[i] == pobj1.pCh[j]) ? '0' : '1';
        }
        for (; i>=0; i--) {
            tmp.pCh[i] = pobj2.pCh[i];
        }
        return tmp;
    }
}

BinStr operator^(int pobj1, const BinStr& pobj2) {
    int pobj1len = 0;
    int pobj1i = pobj1;
    for (; pobj1i != 0; pobj1i >>= 1, pobj1len++);

    if (pobj1len >= pobj2.len) {
        BinStr tmp(pobj1len);
        int i = pobj1len - 1;
        int j = pobj2.len - 1;
        for (; j>=0; i--, j--) {
            tmp.pCh[i] = ((pobj1 % 2) == (pobj2.pCh[j]-'0')) ? '0' : '1';
            pobj1 >> 1;
        }
        for (; i>=0; i--) {
            tmp.pCh[i] = (pobj1 % 2 == 0) ? '0' : '1';
            pobj1 >> 1;
        }
        return tmp;
    } else {
        BinStr tmp(pobj2.len);
        int i = pobj2.len - 1;
        int j = pobj1len - 1;
        for (; j>=0; i--, j--) {
            tmp.pCh[i] = ((pobj2.pCh[i]-'0') == (pobj1 % 2)) ? '0' : '1';
            pobj1 >> 1;
        }
        for (; i>=0; i--) {
            tmp.pCh[i] = pobj2.pCh[i];
        }
        return tmp;
    }
}

BinStr operator^(const BinStr& pobj1, int pobj2) {
    return pobj2^pobj1;
}

int operator==(const BinStr& pobj1, const BinStr& pobj2) {
    return pobj1.getNum() == pobj2.getNum();
}

int operator==(const BinStr& pobj1, int pobj2) {
    return pobj1.getNum() == pobj2;
}

int operator==(int pobj1, const BinStr& pobj2) {
    return pobj1 == pobj2.getNum();
}

}
