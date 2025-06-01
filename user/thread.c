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
}

void lock_release(struct lock_t *lock) {
    __sync_lock_release(&lock->locked);
}

int thread_create(void (*start_routine)(void *), void *arg) {
    void *stack = sbrk(PGSIZE);
    if (stack == (void *)-1 || stack == 0) return -1;
    int tid = clone(stack);
    if (tid < 0) return -1;
    if (tid == 0) {
        start_routine(arg);
        exit(0);
    }
    return 0;
}
