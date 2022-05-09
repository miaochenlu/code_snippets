#include <iostream>
#include "derived_class1.h"

using namespace std;
using namespace register_factory::common;

BEGIN_REGISTER_FACTORY_NS(test);

void Derived1::DoProcess() {
    std::cout << "Derived1::DoProcess()" << std::endl;
}

Derived1* Derived1::CreateObject() {
    return new Derived1();
}

END_REGISTER_FACTORY_NS(test);