#pragma once

struct TestUniquePtr {
    int elem = 100;

    void testClass();

    void testConstructors();
    void testConstructorWithPtr();
    void testConstructorMove();
    void testConstructorWithInheritance();

    void testGet();
    void testGetNaked();
    void testGetWithMakeUnique();

    void testAssignMoveSemantics();
    void testAssignMoveSemanticsDefault();
    void testAssignMoveSemanticsWithInheritance();

    void testReset();
    void testResetWithNewObject();

    void testDeferenceOperator();
};