#include "__utils/decls.h"
#include "stdio.h"
#include "string.h"
#include "unistd.h"

BEGIN_DECLS

/* ------------------------------------------------------------------------------------------------- */
int puts(const char *s)
{
        const char *newline = "\n";

        write(stdout->fd, (const void *)s, strlen(s));
        write(stdout->fd, (const void *)newline, strlen(newline));

        return 0;
}
/* ------------------------------------------------------------------------------------------------- */

END_DECLS