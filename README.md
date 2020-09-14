# Библиотека String
Лабораторная работа ФБИТ ИТМО
• [Задание](TASK.md)
• [Результат](RESULT.md)


- Документация (Doxygen): <https://alyukovnet.ru/string>
- Репозиторий (GitHub): <https://github.com/alyukovnet/string>

## To-do
1. [x] Модуль `String` с реализацией классов `String`, `IdentStr`, `BinStr`
2. [x] Тестовая консольная программа
3. [ ] Интерфейс на Qt для демонстрации возможностей методов классов

### Зависимости
## Сборка и запуск
1. g++ compiler
2. [CMake](https://cmake.org/)
3. [Catch2](https://github.com/catchorg/Catch2) (включён в проект)
```shell script
### Сборка
mkdir build
cd build
cmake .. && cmake --build
```
### Тестирование
```shell script
ctest
```
### Запуск примеров
```shell script
./examples/cli
```
