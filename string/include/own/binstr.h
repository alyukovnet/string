/*!
\file
\brief Заголовочный файл с описанием класса "Битовая строка"

Данный файл содержит в себе определения производного
от "Строка" класса "Битовая строка"
*/
#ifndef OWN_STRING_BINSTR_H
#define OWN_STRING_BINSTR_H

#include "string.h"

namespace own {

/*!
\brief Производный от "Строка" класс "Битовая строка"

Строки данного класса могут содержать только символы '0' или '1'. Если
в составе инициализирующей строки будут встречены любые символы, отличные
от допустимых, "Битовая строка" принимает нулевое значение.
Содержимое данных строк рассматривается как двоичное число.
Отрицательные числа хранятся в дополнительном коде.
*/
class BinStr : public String
{
public:
    /*!
    Конструктор без параметров (длина строки = 0) или принимающий длину строки
    \param[in] len Длина строки (по умолчанию 0)
    */
    BinStr(int = 0);

    /*!
    Конструктор, принимающий в качестве параметра Си-строку (заканчивается нулевым байтом)
    \param[in] s Си-строка
    */
    BinStr(const char*);
    
    /*!
    Конструктор копирования
    \param[in] from Исходный объект
    */
    BinStr(const BinStr&);
    
    /*!
    Деструктор
    */
    ~BinStr();

    //! Знак двочного числа
	enum SIGN {
        POSITIVE = 1,  ///< Положительное число
        NEGATIVE = 0  ///< Отрицательное число
    };

	/*!
	Получение знака двоичного числа
	\return Знак числа SIGN::POSITIVE или SIGN::NEGATIVE
	*/
	int getSign() const;

    /*!
    Проверка на положительное число
    \return Является ли число положительным
    */
    bool isPositive() const;

    /*!
    Проверка на отрицательное число
    \return Является ли число отрицательным
    */
    bool isNegative() const;

    /*!
	Преобразование строки в беззнаковое число
    \return Беззнаковое число
	*/
    int getUnsignedNum() const;

    /*!
	Преобразование строки в число
    \return Число
	*/
	int getNum() const;

    /*!
    Оператор присваивания
    */
    BinStr& operator=(const BinStr&);

    /*!
    Операция "исключающее или"
    \return Сумма по модулю 2
    */
    friend BinStr operator^(const BinStr&, const BinStr&);

    /*!
    Операция "исключающее или"
    \return Сумма по модулю 2
    */
    friend BinStr operator^(const BinStr&, int);

    /*!
    Операция "исключающее или"
    \return Сумма по модулю 2
    */
    friend BinStr operator^(int, const BinStr&);

    /*!
    Проверка равенства строк как бинарных чисел
    */
    friend int operator==(const BinStr&, const BinStr&);

    /*!
    Проверка равенства бинарной строки и числа
    */
    friend int operator==(const BinStr&, int);

    /*!
    Проверка равенства бинарной строки и числа
    */
    friend int operator==(int, const BinStr&);
};

}
#endif // OWN_STRING_BINSTR_H
