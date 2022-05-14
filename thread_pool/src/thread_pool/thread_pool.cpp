#include <unistd.h>
#include "thread_pool.h"

using namespace std;
using namespace thread_pool::workitem;

BEGIN_THREAD_POOL_NS(thread_pool)

ThreadPool::ThreadPool(const size_t threadNum, const size_t queueSize)
    : mThreadNum(threadNum), mQueueSize(queueSize) {
}

ThreadPool::~ThreadPool() {

}

void ThreadPool::Start() {
    mPushSignal = true;
    CreateThread();
}

void ThreadPool::Stop() {
    mPushSignal = false;
    while(mWorkItemQueue.size() > 0) {
        sleep(5);
    }

    for(size_t i = 0; i < mThreadNum; i++) {
        mThreadQueue[i].detach();
    }
}

void ThreadPool::CreateThread() {
    for(size_t i = 0; i < mThreadNum; i++) {
        mThreadQueue.push_back(
            thread(&ThreadPool::WorkerLoop, this, ref(i))
        );
    }
}

void ThreadPool::WorkerLoop(const size_t i) {
    while(1) {
        WorkItemPtr pItem = PopWorkItem();
        if(pItem != nullptr) {
            cout << "Get One WorkItem" << endl;
            pItem->DoProcess();
        } else {
            cout << "WorkItem Is NULL" << endl;
        }
    }
}

bool ThreadPool::PushWorkItem(WorkItemPtr pItem) {
    if(!mPushSignal) return false;
    unique_lock lock(mMutex);
    while(mWorkItemQueue.size() >= mQueueSize) {
        mQueueFull.wait(lock);
    }
    mWorkItemQueue.push(pItem);
    mQueueEmpty.notify_one();
    return true;
}

WorkItemPtr ThreadPool::PopWorkItem() {
    unique_lock lock(mMutex);
    while(mWorkItemQueue.size() == 0) {
        mQueueEmpty.wait(lock);
    }

    WorkItemPtr pItem = mWorkItemQueue.front();
    mWorkItemQueue.pop();
    mQueueFull.notify_one();
    return pItem;
}

END_THREAD_POOL_NS(thread_pool)