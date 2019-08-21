#include <stdexcept>

#include "all_function.h"

class MyError : public runtime_error {
public:
    MyError(const string& msg = "") : runtime_error(msg) {}
};

int StdExept(){
    try {
        throw MyError("my message");
    }
    catch (MyError& x) {
        cout << x.what()<<endl;
    }
    return 0;
}