#ifndef THREAD_POOL_WORKITEM_H
#define THREAD_POOL_WORKITEM_H

#include <iostream>
#include <memory>
#include "../common/common.h"

BEGIN_THREAD_POOL_NS(workitem);

class WorkItem {
public:
    WorkItem();

    virtual ~WorkItem();

public:
    virtual void DoProcess();
};

typedef std::shared_ptr<WorkItem> WorkItemPtr;

END_THREAD_POOL_NS(workitem);

#endif