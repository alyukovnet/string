# Лабораторная работа
Вариант 32. [Задание](TASK.md) [Интерфейс](interface.txt)
## To-do:
1. [x] Модуль `String` с реализацией классов `String`, `IdentStr`, `BinStr`
2. [ ] Тестовая консольная программа
3. [ ] Интерфейс на Qt для демонстрации возможностей методов классов
## Сборка и запуск:
### Зависимости
1. g++ compiler
2. CMake
3. Catch2 (exists in project)
```shell script
mkdir build
cd build
cmake .. && cmake --build
ctest
./main
```
