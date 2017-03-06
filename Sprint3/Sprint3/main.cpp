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

//implements quicksort for primary condition (sorting by length) and switches to insertion sort as needed
void primaryQuickSort(Vector<String>& v, int beg, int end) {
    if (beg < end) { //checks to see if index range is valid
        int pivot = primaryChoosePivot(v, beg, end); //chooses a pivot (based on length)
        int newPivotLoc = primaryPartition(v, beg, end, pivot); //sorts vector based on pivot value
        if (end-beg > 21) { //if size of subarray in vector is above insertion threshold
            primaryQuickSort(v, beg, newPivotLoc-1);
            primaryQuickSort(v, newPivotLoc+1, end);
        }
        else { //if size of subarray is small enough to switch insertion sort
            primaryInsertionSort(v, beg, newPivotLoc);
            primaryInsertionSort(v, newPivotLoc+1, end+1);
        }
    }
}

//implements quicksort for secondary condition (sorting alphabetically) and switches to insertion sort as needed
void secondaryQuickSort(Vector<String>& v, int beg, int end) {
    if (beg < end) { //checks to see if index range is valid
        int pivot = secondaryChoosePivot(v, beg, end); //chooses pivot (based on char in alphabet)
        int newPivotLoc = secondaryPartition(v, beg, end, pivot);
        if (end-beg > 21) { //if size of subarray in vector is above insertion threshold
            secondaryQuickSort(v, beg, newPivotLoc-1);
            secondaryQuickSort(v, newPivotLoc+1, end);
        }
        else { //if size of subarray is small enough to switch insertion sort
            secondaryInsertionSort(v, beg, newPivotLoc);
            secondaryInsertionSort(v, newPivotLoc+1, end+1);
        }
    }
}

//uses primary quicksort algorithm for length and three way partition quicksort for alphabetical sorting
void combineQuickSorts(Vector<String>& v) {
    if (v.size() < 21) { //if entire array size is less than 21, use insertion sort entirely
        combineInsertionSorts(v);
        return;
    }

    primaryQuickSort(v, 0, v.size()-1); //calls primary quicksort algorithm for length

    int beg = 0;
    int end = 0;
    for (int i = 1; i < v.size(); i++) { //loops through vector elements to find bounds for different lengths
        if (i == v.size()-1) { //if for loop has reached last element of vector
            //secondaryQuickSort(v, beg, v.size()-1);
            threeWayPartition(v, beg, v.size()-1, 0); //partition+sort from last beginning index to end of vector
        }
        else {
            if (v[i].size() != v[beg].size()) { //checks to find index where length changes
                end = i-1; //sets end as index of last element with a particular length
                //secondaryQuickSort(v, beg, end);
                threeWayPartition(v, beg, end, 0); //partition for current subarray of vector
                beg = i; //resets beginning index for next length
            }
        }
    }
}

//chooses a pivot for primary condition of length using median of three
int primaryChoosePivot(Vector<String>& v, int beg, int end) {
    int mid = (beg+end)/2; //finds index of middle element
    if (v[mid].size() <= v[beg].size() && v[beg].size() <= v[end].size()) { //if mid length <= beg length <= end length
        return beg;
    }
    else if (v[end].size() <= v[beg].size() && v[beg].size() <= v[mid].size()) { //if end length <= beg length <= mid length
        return beg;
    }
    else if (v[beg].size() <= v[mid].size() && v[mid].size() <= v[end].size()) { //if beg length <= mid length <= end length
        return mid;
    }
    else if (v[end].size() <= v[mid].size() && v[mid].size() <= v[beg].size()) { //if end length <= mid length <= beg length
        return mid;
    }
    else { //if end length is between beg length and mid length
        return end;
    }
}

//partitions data based on length and selected median of three pivot
int primaryPartition(Vector<String>& v, int beg, int end, int pivotLoc) {
    v.swap(pivotLoc, end); //move pivot to end of subarray
    String pivot = v[end];
    int j = beg; //sets variable that will move up array
    int k = end-1; //sets variable that will move down array

    //while jth element in vector with length > pivot length has not been found
    while (j < end && (pivot.size() > v[j].size() || v[j].size() == pivot.size())) {
        j++;
    }
    //while kth element in vector with length < pivot length has not been found
    while (k > beg && (v[k].size() > pivot.size() || v[k].size() == pivot.size())) {
        k--;
    }

    while (k > j) { //while j and k have not crossed, indicating end of partition
        v.swap(j, k);
        while (pivot.size() > v[j].size() || v[j].size() == pivot.size()) {
            j++;
        }
        while (v[k].size() > pivot.size() || v[k].size() == pivot.size()) {
            k--;
        }
    }
    v.swap(j, end); //return pivot to rightful place
    return j; //return pivot index
}

//chooses a pivot for secondary alphabetical condition using median of three
int secondaryChoosePivot(Vector<String>& v, int beg, int end) {
    int mid = (beg+end)/2; //find middle value
    if ((v[beg] > v[mid] || v[beg] == v[mid]) && (v[end] > v[beg] || v[beg] == v[end])) { //if element at beg is median (between mid and end)
        return beg;
    }
    else if ((v[beg] > v[end] || v[beg] == v[end]) && (v[mid] > v[beg] || v[beg] == v[mid])) { //if element at beg is median (between end and mid)
        return beg;
    }
    else if ((v[mid] > v[beg] || v[mid] == v[beg]) && (v[end] > v[mid] || v[mid] == v[end])) { //if element at mid is median (between beg and end)
        return mid;
    }
    else if ((v[mid] > v[end] || v[mid] == v[end]) && (v[beg] > v[mid] || v[mid] == v[beg])) { //if element at mid is median (between end and beg)
        return mid;
    }
    else { //if element at end is median (between beg and mid or mid and beg)
        return end;
    }
}

//partitions data by alphabetical order based on pivot selected by median of three
int secondaryPartition(Vector<String>& v, int beg, int end, int pivotLoc) {
    v.swap(pivotLoc, end); //isolates pivot at end of subarray
    String pivot = v[end];
    int j = beg; //variable to iterate up
    int k = end-1; //variable to iterate down

    while (j < end && (pivot > v[j]|| v[j] == pivot)) { //while jth element that is > pivot has not been found
        j++;
    }
    while (k > beg && (v[k] > pivot || v[k] == pivot)) { //while kth element that is < pivot has not been found
        k--;
    }

    while (k > j) { //while j and k have not crossed, indicating end of partition
        v.swap(j, k);
        while (pivot > v[j] || v[j] == pivot) {
            j++;
        }
        while (v[k] > pivot || v[k] == pivot) {
            k--;
        }
    }
    v.swap(j, end); //return pivot to rightful place
    return j; //return pivot index
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
