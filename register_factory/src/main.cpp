#include "register_factory.h"
using namespace std;
using namespace register_factory::factory;
using namespace register_factory::common;
int main() {
    Factory& factory = Factory::GetInstance();
    // BasePtr base;
    // base.reset(factory.GetObject("derived1"));
    // base->DoProcess();
    Base* base;
    base = factory.GetObject("derived1");
    base->DoProcess();

}