#include "TestSharedPtr.h"
#include "TestUniquePtr.h"
#include "TestWeakPtr.h"
#include "TestSmartPtrs.h"

void TestSmartPtrs::testSharedPtr() {
    TestSharedPtr testSharedPtr;
    testSharedPtr.testConstructors();
    testSharedPtr.testConstructorWithPtr();
    testSharedPtr.testConstructorCopy();
    testSharedPtr.testConstructorWithMakeShared();
    testSharedPtr.testControlBlock();
    testSharedPtr.testControlBlockNaked();
    testSharedPtr.testControlBlockWithMakedShared();
    testSharedPtr.testGet();
    testSharedPtr.testAssignOperator();
    testSharedPtr.testDeferenceOperator();
}

void TestSmartPtrs::testUniquePtr() {
    TestUniquePtr testUniquePtr;
    testUniquePtr.testConstructors();
    testUniquePtr.testConstructorWithPtr();
    testUniquePtr.testConstructorMove();
    testUniquePtr.testGet();
    testUniquePtr.testGetNaked();
    testUniquePtr.testGetWithMakeUnique();
    testUniquePtr.testAssignMoveSemantics();
    testUniquePtr.testReset();
    testUniquePtr.testResetWithNewObject();
    testUniquePtr.testDeferenceOperator();
}

void TestSmartPtrs::testWeakPtr() {
    TestWeakPtr testWeakPtr;
    testWeakPtr.testConstructors();
    testWeakPtr.testConstructorCopy();
    testWeakPtr.testConstructorWithSharedPtr();
    testWeakPtr.testAssignOperator();
    testWeakPtr.testLock();
    testWeakPtr.testCirclePtrs();
    testWeakPtr.testExpired();
}

void TestSmartPtrs::testAllPtrs() {
    testSharedPtr();
    testUniquePtr();
    testWeakPtr();
}