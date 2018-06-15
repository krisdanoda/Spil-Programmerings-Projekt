#include "menu.h"





void clear_line(uint8_t y){
    // A function to replace text with spaces
    gotoxy(3,y);
    printf("                                                                                                                                            ");
}


void init_menu(){
    uint8_t text_line_1=BORDERY/5;
    uint8_t text_col_1=BORDERX/2-10;

    uint8_t i;
    for (i=0;i<6;i++){
        clear_line(text_line_1+2*i); // Delete old text
    }

    gotoxy(text_col_1,text_line_1);  // Print main menu
    printf("New Game");
    gotoxy(text_col_1,text_line_1+2);
    printf("High scores");
    gotoxy(text_col_1,text_line_1+4);
    printf("Help");
}

void init_high_score(){
    uint8_t text_line_1=BORDERY/5;
    uint8_t text_col_1=BORDERX/2-10;

    uint8_t i;
    for (i=0;i<6;i++){
        clear_line(text_line_1+2*i); // Delete old text
    }

    gotoxy(text_col_1,text_line_1);     // Print high scores
    printf("This is a list of the highest scores. Press >left< to go back.");
    gotoxy(text_col_1,text_line_1+2);
    printf("    #1: ");
    gotoxy(text_col_1,text_line_1+4);
    printf("    #2: ");
    gotoxy(text_col_1,text_line_1+6);
    printf("    #3: ");
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

    gotoxy(text_col_1,text_line_1);     // Print help page
    printf("This is the help section. To get back to the menu press >left<.");
    gotoxy(text_col_1,text_line_1+2);
    printf("In the game press >left< or >right< to move the striker.");
    gotoxy(text_col_1,text_line_1+4);
    printf("The diode on the micro controller shows your remaining lives.");
    gotoxy(text_col_1,text_line_1+6);
    printf("    Green = 3, yellow = 2 and red = 1. If you see a white light, you're dead.");
    gotoxy(text_col_1,text_line_1+8);
    printf("Your score and level can be seen on the LCD.");
    gotoxy(text_col_1,text_line_1+10);
    printf("Some of the bricks are power-ups!");

}


void control_menu(struct variables *var_main){
    // a function to control the menu
    // Inputs:
    // read is the joystick value (1=up, 2=down, 4=left, 8=right, 16=center).
    // menu_counter keeps track of which menu option is marked.
    // old_read is to ensure the cursor moves once pr joystick interaction
    // in_game is a flag set high if the game is being played and the menu should not be controlled


    uint8_t text_cursor_1=BORDERX/2-15;
    uint8_t text_line_1=BORDERY/5;
    uint8_t read = readJoystick();

    // Gå tilbage til menuen hvis der trykkes mod venstre
    if(read == 4){
        init_menu();
        var_main->menu_counter = 1;
    }


    // Her ændres menu_counter så der holdes styr på cursoren
    if ((read != var_main->old_read) && (read ==1)){
            (var_main->menu_counter)--;
        }
    else if (((read != var_main->old_read) && (read ==2))){
            (var_main->menu_counter)++;
    }



    if (var_main->menu_counter == 0){        // Counteren må ikke være lavere end 1
            (var_main->menu_counter)++;
    }
    else if (var_main->menu_counter == 4) {  // Counteren må ikke være højere end 3
            (var_main->menu_counter)--;
    }


    // Her flyttes cursoren
    if (var_main->menu_counter == 1){        // Flyt cursor til "new game"
        gotoxy(text_cursor_1,text_line_1);
        printf("%c",175);
        gotoxy(text_cursor_1,text_line_1+2);
        printf("  ");
        gotoxy(text_cursor_1,text_line_1+4);
        printf("  ");
    }
    else if (var_main->menu_counter == 2){        // Flyt cursor til "high scorres"
        gotoxy(text_cursor_1,text_line_1);
        printf("  ");
        gotoxy(text_cursor_1,text_line_1+2);
        printf("%c",175);
        gotoxy(text_cursor_1,text_line_1+4);
        printf("  ");
    }
    else if (var_main->menu_counter == 3){        // Flyt cursor til "help"
        gotoxy(text_cursor_1,text_line_1);
        printf("  ");
        gotoxy(text_cursor_1,text_line_1+2);
        printf("  ");
        gotoxy(text_cursor_1,text_line_1+4);
        printf("%c",175);
    }



    // Her tilgås nyt spil
    if ((var_main->menu_counter == 1) && (read == 16)){
        (var_main->in_game) = 1;
        (var_main->menu_counter) = 100;
        }
    else if ((var_main->menu_counter == 1) && (read == 8)){
        (var_main->in_game) = 1;
        (var_main->menu_counter) = 100;      // menu_counter sættes højt så der ikke printes cursor
        }



    // Her tilgås high score
    if ((var_main->menu_counter == 2) && (read == 16)){
        init_high_score();
        (var_main->menu_counter) = 100;
        }
    else if ((var_main->menu_counter == 2) && (read == 8)){
        init_high_score();
        (var_main->menu_counter) = 100;      // menu_counter sættes højt så der ikke printes cursor
        }


    // Her tilgås hjælp
    if ((var_main->menu_counter == 3) && (read == 16)){
        init_help();
        (var_main->menu_counter) = 100;
        }
    else if ((var_main->menu_counter == 3) && (read == 8)){
        init_help();
        (var_main->menu_counter) = 100;      // menu_counter sættes højt så der ikke printes cursor
        }

    (var_main->old_read) = read;

}


void game_over(struct variables *var, struct striker_t *ks,uint8_t SS){


   for(uint8_t i = 2; i < (BORDERY-1); i++ ){

   clear_line(i);
   }

   gotoxy(70,20);
printf("LOL, YOUR GAY!");

   var->in_game = 0;

   gotoxy(70,21);
   printf( " Press >up< to continue");

while(readJoystick() != 1){

}

 for(uint8_t i = 2; i < (BORDERY-1); i++ ){
var->menu_counter = 1;
   clear_line(i);
   }
init_menu();

}
