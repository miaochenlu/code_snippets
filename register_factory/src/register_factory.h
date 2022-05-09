#ifndef REGISTER_FACTORY_REGISTER_FACTORY_H
#define REGISTER_FACTORY_REGISTER_FACTORY_H

#include <map>
#include <string>
#include <functional>
#include "common/common.h"
#include "common/base_class.h"

BEGIN_REGISTER_FACTORY_NS(factory);

class Factory {
public:
    typedef std::function<common::Base*()> ObjectConstructor;

    typedef std::map<std::string, ObjectConstructor> ClassContainer;

public:
    ~Factory() = default;

private:
    Factory() = default;

    Factory(const Factory&) = delete;

    Factory& operator=(const Factory&) = delete;

public:
    static Factory& GetInstance();

    bool Register(std::string className, ObjectConstructor constructor);

    common::Base* GetObject(std::string className);

public:
    ClassContainer mClassContainer;

};


#define REGISTER_CLASS(kclass, className)                                   \
    class Register##kclass##className {                                     \
    public:                                                                 \
        Register##kclass##className() {                                     \
            register_factory::factory::Factory&                             \
            factory = register_factory::factory::Factory::GetInstance();    \
            factory.Register(#className, kclass::CreateObject);             \
        }                                                                   \
    };                                                                      \
    static Register##kclass##className R##kclass##className;

END_REGISTER_FACTORY_NS(factory);

#endif