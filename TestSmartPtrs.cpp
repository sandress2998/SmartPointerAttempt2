#include "TestSharedPtr.h"
#include "TestUniquePtr.h"
#include "TestWeakPtr.h"
#include "TestSmartPtrs.h"

void TestSmartPtrs::testSharedPtr() {
    TestSharedPtr testSharedPtr;
    testSharedPtr.testClass();
}

void TestSmartPtrs::testUniquePtr() {
    TestUniquePtr testUniquePtr;
    testUniquePtr.testClass();
}

void TestSmartPtrs::testWeakPtr() {
    TestWeakPtr testWeakPtr;
    testWeakPtr.testClass();
}

void TestSmartPtrs::testAllPtrs() {
    testSharedPtr();
    testUniquePtr();
    testWeakPtr();
}