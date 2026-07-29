#include "stdio.h"
#include "unistd.h"

#ifdef __cplusplus
extern "C" {
#endif

static FILE __stdin_file;
static FILE __stdout_file;
FILE *stdin = &__stdin_file;
FILE *stdout = &__stdout_file;

void tomato_init()
{
        int stdin_fd = open("D:/input");
        int stdout_fd = open("D:/console");

        __stdin_file.fd = stdin_fd;
        __stdout_file.fd = stdout_fd;
}

void tomato_end()
{
        exit();
}

#ifdef __cplusplus
}
#endif