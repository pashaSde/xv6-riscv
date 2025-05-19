//
// Created by Pankaj Sharma on 18/05/25.
//
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    int ret = sched_statistics();
    printf("sched_statistics: %d\n", ret);
    exit(0);
}