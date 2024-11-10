//
//

#ifndef CPP_HANDS_TEST_H
#define CPP_HANDS_TEST_H

#include <iostream>

class A;
class B;
class Functors {
public:
    void call(A* a);
    void call(B* a);
};

class A {
public:
    virtual void call() {
        std::cout << "call A" << std::endl;
    }
    virtual void module(Functors* func) {
        // 静态绑定，非运行时绑定
        func->call(this);
    }
};

class B : public A {
public:
    virtual void call() {
        std::cout << "call B" << std::endl;
    }
};

void Functors::call(A* a) {
    std::cout << "func a" << std::endl;
    a->call();
}

void Functors::call(B* a) {
    std::cout << "func b" << std::endl;
    a->call();
}

struct Box { // 16/8
    double a; // 8
    char b; // 1 + 7
};
class TEST{     // 24 / 8
    Box b;      // 16 / 8
    char c;     // 1 + 7
};

//int main(int argc, char* argv[]) {
//    Functors* func = new Functors;
//    A* a = new A;
//    B* b = new B;
//    a->module(func);
//    b->module(func);
//
//    std::cout << "..." << std::endl;
//    std::cout << sizeof(Box) << std::endl;
//    std::cout << sizeof(TEST) << std::endl;
//
//}

void Fx() {
    std::cout << "test0" << std::endl;
}

using FnPtr = void(*)();
using Fn = void();

int main(int argc, char* argv[]) {
    FnPtr fn_ptr = &Fx; // Fx 都可以
    fn_ptr();

    Fn* fn = Fx;
    fn();
}


#endif //CPP_HANDS_TEST_H
