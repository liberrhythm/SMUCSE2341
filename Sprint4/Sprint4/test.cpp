/*
Course Number:  CSE 2341
Programmer:     Sabrina Peng
Date:           3/25/17
Program Number: Sprint2
Purpose:        Uses CATCH framework to test custom linked list class
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

    LinkedList<String> list7 = list5;

    SECTION("Size function") {
        REQUIRE(list1.size() == 0);
        REQUIRE(list2.size() == 10);
        REQUIRE(list3.size() == 1);
        REQUIRE(list4.size() == 0);
        REQUIRE(list5.size() == 11);
        REQUIRE(list6.size() == 1);
    }

    SECTION("[] Operator") {
        REQUIRE(list2[2] == 2);
        REQUIRE(list2[8] == list3[0]);
        REQUIRE(list5[3] == "THIS IS AN UPPERCASE STRING");
        String str = "yo gabba gabba";
        REQUIRE(list6[0] == str);
    }

    SECTION("Get function") {
        REQUIRE(list2.get(2) == 2);
        REQUIRE(list2.get(8) == list3.get(0));
        REQUIRE(list5.get(3) == "THIS IS AN UPPERCASE STRING");
        String str = "yo gabba gabba";
        REQUIRE(list6.get(0) == str);
    }

    SECTION("Copy constructor") {
        REQUIRE(list7.size() == 11);
        REQUIRE(list7[4] == "this is an uppercase string");
        LinkedList<int> integers1 = list2;
        for (int i = 0; i < 10; i++) {
            REQUIRE(list2[i] == i);
        }
        LinkedList<String> strings1 = list4;
        REQUIRE(strings1.size() == 0);
        LinkedList<String> strings2 = list6;
        REQUIRE(strings2.size() == 1);
        REQUIRE(strings2[0] == s[10]);
    }

    SECTION("Assignment operator") {
        LinkedList<String> strings1;
        strings1 = list4;
        REQUIRE(strings1.size() == 0);
        strings1 = list6;
        REQUIRE(strings1.size() == 1);
        REQUIRE(strings1[0] == s[10]);
        LinkedList<int> integers1(4);
        list2 = integers1;
        REQUIRE(list2.size() == 1);
        REQUIRE(list2[0] == 4);
    }

    SECTION("Add function") {
        list1.add(3);
        REQUIRE(list1.size() == 1);
        REQUIRE(list1[0] == 3);
        String str = "THIS IS AN UPPERCASE STRING";
        list5.add(str);
        REQUIRE(list5.size() == 12);
        REQUIRE(list5[11] == list5[3]);
        list6.add("");
        list6.add("");
        REQUIRE(list6[1] == list6[2]);
    }

    SECTION("Add to front function") {
        list1.addToFront(3);
        REQUIRE(list1.size() == 1);
        REQUIRE(list1[0] == 3);
        String str = "THIS IS AN UPPERCASE STRING";
        list5.addToFront(str);
        REQUIRE(list5.size() == 12);
        REQUIRE(list5[0] == list5[4]);
        REQUIRE(list5[11] == "yo gabba gabba");
        String str1 = list6[0];
        list6.addToFront("");
        list6.addToFront("");
        REQUIRE(list6[0] == list6[1]);
        REQUIRE(list6[2] == str1);
    }

    SECTION("Remove function") {
        list3.remove(0);
        REQUIRE(list3.size() == 0);
        list5.remove(10);
        list5.remove(9);
        list5.remove(8);
        REQUIRE(list5.size() == 8);
        REQUIRE(list5[list5.size()-1] == "  split  split  split  ");
        String str = "THIS IS AN UPPERCASE STRING";
        list6.add(str);
        list6.add(str);
        list6.remove(list6.size()-1);
        REQUIRE(list6.size() == 2);
        REQUIRE(list6[1] == str);
        list7.remove(1);
        list7.remove(1);
        REQUIRE(list7.size() == 9);
        REQUIRE(list7[1] == list5[3]);
    }

    SECTION("Clear function") {
        list2.clear();
        REQUIRE(list2.size() == 0);
        list5.clear();
        REQUIRE(list5.size() == 0);
    }
}
