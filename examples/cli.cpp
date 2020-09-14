/*!
 *  @file
 *  @brief Консольный (CLI) пример
 *  @example CLI cli.cpp
 *  Демонстрация возможностей библиотеки в консоли
 */
#include <iostream>

#include <own/string.h>
#include <own/identstr.h>
#include <own/binstr.h>

/**
 * Вывод информационного сообщения
 * @param message Текст сообщения
 */
void printInfo(std::string);

/**
 * Диалоговой ввод числа
 * @param message Текст сообщения
 * @return Введённое число
 */
int inputDialog(std::string message);

/**
 * Главная функция
 *
 * @param argc Число аргуметов
 * @param argv Список аргументов
 *
 * @return Статус исполнения программы
 */
int main(int argc, char** argv)
{
    int N = inputDialog("Введите число объектов (max: 6)");

    printInfo("Выделение памяти на " + std::to_string(N) + " объектов базового класса String");
    own::String **mass = new own::String*[N];

    for (int i = 0; i < N; i++) {
        printInfo("Ввод (строка)");
        char *in = new char[1024];  // Инициализация Си-строки
        std::cin >> in;

        if (inputDialog("IdentStr(0) / BinStr (1)") == 0) {
            mass[i] = new own::IdentStr(in);
            printInfo(".show()");
            mass[i]->show();
            printInfo(".getDigitsNum()");
            std::cout << static_cast<own::IdentStr*>(mass[i])->getDigitsNum() << std::endl;

        } else {
            mass[i] = new own::BinStr(in);
            printInfo(".show()");
            mass[i]->show();
            printInfo(".getSign()");
            if (static_cast<own::BinStr*>(mass[i])->getSign() == own::BinStr::POSITIVE) {
                std::cout << "Positive" << std::endl;
            } else {
                std::cout << "Negative" << std::endl;
            }
        }
    }
    delete[] mass;

    return 0;
}

void printInfo(std::string message) {
    std::cout << std::endl;
    std::cout << "> " << message << ":" << std::endl;
}

int inputDialog(std::string message) {
    std::cout << std::endl;
    std::cout << "? " << message << ": ";
    int answer;
    std::cin >> answer;
    return answer;
}
