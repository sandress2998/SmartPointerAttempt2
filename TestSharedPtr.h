#pragma once

struct TestSharedPtr {
    int elem = 100;

    void testClass();

    void testConstructors();
    void testConstructorWithPtr();
    void testConstructorCopy();
    void testConstructorWithMakeShared();

    void testControlBlock();
    void testControlBlockNaked();
    void testControlBlockWithMakedShared();

    void testGet();

    void testAssignOperator();

    void testDeferenceOperator();
};