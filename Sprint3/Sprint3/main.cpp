/*
Course Number:  CSE 2341
Programmer:     Sabrina Peng
Date:           3/3/17
Program Number: Sprint3
Purpose:        Sorts
Instructor: 	Mark Fontenot
TA:             Chris Henk, Kevin Queenan
Sources Consulted: Stack Overflow, C++ How to Program by Deitel, Deitel
                   www.informit.com/articles/article.aspex?p=2180073&seqNum=4
                   www.cs.princeton.edu/~rs/AlgsDS07/18RadixSort.pdf
*/

#include <iostream>
#include <fstream>
#include <cstring>

#include "DSString.h"
#include "DSVector.h"

using namespace std;

void primaryInsertionSort(Vector<String>&, int, int);
void secondaryInsertionSort(Vector<String>&, int, int);

void combineInsertionSorts(Vector<String>&);

void primaryQuickSort(Vector<String>&, int, int);
void secondaryQuickSort(Vector<String>&, int, int);
int primaryChoosePivot(Vector<String>&, int, int);
int primaryPartition(Vector<String>&, int, int, int);
int secondaryChoosePivot(Vector<String>&, int, int);
int secondaryPartition(Vector<String>&, int, int, int);
void threeWayPartition(Vector<String>&, int, int, int);

void combineQuickSorts(Vector<String>&);

