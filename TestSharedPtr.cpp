#include "SharedPtr.h"
#include "WeakPtr.h"
#include "TestSharedPtr.h"
#include "Person.h"
#include <cassert>


void TestSharedPtr::testClass() {
    testConstructors();
    testControlBlock();
    testGet();
    testAssignOperator();
    testDeferenceOperator();

}

void TestSharedPtr::testConstructors() {
    TestSharedPtr::testConstructorWithPtr();
    TestSharedPtr::testConstructorWithMakeShared();
    TestSharedPtr::testConstructorCopy();
    TestSharedPtr::testConstructorWithInherirance();
}

void TestSharedPtr::testConstructorWithPtr() {
    SharedPtr<int> ptr = SharedPtr<int>(new int(elem));
    assert(*(ptr.get()) == elem);
    assert(ptr.getSharedPointersQuantity() == 1);
}

void TestSharedPtr::testConstructorWithMakeShared() {
    SharedPtr<int> ptr = makeShared<int>(elem);
    assert(*(ptr.get()) == elem);
    assert(ptr.getSharedPointersQuantity() == 1);
}

void TestSharedPtr::testConstructorCopy() {
    SharedPtr<int> ptr = SharedPtr<int>(new int(elem));
    SharedPtr<int> other(ptr);
    assert(*(ptr.get()) == elem);
    assert(*(other.get()) == elem);
    assert(ptr.getSharedPointersQuantity() == 2);
}

void TestSharedPtr::testConstructorWithInherirance() {
    SharedPtr<Student> student = makeShared<Student>();
    SharedPtr<Person> person(student);
    assert(student.getSharedPointersQuantity() == 2);
}

void TestSharedPtr::testControlBlock() {
    TestSharedPtr::testControlBlockWithMakedShared();
    TestSharedPtr::testControlBlockNaked();
}

void TestSharedPtr::testControlBlockWithMakedShared() {
    SharedPtr<int> sharedPtr = makeShared<int>(elem);
    SharedPtr<int> second = sharedPtr;
    SharedPtr<int> third = second; 
    WeakPtr<int> weakPtr(sharedPtr);
    assert(sharedPtr.getSharedPointersQuantity() == 3);
    assert(sharedPtr.getWeakPointersQuantity() == 1);
}

void TestSharedPtr::testControlBlockNaked() {
    SharedPtr<int> sharedPtr(new int(elem));
    SharedPtr<int> second = sharedPtr;
    SharedPtr<int> third = second;
    WeakPtr<int> weakPtr(sharedPtr);
    assert(sharedPtr.getSharedPointersQuantity() == 3);
    assert(sharedPtr.getWeakPointersQuantity() == 1);
}

void TestSharedPtr::testGet() {
    SharedPtr<int> ptr(new int(elem));
    assert(*(ptr.get()) == elem);
}

void TestSharedPtr::testAssignOperator() {
    testAssignOperatorDefault();
    testAssignOperatorWithInheritance();
}

void TestSharedPtr::testAssignOperatorDefault() {
    int newElem = elem * 2;
    SharedPtr<int> ptr(new int(elem));
    SharedPtr<int> other(new int(newElem));
    SharedPtr<int> ptrCopy = ptr;
    SharedPtr<int> otherCopy = other;
    assert(ptr.getSharedPointersQuantity() == 2);
    assert(other.getSharedPointersQuantity() == 2);
    otherCopy = ptr;
    assert(ptr.getSharedPointersQuantity() == 3);
    assert(other.getSharedPointersQuantity() == 1);
}

void TestSharedPtr::testAssignOperatorWithInheritance() {
    SharedPtr<Student> student = makeShared<Student>();
    SharedPtr<Person> person = student;
    assert(student.getSharedPointersQuantity() == 2);
}

void TestSharedPtr::testDeferenceOperator() {
    SharedPtr<int> ptr2 = makeShared<int>(elem);
    assert(*ptr2 == elem);
}
