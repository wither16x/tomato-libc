int __cxa_atexit(void (*func)(void *), void *arg, void *dso_handle)
{
        (void)func;
        (void)arg;
        (void)dso_handle;
        return 0;
}

void *__dso_hanlde = (void *)&__dso_hanlde;