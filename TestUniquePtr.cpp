#include "UniquePtr.h"
#include "TestUniquePtr.h"
#include "Person.h"
#include <cassert>
#include <utility>

void TestUniquePtr::testClass() {
    testConstructors();
    testGet();
    testAssignMoveSemantics();
    testReset();
    testResetWithNewObject();
    testDeferenceOperator();
}

void TestUniquePtr::testConstructors() {
    testConstructorWithPtr();
    testConstructorMove();
    testAssignMoveSemanticsWithInheritance();
}

void TestUniquePtr::testConstructorWithPtr() {
    UniquePtr<int> ptr(new int(elem));
    assert(*(ptr.get()) == elem);
}

void TestUniquePtr::testConstructorMove() {
    UniquePtr<int> ptr(new int(elem));
    UniquePtr<int> other(std::move(ptr));
    assert(*(other.get()) == elem);
    assert(ptr.get() == nullptr);
}

void TestUniquePtr::testGet() {
    TestUniquePtr::testGetNaked();
    TestUniquePtr::testGetNaked();
}

void TestUniquePtr::testGetNaked() {
    int* newElemPtr = new int(elem);
    UniquePtr<int> ptr = UniquePtr<int>(newElemPtr);
    assert(ptr.get() == newElemPtr);
}

void TestUniquePtr::testGetWithMakeUnique() {
    UniquePtr<int> ptr = makeUnique<int>(elem);
    assert(*(ptr.get()) == elem);
}

void TestUniquePtr::testAssignMoveSemantics() {
    testAssignMoveSemanticsDefault();
    testAssignMoveSemanticsWithInheritance();
}

void TestUniquePtr::testAssignMoveSemanticsDefault() {
    UniquePtr<int> ptr = makeUnique<int>(elem);
    UniquePtr<int> other = UniquePtr<int>(nullptr);
    other = std::move(ptr);
    assert(ptr.get() == nullptr);
    assert(*(other.get()) == elem);
}

void TestUniquePtr::testAssignMoveSemanticsWithInheritance() {
    UniquePtr<Student> ptr = makeUnique<Student>();
    UniquePtr<Person> other = makeUnique<Person>();
    other = std::move(ptr);
    assert(ptr.get() == nullptr);
}

void TestUniquePtr::testReset() {
    UniquePtr<int> ptr(new int(elem));
    ptr.reset();
    assert(ptr.get() == nullptr);
}

void TestUniquePtr::testResetWithNewObject() {
    UniquePtr<int> ptr(new int(elem));
    int* newElemPtr = new int(elem * 2);
    ptr.reset(newElemPtr);
    assert(ptr.get() == newElemPtr);
}

void TestUniquePtr::testDeferenceOperator() {
    UniquePtr<int> ptr(new int(elem));
    assert(*ptr == elem);
}