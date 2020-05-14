/*!
\file
\brief Заголовочный файл с описанием класса "Строка"

Данный файл содержит в себе определения базового
класса "Строка"
*/
#ifndef STRING_MODULE_STRING_H
#define STRING_MODULE_STRING_H

namespace own {

/*!
	\brief Базовый класс "Строка" 
*/
class String
{
protected:
    int len;   ///< Длина строки
    char* pCh; ///< Адрес динамически выделенной памяти для размещения символов строки

public:
    /*!
    Конструктор без параметров (длина строки = 0) или принимающий длину строки
    \param[in] len Длина строки (по умолчанию 0)
    */
    String(int = 0);

    /*!
    Конструктор, принимающий в качестве параметра символ (char)
    \param[in] ch Исходная область памяти
    */
    String(char);

    /*!
    Конструктор, принимающий в качестве параметра Си-строку (заканчивается нулевым байтом)
    \param[in] s Си-строка
    */
    String(const char*);
    
    /*!
    Конструктор копирования
    \param[in] from Исходный объект
    */
    String(const String&);
    
    /*!
    Деструктор
    */
    ~String();

    /*!
    Получение Си-строки
    \return Си-строка
    */
    char* getStr() const;

    /*!
    Получение длины строки
    \return Длина строки
    */
    int getLen() const;

    /*!
    Вывод значений переменных класса
    */
    void show() const;

    /*!
    Получение символа из заданной позиции
    \param[in] pos Позиция символа
    \return Символ
    */
    char getChar(int) const;
};

}
#endif // STRING_MODULE_STRING_H
