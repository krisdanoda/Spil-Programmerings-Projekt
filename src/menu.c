#include "menu.h"
#include "stm32f30x_conf.h"
#include "30010_io.h"

#define BORDERX 144
#define BORDERY 80


void init_menu(){
    gotoxy(BORDERX/2-10,BORDERY/5);
    printf("New Game");
    gotoxy(BORDERX/2-10,BORDERY/5+2);
    printf("High Scores");
    gotoxy(BORDERX/2-10,BORDERY/5+4);
    printf("Help");
}



void control_menu(uint8_t read, uint8_t *menu_counter, uint8_t *old_read){


    // Her ændres menu_counter så der holdes styr på cursoren
    if ((read != *old_read) && (read ==1)){
            (*menu_counter)--;
        }
    else if (((read != *old_read) && (read ==2))){
            (*menu_counter)++;
    }

    if (*menu_counter == 0){        // Counteren må ikke være lavere end 1
            (*menu_counter)++;
    }
    else if (*menu_counter == 4) {  // Counteren må ikke være højere end 3
            (*menu_counter)--;
    }


    // Her flyttes cursoren

    if (*menu_counter == 1){
        gotoxy(BORDERX/2-15,BORDERY/5);
        printf("%c",175);
        gotoxy(BORDERX/2-15,BORDERY/5+2);
        printf("  ");
        gotoxy(BORDERX/2-15,BORDERY/5+4);
        printf("  ");
    }
    else if (*menu_counter == 2){
        gotoxy(BORDERX/2-15,BORDERY/5);
        printf("  ");
        gotoxy(BORDERX/2-15,BORDERY/5+2);
        printf("%c",175);
        gotoxy(BORDERX/2-15,BORDERY/5+4);
        printf("  ");
    }
    else if (*menu_counter == 3){
        gotoxy(BORDERX/2-15,BORDERY/5);
        printf("  ");
        gotoxy(BORDERX/2-15,BORDERY/5+2);
        printf("  ");
        gotoxy(BORDERX/2-15,BORDERY/5+4);
        printf("%c",175);
    }


    (*old_read) = read;
}
