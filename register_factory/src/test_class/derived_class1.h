#ifndef REGISTER_FACTORY_TEST_CLASS_DERIVED_CLASS1_H
#define REGISTER_FACTORY_TEST_CLASS_DERIVED_CLASS1_H

#include "../common/common.h"
#include "../common/base_class.h"
#include "../register_factory.h"

BEGIN_REGISTER_FACTORY_NS(test);

class Derived1: public common::Base {
public:
    Derived1() = default;

    virtual ~Derived1() = default;

public:
    virtual void DoProcess();

    static Derived1* CreateObject();    

};

REGISTER_CLASS(Derived1, derived1);

END_REGISTER_FACTORY_NS(test);
#endif