#include "all_function.h"

class Input {
public:
    Input() {
        cout << "Input()\n";
    }
    ~Input() {
        cout << "~Input()\n";
    }
};

class Input2 {
public:
    Input2() {
        cout << "Input2()\n";
    }
    ~Input2() {
        cout << "~Input2()\n";
    }
};

class BaseClass {
public:
    BaseClass() {
        cout << "BaseClass()\n";
    }
    ~BaseClass() {
        cout << "~BaseClass()\n";
    }
private:
    Input input;
    Input2 input1[2];
};

class DerivedClass1 :public BaseClass {
public:
    DerivedClass1() {
        cout << "DerivedClass1()\n";
    }
    ~DerivedClass1() {
        cout << "~DerivedClass1()\n";
    }
private:
    Input input;
    Input2 input1[2];
};

class DerivedClass2 :public DerivedClass1 {
public:
    DerivedClass2() {
        cout << "DerivedClass2()\n";
    }
    ~DerivedClass2() {
        cout << "~DerivedClass2()\n";
    }
    Input input;
    Input2 input1[2];
};

class DerivedClass3 : public DerivedClass1, public DerivedClass2 {
public:
    DerivedClass3() {
        cout << "DerivedClass3()\n";
    }
    ~DerivedClass3() {
        cout << "~DerivedClass3()\n";
    }
};

int TestBaseClass() {

    //BaseClass base_class;
    //DerivedClass2 derived_class1;
   // DerivedClass2 derived_class2;
    BaseClass* derived_class1 = new DerivedClass2;
    delete derived_class1;
    return 0;
}