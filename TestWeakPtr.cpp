#include "WeakPtr.h"
#include "SharedPtr.h"
#include "TestWeakPtr.h"
#include "Person.h"
#include <cassert>

void TestWeakPtr::testClass() {
    testConstructors();
    testAssignOperator();
    testLock();
    testCirclePtrs();
    testExpired();
}

void TestWeakPtr::testConstructors() {
    testConstructorCopy();
    testConstructorWithSharedPtr();
}

void TestWeakPtr::testConstructorWithSharedPtr() {
    SharedPtr<int> sharedPtr(new int(elem));
    {
        WeakPtr<int> weakPtr(sharedPtr);
        assert(sharedPtr.getSharedPointersQuantity() == 1);
        assert(sharedPtr.getWeakPointersQuantity() == 1);
    }
    assert(sharedPtr.getSharedPointersQuantity() == 1);
    assert(sharedPtr.getWeakPointersQuantity() == 0);
}

void TestWeakPtr::testConstructorCopy() {
    SharedPtr<int> sharedPtr(new int(elem));
    {
        WeakPtr<int> weakPtr(sharedPtr);
        WeakPtr<int> otherWeakPtr(weakPtr);
        assert(sharedPtr.getSharedPointersQuantity() == 1);
        assert(sharedPtr.getWeakPointersQuantity() == 2);
    }
    assert(sharedPtr.getSharedPointersQuantity() == 1);
    assert(sharedPtr.getWeakPointersQuantity() == 0);
}

void TestWeakPtr::testAssignOperator() {
    testAssignOperatorDefault();
}

void TestWeakPtr::testAssignOperatorDefault() {
    int newElem = 2 * elem;
    SharedPtr<int> sharedPtr(new int(elem));
    WeakPtr<int> weakPtr(sharedPtr);
    SharedPtr<int> otherSharedPtr(new int(newElem));
    WeakPtr<int> otherWeakPtr(otherSharedPtr);
    otherWeakPtr = weakPtr;
    assert(sharedPtr.getSharedPointersQuantity() == 1);
    assert(sharedPtr.getWeakPointersQuantity() == 2);
    assert(otherSharedPtr.getSharedPointersQuantity() == 1);
    assert(otherSharedPtr.getWeakPointersQuantity() == 0);
}

void TestWeakPtr::testLock() {
    SharedPtr<int> sharedPtr(new int(elem));
    WeakPtr<int> weakPtr(sharedPtr);
    SharedPtr<int> lockSharedPtr = weakPtr.lock();
    assert(*lockSharedPtr == elem);
    assert(sharedPtr.getSharedPointersQuantity() == 2);
    assert(sharedPtr.getWeakPointersQuantity() == 1);
}

struct Firm;

struct Employee {
    WeakPtr<Firm> firm;
};

struct Firm {
    SharedPtr<Employee> employee;
};

void TestWeakPtr::testCirclePtrs() {
    SharedPtr<Firm> firm(new Firm);
    {
        SharedPtr<Employee> employee(new Employee);
        firm->employee = employee;
        employee->firm = firm;
        assert(firm.getSharedPointersQuantity() == 1);
        assert(firm.getWeakPointersQuantity() == 1);
        assert(employee.getSharedPointersQuantity() == 2);
        assert(employee.getWeakPointersQuantity() == 0);
    }
    assert(firm.getSharedPointersQuantity() == 1);
    assert(firm.getWeakPointersQuantity() == 1);
}

void TestWeakPtr::testExpired() {
    /* написать тест */
}