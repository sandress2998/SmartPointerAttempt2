#pragma once
#include <stdexcept>
#include <type_traits>

template <typename T> // maybe there should be a Deleter
class UniquePtr {
    template <typename U>
    friend class UniquePtr;
private:
    T* ptr;
public:
    UniquePtr<T>(T* ptr): ptr(ptr) {}
    ~UniquePtr<T>() {
        delete ptr;
    }

    //нужно уметь передавать копию объекта в UniquePtr. Т.е. нужно уметь создавать copy constructor.
    template <typename U>
    UniquePtr<T>(const UniquePtr<T>& other) = delete; // copy constructor isn't allowed

    template <typename U>
    UniquePtr<T>(UniquePtr<U>&& other) { // move - semantics 
        if (std::is_base_of<T, U>::value) {
            ptr = other.ptr; 
            other.ptr = nullptr;
        } else {
            throw std::invalid_argument();
        }
    }

    UniquePtr<T>(UniquePtr<T>&& other) { // move - semantics 
            ptr = other.ptr; 
            other.ptr = nullptr;
    }
    
    template <typename U>
    UniquePtr<T>& operator=(const UniquePtr<U>& other) = delete; // assign operator isn't allowed

    template <typename U>
    UniquePtr<T>& operator=(UniquePtr<U>&& other) {
        if (std::is_base_of<T, U>::value) {
            delete ptr; // it would be good if we use something else instead of naked delete
            ptr = other.ptr;
            other.ptr = nullptr;
            return *this;
        } else {
            throw std::invalid_argument("");
        }
    }

    UniquePtr<T>& operator=(UniquePtr<T>&& other) {
        delete ptr; // it would be good if we use something else instead of naked delete
        ptr = other.ptr;
        other.ptr = nullptr;
        return *this;
    }

    T* get() {
        return ptr;
    }

    UniquePtr<T> copy() {
        return UniquePtr<T>(new T(*ptr));
    }

    void reset() {
        delete ptr;
        ptr = nullptr;
    }
    
    void reset(T* newPtr) {
        delete ptr;
        ptr = newPtr;
    }

    operator bool() {
        return ptr;
    }

    T& operator*() {
        return *ptr;
    }

    T& operator->() {
        return *ptr;
    }
};

template <typename T, typename... Args>
UniquePtr<T> makeUnique(const Args&... args) {
    return UniquePtr(new T(args...)); // without std::forward isn't best realization 
} // оптимизация компилятором ...
