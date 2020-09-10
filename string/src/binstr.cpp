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
    if (!((pCh[0] >= '1' && pCh[0] <= '9') || (pCh[0] == '-' && pCh[0] == '+') || pCh[0] != '0')) {
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
    std::cout << "DecStr::DecStr( char* Str):String(Str)" << std::endl;
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

int BinStr::getSign()
{
    if (pCh[0] == '0')
        return SIGN::PLUS;
    else
        return SIGN::MINUS;
}

int BinStr::getNum() const
{
    int tmp = 0;
    for (int i = 0; i < len; i++) {
        tmp *= 2;
        tmp += pCh[i]-'0';
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
    BinStr tmp;
    if (pobj1.len >= pobj2.len) {
        tmp.len = pobj1.len;
        tmp.pCh = new char[tmp.len];
        int i = 0;
        for (; i < pobj1.len - pobj2.len; i++) {
            tmp.pCh[i] = pobj1.pCh[i];
        }
        for (; i < pobj1.len; i++) {
            tmp.pCh[i] = (pobj1.pCh[i]^pobj2.pCh[i]) & 1 + '0';
        }
    } else {
        tmp.len = pobj2.len;
        tmp.pCh = new char[tmp.len];
        int i = 0;
        for (; i < pobj2.len - pobj1.len; i++) {
            tmp.pCh[i] = pobj2.pCh[i];
        }
        for (; i < pobj2.len; i++) {
            tmp.pCh[i] = (pobj1.pCh[i]^pobj2.pCh[i]) & 1 + '0';
        }
    }
}

BinStr operator^(const int pobj1, const BinStr& pobj2) {
    BinStr tmp;
    int pobj1len = 1;
    int pobj1i = pobj1;
    while (pobj1i/=2 != 0) pobj1len++;
    if (pobj1len >= pobj2.len) {
        tmp.len = pobj1len;
        tmp.pCh = new char[tmp.len];
        int i = pobj1len - 1;
        for (; i >= pobj1len - pobj2.len; i--) {
            int digit = pobj1 % 2;
            pobj1 >> 1;
            tmp.pCh[i] = (digit^(pobj2.pCh[i]-'0')) & 1 + '0';
        }
        for (; i >= 0; i--) {
            int digit = pobj1 % 2;
            pobj1 >> 1;
            tmp.pCh[i] = digit + '0';
        }
    } else {
        tmp.len = pobj2.len;
        tmp.pCh = new char[tmp.len];
        int i = pobj2.len - 1;
        for (; i >= pobj2.len - pobj1len; i--) {
            int digit = pobj1 % 2;
            pobj1 >> 1;
            tmp.pCh[i] = digit + '0';
        }
        for (; i >= 0; i--) {
            int digit = pobj1 % 2;
            pobj1 >> 1;
            tmp.pCh[i] = (digit^(pobj2.pCh[i]-'0')) & 1 + '0';
        }
    }
    return tmp;
}

BinStr operator^(const BinStr& pobj1, const int pobj2) {
    return pobj2^pobj1;
}

int operator==(const BinStr& pobj1, const int pobj2) {
    return pobj1.getNum() == pobj2;
}

int operator==(const int pobj1, const BinStr& pobj2) {
    return pobj1 == pobj2.getNum();
}

}
