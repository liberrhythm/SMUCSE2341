#include <iostream>
#include <fstream>
#include <cstring>

#include "DSString.h"
#include "DSVector.h"
using namespace std;

void primaryInsertionSort(Vector<String>&);
void secondaryInsertionSort(Vector<String>&, int, int);

int main(int argc, char* argv[])
{
    ifstream inFile("input.txt", ios::in);
    if (!inFile) {
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
        String s(word);
        words.push_back(s);
        inFile >> word;
    }

    inFile.close();

    primaryInsertionSort(words);

    ofstream outFile(argv[2], ios::out);
    for (int i = 0; i < numWords; i++) {
        outFile << words[i] << endl;
    }

    outFile.close();
}

void primaryInsertionSort(Vector<String>& v) {
    for (int i = 1; i < v.size(); i++) {
        String s = v[i];
        int j = i - 1;
        while (j >= 0 && v[j].size() > s.size()) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = s;
    }

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


void secondaryInsertionSort(Vector<String>& v, int beg, int end) {
    for (int i = beg+1; i < end; i++) {
        String s = v[i];
        int j = i - 1;
        while (j >= beg && v[j] > s) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = s;
    }
}


/*
 for i = 1 to length(A)
    x = A[i]
    j = i - 1
    while j >= 0 and A[j] > x
        A[j+1] ← A[j]
        j ← j - 1
    end while
    A[j+1] = x[3]
 end for
*/
