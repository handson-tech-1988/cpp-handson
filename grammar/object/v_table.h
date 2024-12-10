#include <iostream>
#include <vector>

namespace v1 {
class Base {
    char s;
public:
//    virtual ~Base() {
//        std::cout << "Base destructor, " << s << std::endl;
//    };
public:
    virtual void fun1() {
        std::cout << "Base fun1" << std::endl;
    }

    virtual void fun2() {
        std::cout << "Base fun2" << std::endl;
    }
    void fun0() {
        std::cout << "Base fun0" << std::endl;
    }
};

template <typename T>
union FunPtr {
    T fun_ptr;
    ptrdiff_t offset;
};

using FUNC = void (*)();
using FUNC0 = void (*)(Base*);

}

int main0() {
    v1::Base * b = new v1::Base();
// 将b的地址转换成long long型，因为在64位编译器上面，指针占用8个字节
// b是指向虚函数表的指针的地址
    long long *tmp = (long long *) b;

    v1::FunPtr<void(v1::Base::*)()> fun1_addr = {};
    fun1_addr.fun_ptr = &v1::Base::fun1;
    std::cout << "fun_ptr1=" << fun1_addr.offset << std::endl;
    fun1_addr.fun_ptr = &v1::Base::fun0;
    std::cout << "fun_ptr0=" << fun1_addr.offset << std::endl;
    fun1_addr.fun_ptr = &v1::Base::fun2;
    std::cout << "fun_ptr2=" << fun1_addr.offset << std::endl;
//    v1::FunPtr<void(v1::Base::*)()> dest_addr = {};
//    fun1_addr.fun_ptr = &v1::Base::~Base;
//    std::cout << "fun_ptr1=" << fun1_addr.offset << std::endl;

// 对tmp解引用，得到虚函数表的地址
    long long *vptr = (long long *) (*tmp);
    std::cout << "虚函数表的地址为：" << vptr << std::endl;

// 虚函数表中第一个方法，继承于父类的虚函数fun1
    v1::FUNC fun1 = (v1::FUNC) *(vptr + 2);
// 虚函数表中第二个方法
    v1::FUNC fun2 = (v1::FUNC) *(vptr + 3);
    v1::FUNC0 destructor = (v1::FUNC0) *(vptr + 0);
    v1::FUNC0 destructor_delete = (v1::FUNC0) *(vptr + 1);

    fun1();  //
    fun2();
    destructor_delete(b); // 虚表2=虚析构函数 + free?
    destructor(b); // 虚表1=虚析构函数

    // delete b; // causing double free

    return 0;
}