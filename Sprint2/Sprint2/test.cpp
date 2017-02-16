//test class for custom string/vector implementation

//#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "DSVector.h"
#include "DSString.h"

TEST_CASE("Vector class", "[vector]"){

    Vector<int> integers1;
    Vector<int> integers2;
    for (int i = 0; i < 15; i++) {
        integers2.push_back(i);
    }
    Vector<int> integers3 = integers2;
    for (int i = 0; i < 10; i++) {
        integers3.pop_back();
    }

    Vector<String> strings1;
    Vector<String> strings2;
    String s[10];
    s[0] = String("testString");
    s[1] = String("a test string");
    s[2] = String("");
    s[3] = String("THIS IS AN UPPERCASE STRING");
    s[4] = String("this is an uppercase string");
    s[5] = String("\n");
    s[6] = String("");
    s[7] = String("  split  split  split  ");
    s[8] = String("                          ");
    s[9] = String("testString");
    for (int i = 0; i < 10; i++) {
        strings2.push_back(s[i]);
    }

    SECTION("Size function"){
        REQUIRE(integers1.size() == 0);
        REQUIRE(integers2.size() == 15);
        REQUIRE(integers3.size() == 5);
        REQUIRE(strings1.size() == 0);
        REQUIRE(strings2.size() == 10);
    }

    SECTION("Capacity function"){
        REQUIRE(integers1.getCapacity() == 10);
        REQUIRE(integers2.getCapacity() == 20);
        REQUIRE(integers3.getCapacity() == 20);
        REQUIRE(strings1.getCapacity() == 10);
        REQUIRE(strings2.getCapacity() == 10);
    }

}




/*
TEST_CASE("String class", "[string]"){

    String s[10];
    s[0] = String("testString");
    s[1] = String("a test string");
    s[2] = String("");
    s[3] = String("THIS IS AN UPPERCASE STRING");
    s[4] = String("this is an uppercase string");
    s[5] = String("\n");
    s[6] = String("");
    s[7] = String("  split  split  split  ");
    s[8] = String("                          ");
    s[9] = String("testString");

    SECTION("Equality operators"){
        REQUIRE(s[0] == String("testString"));
        REQUIRE(s[0] == s[9]);
        REQUIRE(s[2] == "");
        REQUIRE(s[1] == "a test string");
        REQUIRE(!(s[3] == s[4]));
    }

    SECTION("Assignment operators"){
        String str;
        str = "a test string";
        REQUIRE(str == s[1]);
        str = String("testString");
        REQUIRE(str == s[0]);
        str = "";
        REQUIRE(str == s[6]);
        str = String("\n");
        REQUIRE(str == s[5]);
    }

    SECTION("Addition operator"){
        REQUIRE(String("testStringtestString") == s[0]+s[9]);
        REQUIRE(s[6] + s[6] == "");
        REQUIRE(s[5] + s[6] == String("\n"));
        REQUIRE(s[0] + s[1] + s[2] == "testStringa test string");
    }

    SECTION("Greater than operator"){
        REQUIRE(s[0] > s[1]);
        REQUIRE(s[4] > s[3]);
        REQUIRE(s[9] > s[6]);
        REQUIRE(s[7] > s[6]);
    }

    SECTION("[] Operator"){
        REQUIRE(s[0][1] == 'e');
        REQUIRE(s[9][-1] == 'g');
        REQUIRE(s[3][-3] == 'I');
        REQUIRE(s[4][4] == ' ');
        REQUIRE(s[6][0] == 0);
    }

    SECTION("Size function"){
        REQUIRE(s[9].size() == 10);
        REQUIRE(s[2].size() == 0);
        REQUIRE(s[8].size() == 26);
        REQUIRE(s[3].size() == 27);
    }

    SECTION("Substring function"){
        REQUIRE(s[0].substring(0, 5) == "testS");
        REQUIRE(s[1].substring(-6, -1) == "tring");
        REQUIRE(s[9].substring(0, -3) == "testStri");
        REQUIRE(s[9].substring(0, -1) == s[9]);
        REQUIRE(s[4].substring(0, 4) == "this");
    }

    SECTION("c_str function"){
        REQUIRE(strcmp(s[0].c_str(), "testString") == 0);
        REQUIRE(strcmp(s[9].c_str(), s[0].c_str()) == 0);
        REQUIRE(strcmp(s[2].c_str(), "") == 0);
    }

}
*/
