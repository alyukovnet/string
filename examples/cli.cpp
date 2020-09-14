/*!
 *  @file
 *  @brief Заголовочный файл с описанием классов
 *  @example CLI cli.cpp
 *  An example of the test class.
 */
#include <iostream>

#include <own/string.h>
#include <own/identstr.h>
#include <own/binstr.h>

/**
 * @brief Консольный (CLI) пример
 *
 * Демонстрация возможностей библиотеки в консоли
 *
 * @param argc Число аргуметов
 * @param argv Список аргументов
 *
 * @return Статус исполнения программы
 */
int main(int argc, char** argv)
{
    own::IdentStr *str = new own::IdentStr("abc");
    //own::IdentStr *istr = new own::IdentStr("Ya");
    //own::IdentStr t("aue");
    //own::IdentStr estr = ~t;
    //str->show();
    //std::cout << (*str)[0] << std::endl;
    //estr.show();
    return 0;
}
