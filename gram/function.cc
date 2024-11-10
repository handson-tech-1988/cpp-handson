//
//

#include <iostream>

namespace X {
struct A {
    __attribute__((noinline)) int foo(int) { return 0;}
    inline static int bar(A*, int) {
        int a = 0;
        return a + 1 + 3;
    }
};
int bar(A*, int) {
    int a = 0;
    return a + 1 + 3;
}
int (A::* const pmf)(int) = &A::foo;
int (* const pf)(A*,int) = &bar;
int call_pmf(A* a, int x) { return (a->*pmf)(x); }
int call_pf(A* a, int x) { return pf(a, x); }
int call_2pf(A* a, int x) { return A::bar(a, x); }
int call_di(A* a, int x) { return a->foo(x);}
}

struct Slot {         // basic memory block
    long rc_;          // number of users of this memory slot
    long mem_[];      // mark beginning of the object. size = 0
};

int main(int argc, char* argv[]) {
    std::cout << "void:" << sizeof(std::nullptr_t) << std::endl;
    std::cout << "void:" << sizeof(nullptr) << std::endl;
    std::cout << "void:" << sizeof(4) << std::endl;
    auto a = std::nullptr_t();
    std::cout << "void:" << sizeof(a) << std::endl;

    std::cout << "Slot size:" << sizeof(Slot) << std::endl;
    return 0;
}