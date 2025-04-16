//
// Created by Pankaj Sharma on 15/04/25.
//
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    int n_active_proc, n_syscalls, n_free_pages;
    n_active_proc = sysinfo(0);
    n_syscalls = sysinfo(1);
    n_free_pages = sysinfo(2);
    int else_part = sysinfo(3);
    printf("[sysinfo] active proc: %d, syscalls: %d, free pages: %d, else part: %d\n",
    n_active_proc, n_syscalls, n_free_pages, else_part);

    struct pinfo pinfo;
    int ret = procinfo(&pinfo);
    if (ret == 0) {
        printf("[procinfo] ppid: %d, syscall_count: %d, page_usage: %d\n",
        pinfo.ppid + 2, pinfo.syscall_count + 2, pinfo.page_usage + 2);
    } else {
        printf("procinfo failed\n");
    }
//
//    ret = procinfo(&void);
//    if (ret == 0) {
//        printf("[procinfo] ppid: %d, syscall_count: %d, page_usage: %d\n",
//        pinfo.ppid + 2, pinfo.syscall_count + 2, pinfo.page_usage + 2);
//    } else {
//        printf("procinfo failed\n");
//    }
}