int main(int argc, char* argv[])
{
    ifstream inFile(argv[1], ios::in);
    if (!inFile) { //checks to see if input file can be opened
        cerr << "Input file could not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    int totalWords;
    inFile >> totalWords;
    int numWords;
    inFile >> numWords;

    Vector<String> words(totalWords);
    char word[81];
    inFile >> word;
    while(!inFile.eof()) {
        String s(word); //creates custom String object with char array/buffer
        words.push_back(s);
        inFile >> word;
    }

    inFile.close();

    combineQuickSorts(words); //calls sorting function

    ofstream outFile(argv[2], ios::out);
    if (!outFile) { //checks to see if output file can be opened
        cerr << "Output file could not be opened" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < numWords; i++) {
        outFile << words[i] << endl; //prints out first ___ specified number of words from sorted data
    }

    outFile.close();
}

void primaryQuickSort(Vector<String>& v, int beg, int end) {
    if (beg < end) {
        int pivot = primaryChoosePivot(v, beg, end);
        int newPivotLoc = primaryPartition(v, beg, end, pivot);
        if (end-beg > 21) {
            primaryQuickSort(v, beg, newPivotLoc-1);
            primaryQuickSort(v, newPivotLoc+1, end);
        }
        else {
            primaryInsertionSort(v, beg, newPivotLoc);
            primaryInsertionSort(v, newPivotLoc+1, end+1);
        }
    }
}

void secondaryQuickSort(Vector<String>& v, int beg, int end) {
    if (beg < end) {
        int pivot = secondaryChoosePivot(v, beg, end);
        int newPivotLoc = secondaryPartition(v, beg, end, pivot);
        if (end-beg > 21) {
            secondaryQuickSort(v, beg, newPivotLoc-1);
            secondaryQuickSort(v, newPivotLoc+1, end);
        }
        else {
            secondaryInsertionSort(v, beg, newPivotLoc);
            secondaryInsertionSort(v, newPivotLoc+1, end+1);
        }
    }
}

void combineQuickSorts(Vector<String>& v) {
    if (v.size() < 21) {
        combineInsertionSorts(v);
    }
    primaryQuickSort(v, 0, v.size()-1);

    int beg = 0;
    int end = 0;
    for (int i = 1; i < v.size(); i++) {
        if (i == v.size()-1) {
            //secondaryQuickSort(v, beg, v.size()-1);
            threeWayPartition(v, beg, v.size()-1, 0);
        }
        else {
            if (v[i].size() != v[beg].size()) {
                end = i-1;
                //secondaryQuickSort(v, beg, end);
                threeWayPartition(v, beg, end, 0);
                beg = i;
            }
        }
    }
}

int primaryChoosePivot(Vector<String>& v, int beg, int end) {
    int mid = (beg+end)/2;
    if (v[mid].size() <= v[beg].size() && v[beg].size() <= v[end].size()) {
        return beg;
    }
    else if (v[end].size() <= v[beg].size() && v[beg].size() <= v[mid].size()) {
        return beg;
    }
    else if (v[beg].size() <= v[mid].size() && v[mid].size() <= v[end].size()) {
        return mid;
    }
    else if (v[end].size() <= v[mid].size() && v[mid].size() <= v[beg].size()) {
        return mid;
    }
    else {
        return end;
    }
}

int primaryPartition(Vector<String>& v, int beg, int end, int pivotLoc) {
    v.swap(pivotLoc, end);
    String pivot = v[end];
    int j = beg;
    int k = end-1;

    while (j < end && (pivot.size() > v[j].size() || v[j].size() == pivot.size())) {
        j++;
    }
    while (k > beg && (v[k].size() > pivot.size() || v[k].size() == pivot.size())) {
        k--;
    }

    while (k > j) {
        v.swap(j, k);
        while (pivot.size() > v[j].size() || v[j].size() == pivot.size()) {
            j++;
        }
        while (v[k].size() > pivot.size() || v[k].size() == pivot.size()) {
            k--;
        }
    }
    v.swap(j, end);
    return j;
}

int secondaryChoosePivot(Vector<String>& v, int beg, int end) {
    int mid = (beg+end)/2;
    if ((v[beg] > v[mid] || v[beg] == v[mid]) && (v[end] > v[beg] || v[beg] == v[end])) {
        return beg;
    }
    else if ((v[beg] > v[end] || v[beg] == v[end]) && (v[mid] > v[beg] || v[beg] == v[mid])) {
        return beg;
    }
    else if ((v[mid] > v[beg] || v[mid] == v[beg]) && (v[end] > v[mid] || v[mid] == v[end])) {
        return mid;
    }
    else if ((v[mid] > v[end] || v[mid] == v[end]) && (v[beg] > v[mid] || v[mid] == v[beg])) {
        return mid;
    }
    else {
        return end;
    }
}

int secondaryPartition(Vector<String>& v, int beg, int end, int pivotLoc) {
    v.swap(pivotLoc, end);
    String pivot = v[end];
    int j = beg;
    int k = end-1;

    while (j < end && (pivot > v[j]|| v[j] == pivot)) {
        j++;
    }
    while (k > beg && (v[k] > pivot || v[k] == pivot)) {
        k--;
    }

    while (k > j) {
        v.swap(j, k);
        while (pivot > v[j] || v[j] == pivot) {
            j++;
        }
        while (v[k] > pivot || v[k] == pivot) {
            k--;
        }
    }
    v.swap(j, end);
    return j;
}

void threeWayPartition(Vector<String>& v, int beg, int end, int strIndex) {
    if (beg >= end || strIndex >= v[beg].size()) {
        return;
    }
    if (end-beg <= 21) {
        secondaryInsertionSort(v, beg, end+1);
        return;
    }
    int j = beg;
    int k = end;
    char c = v[beg][strIndex];
    int i = beg+1;
    while (i <= k) {
       char t = v[i][strIndex];
       if (t < c) {
           v.swap(j, i);
           j++, i++;
       }
       else if (t > c) {
           v.swap(k, i);
           k--;
       }
       else {
           i++;
       }
    }
    threeWayPartition(v, beg, j-1, strIndex);
    threeWayPartition(v, j, k, strIndex+1);
    threeWayPartition(v, k+1, end, strIndex);
}

void primaryInsertionSort(Vector<String>& v, int beg, int end) {
    for (int i = beg; i < end; i++) {
        String s = v[i];
        int j = i - 1;
        while (j >= 0 && v[j].size() > s.size()) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = s;
    }
}

void secondaryInsertionSort(Vector<String>& v, int beg, int end) {
    for (int i = beg; i < end; i++) {
        String s = v[i];
        int j = i - 1;
        while (j >= beg && v[j] > s) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = s;
    }
}

void combineInsertionSorts(Vector<String>& v) {
    primaryInsertionSort(v, 0, v.size());
    int beg = 0;
    int end = 0;
    for (int i = 1; i < v.size(); i++) {
        if (i == v.size()-1) {
            secondaryInsertionSort(v, beg, v.size());
        }
        else {
            if (v[i].size() != v[beg].size()) {
                end = i;
                secondaryInsertionSort(v, beg, end);
                beg = i;
            }
        }
    }
}
