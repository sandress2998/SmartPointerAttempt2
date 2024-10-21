#pragma once
#include <stddef.h>

template <typename T>
class SharedPtr {
     // будем удалять controlBlock только тогда, когда не осталось ни weakCount, ни sharedCount
    struct ControlBlock {
        ControlBlock(size_t sharedCount, size_t weakCount): sharedCount(sharedCount), weakCount(weakCount) {}
        size_t sharedCount;
        size_t weakCount;
    };
    template <typename U>
    friend class WeakPtr;

    template <typename U, typename... Args>
    friend SharedPtr<U> makeShared(const Args&... args);

private:

    T* ptr;
    ControlBlock* controlBlock;

    SharedPtr(ControlBlock* controlBlock, T* ptr): ptr(ptr), controlBlock(controlBlock) {
        ++(controlBlock->sharedCount);
    }
public:

    SharedPtr(): ptr(nullptr), controlBlock(new ControlBlock(0, 0)) {}

    SharedPtr(T* ptr): ptr(ptr), controlBlock(new ControlBlock(1, 0)) {}
    SharedPtr(const SharedPtr<T>& other): ptr(other.ptr), controlBlock(other.controlBlock) {
        ++(controlBlock->sharedCount);
    }
    ~SharedPtr() {
        --(controlBlock->sharedCount);
        if (controlBlock->sharedCount <= 0 && controlBlock->weakCount <= 0) {
            if (ptr) {
                delete ptr;
                ptr = nullptr;
            }
            delete controlBlock;
            controlBlock = nullptr; // наверное, это лишнее
        }
    }

    
    SharedPtr<T>& operator=(const SharedPtr<T>& other) {
        if (&other == this) return *this;
        if (ptr != nullptr) {
            if (--(controlBlock->sharedCount) <= 0) {
                delete ptr;
                ptr = nullptr;
            }
        }
        ptr = other.ptr;
        controlBlock = other.controlBlock;
        ++(controlBlock->sharedCount);
        return *this;
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }

    T* get() {
        return ptr;
    }

    size_t getSharedPointersQuantity() const {
        return controlBlock->sharedCount; 
    }

    size_t getWeakPointersQuantity() const { 
        return controlBlock->weakCount; 
    }
};

template <typename T, typename... Args>
SharedPtr<T> makeShared(const Args&... args) {
    typename SharedPtr<T>::ControlBlock* controlBlock = new typename SharedPtr<T>::ControlBlock(0, 0); 
    return SharedPtr<T>(controlBlock, new T(args...));
}

