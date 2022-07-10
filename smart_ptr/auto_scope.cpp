/**
 * @brief auto_ptr scope_ptr
 */

#include "RAII.h"

template <typename T> class auto_ptr {
  public:
    explicit auto_ptr(T *ptr = nullptr) : ptr_(ptr) {
        cout << "default constructor" << endl;
    }

    // copy constructor 被复制释放原来指针的所有权,交给复制方
    // 始终只有一个对象管理一块空间
    auto_ptr(auto_ptr &other) noexcept {
        cout << "copy constructor" << endl;
        ptr_ = other.release();
    }

    // copy and swap 始终只有一个对象有管理这块空间的权限
    auto_ptr &operator=(auto_ptr &rhs) noexcept {
        auto_ptr tmp(rhs.release());
        tmp.swap(*this);
        return *this;
    }

    ~auto_ptr() { delete ptr_; }

    T &operator*() const noexcept { return *ptr_; }

    T *operator->() const noexcept { return ptr_; }

    operator bool() const noexcept {
        return ptr_;
    } // 返回bool类型操作,可用来此指针是否为空

    T *get() const noexcept { return ptr_; }

    T *release() noexcept {
        T *ptr = ptr_;
        ptr_ = nullptr;
        return ptr;
    }

    void swap(auto_ptr &rhs) noexcept { std::swap(ptr_, rhs.ptr_); }

  private:
    T *ptr_;
};

template <typename T> void swap(auto_ptr<T> &lhs, auto_ptr<T> &rhs) {
    lhs.swap(rhs);
}

template <class T> class scope_ptr {
  public:
    scope_ptr(T *ptr = 0) : ptr_(ptr) {}

  private:
    T *ptr_;
};

int main(int argc, char **argv) {
    auto_ptr<shape> ptr1{create_shape(shape_type::circle)};

    if (ptr1) {
        cout << "It is not a empty ptr\n";
    }

    auto_ptr<shape> ptr2(ptr1);
    return 0;
}