#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <own/string.h>

using Catch::Matchers::Equals;

TEST_CASE("Test String", "[String]") {
    own::String es;
    SECTION("Empty string") {
        REQUIRE(es.getLen() == 0);
        REQUIRE_THAT(es.getStr(), Equals(""));
        REQUIRE(es.getChar(0) == '\0');
    }
    own::String s("Aue");
    SECTION("String created from c-string") {
        REQUIRE(s.getLen() == 3);
        REQUIRE_THAT(s.getStr(), Equals("Aue"));
        REQUIRE(s.getChar(0) == 'A');
        REQUIRE(s.getChar(1) == 'u');
        REQUIRE(s.getChar(2) == 'e');
        REQUIRE(s.getChar(3) == '\0');
    }
}
