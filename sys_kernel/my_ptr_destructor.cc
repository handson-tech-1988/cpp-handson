//
//

#include "test_3.h"

#include <iostream>
#include <memory>
#include <typeinfo>
#include <vector>

template<typename T> class Object {
    T* data_;
public:
    Object() { data_ = (T*) malloc(sizeof(T)); }
    void Construct() { new (data_) T(); }
    void Destory() { data_->~T(); }
    T& operator->() { return *data_; }
    ~Object() { free(data_); }
};

class A {
public:
    void hello() {
        std::cout << "hello A" << std::endl;
    }
public:
    ~A() {
        std::cout << "A" << std::endl;
    }
};

class B : public A {
public:
    void hello() {
        std::cout << "hello B" << std::endl;
    }
public:
    ~B() {
        std::cout << "B" << std::endl;
    }
};

template <class T>
struct Data {
    void (Data::*del)() = &Data::function;
    // T0::~T, 编译器~T不知为何物(类型 还是 函数?)
    // int counter;
    T data_;
    typedef T T0;
public:
    void function() {
        T* ptr = &data_;
        ptr->~T();
        std::cout << "delete T of Data: " << typeid(T).name() << std::endl;

        std::cout << "typeid(std::vector<int>).name():" << typeid(std::vector<int>).name() << std::endl;

    }
};

int main() {
    B* b = new B();
    std::shared_ptr<A> a = std::make_shared<B>();
    a->hello();

//    Data<A>* p = (Data<A>*)new Data<B>();
//    (p->*(p->del))();

}