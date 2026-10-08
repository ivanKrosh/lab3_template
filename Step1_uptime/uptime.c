#include <stdio.h>
#include <windows.h>

int main(void)
{
    ULONGLONG ms    = GetTickCount64();     /* мілісекунд від запуску Windows */
    ULONGLONG total = ms / 1000;
    ULONGLONG d = total / 86400;
    ULONGLONG h = total % 86400 / 3600;
    ULONGLONG m = total % 3600 / 60;
    ULONGLONG s = total % 60;
    printf("Uptime: %llu ms\n", ms);
    printf("= %llu d %02llu:%02llu:%02llu\n", d, h, m, s);
    return 0;
}
