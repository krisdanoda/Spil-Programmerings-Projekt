/*
**
**                           Main.c
**
**
**********************************************************************/
/*
   Last committed:     $Revision: 00 $
   Last changed by:    $Author: $
   Last changed date:  $Date:  $
   ID:                 $Id:  $

**********************************************************************/
#include "stm32f30x_conf.h"
#include "30010_io.h"
#include "config_project.h"
#include "ansi.h"
#include "LUT.h"
#include "trig.h"
#include "controller.h"
#include "our_timer.h"
#include <string.h>
#include "charset.h"
#include "lcd.h"
#include "striker.h"
#include "menu.h"
#include "block_control.h"
#include "ball.h"
#include <time.h>
#include <stdlib.h>

#define BORDERX 150                                                     //define the size of the window
#define BORDERY 60                                                      //define the size of the window


int main(void)
{
    init_usb_uart( 115200 );                                            //set speed of microprocessor

    srand(time(NULL));


    clrscr();                                                           // clear screen
    gotoxy(1, 1);                                                       // go to the first pixel in command prompt
    printf("%c[?25l", ESC);                                             // remove visible cursor
    counter(1, 1, BORDERX, BORDERY);                                    // create the window with border size
    init_joystick();                                                    // initialize joystick

    init_PS2joy();
    init_RGB();                                                         // initialize RGB
    init_spi_lcd();                                                     // initialize LCD display
    init_menu();                                                        // initialize start menu

<<<<<<< HEAD
    struct ball_t b[3];                                                 // initialize struct of the ball
    struct striker_t strike;                                            // initialize struct of the striker
    struct blockpos block[100];                                         // initialize boxes in game
    struct variables var_main;

    strike.s_size = 20;                                                 // initialize striker size

=======
    struct ball_t b[3];                                         // initialize struct of the balls
    struct striker_t strike;                                    // initialize struct of the striker
    struct blockpos block[100];                                 // initialize boxes in game
    struct variables var_main;

    strike.s_size = 9;                                          // initialize striker size
>>>>>>> Halløjsa

    init_var_main(&var_main);                                   // initialize various variables
    init_timer(0);                                              // Initilise timer and intterupt


    while (1) {


        while (var_main.in_game == 0) {

            control_menu(&var_main);                                    // Navigate menu with joystick
        }


        if ((var_main.in_game) == 1) {                                  // initialize game


            for (uint8_t i = 2; i < BORDERY - 2; i++) {                 // Clear screen before printing new level
                clear_line(i);
            }

<<<<<<< HEAD
            init_blocks(block, var_main.level_counter);                 // create blocks and input level
            init_striker(BORDERX, BORDERY, &strike);                    // create striker
            initVector(&b[0].posi, 20, 45);                             // set start position of ball
            initVector(&b[0].vel, 2, 1);                                // set velocity that is manipulated later
            b[0].ball_life = 1;

            initVector(&b[1].posi, BORDERX + 5, 5);                     // set start position of ball
            initVector(&b[1].vel, 0, 0);                                // set velocity that is manipulated later
            b[1].ball_life = 0;                                         // Ball #2 is not initially in play
=======
            init_blocks(block, var_main.level_counter);         // create blocks and input level
            init_striker(BORDERX, BORDERY, &strike);            // create striker


            (var_main.life_count)=3;                            // Set remaining lives to 3
>>>>>>> Halløjsa

            initVector(&b[2].posi, BORDERX + 5, 5);                     // set start position of ball
            initVector(&b[2].vel, 0, 0);                                // set velocity that is manipulated later
            b[2].ball_life = 0;                                         // Ball #3 is not initially in play

            var_main.nob = 1;                                           // Set power-up variable to default
            strike.s_size = 9;                                          // Set power-up variable to default
            var_main.speed_multi = var_main.level_counter + 1;          // Set speed according to level

<<<<<<< HEAD
            write_level(var_main.level_counter);                        // Print level on LCD
            set_RGB(var_main.life_count);                               // Print life on RGB

            init_ng_ball(&b[0], &strike, &var_main);                    // initialize ball and striker

            (var_main.in_game)++;                                       // set in_game to 2 (start game)
=======
            init_ng_ball(&(b[0]), &strike, &var_main);          // initialize ball and striker
            b[0].b_life = 1;

            initVector(&b[1].posi, BORDERX+5, 5);               // New ball starts at upper left corner of destroyed block.
            initVector(&b[1].vel, 0, 0);                        // Initialize speed of new ball
            b[1].b_life = 0;

            initVector(&b[2].posi, BORDERX+5, 5);               // New ball starts at upper left corner of destroyed block.
            initVector(&b[2].vel, 0, 0);                        // Initialize speed of new ball
            b[2].b_life = 0;
            (var_main.in_game)++;                               // set in_game to 2 (start game)
>>>>>>> Halløjsa



<<<<<<< HEAD
        }

        while (var_main.in_game == 2) {                                 // start game

            if (1 == get_flag()){                                           // This is a time flag, the game is triggered for every time the interrupts is run for a more smooth experience
                uint8_t sum = 0;
                for (uint8_t i = 0; i < 3; i++) {
                    sum += b[i].ball_life;                                  // Test how many balls are in play
                }
                update_striker(&strike, &var_main);                         // update striker when joystick is pressed

                for (uint8_t k = 0; k < 3; k++) {                           // run thrugh number of balls;

                    if (b[k].ball_life == 1) {


                        gotoxy(b[k].posi.x >> 14, b[k].posi.y >> 14);       // go to old ball position
                        printf(" ");                                        // delete the print of old ballS
                        border_control(&b[k]);                              // make sure the ball bounces of the window

                        block_control(&(b[k]), block, &var_main, &strike);  // Check blocks and hits and return the score

                        updatepos(&b[k], var_main.speed_multi);             // update position of ball and set the speed of the ballS
                        gotoxy(b[k].posi.x >> 14, b[k].posi.y >> 14);       // go to new ball location
                        printf("%c", 254);                                  // Print new ball
                        striker_bounce(&strike, &b[k], &var_main, sum);     // return ball in another angle
                    }
                }
                set_flag(0);
            }
=======
        while (var_main.in_game == 2) {                         // start game
            uint8_t i;                                          // Variable used for looping later
            uint8_t sum=0;

            update_striker(&strike, &var_main);                 // update striker when joystick is pressed

            if (var_main.nob == 2){
                initVector(&b[1].posi, BORDERX/2, BORDERY-5);               // New ball starts at upper left corner of destroyed block.
                initVector(&b[1].vel, 0, -3);                        // Initialize speed of new ball
                b[1].b_life = 1;
            }

            for (i=0;i<3;i++){
                sum+= b[i].b_life;
            }


            for (i=0;i<3;i++){                                  // for each ball:

                if (b[i].b_life == 1){
                striker_bounce(&strike, &b[i], &var_main, sum);             // return ball in another angle

                gotoxy(b[i].posi.x >> 14, b[i].posi.y >> 14);       // go to old ball position
                printf(" ");

                border_control(&b[i]);                                 // make sure the ball bounces of the window

                block_control(&b[i], block, &var_main, &strike);       // Check blocks and hits and return the score
                updatepos(&b[i], var_main.speed_multi);                // update position of ball and set the speed of the ballS

                gotoxy(b[i].posi.x >> 14, b[i].posi.y >> 14);       // go to new ball location
                printf("%c", 254);                                  // Print new ball
            }
            }

>>>>>>> Halløjsa
        }
    }
}




