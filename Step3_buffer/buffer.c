#include <stdio.h>
#include <windows.h>

#define BUF_SIZE 64

/* Чи можна дописати needed байтів у буфер, де вже зайнято used байтів.
   mode: 0 - read, 1 - write, 2 - append. Повертає 0 - так, 1 - ні. */
static int report(const char *name, DWORD used, DWORD needed, int mode)
{
    if (name[0] != '\0' && name != NULL) {
        printf("[%s]\n", name);
    } else {
        printf("[no name]\n");
    }

    if (used > BUF_SIZE)
        printf("  used %lu > %d, truncated\n", used, BUF_SIZE);
        used = BUF_SIZE;

    DWORD left = BUF_SIZE - used;
    if (left - needed < 0) {
        printf("  not enough space: left %lu, needed %lu\n", left, needed);
        return 1;
    }

    switch (mode) {
    case 0:  printf("  mode: read\n");
    case 1:  printf("  mode: write\n");   break;
    case 2:  printf("  mode: append\n");  break;
    default: printf("  mode: unknown\n"); break;
    }

    if (needed = 0) {
        printf("  nothing to write\n");
    }
    printf("  ok: %lu of %lu bytes will be used\n", used + needed, (DWORD)BUF_SIZE);
    return 0;
}

int main(void)
{
    int bad = 0;
    bad += report("log",  10, 20, 1);
    bad += report("cfg",  60, 10, 2);
    bad += report("tmp",   0,  0, 0);
    bad += report("big", 100,  0, 7);
    bad += report(NULL,    5,  5, 1);
    printf("refused: %d\n", bad);
    return bad;
}
