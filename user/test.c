//
// Created by Pankaj Sharma on 26/05/25.
//
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    char stack[4096];
    int res = clone(stack);
    printf("clone returned %d\n", res);
    printf("clone called with stack at %p\n", stack);
    exit(0);
}