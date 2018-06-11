#include "menu.h"
#include "stm32f30x_conf.h"
#include "30010_io.h"

#define BORDERX 150
#define BORDERY 80



void clear_line(uint8_t y){
    gotoxy(3,y);
    printf("                                                                                                                                 ");
    // her indsættes en masse mellemrum så linje "y" overskrives
}


void init_high_score(){
    clear_line(BORDERY/5);
    clear_line(BORDERY/5+2);
    clear_line(BORDERY/5+4);
    clear_line(BORDERY/5+6);
    clear_line(BORDERY/5+8);
    gotoxy(BORDERX/2-10,BORDERY/5);
    printf("This is a list of the highest scores. Press >left< to go back.");
    gotoxy(BORDERX/2-10,BORDERY/5+2);
    printf("    #1: ");
    gotoxy(BORDERX/2-10,BORDERY/5+4);
    printf("    #2: ");
    gotoxy(BORDERX/2-10,BORDERY/5+6);
    printf("    #3: ");
    }


void init_menu(){
    clear_line(BORDERY/5);
    clear_line(BORDERY/5+2);
    clear_line(BORDERY/5+4);
    clear_line(BORDERY/5+6);
    clear_line(BORDERY/5+8);
    gotoxy(BORDERX/2-10,BORDERY/5);
    printf("New Game");
    gotoxy(BORDERX/2-10,BORDERY/5+2);
    printf("High scores");
    gotoxy(BORDERX/2-10,BORDERY/5+4);
    printf("Help");
}

void init_help(){
    gotoxy(BORDERX/2-15,BORDERY/5+4);  // remove cursor
    printf("  ");
    gotoxy(BORDERX/2-15,BORDERY/5);
    printf("  ");
    gotoxy(BORDERX/2-15,BORDERY/5+2);
    printf("  ");
    gotoxy(BORDERX/2-10,BORDERY/5);
    printf("This is the help section. To get back to the menu press >left<.");
    gotoxy(BORDERX/2-10,BORDERY/5+2);
    printf("In the game press >left< or >right< to move the striker.");
    gotoxy(BORDERX/2-10,BORDERY/5+4);
    printf("The diode on the micro controller shows your remaining lives.");
    gotoxy(BORDERX/2-10,BORDERY/5+6);
    printf("    Green = 3, yellow = 2 and red = 1.");
    gotoxy(BORDERX/2-10,BORDERY/5+8);
    printf("Your score can be seen on the LCD.");

}






void control_menu(uint8_t read, uint8_t *menu_counter, uint8_t *old_read, uint8_t *in_game){

    // Gå tilbage til menuen hvis der trykkes mod venstre
    if ((read == 4) && ((*in_game) == 0)){
        clear_line(BORDERY/5);
        init_menu();
        (*menu_counter) = 1;
    }


    // Her ændres menu_counter så der holdes styr på cursoren
    if ((read != *old_read) && (read ==1) && ((*in_game) == 0)){
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



    // Her tilgås nyt spil
    if ((*menu_counter == 1) && (read == 16) && ((*in_game) == 0)){
        (*in_game) = 1;
        // Noget der starter spillet her
        gotoxy(3,3);
        printf("spil under udvikling");
        (*menu_counter) = 100;
        }
    else if ((*menu_counter == 1) && (read == 8) && ((*in_game) == 0)){
        (*in_game) = 1;
        // Noget der starter spillet her
        gotoxy(3,3);
        printf("spil under udvikling");
        (*menu_counter) = 100;      // menu_counter sættes højt så der ikke printes cursor
        }



    // Her tilgås high score
    if ((*menu_counter == 2) && (read == 16) && ((*in_game) == 0)){
        init_high_score();
        (*menu_counter) = 100;
        }
    else if ((*menu_counter == 2) && (read == 8) && ((*in_game) == 0)){
        init_high_score();
        (*menu_counter) = 100;      // menu_counter sættes højt så der ikke printes cursor
        }


    // Her tilgås hjælp
    if ((*menu_counter == 3) && (read == 16) && ((*in_game) == 0)){
        init_help();
        (*menu_counter) = 100;
        }
    else if ((*menu_counter == 3) && (read == 8) && ((*in_game) == 0)){
        init_help();
        (*menu_counter) = 100;      // menu_counter sættes højt så der ikke printes cursor
        }




    (*old_read) = read;
}
