// ctrip_thread_pool.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include "ctrip_thread_pool.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    ctrip_init_thread_pool(5);
    struct ctrip_task* task = NULL;
    int i;
    for (i = 0; i < 100; ++i)
    {
        task = (struct ctrip_task*)malloc(sizeof(struct ctrip_task));
        task->value = i + 1;
        task->pNext = NULL;
        printf("add task, task value [%d]\n", task->value);
        ctrip_thread_pool_add_task(task);
    }

    sleep(10);

    ctrip_destroy_thread_pool();
    
    return 0;
}