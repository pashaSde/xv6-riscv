//
// Created by Pankaj Sharma on 26/05/25.
//
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void thread_func(void *arg) {
    printf("hello from thread!\n");
    exit(0); // only exit the thread!
}

int main() {
    void *stack = malloc(4096);
    int pid = clone(stack);
    if (pid == 0) {
        thread_func(0); // child runs function
    } else {
        // parent waits for thread to finish
        wait(0);
        printf("thread exited\n");
    }
    exit(0);
}