#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "Type_WE.h"

void slow_type_text(char *s, useconds_t delay_us) {
    for(size_t i = 0; s[i]; i++) {
        putchar(s[i]);
        fflush(stdout);
        usleep(delay_us);
    }
}