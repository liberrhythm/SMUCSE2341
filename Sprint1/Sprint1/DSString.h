#ifndef STRING
#define STRING

#include <iostream>
#include <cstring>
#include <stdexcept>
#include <iomanip>
#include <fstream>

//using namespace std;

class String {

    friend std::ofstream& operator<< (std::ofstream&, const String&);
    friend std::ifstream& operator>> (std::ifstream&, String&);

    private:

        int length;
        char* arr;

    public:

        String();
        String(const char*);
        String(const String&);

        String& operator= (const char*);
        String& operator= (const String&);
        String operator+ (const String&);
        bool operator== (const char*);
        bool operator== (const String&);
        bool operator> (const String&);
        char& operator[] (const int);

        int size();
        String substring(int, int);
        char* c_str(); //get cstring equivalent
        bool empty();

        ~String();

};
#endif
