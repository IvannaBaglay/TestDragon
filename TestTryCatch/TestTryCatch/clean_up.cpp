// when an exception is triggered,
// only finished objects are destroyed

#include "all_function.h"

class Trace {
public:
    Trace() {
        obj_id_ = counter_++;
        cout << "constructing Trace #" << obj_id_ << endl;
        if (obj_id_ == 3)
        {
            throw 3;
        }
    }
    ~Trace() {
        cout << "destruction Trace #" << obj_id_ << endl;
    }
private:
    static int counter_;
    int obj_id_;
};

int Trace::counter_ = 0;

int CleanUp() {
    try {
        Trace n1;
        Trace array[5];
        Trace n2;
    }
    catch (int i) {
        cout << "catch" << i << endl;
    }
    return 0;
}