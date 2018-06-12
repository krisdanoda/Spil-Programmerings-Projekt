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
    uint8_t text_line_1=BORDERY/5;
    uint8_t text_col_1=BORDERX/2-10;
    clear_line(text_line_1);
    clear_line(text_line_1+2);
    clear_line(text_line_1+4);
    clear_line(text_line_1+6);
    clear_line(text_line_1+8);
    gotoxy(text_col_1,text_line_1);
    printf("This is a list of the highest scores. Press >left< to go back.");
    gotoxy(text_col_1,text_line_1+2);
    printf("    #1: ");
    gotoxy(text_col_1,text_line_1+4);
    printf("    #2: ");
    gotoxy(text_col_1,text_line_1+6);
    printf("    #3: ");
    }


void init_menu(){
    uint8_t text_line_1=BORDERY/5;
    uint8_t text_col_1=BORDERX/2-10;
    clear_line(text_line_1);
    clear_line(text_line_1+2);
    clear_line(text_line_1+4);
    clear_line(text_line_1+6);
    clear_line(text_line_1+8);
    gotoxy(text_col_1,text_line_1);
    printf("New Game");
    gotoxy(text_col_1,text_line_1+2);
    printf("High scores");
    gotoxy(text_col_1,text_line_1+4);
    printf("Help");
}

void init_help(){
    uint8_t text_cursor_1=BORDERX/2-15;
    uint8_t text_line_1=BORDERY/5;
    uint8_t text_col_1=BORDERX/2-10;
    gotoxy(text_cursor_1,text_line_1);
    printf("  ");
    gotoxy(text_cursor_1,text_line_1+2);
    printf("  ");
    gotoxy(text_cursor_1,text_line_1+4);  // remove cursor
    printf("  ");

    gotoxy(text_col_1,text_line_1);
    printf("This is the help section. To get back to the menu press >left<.");
    gotoxy(text_col_1,text_line_1+2);
    printf("In the game press >left< or >right< to move the striker.");
    gotoxy(text_col_1,text_line_1+4);
    printf("The diode on the micro controller shows your remaining lives.");
    gotoxy(text_col_1,text_line_1+6);
    printf("    Green = 3, yellow = 2 and red = 1.");
    gotoxy(text_col_1,text_line_1+8);
    printf("Your score can be seen on the LCD.");

}






void control_menu(uint8_t read, uint8_t *menu_counter, uint8_t *old_read, uint8_t *in_game){
    uint8_t text_cursor_1=BORDERX/2-15;
    uint8_t text_line_1=BORDERY/5;



    // Gå tilbage til menuen hvis der trykkes mod venstre
    if ((read == 4) && ((*in_game) == 0)){
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
        gotoxy(text_cursor_1,text_line_1);
        printf("%c",175);
        gotoxy(text_cursor_1,text_line_1+2);
        printf("  ");
        gotoxy(text_cursor_1,text_line_1+4);
        printf("  ");
    }
    else if (*menu_counter == 2){
        gotoxy(text_cursor_1,text_line_1);
        printf("  ");
        gotoxy(text_cursor_1,text_line_1+2);
        printf("%c",175);
        gotoxy(text_cursor_1,text_line_1+4);
        printf("  ");
    }
    else if (*menu_counter == 3){
        gotoxy(text_cursor_1,text_line_1);
        printf("  ");
        gotoxy(text_cursor_1,text_line_1+2);
        printf("  ");
        gotoxy(text_cursor_1,text_line_1+4);
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
