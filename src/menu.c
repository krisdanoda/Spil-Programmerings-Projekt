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
    for (i=0;i<((BORDERY-text_line_1-1)/2);i++){
        clear_line(text_line_1+2*i); // Delete old text
    }

    gotoxy(text_col_1,text_line_1);  // Print main menu
    printf("New Game");
    gotoxy(text_col_1,text_line_1+2);
    printf("High scores");
    gotoxy(text_col_1,text_line_1+4);
    printf("Help");
}

void init_high_score(struct variables *var_main){
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
    gotoxy(text_col_1+10,text_line_1+2);
    printf("%d points",var_main->high_score[1]);

    gotoxy(text_col_1,text_line_1+4);
    printf("    #2: ");
    gotoxy(text_col_1+10,text_line_1+4);
    printf("%d points",var_main->high_score[2]);

    gotoxy(text_col_1,text_line_1+6);
    printf("    #3: ");
    gotoxy(text_col_1+10,text_line_1+6);
    printf("%d points",var_main->high_score[3]);
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
    uint8_t read = readJoystick(var_main);
    // a function to control the menu
    // Inputs:
    // read is the stick value (1=up, 2=down, 4=left, 8=right, 16=center).
    // menu_counter keeps track of which menu option is marked.
    // old_read is to ensure the cursor moves once pr joystick interaction
    // in_game is a flag set high if the game is being played and the menu should not be controlled


    uint8_t text_cursor_1=BORDERX/2-15;
    uint8_t text_line_1=BORDERY/5;


    // G� tilbage til menuen hvis der trykkes mod venstre
    if(read == 4){
        init_menu();
        var_main->menu_counter = 1;
    }


    // Her �ndres menu_counter s� der holdes styr p� cursoren
    if ((read != var_main->old_read) && (read ==1)){
            (var_main->menu_counter)--;
        }
    else if (((read != var_main->old_read) && (read ==2))){
            (var_main->menu_counter)++;
    }



    if (var_main->menu_counter == 0){        // Counteren m� ikke v�re lavere end 1
            (var_main->menu_counter)++;
    }
    else if (var_main->menu_counter == 4) {  // Counteren m� ikke v�re h�jere end 3
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



    // Her tilg�s nyt spil
    if ((var_main->menu_counter == 1) && (read == 16)){
        (var_main->in_game) = 1;
        (var_main->menu_counter) = 100;
        init_new_game(var_main);
        }
    else if ((var_main->menu_counter == 1) && (read == 8)){
        (var_main->in_game) = 1;
        (var_main->menu_counter) = 100;      // menu_counter s�ttes h�jt s� der ikke printes cursor
        init_new_game(var_main);
        }



    // Her tilg�s high score
    if ((var_main->menu_counter == 2) && (read == 16)){
        init_high_score(var_main);
        (var_main->menu_counter) = 100;
        }
    else if ((var_main->menu_counter == 2) && (read == 8)){
        init_high_score(var_main);
        (var_main->menu_counter) = 100;      // menu_counter s�ttes h�jt s� der ikke printes cursor
        }


    // Her tilg�s hj�lp
    if ((var_main->menu_counter == 3) && (read == 16)){
        init_help();
        (var_main->menu_counter) = 100;
        }
    else if ((var_main->menu_counter == 3) && (read == 8)){
        init_help();
        (var_main->menu_counter) = 100;      // menu_counter s�ttes h�jt s� der ikke printes cursor
        }

    (var_main->old_read) = read;

}



void init_new_game(struct variables *var_main){
    var_main->level_counter     = 1;        // set start level
    var_main->life_count        = 3;        // life count updates after missed ball
    var_main->nob               = 1;        // Number of ball in the game.
    var_main->old_read          = 0;        // When in the menu, the joystick is only moves the cursor one step pr push. This variable keeps track of joystick changes.
    var_main->score_counter     = 0;        // score counter increase when a block is hit
    var_main->ex_or_in_joy      = 2;        // If 1 the game is controlled by provided joystick. If 2 game is controlled by analog joystick.
    var_main->speed_multi       = 1;        // Adjusts ball speed.

}



void game_over(struct variables *var_main, struct striker_t *ks){


   for(uint8_t i = 2; i < (BORDERY-1); i++ ){

   clear_line(i);
   }

    var_main->in_game = 0;      // Go to menu when >up< is pressed

   gotoxy(70,20);
   printf("LOL, YOU'RE A TOTAL LOSER!");
   gotoxy(70,21);
   printf( " Press >up< to continue");

uint16_t x = 20; uint16_t y = 25;
gotoxy(x,y);
printf("                                  |%c`:.",92);
gotoxy(x,y); y++;
printf("                                  | %c `:.",92);
gotoxy(x,y); y++;
printf("                                  |  %c__(:.",92);
gotoxy(x,y); y++;
printf("                                  |     %c `:.                __",92);
gotoxy(x,y); y++;
printf("         __________               |      %c__(:.            <`__')",92);
gotoxy(x,y); y++;
printf("        /          %c____          |         %c `:._         :9)9%c%c",92,92,92,92);
gotoxy(x,y); y++;
printf("       |   Right?   ,-'           |          %c__(L).        %co_/`",92,92);
gotoxy(x,y); y++;
printf("        %c__________/              |              %c%c)) _    /\ `.",92,34,92);
gotoxy(x,y); y++;
printf("                                  |                %c.`:`-.//,'  )",92);
gotoxy(x,y); y++;
printf("                                  |                 `. `--+' ,'//");
gotoxy(x,y); y++;
printf("                                  |                   `;;---'.//");
gotoxy(x,y); y++;
printf("                                  |        .     _,--;;'   `-//");
gotoxy(x,y); y++;
printf("                                  |        %c`..-'_.-' _,=._,_/",92);
gotoxy(x,y); y++;
printf("                                  |         %c_%c`'._,-','_,'`._________",92,92);
gotoxy(x,y); y++;
printf("                                  |     _,-'___%c,'___'_,'____`._______",92);
gotoxy(x,y); y++;
printf("                                  |    [______________________________");
gotoxy(x,y); y++;
printf("                                  |         |  |     |  |");
gotoxy(x,y); y++;
printf("                                  |         |  |     |  |");
gotoxy(x,y); y++;
printf("  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~|  |~~~~~|  |~~~~~~~~~~ool");
gotoxy(x,y); y++;
printf("               (  (  o_ )  )   ( ( ) )      |  |     `--'");
gotoxy(x,y); y++;
printf("  compliment         | `-._____,-'          `--'            compliment");
gotoxy(x,y); y++;
printf("                     |             compliment");
gotoxy(x,y); y++;
printf("                     |                          compliment");
gotoxy(x,y); y++;
printf("      compliment     J      compliment");
gotoxy(x,y); y++;
printf(" ");
gotoxy(x,y); y++;
printf("                                      compliment");
gotoxy(x,y); y++;
printf("                       compliment                       compliment");
gotoxy(x,y); y++;
printf("         compliment");





while(readJoystick(var_main) != 1){

}

 for(uint8_t i = 2; i < (BORDERY-1); i++ ){
var_main->menu_counter = 1;
   clear_line(i);
   }
init_menu();



}


void test_hs(struct variables *var_main){
    if ((var_main->score_counter) > (var_main->high_score[1])){         // test if score is better than first place

        (var_main->high_score[3])=(var_main->high_score[2]);            // new third place is old second place moved down
        (var_main->high_score[2])=(var_main->high_score[1]);            // new second place is old first place moved down
        (var_main->high_score[1]) = (var_main->score_counter);          // new first place is saved
    }
    else if ((var_main->score_counter) > (var_main->high_score[2])){    // test if score is better than second place

        (var_main->high_score[3])=(var_main->high_score[2]);            // old second place moves down
        (var_main->high_score[2]) = (var_main->score_counter);          // new second place is saved
    }
    else if ((var_main->score_counter) > (var_main->high_score[3])){    // test if score is better than third place
        (var_main->high_score[3]) = (var_main->score_counter);          // new third place is saved
    }

    (var_main->score_counter)=0;
}














