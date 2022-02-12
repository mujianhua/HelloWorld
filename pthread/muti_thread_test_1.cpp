#include <iostream>
#include <pthread.h>

using namespace std;

#define NUMS_THREAD 20

void *say_hello(void *args)
{
    cout << "hello..." << '\n';
}

int main()
{
    pthread_t tids[NUMS_THREAD];
    for (int i = 0; i < NUMS_THREAD; i++)
    {
        //参数：创建的线程id，线程参数，线程运行函数的起始地址，运行函数的参数
        int ret = pthread_create(&tids[i], nullptr, say_hello, nullptr);
        if (ret != 0) //创建线程成功返回0
            cout << "pthread_create error:error_code=" << ret << '\n';
    }
    pthread_exit(nullptr); //等待各个线程退出后，进程才结束，否则进程强制结束，线程处于未终止的状态
}
