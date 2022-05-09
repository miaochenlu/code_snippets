#include <iostream>
#include "register_factory.h"

using namespace std;
using namespace register_factory::common;

BEGIN_REGISTER_FACTORY_NS(factory);

Factory& Factory::GetInstance() {
    static Factory factory;
    return factory;
}

bool Factory::Register(string className, ObjectConstructor constructor) {
    if(mClassContainer.find(className) != mClassContainer.end()) {
        cout << className << " has already been registered" << endl;
        return false;
    }
    mClassContainer[className] = constructor;
    return true;
}

Base* Factory::GetObject(std::string className) {
    if(mClassContainer.find(className) == mClassContainer.end()) {
        cout << className << " doesn't exist" << endl;
        return NULL;
    }
    return mClassContainer[className]();
}

END_REGISTER_FACTORY_NS(factory);