#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/spinlock.h"
#include "kernel/fcntl.h"
#include "user/thread.h"

int thread_create(void *(start_routine)(void*), void *arg)
{
    void *stack = malloc(2*4096U);

    if((uint64)stack % 4096U)
    {
        stack = stack + (4096U - (uint64)stack%4096U);
    }

    int sz = 8;
    int thread_id = clone(stack,sz,start_routine,arg);

    if(thread_id < 0)
    {
        printf("clone failed");
        return 0;
    }

    close_thread();
    return 0;

}

{
    lock->locked = 0;
}

void lock_aquire(lock_t *lock)
{
     while(__sync_lock_test_and_set(&lock->locked,1));
}

void lock_release(lock_t *lock)
{
    lock->locked = 0;
}



