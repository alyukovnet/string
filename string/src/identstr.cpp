#include <iostream>
#include <cstring>

#include "own/string.h"
#include "own/identstr.h"

namespace own {

IdentStr::IdentStr(int val) : String(val)
{
    std::cout << "IdentStr::IdentStr(int val) : String(val), val = " << val << std::endl;
}

IdentStr::IdentStr(char Ch) : String(Ch)
{
    if(!((pCh[0] >= 'a' && pCh[0] <= 'z') || (pCh[0] >= 'A'&& pCh[0] <= 'Z') || (pCh[0]=='_'))) {
        std::cout << "Bad Simvol, pCh[0] = " << pCh[0] << std::endl;
        delete[] pCh;
        len = 0;
        pCh = new char[len + 1];
        pCh[0] = '\0';
        return;
    }
    std::cout << "IdentStr::IdentStr(char Ch) : String(Ch)" << std::endl;
}

IdentStr::IdentStr(const char* Str) : String(Str)
{
    if (!((pCh[0] >= 'a'&& pCh[0] <= 'z') || (pCh[0] >= 'A'&& pCh[0] <= 'Z') || (pCh[0] == '_'))) {
        std::cout << "Bad Simvol, pCh[0] = " << pCh[0] << std::endl;
        delete[] pCh;
        len = 0;
        pCh = new char[len + 1];
        pCh[0] = '\0';
        return;
    }
    for (int i = 1; i < len; i++) {
        if(!((pCh[i] >= 'a'&& pCh[i] <= 'z') || (pCh[i] >= 'A'&& pCh[i] <= 'Z') || (pCh[i] >= '0'&& pCh[i] <= '9') || (pCh[i] == '_'))) {
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

// char& IdentStr::operator[](int index)
// {
//     if (index >= 0 && index < len) {
//         std::cout << "char& IdentStr::operator[](int index)" << std::endl;
//         return pCh[index];
//     }
//     return pCh[0];
//     return 
// }

IdentStr IdentStr::operator~()
{
    return IdentStr((~String(pCh)).getStr());
}

IdentStr operator+(const IdentStr& pobj1, const IdentStr& pobj2)
{
    //IdentStr tmp(pobj1);
    IdentStr tmp(pobj1.getLen() + pobj2.getLen());
    //strcpy_s(tmp.pCh,tmp.len+1, pobj1.GetStr());
    int i = 0,j=0;
    while (tmp.pCh[i++] = pobj1.pCh[j++]);
    //strcat_s(tmp.pCh,tmp.len+1, pobj2.GetStr());
    --i; //i = pobj1.GetLen();
    j = 0;
    while (tmp.pCh[i++] = pobj2.pCh[j++]);
    std::cout << "IdentStr operator + (const IdentStr pobj1,const IdentStr pobj2)" << std::endl;
    return tmp;
}

IdentStr operator+(const IdentStr& pobj1, const char* pobj2)
{
//IdentStr tmp(pobj1);
IdentStr tmp1(pobj2);
//if (tmp1.len == 0)
//{
// IdentStr tmp(pobj1.GetLen());
// int i = 0, j = 0; //i = pobj1.GetLen();
// while (tmp.pCh[i++] = pobj1.pCh[j++]);
// cout << "IdentStr operator + ( const IdentStr& pobj1,const char* pobj2,)" << endl;
// return tmp;
//}
//else
//{
IdentStr tmp(pobj1.getLen() + tmp1.getLen());
//IdentStr tmp(pobj1.GetLen() + (int)strlen(pobj2));
int i = 0, j = 0;
while (tmp.pCh[i++] = pobj1.pCh[j++]);
//strcat_s(tmp.pCh,tmp.len+1, pobj2.GetStr());
--i; //i = pobj1.GetLen();
j = 0;
//while (tmp.pCh[i++] = *pobj2++);
while (tmp.pCh[i++] = tmp1.pCh[j++]);
std::cout << "IdentStr operator + (const IdentStr& pobj1,const char* pobj2)" << std::endl;
return tmp;
//}
//IdentStr tmp(pobj1.GetLen() + (int)strlen(pobj2));
//strcpy_s(tmp.pCh,tmp.len+1, pobj1.GetStr());
//int i = 0, j = 0;
//while (tmp.pCh[i++] = pobj1.pCh[j++]);
//strcat_s(tmp.pCh,tmp.len+1, pobj2);
//--i; //i = pobj1.GetLen();
//j = 0;
//while (tmp.pCh[i++] = pobj2[j++]);
//while (tmp.pCh[i++] = *pobj2++);
//std::cout << "IdentStr operator + (const IdentStr pobj1,const char* pobj2)" << std::endl;

//return tmp;

}

IdentStr operator +(const char* pobj1, const IdentStr& pobj2)
{
    IdentStr tmp1(pobj1);
    if (tmp1.len == 0) {
        IdentStr tmp( pobj2.getLen());
        int i=0, j = 0; //i = pobj1.GetLen();
        while (tmp.pCh[i++] = pobj2.pCh[j++]);
        std::cout << "IdentStr operator + (const char* pobj1, const IdentStr& pobj2)" << std::endl;
        return tmp;
    } else {
        IdentStr tmp((int)strlen(pobj1) + pobj2.getLen());
        int i = 0, j = 0;
        while (tmp.pCh[i++] = *pobj1++);
        //strcat_s(tmp.pCh,tmp.len+1, pobj2.GetStr());
        --i; //i = pobj1.GetLen();
        //j = 0;
        while (tmp.pCh[i++] = pobj2.pCh[j++]);
        std::cout << "IdentStr operator + (const char* pobj1, const IdentStr& pobj2)" << std::endl;
        return tmp;
    }

    //IdentStr tmp((int)strlen(pobj1) + pobj2.GetLen());
    //strcpy_s(tmp.pCh,tmp.len+1, pobj1);
    //int i = 0, j = 0;
    //while (tmp.pCh[i++] = *pobj1++);
    //strcat_s(tmp.pCh,tmp.len+1, pobj2.GetStr());
    //--i; //i = pobj1.GetLen();
    //j = 0;
    //while (tmp.pCh[i++] = pobj2.pCh[j++]);
    //std::cout << "IdentStr operator + (const char* pobj2, const IdentStr pobj1)" << std::endl;
    //return tmp;
}

}
