/**
 *  线程池工具, ctrip_thread_pool.h
 *  zhangyl 2018.03.23
 */

#ifndef __CTRIP_THREAD_POOL_H__
#define __CTRIP_THREAD_POOL_H__

#include <pthread.h>

#ifndef NULL
#define NULL 0
#endif

#define PUBLIC 

PUBLIC struct ctrip_task
{
    struct ctrip_task*   pNext;
    int                  value;
};

struct ctrip_thread_info
{
    //线程退出标志
    int                    thread_running;
    int                    thread_num;
    int                    tasknum;
    struct ctrip_task*     tasks;
    pthread_t*             threadid;
    pthread_mutex_t        mutex;
    pthread_cond_t         cond;
};

/* 初始化线程池线程数目
 * @param thread_num 线程数目, 默认为8个
 */
PUBLIC void  ctrip_init_thread_pool(int thread_num);

/* 销毁线程池
 */
PUBLIC void  ctrip_destroy_thread_pool();

/**向任务池中增加一个任务
 * @param t 需要增加的任务
 */
PUBLIC void ctrip_thread_pool_add_task(struct ctrip_task* t);

/**从任务池中取出一个任务
 * @return 返回得到的任务
 */
struct ctrip_task* ctrip_thread_pool_retrieve_task();

/**执行任务池中的任务
 * @param t 需要执行的任务
 */
PUBLIC void ctrip_thread_pool_do_task(struct ctrip_task* t);

/**线程函数
 * @param thread_param 线程参数
 */
void* ctrip_thread_routine(void* thread_param);

#endif //!__CTRIP_THREAD_POOL_H__