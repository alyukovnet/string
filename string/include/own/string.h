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
    \param[in] ch Символ
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
    Вывод в консоль значений переменных класса
    */
    void show() const;
    
    /*!
    Получение символа из заданной позиции
    \param[in] index Позиция символа
    \return Символ
    */
    char getChar(int) const;

    /*!
    Получение ссылки на символ из заданной позиции
    \param[in] index Позиция символа
    \return Ссылка на символ
    */
    char& operator[](int);

    /*!
    Получение перевёрнутой строки
    \return Перевёрнутая строка
    */
    String operator~();

    /*!
    Оператор присваивания
    */
    String& operator=(const String&);

    /*!
    Унарный плюс
    \return Исходная строка
    */
    friend const String& operator+(const String& i);

    /*!
    Сложение строк
    \return Объединённая строка
    */
    friend String operator+(const String&, const String&);

    /*!
    Сложение строк
    \return Объединённая строка
    */
    friend String operator+(const char* pobj2, const String&);

    /*!
    Сложение строк
    \return Объединённая строка
    */
    friend String operator+(const String&, const char* pobj2);

    /*!
    Сложение строк
    */
    String& operator+=(const String&);

    /*!
    Сложение строк
    */
    String& operator+=(const char* pobj2);

    /*!
    Посимвольная проверка равенства строк
    */
    friend int operator==(const String&, const String&);

    /*!
    Посимвольная проверка различности строк
    */
    friend int operator!=(const String&, const String&);
};

}
#endif // STRING_MODULE_STRING_H
