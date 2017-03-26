/*
Course Number:  CSE 2341
Programmer:     Sabrina Peng
Date:           2/17/17
Program Number: Sprint2
Purpose:        Uses CATCH framework to test custom string and vector classes
Instructor: 	Mark Fontenot
TA:             Chris Henk, Kevin Queenan
Sources Consulted: Stack Overflow, C++ How to Program by Deitel, Deitel
*/

//#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "DSVector.h"
#include "DSString.h"
#include "LinkedList.h"

TEST_CASE("LinkedList class", "[linkedlist]"){

    LinkedList<int> list1;
    LinkedList<int> list2;
    LinkedList<int> list3(8);
    LinkedList<String> list4;
    LinkedList<String> list5;
    LinkedList<String> list6("yo gabba gabba");

    for (int i = 0; i < 10; i++) {
        list2.add(i);
    }

    String s[11];
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
    s[10] = String("yo gabba gabba");
    for (int i = 0; i < 11; i++) {
        list5.add(s[i]);
    }

    SECTION("NumElements function") {
        REQUIRE(list1.size() == 0);
        REQUIRE(list2.size() == 10);
        REQUIRE(list3.size() == 1);
        REQUIRE(list4.size() == 0);
        REQUIRE(list5.size() == 11);
        REQUIRE(list6.size() == 1);
    }

    SECTION("[] Operator") {
        //REQUIRE(list1[3] == "OUT OF RANGE");
        REQUIRE(list2[2] == 2);
        REQUIRE(list2[8] == list3[0]);
        //REQUIRE(list4[2] == "OUT OF RANGE");
        REQUIRE(list5[3] == "THIS IS AN UPPERCASE STRING");
        String str = "yo gabba gabba";
        REQUIRE(list6[0] == str);
    }

    /*
    SECTION("Assignment operator") {
        Vector<int> vtr1;
        vtr1 = integers2;
        REQUIRE(vtr1[4] == 4);
        Vector<String> vtr2;
        vtr2 = strings2;
        REQUIRE(vtr2[3] == s[3]);
        vtr2 = Vector<String>(3);
        REQUIRE(vtr2.getCapacity() == 3);
        Vector<String> vtr3 = vtr2;
        REQUIRE(vtr3.size() == 0);
        REQUIRE(vtr3.getCapacity() == 3);
    }

    SECTION("Resize function") {
        integers1.resize();
        REQUIRE(integers1.size() == 0);
        REQUIRE(integers1.getCapacity() == 20);
        integers2.resize();
        for (int i = 0; i < 15; i++) {
            REQUIRE(integers2[i] == i);
        }
        strings2.resize();
        REQUIRE(strings2.size() == 11);
        REQUIRE(strings2.getCapacity() == 30);
        REQUIRE(strings2[strings2.size()-1] == "yo gabba gabba");
    }

    SECTION("push_back function") {
        integers1.push_back(23);
        REQUIRE(integers1.size() == 1);
        REQUIRE(integers1[integers1.size()-1] == 23);
        String str = "THIS IS AN UPPERCASE STRING";
        strings2.push_back(str);
        REQUIRE(strings2.size() == 12);
        REQUIRE(strings2[strings2.size()-1] == strings2[3]);
        strings3.push_back(str);
        strings3.push_back(str);
        REQUIRE(strings3[0] == "THIS IS AN UPPERCASE STRING");
        REQUIRE(strings3[0] == strings3[1]);
    }

    SECTION("pop_back function") {
        integers1.push_back(23);
        integers1.pop_back();
        REQUIRE(integers1.size() == 0);
        strings2.pop_back();
        strings2.pop_back();
        strings2.pop_back();
        REQUIRE(strings2[strings2.size()-1] == "  split  split  split  ");
        String str = "THIS IS AN UPPERCASE STRING";
        strings3.push_back(str);
        strings3.push_back(str);
        strings3.pop_back();
        REQUIRE(strings3.size() == 1);
        REQUIRE(strings3[0] == "THIS IS AN UPPERCASE STRING");
    }

    SECTION("Empty function") {
        REQUIRE(integers1.empty() == true);
        REQUIRE(integers2.empty() == false);
        REQUIRE(integers3.empty() == false);
        REQUIRE(strings1.empty() == true);
        REQUIRE(strings2.empty() == false);
        REQUIRE(strings3.empty() == true);
    }
    */
}
