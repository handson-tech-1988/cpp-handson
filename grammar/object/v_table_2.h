//
//

#ifndef CPP_HANDS_V_TABLE_2_H
#define CPP_HANDS_V_TABLE_2_H


#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

#include <string>

class Base {
public:
//    virtual ~Base() = default;

    template <typename T>
    union FunPtr {
        T fun_ptr;
        long offset;
    };

    virtual void call() {
        FunPtr<void (Base::*)()> u = {};
        u.fun_ptr = &Base::call;
        dump(__PRETTY_FUNCTION__, u.offset);
    }

    void dumpConcreteFun() {
        FunPtr<void(Base::*)()> u = {};
        u.fun_ptr = &Base::dumpConcreteFun;
        printf("dumpConcreteFun.addr of %s 0x%zx\n", __PRETTY_FUNCTION__, u.offset);
    }

protected:
    void dump(const char *fun_name, long offset) {
        void *vptr = *(void **)this;
        size_t index = offset / sizeof(void *);
        void *fun_real_addr = ((void **)vptr)[index];
        printf("%s, virtual function table index %zu, real addr %p, offset = %ld  \n", fun_name,
               index, fun_real_addr, (long)offset);

//        Dl_info info = {};
//        if (!dladdr(fun_real_addr, &info)) {
//            printf("dladdr failed\n");
//            return;
//        }
//        printf(
//                "dladdr symbol name %s, exact addr %p, base addr %p, pc offset "
//                "from real addr 0x%lx\n",
//                info.dli_sname, info.dli_saddr, info.dli_fbase,
//                (long)((char *)fun_real_addr - (char *)info.dli_fbase));
    }
};

class Base2 {
public:
//    virtual ~Base2() = default;

    virtual void call2() {}
};

class Child : public Base, public Base2 {
public:
    // ~Child() override { printf("%s\n", __PRETTY_FUNCTION__); }

    void call() override {
        printf("this addr in %s is %p\n", __PRETTY_FUNCTION__, this);
        FunPtr<void (Child::*)()> u = {};
        u.fun_ptr = &Child::call;
        dump(__PRETTY_FUNCTION__, u.offset);
        call2();
    }

    void call2() override {
        FunPtr<void (Child::*)()> u = {};
        u.fun_ptr = &Child::call2;
        dump(__PRETTY_FUNCTION__, u.offset);
    }
};

int main0(int argc, char *argv[]) {
    auto p = new Base();
    p->dumpConcreteFun();
    p->call();
    delete p;

    p = new Child();
    p->call();
    delete p;

    return 0;
}


#endif //CPP_HANDS_V_TABLE_2_H
