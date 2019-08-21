#include "all_function.h"

class BaseInitExept {
public:
    class BaseInitExeptExept {};
    BaseInitExept(int i){
        i_ = i;
        //throw BaseInitExeptExept();
    }
    BaseInitExept();
private:
    int i_;
};

class DerivedInitExept : public BaseInitExept {
public:
    class DerivedInitExeptExept {
        string msg_;
    public:
        DerivedInitExeptExept(string msg) {
            msg_ = msg;
        }
        const string get_msg() const {
            return msg_;
        }
    };
    DerivedInitExept(int j)
    try
        : BaseInitExept(j) {
        cout << "This won't print; " << endl;
    }
    catch (BaseInitExeptExept&) {
        throw DerivedInitExeptExept("Base subobject threw; ");
    }
};

int InitExept() {
    try {
        DerivedInitExept d(3);
    }
    catch(DerivedInitExept::DerivedInitExeptExept &d){
        cout << d.get_msg() << endl;
    }
    return 0;
}