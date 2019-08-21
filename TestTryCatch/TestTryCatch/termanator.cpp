// Using set_terminate()
// Delete only created object
#include <exception>

#include "all_function.h"

void terminator() {
    cout << "I'll be back!" << endl;
    exit(0);
}

void (*old_terminame)() = set_terminate(terminate);

class Botch {
public:
    class Fruit {};
    Botch() {
        cout << "Botch" << endl;
    }
    void f() {
        cout << "Botch::f()" << endl;
        throw Fruit();
        
    }
    ~Botch() { 
        cout << "~Botch" << endl; 
        throw 'c';
         }
};

int TryTerminator() {
    try {
        Botch b;
        b.f();
    }
    catch (...) {
        cout << "inside catch(...)" << endl;
    }

    return 0;
}