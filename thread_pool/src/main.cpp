#include "thread_pool/thread_pool.h"
#include "workitem/workitem.h"
#include <unistd.h>

using namespace std;
using namespace thread_pool::thread_pool;
using namespace thread_pool::workitem;

int main() {
    ThreadPoolPtr pThreadPool(new ThreadPool(10, 10));
    std::vector<WorkItemPtr> workItemList;
    pThreadPool->Start();
    for(int i = 0; i < 20; i++) {
        WorkItemPtr pItem(new WorkItem);
        workItemList.push_back(pItem);
        pThreadPool->PushWorkItem(pItem);
    }
    pThreadPool->Stop();
}