#include "TestContainers.h"
#include "TestMutableSequence.h"
#include "TestImmutableSequence.h"
#include "MutableArraySequence.h"
#include "MutableListSequence.h"
#include "ImmutableArraySequence.h"
#include "ImmutableListSequence.h"

void TestContainers::startTest() {
    testMutableArraySequence();
    testMutableListSequence();
    testImmutableArraySequence();
    testImmutableListSequence();
}

void TestContainers::testMutableArraySequence() {
    TestMutableSequence<MutableArraySequence> testMutableArraySequence;
    testMutableArraySequence.testClass();
}

void TestContainers::testMutableListSequence() {
    TestMutableSequence<MutableListSequence> testMutableListSequence;
    testMutableListSequence.testClass();
}

void TestContainers::testImmutableArraySequence() {
    TestImmutableSequence<ImmutableArraySequence> testImmutableArraySequence;
    testImmutableArraySequence.testClass();
}

void TestContainers::testImmutableListSequence() {
    TestImmutableSequence<ImmutableListSequence> testImmutableListSequence;
    testImmutableListSequence.testClass();
}
