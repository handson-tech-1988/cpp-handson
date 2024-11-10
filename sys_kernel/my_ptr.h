//
//

#ifndef CPP_HANDS_MY_PTR_H
#define CPP_HANDS_MY_PTR_H

#include <memory>

template<typename T>
struct Repo {
    std::atomic_int cnt{0};
    T* data = nullptr;
    ~Repo() {
        if (this->data != nullptr) {
            delete this->data;
            this->data = nullptr;
        }
    }
};

/**
 * 内存回收的委托 = 最后一个持有指针的业务对象和线程.
 * @tparam T
 */
template <typename T>
class MyPtr {
private:
    Repo<T>* repo = nullptr;
public:
    MyPtr() {
        this->repo = nullptr;
    }
    MyPtr(MyPtr& other) {
        this->repo = other.repo;
        if (this->repo != nullptr) {
            this->repo->cnt++;
        }
    }
    ~MyPtr() {
        if (this->repo != nullptr) {
            if (--this->repo->cnt == 0) {
                delete this->repo;
                this->repo = nullptr;
            }
        }
    }
private:
    void swap(MyPtr& first, MyPtr& second) {
        Repo<T>* tmp = first.repo;
        first.repo = second.repo;
        second.repo = tmp;
    }
public:
    // 判定指针对象
    // 注意内存修改导致自身变化.
    MyPtr& operator = (MyPtr& other) {
        if (this == &other) {
            return *this;
        }
        if (this->repo == other.repo) {
            return *this;
        }
        MyPtr tmp;
        swap(tmp, *this); // 引用交换 <=> 数据等价
        new ( (void*) this) MyPtr(other);
        return *this;
    }
};


#endif //CPP_HANDS_MY_PTR_H
