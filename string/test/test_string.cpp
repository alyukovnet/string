#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <own/string.h>

using Catch::Matchers::Equals;

TEST_CASE("Конструктор без параметров", "[String]") {
    own::String a;
    REQUIRE(a.getLen() == 0);
    REQUIRE_THAT(a.getStr(), Equals(""));
}

TEST_CASE("Конструктор принимающий длину строки", "[String]") {
    own::String b(2);
    REQUIRE(b.getLen() == 2);
    REQUIRE_THAT(b.getStr(), Equals(""));
}

TEST_CASE("Конструктор принимающий Си-строку", "[String]") {
    own::String c("Rex");
    REQUIRE(c.getLen() == 3);
    REQUIRE_THAT(c.getStr(), Equals("Rex"));
    REQUIRE(c.getChar(0) == 'R');
    REQUIRE(c.getChar(1) == 'e');
    REQUIRE(c.getChar(2) == 'x');
}

TEST_CASE("Конструктор принимающий символ", "[String]") {
    own::String d('F');
    REQUIRE(d.getLen() == 1);
    REQUIRE_THAT(d.getStr(), Equals("F"));
    REQUIRE(d.getChar(0) == 'F');
}

TEST_CASE("Конструктор копирования", "[String]") {
    own::String d('F');
    own::String e(d);
    REQUIRE(e.getLen() == 1);
    REQUIRE_THAT(e.getStr(), Equals("F"));
    REQUIRE(e.getChar(0) == 'F');
}
