#ifndef STRING
#define STRING

#include <iostream>
#include <cstring>
#include <stdexcept>
#include <iomanip>

//using namespace std;

class String {

    friend std::ostream& operator<< (std::ostream&, const String&);

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
