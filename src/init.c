#include "stdio.h"

extern int stdin_fd;
extern int stdout_fd;

static FILE __stdin_file;
static FILE __stdout_file;
FILE *stdin = &__stdin_file;
FILE *stdout = &__stdout_file;

void tomato_init()
{
        __stdin_file.fd = stdin_fd;
        __stdout_file.fd = stdout_fd;
}