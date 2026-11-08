#include <linux/input.h>
#include <stdio.h>
#include "r_KB.h"
#include <fcntl.h>
#include <unistd.h>

void read_KB(char *key_btn) { // читать клавиатуру, read keyboard
    FILE *p = fopen("log_rkb.txt", "w");
    int fd = open("/dev/input/event3", O_RDONLY);
    if(fd == -1) {
        perror("open");
        fprintf(p, "драйвер не открылся\n");
    }
    struct input_event ev;
    while(read(fd, &ev, sizeof(ev)) == sizeof(ev)) {
        if(ev.type == EV_KEY && ev.value == 1) {
            *key_btn = ev.code;
        } 
        break;
    }
    return;
}