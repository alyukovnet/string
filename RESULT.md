# Результат
- Исходник на GitHub: <https://github.com/alyukovnet/string/blob/master/examples/cli.cpp>
- Исходник в документации: <https://alyukovnet.ru/string/cli_8cpp.html>
## Вывод программы
```
? Введите число объектов (max: 6): 4

> Выделение памяти на 4 объектов базового класса String:

> Ввод (строка):
ITMO_Counter

? IdentStr(0) / BinStr (1): 0
String::String(const char* S) : len(strlen(S))
IdentStr::IdentStr(char* Str) : String(Str)

> .show():
pCh = ITMO_Counter
len = 12

> .getDigitsNum():
0

> Ввод (строка):
1channel

? IdentStr(0) / BinStr (1): 0
String::String(const char* S) : len(strlen(S))
Bad symbol, pCh[0] = 1

> .show():
pCh = 
len = 0

> .getDigitsNum():
0

> Ввод (строка):
00001001

? IdentStr(0) / BinStr (1): 1
String::String(const char* S) : len(strlen(S))
BinStr::BinStr( char* Str):String(Str)

> .show():
pCh = 00001001
len = 8

> .getSign():
Positive

> Ввод (строка):
11111111

? IdentStr(0) / BinStr (1): 1
String::String(const char* S) : len(strlen(S))
BinStr::BinStr( char* Str):String(Str)

> .show():
pCh = 11111111
len = 8

> .getSign():
Negative

Process finished with exit code 0
```
