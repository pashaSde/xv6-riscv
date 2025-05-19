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
    int tickets = sched_tickets(100);
    printf("sched_tickets: %d\n", tickets);
    ret = sched_statistics();
    printf("sched_statistics: %d\n", ret);
    exit(0);
}