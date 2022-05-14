#ifndef THREAD_POOL_THREAD_POOL_H
#define THREAD_POOL_THREAD_POOL_H

#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <memory>
#include <condition_variable>
#include "../common/common.h"
#include "../workitem/workitem.h"

BEGIN_THREAD_POOL_NS(thread_pool)

class ThreadPool {
public:
    ThreadPool(const size_t threadNum, const size_t queueSize);
    
    ~ThreadPool();

public:
    void Start();

    void Stop();

    void CreateThread();

    void WorkerLoop(const size_t i);

    bool PushWorkItem(workitem::WorkItemPtr pItem);

    workitem::WorkItemPtr PopWorkItem();


private:
    bool mPushSignal;
    size_t mThreadNum;
    size_t mQueueSize;
    std::mutex mMutex;
    std::condition_variable mQueueEmpty;
    std::condition_variable mQueueFull;
    std::vector<std::thread> mThreadQueue;
    std::queue<workitem::WorkItemPtr> mWorkItemQueue;

};

typedef std::shared_ptr<ThreadPool> ThreadPoolPtr;
END_THREAD_POOL_NS(thread_pool)

#endif