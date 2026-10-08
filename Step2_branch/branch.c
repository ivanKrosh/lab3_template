#include <stdio.h>
#include <stdlib.h>

static int check_level(int level, int limit)
{
    if (level >= limit) {
        return 1;
    } else {
        return 0;
    }
}

int main(int argc, char *argv[])
{
    int level = argc > 1 ? atoi(argv[1]) : 50;
    int limit = 80;
    int r = check_level(level, limit);
    printf("level %d, limit %d -> %s\n", level, limit, r ? "ABOVE" : "below");
    return r;
}
