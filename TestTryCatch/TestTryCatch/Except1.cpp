#include "all_function.h"

class Except1 {
public:
    Except1() {
        cout << "Except1\n";
    }
    ~Except1() {
        cout << "~Except1\n";
    }
};

class Except2 {
public:
    Except2(const Except1&) {
        cout << "Except2\n";
    }
    ~Except2() {
        cout << "~Except2\n";
    }
};

void f() { throw Except1(); }

/*
    If void f() { throw Except1(); }
    Output:
        Except1
        inside catch(Except1)
        ~Except1
*/

/*
    void f() { throw Except2(Except1()); }
    Output:
        Except1
        Except2
        ~Except1
        inside catch(Except2)
        ~Except2
*/

int TryExcept() {
    try {
        f();
    }
    catch (Except2&) {
        cout << "inside catch(Except2)" << endl;
    }
    catch (Except1&) {
        cout << "inside catch(Except1)" << endl;
    }
    return 0;
}