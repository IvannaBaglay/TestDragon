#include "all_function.h"

class X {
public:
    X(){
        cout << "X" << endl;
    }
    ~X() {
        cout << "~X" << endl;
    }
    class Trouble {
    public:
        Trouble() {
            cout << "Trouble" << endl;
        }
        ~Trouble() {
            cout << "~Trouble" << endl;
        }
    };
    class Small : public Trouble {
    public:
        Small() {
            cout << "Small" << endl;
        }
        ~Small() {
            cout << "~Small" << endl;
        }
    };
    class Big : public Trouble {
    public:
        Big() {
            cout << "Big" << endl;
        }
        ~Big() {
            cout << "~Big" << endl;
        }
    };

    void f() { throw Big(); }
};

int CallBaseExcept () {
    X x;

    try {
        x.f();
    }
    catch (X::Trouble&) {
        cout << "Cought Trouble" << endl;
    }
    catch (X::Small&) {
        cout << "Cought Small" << endl;
    }
    catch (X::Big) {
        cout << "Cought Big" << endl;
    }
   

    return 0;
}