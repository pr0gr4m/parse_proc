#ifndef COMMON_H
#define COMMON_H

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

#define TRUE    1
#define FALSE   0

#define RET_SUC 0
#define RET_ERR 2

#define BUF_LEN	256

/*
#define print_msg(io, msgtype, arg...) \
    flockfile(io); \
    fprintf(io, "["#msgtype"] [%s/%s:%03d] ", __FILE__, __FUNCTION__, __LINE__); \
    fprintf(io, arg); \
    fputc('\n', io); \
    funlockfile(io)

#define print_msg_no_enter(io, msgtype, arg...) \
    flockfile(io); \
    fprintf(io, "["#msgtype"] [%s/%s:%03d] ", __FILE__, __FUNCTION__, __LINE__); \
    fprintf(io, arg); \
    funlockfile(io)

#define pr_err(arg...) print_msg(stderr, ERR, arg)
#define pr_out(arg...) print_msg(stdout, REP, arg)
#define pr_out_n(arg...) print_msg_no_enter(stdout, REP, arg)
*/

#endif // COMMON_H

