#ifndef STRING
#define STRING

#include <iostream>
#include <cstring>
using namespace std;

class String {

    private:
        int length;
        int capacity;
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
        char& find(); //find first instance of char
        bool empty();


        friend std::ostream& operator<< (std::ostream&, const String&);

        ~String();

};
#endif
