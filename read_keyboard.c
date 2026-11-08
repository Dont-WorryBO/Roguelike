#include <linux/input.h>
#include <stdio.h>
#include "r_KB.h"
#include <fcntl.h>
#include <unistd.h>

void read_KB(int *key_btn) { // читать клавиатуру, read keyboard
    int fd = open("/dev/input/event3", O_RDONLY);
    if(fd == -1) {
        perror("open");
    }
    struct input_event ev;
    *key_btn = 0;
    while(read(fd, &ev, sizeof(ev)) == sizeof(ev)) {
        if(ev.type == EV_KEY && ev.value == 1) {
            *key_btn = ev.code;
            break;
        } 
    }
    close(fd);   
}