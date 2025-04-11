## To add any sys_call, lets say abc, you need to do changes in the following changes:

1. kernel/syscall.h
2. kernel/syscall.c
3. kernel/sysproc.c
4. kernel/proc.c
5. kernel/defs.h
6. user/usys.pl
7. user/user.h
8. user/test_file.c
9. Makefile