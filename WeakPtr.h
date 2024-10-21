#pragma once
#include "SharedPtr.h"
#include <iostream>

template <typename T>
class WeakPtr {
private:
    T* ptr;
    typename SharedPtr<T>::ControlBlock* controlBlock;
public:
    WeakPtr(): ptr(nullptr), controlBlock(new typename SharedPtr<T>::ControlBlock(0, 0)) {}
    WeakPtr(const SharedPtr<T>& other): ptr(other.ptr), controlBlock(other.controlBlock) {
        ++(controlBlock->weakCount);
    }
    WeakPtr(const WeakPtr<T>& other): ptr(other.ptr), controlBlock(other.controlBlock) {
        ++(controlBlock->weakCount);
    }

    ~WeakPtr() {
        --(controlBlock->weakCount);
        if (controlBlock->weakCount <= 0 && controlBlock->sharedCount <= 0) {
            // значит, что ptr == nullptr уже
            delete controlBlock;
        }
    }

    WeakPtr<T>& operator=(const SharedPtr<T>& other) {
        --(controlBlock->weakCount);
        if (controlBlock->weakCount <= 0 && controlBlock->sharedCount <= 0) {
            delete controlBlock;
        }
        ptr = other.ptr;
        controlBlock = other.controlBlock;
        ++(controlBlock->weakCount);
        return *this;
    }

    WeakPtr<T>& operator=(const WeakPtr<T>& other) {
        --(controlBlock->weakCount);

        if (controlBlock->weakCount <= 0 && controlBlock->sharedCount <= 0) {
            delete controlBlock;
        }
        ptr = other.ptr;
        controlBlock = other.controlBlock;
        ++(controlBlock->weakCount);
        return *this;
    }

    bool expired() const { // checks if an object is nullptr
        if (ptr == nullptr) return true;
        return false; 
    }

    SharedPtr<T> lock() const {
        if (ptr) return SharedPtr(controlBlock, ptr);
        return nullptr;
    }

    T* operator->() {
        return ptr;
    }

    T& operator*() {
        return *ptr;
    }

};