#define PGSIZE 4096
#include "kernel/types.h"
#include "user/user.h"

struct lock_t {
    uint locked;
};

void lock_init(struct lock_t *lock) {
    lock->locked = 0;
}
void lock_acquire(struct lock_t *lock) {
    while (__sync_lock_test_and_set(&lock->locked, 1) != 0); // spin
    __sync_synchronize();
}

void lock_release(struct lock_t *lock) {
    __sync_synchronize();
    __sync_lock_release(&lock->locked);
}

int thread_create(void (*start_routine)(void *), void *arg) {
    
    void *stack = (void*)malloc(PGSIZE * sizeof(void));
    if (stack == 0 ) return -1;
    printf("I was here in Thread Create stack return!\n");
    int tid = clone(stack);
    if (tid < 0) return -1;
    printf("I was here in Thread Create tid return!\n");
    if (tid == 0) {
        start_routine(arg);
        exit(0);
    }

    return 0;
}
// int thread_create(void *(*thread_fn)(void*), void *arg) {
// 	int threadid;
// 	void* stack = (void*)malloc(4096 * sizeof(void));
// 	threadid  = clone(stack);
// 	if(threadid != 0) {
// 	}
//     else{
//     (*thread_fn) (arg);
// 	exit(0);
//     }
// 	return 0;
// }
