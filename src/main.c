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

#define BORDERX 150                                             //define the size of the window
#define BORDERY 60                                              //define the size of the window


int main(void)
{
    init_usb_uart( 115200 );                                    //set speed of microprocessor

    srand(time(NULL));

    clrscr();                                                   // clear screen
    gotoxy(1, 1);                                               // go to the first pixel in command prompt
    printf("%c[?25l", ESC);                                     // remove visible cursor
    counter(1, 1, BORDERX, BORDERY);                            // create the window with border size
    init_joystick();                                            // initialize joystick
    init_PS2joy();
    init_RGB();                                                 // initialize RGB
    init_spi_lcd();                                             // initialize LCD display
    init_menu();                                                // initialize start menu

    struct ball_t b;                                            // initialize struct of the ball
    struct striker_t strike;                                    // initialize struct of the striker
    struct blockpos block[100];                                 // initialize boxes in game
    struct variables var_main;

    strike.s_size = 9;                                          // initialize striker size

    init_var_main(&var_main);                                   // initialize various variables

    while (1) {


        while (var_main.in_game == 0) {
            control_menu(&var_main);                            // Navigate menu with joystick
        }


        if ((var_main.in_game) == 1) {                          // initialize game

            for (uint8_t i=2; i< BORDERY-2;i++){                // Clear screen before printing new level
                clear_line(i);
            }

            uint8_t text_line_1 = BORDERY / 5;                  // go to text location from menu
            clear_line(text_line_1);                            // Delete old text
            clear_line(text_line_1 + 2);                        // Delete old text
            clear_line(text_line_1 + 4);                        // Delete old text

            init_blocks(block, var_main.level_counter);         // create blocks and input level
            init_striker(BORDERX, BORDERY, &strike);            // create striker
            initVector(&b.posi, 20, 45);                        // set start position of ball
            initVector(&b.vel, 2, 1);                           // set velocity that is manipulated later
            (var_main.life_count)=3;                            // Set remaining lives to 3

            init_ng_ball(&b, &strike, &var_main);                          // initialize ball and striker

            (var_main.in_game)++;                               // set in_game to 2 (start game)
        }

        while (var_main.in_game == 2) {                         // start game

            set_RGB(var_main.life_count);                       // Display life_count on RGB
            write_score(var_main.score_counter);                // Display score_counter on LCD
            write_level(var_main.level_counter);                // Display life_counter on LCD


            update_striker(&strike, &var_main);                            // update striker when joystick is pressed
            striker_bounce(&strike, &b, &var_main);             //FIX LIFE COUNT             // return ball in another angle


            gotoxy(b.posi.x >> 14, b.posi.y >> 14);             // go to old ball position
            printf(" ");                                        // delete the print of old ballS
            border_control(&b);                                 // make sure the ball bounces of the window

            block_control(&b, block, &var_main, &strike);                // Check blocks and hits and return the score

            updatepos(&b, var_main.speed_multi);                // update position of ball and set the speed of the ballS


            gotoxy(b.posi.x >> 14, b.posi.y >> 14);             // go to new ball location
            printf("%c", 254);                                  // Print new ball
        }
    }
}




