#include "TestSmartPtrs.h"

int main() {
    TestSmartPtrs test;
    test.testAllPtrs();
}

/*
int main() {
    SharedPtr<Employee> e = SharedPtr<Employee>(new Employee);
    SharedPtr<Firm> f = SharedPtr<Firm>(new Firm);
    std::cout << "f: " << f.getSharedPointersQuantity() << " " << f.getWeakPointersQuantity() << "\n";
    std::cout << "e: " << e.getSharedPointersQuantity() << " " << e.getWeakPointersQuantity() << "\n";
    std::cout << "f: " << f.getSharedPointersQuantity() << " " << f.getWeakPointersQuantity() << "\n";
    std::cout << "e: " << e.getSharedPointersQuantity() << " " << e.getWeakPointersQuantity() << "\n";
    f->employee = e;
    e->firm = f;
    std::cout << "something happend\n";
    std::cout << "f: " << f.getSharedPointersQuantity() << " " << f.getWeakPointersQuantity() << "\n";
    std::cout << "e: " << e.getSharedPointersQuantity() << " " << e.getWeakPointersQuantity() << "\n";

    int* a = new int(10);
    delete a;
   // ++(*a);
    int b = 100;
    std::cout<< b;
    std::cout << ++b;
}
*/
