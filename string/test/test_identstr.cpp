#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <own/identstr.h>

using Catch::Matchers::Equals;

TEST_CASE("Конструктор без параметров", "[IdentStr]") {
    own::IdentStr a;
    REQUIRE(a.getLen() == 0);
    REQUIRE_THAT(a.getStr(), Equals(""));
    REQUIRE(a.getDigitsNum() == 0);
}

TEST_CASE("Конструктор принимающий длину строки", "[IdentStr]") {
    own::IdentStr b(2);
    REQUIRE(b.getLen() == 2);
    REQUIRE_THAT(b.getStr(), Equals("\0\0"));
    REQUIRE(b.getDigitsNum() == 0);
}

TEST_CASE("Конструктор принимающий Си-строку (правильная строка)", "[IdentStr]") {
    own::IdentStr c("Rex12e3e");
    REQUIRE(c.getLen() == 8);
    REQUIRE_THAT(c.getStr(), Equals("Rex12e3e"));
    REQUIRE(c.getDigitsNum() == 3);
}

TEST_CASE("Конструктор принимающий Си-строку (строка, начинающаяся с числа)", "[IdentStr]") {
    own::IdentStr c("1ex12e3e");
    REQUIRE(c.getLen() == 0);
    REQUIRE_THAT(c.getStr(), Equals("\0"));
    REQUIRE(c.getDigitsNum() == 0);
}

TEST_CASE("Конструктор принимающий Си-строку (строка с невалидными символами)", "[IdentStr]") {
    own::IdentStr c("Eex!2e3e");
    REQUIRE(c.getLen() == 0);
    REQUIRE_THAT(c.getStr(), Equals("\0"));
    REQUIRE(c.getDigitsNum() == 0);
}

TEST_CASE("Конструктор копирования", "[IdentStr]") {
    own::IdentStr d("F");
    own::IdentStr e(d);
    REQUIRE(e.getLen() == 1);
    REQUIRE_THAT(e.getStr(), Equals("F"));
    REQUIRE(e.getDigitsNum() == 0);
}

TEST_CASE("Оператор присваивания", "[IdentStr]") {
    own::IdentStr d("F");
    own::IdentStr e = d;
    REQUIRE(e.getLen() == 1);
    REQUIRE_THAT(e.getStr(), Equals("F"));
    REQUIRE(e.getDigitsNum() == 0);
}

TEST_CASE("Объединение строк-идентификаторов", "[IdentStr]") {
    own::IdentStr a("Beg");
    own::IdentStr b("Rex");
    own::IdentStr e = a & b;
    REQUIRE(e.getLen() == 5);
    REQUIRE_THAT(e.getStr(), Equals("BegRx"));
    REQUIRE(e.getDigitsNum() == 0);
}

TEST_CASE("Объединение строки-идентификатора с Си-строкой", "[IdentStr]") {
    own::IdentStr a("Beg");
    own::IdentStr e = a & "4youe";
    REQUIRE_THAT(e.getStr(), Equals("Beg4you"));
    REQUIRE(e.getLen() == 7);
    REQUIRE(e.getDigitsNum() == 1);
}

TEST_CASE("Объединение строки-идентификатора с Си-строкой с невалидными символами", "[IdentStr]") {
    own::IdentStr a("Beg");
    own::IdentStr e = a & "4yo!ue";
    REQUIRE(e.getLen() == 0);
    REQUIRE_THAT(e.getStr(), Equals(""));
    REQUIRE(e.getDigitsNum() == 0);
}

TEST_CASE("Объединение Си-строки со строкой-идентификатором", "[IdentStr]") {
    own::IdentStr a("Beg");
    own::IdentStr e = "Y4yoe" & a;
    REQUIRE(e.getLen() == 7);
    REQUIRE_THAT(e.getStr(), Equals("Y4yoeBg"));
    REQUIRE(e.getDigitsNum() == 1);
}

TEST_CASE("Объединение невалидной Си-строки со строкой-идентификатором", "[IdentStr]") {
    own::IdentStr a("Beg");
    own::IdentStr e = "4Y4yoe" & a;
    REQUIRE(e.getLen() == 0);
    REQUIRE_THAT(e.getStr(), Equals(""));
    REQUIRE(e.getDigitsNum() == 0);
}
