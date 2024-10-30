#include "TestSmartPtrs.h"
#include "TestSharedPtr.h"
#include "TestUniquePtr.h"
#include "TestWeakPtr.h"
#include "UI.h"
#include <iostream>
#include <cstring>

// класс UI будет выбирать, какой тест запускать
class UI {
private:

    TestSmartPtrs testSmartPtrs;
    TestUniquePtr testUniquePtr;
    TestSharedPtr testSharedPtr;
    TestWeakPtr testWeakPtr;
    
public:
    
    void startUI() {
        std::cout << "Enter the name of test. All commands names are accessible:\n";
        std::cout << "testAllPtrs;\n\ntestUniquePtr;\nuniqueTestConstructors;\nuniqueTestGet;\nuniqueTestAssignMoveSemantics;\n";
        std::cout << "uniqueTestReset;\nuniqueTestResetWithNewObject;\nuniqueTestDeferenceOperator;\n\ntestSharedPtr;\nsharedTestConstructors;\n";
        std::cout << "sharedTestControlBlock;\nsharedTestGet;\nsharedTestAssignOperator;\nsharedTestDeferenceOperator;\n\n";
        std::cout << "testWeakPtr;\nweakTestConstructors;\nweakTestAssignOperator;\nweakTestLock;\nweakTestCirclePtrs;\nweakTestExpired;\n\n";
        std::cout << "finish.\n\n";

        std::string command;
        
        do {
            std::cout << "Enter the command ";
            std::cin >> command;
            if (command == "testAllPtrs") {
                testSmartPtrs.testAllPtrs();
                std::cout << "The test are successful\n";
            } else if (command == "testUniquePtr") {
                testSmartPtrs.testUniquePtr();
                std::cout << "The test are successful\n";
            } else if (command == "uniqueTestConstructors") {
                testUniquePtr.testConstructors();
                std::cout << "The test are successful\n";
            } else if (command == "uniqueTestGet") {
                testUniquePtr.testGet();
                std::cout << "The test are successful\n";
            } else if (command == "uniqueTestAssignMoveSemantics") {
                testUniquePtr.testAssignMoveSemantics();
                std::cout << "The test are successful\n";
            } else if (command == "uniqueTestReset") {
                testUniquePtr.testReset();
                std::cout << "The test are successful\n";
            } else if (command == "uniqueTestResetWithNewObject") {
                testUniquePtr.testResetWithNewObject();
                std::cout << "The test are successful\n";
            } else if (command == "uniqueTestDeferenceOperator") {
                testUniquePtr.testDeferenceOperator();
                std::cout << "The test are successful\n";
            } else if (command == "testSharedPtr") {
                testSmartPtrs.testSharedPtr();
                std::cout << "The test are successful\n";
            } else if (command == "sharedTestConstructors") {
                testSharedPtr.testConstructors();
                std::cout << "The test are successful\n";
            } else if (command == "sharedTestControlBlock") {
                testSharedPtr.testControlBlock();
                std::cout << "The test are successful\n";
            } else if (command == "sharedTestGet") {
                testSharedPtr.testGet();
                std::cout << "The test are successful\n";
            } else if (command == "sharedTestAssignOperator") {
                testSharedPtr.testAssignOperator();
                std::cout << "The test are successful\n";
            } else if (command == "sharedTestDeferenceOperator") {
                testSharedPtr.testDeferenceOperator();
                std::cout << "The test are successful\n";
            } else if (command == "testWeakPtr") {
                testSharedPtr.testDeferenceOperator();
                std::cout << "The test are successful\n";
            } else if (command == "weakTestConstructors") {
                testWeakPtr.testConstructors();
                std::cout << "The test are successful\n";
            } else if (command == "weakTestAssignOperator") {
                testWeakPtr.testAssignOperator();
                std::cout << "The test are successful\n";
            } else if (command == "weakTestLock") {
                testWeakPtr.testLock();
                std::cout << "The test are successful\n";
            } else if (command == "weakTestCirclePtrs") {
                testWeakPtr.testCirclePtrs();
                std::cout << "The test are successful\n";
            } else if (command == "weakTestExpired") {
                testWeakPtr.testExpired();
                std::cout << "The test are successful\n";
            } else if (command == "finish") {} else {
                std::cout << "unknown command.\n";
            }
        } while (command != "finish");
        
        std::cout << "The finish of program.\n";
    }
};

void startUI() {
    UI ui;
    ui.startUI();
}