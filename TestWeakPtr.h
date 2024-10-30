#pragma once

struct TestWeakPtr {
    int elem = 100;
    
    void testClass();

    void testConstructors();
    void testConstructorCopy();
    void testConstructorWithSharedPtr();

    void testAssignOperator();
    void testAssignOperatorDefault();
    void testAssignOperatorWithInheritance();

    void testLock();
    
    void testCirclePtrs();

    void testExpired();
};