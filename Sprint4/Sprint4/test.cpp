/*
Course Number:  CSE 2341
Programmer:     Sabrina Peng
Date:           4/8/17
Program Number: Sprint4
Purpose:        Uses CATCH framework to test custom linked list class, stack class, and queue class
Instructor: 	Mark Fontenot
TA:             Chris Henk, Kevin Queenan
Sources Consulted: Stack Overflow, C++ How to Program by Deitel, Deitel
*/

//#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "DSVector.h"
#include "DSString.h"
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"

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
        list6.add("New York");
        list6.add("New York");
        list6.print();
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

TEST_CASE("Stack class", "[stack]"){

    Stack<int> s1;
    Stack<String> s2;
    Stack<int> s3;
    Stack<String> s4;

    for (int i = 0; i < 10; i++) {
        s1.push(i);
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
        s2.push(s[i]);
    }

    SECTION("Pop function") {
        REQUIRE(s1.pop() == 9);
        REQUIRE(s1.size() == 9);
        REQUIRE(s2.pop() == "yo gabba gabba");
        REQUIRE(s2.pop() == "testString");
        REQUIRE(s2.size() == 9);
    }

    SECTION("Peek function") {
        REQUIRE(s1.peek() == 9);
        REQUIRE(s1.size() == 10);
        REQUIRE(s2.peek() == "yo gabba gabba");
        REQUIRE(s2.size() == 11);
    }

    SECTION("Push function") {
        s3.push(5);
        REQUIRE(s3.peek() == 5);
        REQUIRE(s3.isEmpty() == false);
        REQUIRE(s3.pop() == 5);
        REQUIRE(s3.isEmpty() == true);
        s4.push("meringue");
        s4.push("cream");
        s4.push("bourbon");
        REQUIRE(s4.size() == 3);
        REQUIRE(s4.isEmpty() == false);
        REQUIRE(s4.peek() == "bourbon");
    }

    SECTION("IsEmpty function") {
        REQUIRE(s1.isEmpty() == false);
        REQUIRE(s2.isEmpty() == false);
        REQUIRE(s3.isEmpty() == true);
        REQUIRE(s4.isEmpty() == true);
    }
}

TEST_CASE("Queue class", "[queue]"){

    Queue<int> q1;
    Queue<String> q2;
    Queue<int> q3;
    Queue<String> q4;

    for (int i = 0; i < 10; i++) {
        q1.enqueue(i);
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
        q2.enqueue(s[i]);
    }

    SECTION("Dequeue function") {
        REQUIRE(q1.dequeue() == 0);
        REQUIRE(q1.size() == 9);
        REQUIRE(q2.dequeue() == "testString");
        REQUIRE(q2.dequeue() == "a test string");
        REQUIRE(q2.size() == 9);
    }

    SECTION("Peek function") {
        REQUIRE(q1.peek() == 0);
        REQUIRE(q1.size() == 10);
        int e1 = q1.dequeue();
        REQUIRE(q1.peek() == 1);
        REQUIRE(q2.peek() == "testString");
        REQUIRE(q2.size() == 11);
        String e2 = q2.dequeue();
        REQUIRE(q2.peek() == "a test string");
    }

    SECTION("Enqueue function") {
        q2.enqueue("");
        REQUIRE(q2.size() == 12);
        REQUIRE(q2.peek() == "testString");
        q3.enqueue(5);
        REQUIRE(q3.size() == 1);
        REQUIRE(q3.peek() == 5);
        REQUIRE(q3.isEmpty() == false);
        REQUIRE(q3.dequeue() == 5);
        REQUIRE(q3.isEmpty() == true);
        q4.enqueue("meringue");
        q4.enqueue("cream");
        q4.enqueue("bourbon");
        REQUIRE(q4.size() == 3);
        REQUIRE(q4.isEmpty() == false);
        REQUIRE(q4.peek() == "meringue");
    }

    SECTION("IsEmpty function") {
        REQUIRE(q1.isEmpty() == false);
        String e1;
        int q2size = q2.size();
        for (int i = 0; i < q2size; i++) {
            e1 = q2.dequeue();
        }
        REQUIRE(q2.isEmpty() == true);
        REQUIRE(q3.isEmpty() == true);
        q3.enqueue(4);
        REQUIRE(q3.isEmpty() == false);
        int e2 = q3.dequeue();
        REQUIRE(q3.isEmpty() == true);
        REQUIRE(q4.isEmpty() == true);
    }
}
