#include <stdio.h>
#include <linux/input.h>
#include "esc_codes.h"
#include "Mmenu.h"
#include "r_KB.h"

void main_menu() {

    FILE *f = fopen("log.txt", "w");
    if(f == NULL) {
        perror("fopen");
    }


    const char *buttons[5] = {"Start", "Quit"}; // Кнопки, которые будут выводиться в главном меню
    int count = 0;
    for(int i = 0; buttons[i] != NULL; i++) {
        count++;
    }
    
    int end_cicle = 0; // переменная для обозначения конца и продолжения цикла
    int position = 0; // позиция на кнопках меню
    fprintf(f, "position: %d\n", position);

    while(end_cicle == 0) {
        
        printf(reset); // обновление экрана

        // printf("%d", count);   // логовая инфомация
        
        printf("=== MAIN MENU ===\n");
        for(int i = 0; i < count; i++) { 
            
            if(i != position) { // если  числа итерации не равно позиции
                printf("%d. %s\n", i+1, buttons[i]);
            } else { // если число итерации равно позиции 
                printf("%d. %s <<\n", i+1, buttons[i]);
            }
        }
        char KC = '\0'; // KeyCode
        fprintf(f, "До нажатия: %s\n", KC);
        read_KB(&KC);
        fprintf(f, "После нажатия: %s\n", KC);

        if(KC == KEY_UP && position != 0) {
            position--;
        } else if(KC == KEY_DOWN && position != count) {
            position++;
        } else {
            continue;
        }
        fprintf(f, "position: %d\n", position);
        fclose(f);
    }
}