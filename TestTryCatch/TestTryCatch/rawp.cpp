// lost pointer

#include <cstddef>

#include "all_function.h"

class Cat {
public:
    Cat() {
        cout << "Cat()" << endl;
    }
    ~Cat() {
        cout << "~Cat()" << endl;
    }
};

class Dog {
public :
    void* operator new(size_t sz) {
        cout << "allocating a Dog" << endl;
        throw 47;
    }
    void operator delete(void* p) {
        cout << "deallocating a Dog" << endl;
        ::operator delete(p);
    }
};

class UseResources {
public:
    UseResources(int count = 1) {
        cout << "UseResources()" << endl;
        cat = new Cat[count];
        dog = new Dog;
    }
    ~UseResources() {
        cout << "~UseResources()" << endl;
        delete[] cat;
        delete dog;
    }
private:
    Cat* cat;
    Dog* dog;

};

int rawp() {
    try {
        UseResources ur(3);
    }
    catch (int) {
        cout << "inside handler" << endl;
    }
    return 0;
}