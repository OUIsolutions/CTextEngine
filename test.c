#include "CTextEngine/CTextEngineMain.h"
#include <stdio.h>
#include <time.h>

static double now(void)
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + ts.tv_nsec/1e9;
}

int main(void)
{
    int step = 1000;
    for (int n = step; n < 100000; n += step) {
        struct CTextStack *s = newCTextStack("", "");
        double start = now();
        for (int i = 0; i < n; i++) {
            s->segment_format(s, "%d", i);
        }
        printf("%d %.9g\n", n, now()-start);
        s->free(s);
    }
}