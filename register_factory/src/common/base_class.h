#ifndef REGISTER_FACTORY_COMMON_BASE_CLASS_H
#define REGISTER_FACTORY_COMMON_BASE_CLASS_H

#include <memory>
#include <iostream>
#include "common.h"

BEGIN_REGISTER_FACTORY_NS(common);

class Base {
public:
    Base() {};
    
    virtual ~Base() {};

public:
    virtual void DoProcess() {
        std::cout << "base::DoProcess" << std::endl;
    }
};

typedef std::shared_ptr<Base> BasePtr;

END_REGISTER_FACTORY_NS(common);

#endif