/*!
\file
\brief Файл с тестами для класса "Бинарная строка"

Данный файл содержит в себе модульные тесты для
производного от "Строка" класса "Бинарная строка"
*/
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <own/binstr.h>

using Catch::Matchers::Equals;

TEST_CASE("Конструктор без параметров", "[BinStr]") {
    own::BinStr a;
    REQUIRE(a.getLen() == 0);
    REQUIRE_THAT(a.getStr(), Equals(""));
    REQUIRE(a.isPositive());
    REQUIRE_FALSE(a.isNegative());
    REQUIRE(a.getNum() == 0);
}

TEST_CASE("Конструктор принимающий длину строки", "[BinStr]") {
    own::BinStr b(2);
    REQUIRE(b.getLen() == 2);
    REQUIRE_THAT(b.getStr(), Equals("\0\0"));
    REQUIRE(b.isPositive());
}

TEST_CASE("Конструктор принимающий Си-строку", "[BinStr]") {
    own::BinStr c("011");
    REQUIRE(c.getLen() == 3);
    REQUIRE_THAT(c.getStr(), Equals("011"));
    REQUIRE(c.isPositive());
    REQUIRE(c.getNum() == 3);
}

TEST_CASE("Конструктор принимающий Си-строку (строка с невалидными символами)", "[IdentStr]") {
    own::BinStr c("b010");
    REQUIRE(c.getLen() == 0);
    REQUIRE_THAT(c.getStr(), Equals("\0"));
    REQUIRE(c.isPositive());
    REQUIRE(c.getNum() == 0);
}

TEST_CASE("Конструктор копирования", "[BinStr]") {
    own::BinStr d("1110");
    own::BinStr e(d);
    REQUIRE(e.getLen() == 4);
    REQUIRE_THAT(e.getStr(), Equals("1110"));
    REQUIRE(e.getNum() == -2);
    REQUIRE(e.getUnsignedNum() == 14);
}

TEST_CASE("Оператор присваивания", "[BinStr]") {
    own::BinStr d("0110");
    own::BinStr e = d;
    REQUIRE(e.getLen() == 4);
    REQUIRE_THAT(e.getStr(), Equals("0110"));
    REQUIRE(e.getNum() == 6);
}

TEST_CASE("Оператор \"исключаещего или\"", "[BinStr]") {
    own::BinStr a("0110");
    own::BinStr b("0110");
    own::BinStr e = a^b;
    REQUIRE(e.getLen() == 4);
    REQUIRE_THAT(e.getStr(), Equals("0000"));
    REQUIRE(e.getNum() == 0);
    REQUIRE(e.isPositive());
}

TEST_CASE("Оператор \"исключаещего или\" a>b", "[BinStr]") {
    own::BinStr a("10110");
    own::BinStr b("0110");
    own::BinStr e = a^b;
    REQUIRE(e.getLen() == 5);
    REQUIRE_THAT(e.getStr(), Equals("10000"));
    REQUIRE(e.getNum() == -16);
    REQUIRE(e.isNegative());
}

TEST_CASE("Оператор \"исключаещего или\" b>a", "[BinStr]") {
    own::BinStr a("0110");
    own::BinStr b("01110");
    own::BinStr e = a^b;
    REQUIRE(e.getLen() == 5);
    REQUIRE_THAT(e.getStr(), Equals("01000"));
    REQUIRE(e.getNum() == 8);
}

TEST_CASE("Оператор \"исключаещего или\" с числом a", "[BinStr]") {
    own::BinStr a("0110");
    own::BinStr e = 0b1111^a;
    REQUIRE(e.getLen() == 4);
    REQUIRE_THAT(e.getStr(), Equals("1001"));
    REQUIRE(e.getNum() == -7);
}

TEST_CASE("Оператор \"исключаещего или\" с числом b", "[BinStr]") {
    own::BinStr a("0110");
    own::BinStr e = a^0b1111;
    REQUIRE(e.getLen() == 4);
    REQUIRE_THAT(e.getStr(), Equals("1001"));
    REQUIRE(e.getNum() == -7);
}

TEST_CASE("Оператор == 2 бинарные строки", "[BinStr]") {
    own::BinStr a("0110");
    own::BinStr b("00110");
    REQUIRE(a == b);
}

TEST_CASE("Оператор == бинарная строка и число", "[BinStr]") {
    own::BinStr a("0110");
    REQUIRE(a == 6);
}

TEST_CASE("Оператор == число и бинарная строка", "[BinStr]") {
    own::BinStr b("00110");
    REQUIRE(6 == b);
}
