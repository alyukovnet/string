/*!
\file
\brief Заголовочный файл с описанием классов

Данный файл содержит в себе определения основных 
классов, используемых в демонстрационной программе
*/
#ifndef STRING_MODULE_IDENTSTRING_H
#define STRING_MODULE_IDENTSTRING_H

#include "string.h"

namespace own {

/*!
	\brief Производный от "Строка" класс "Строка-идентификатор"

	Строки данного класса строятся по правилам записи идентификаторов
	в СИ, и могут включать в себя только те символы, которые могут входить
	в состав Си-идентификаторов. Если исходные данные противоречат правилам
	записи идентификатора, то создается пустая "Строка-идентификатор".
*/
class IdentStr : public String
{
public:
    /*!
    Конструктор без параметров (длина строки = 0) или принимающий длину строки
    \param[in] len Длина строки (по умолчанию 0)
    */
	IdentStr(int = 0);

    /*!
    Конструктор, принимающий в качестве параметра символ (char)
    \param[in] ch Исходная область памяти
    */
	IdentStr(char ch);

    /*!
    Конструктор, принимающий в качестве параметра Си-строку (заканчивается нулевым байтом)
    \param[in] s Си-строка
    */
	IdentStr(const char*);

    /*!
    Конструктор копирования
    \param[in] from Исходный объект
    */
	IdentStr(const IdentStr&);

    /*!
    Деструктор
    */
	~IdentStr();

	/*!
	Оператор &
	*/
	IdentStr& operator=(const IdentStr&);

	/*!
	Оператор [int]
	*/
	//char& operator[](int);

	/*!
	Поворот строки
	*/
	IdentStr operator~();

	friend IdentStr operator+(const IdentStr&, const IdentStr&);

	friend IdentStr operator+(const IdentStr&, const char*);

	friend IdentStr operator+(const char*, const IdentStr&);
};

}
#endif // STRING_MODULE_STRING_H
