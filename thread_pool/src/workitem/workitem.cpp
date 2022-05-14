#include <iostream>
#include "workitem.h"

using namespace std;

BEGIN_THREAD_POOL_NS(workitem);

WorkItem::WorkItem() {}

WorkItem::~WorkItem() {}

void WorkItem::DoProcess() {
    cout << "WorkItem::DoProcess()" << endl;
}

END_THREAD_POOL_NS(workitem);