#include <cstddef>

#include "all_function.h"

template<class T, int sz = 1> class PWrap {
public:
    class RangeError{};
    PWrap() {
        ptr = new T[sz];
        cout << "PWrap constructor " << __FUNCTION__ << endl;
    }
    ~PWrap() {
        delete[] ptr;
        cout << "PWrap destructor " << __FUNCTION__ <<endl;
    }
    T& operator[](int i) throw (RangeError) {
        if (i >= 0 && i < sz) return ptr[i];
        throw RangeError();
    }
private:
    T* ptr;

};

class Cat {
public:
    Cat() {
        cout << "Cat() " << __FUNCTION__ << endl;
    }
    ~Cat() {
        cout << "~Cat() " << __FUNCTION__ << endl;
    }
    void g();
};

class Dog {
public:
    void* operator new[](size_t) {
        cout << "Allocating a Dog " << __FUNCTION__ << endl;
        //throw 47;
        return nullptr;
    }
        void operator delete[](void* p) {
        cout << "Deallocating a Dog " << __FUNCTION__ << endl;
        ::operator delete[](p);
    }
};


class UseResourcesBase1 {
public:
    UseResourcesBase1() {
        cout << "UseResourcesBase1() " << __FUNCTION__ << endl;
    }
    ~UseResourcesBase1() {
        cout << "~UseResourcesBase1() " << __FUNCTION__ << endl;
    }
    void f() {
        cats[1].g();
    }
private:
    PWrap<Cat, 3> cats;
    PWrap<Dog> dog;

};

class UseResources1:public UseResourcesBase1 {
public:
    UseResources1() {
        cout << "UseResources1() " << __FUNCTION__ << endl;
    }
     ~UseResources1() {
        cout << "~UseResources1() " << __FUNCTION__ << endl;
    }
    void f() {
        cats[1].g();
    }
private:
    PWrap<Cat, 3> cats;
    PWrap<Dog> dog;
};

int Wrapped() {
    try {
        
        //UseResources1 ur;
        UseResourcesBase1* ur1 = new UseResources1();
        cout << "\nPointer\n";
        delete ur1;
    }
    catch (int) {
        cout << "inside handler" << endl;
    }
    catch (...) {
        cout << "inside catch(...)" << endl;
    }
    cout << "END" << endl;
    return 0;
}