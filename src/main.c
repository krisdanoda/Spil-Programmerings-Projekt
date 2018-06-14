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
#include "ansi.h"
#include "LUT.h"
#include "trig.h"
#include "controller.h"
#include "timer.h"
#include <string.h>
#include "charset.h"
#include "lcd.h"
#include "striker.h"
#include "menu.h"
#include "block_control.h"


#define BORDERX 150                                             //define the size of the window
#define BORDERY 60                                              //define the size of the window





int main(void)
{

    init_usb_uart( 115200 );                                    //set speed of microprocessor

    clrscr();                                                   // clear screen
    gotoxy(1, 1);                                               // go to the first pixel in command prompt
    printf("%c[?25l", ESC);                                     // remove visible cursor
    counter(1, 1, BORDERX, BORDERY);                            // create the window with border size
    init_joystick();                                            // initialize joystick
    init_RGB();                                                 // initialize RGB
    init_spi_lcd();                                             // initialize LCD display
    init_menu();                                                // initialize start menu
    init_disp_score();                                          // initialize display score

    // Variables in main
    uint8_t ss = 9;                                             // size of striker
    uint8_t in_game = 0;                                        // if 0 menu , 1 initialize game , 2 in game.

    uint8_t menu_counter = 1;                                   // used in menu
    uint8_t old_read = 0;                                       // used in menu
    uint8_t life_count = 3;                                     // to show with RGB
    uint32_t score_counter = 0;                                 // to print on LCD
    uint8_t level_counter = 1;                                  // keep track of level
    uint16_t speed_multi = 12;                                  // Used to adjust speed


    // Init balls
    struct ball_t b;                                            // initialize struct of the ball
    struct striker_t strike;                                    // initialize struct of the striker

    // Init blocks
    struct blockpos block[27];                                  // initialize boxes in game

    while (1)
    {

        set_RGB(life_count);                                    // Display life_count on RGB
        write_score(score_counter);                             // Display score_counter on LCD
        write_level(level_counter);                             // Display score_counter on LCD


        uint8_t read = readJoystick();                          // Navigate menu with joystick
        control_menu(read, &menu_counter, &old_read, &in_game);

        if ((in_game) == 1) {
            uint8_t text_line_1 = BORDERY / 5;
            clear_line(text_line_1);                            // Delete old text
            clear_line(text_line_1 + 2);
            clear_line(text_line_1 + 4);

            in_game++;

            init_blocks(block, 1);                              // create blocks and input level
            init_striker(BORDERX, BORDERY, ss, &strike);
            initVector(&b.posi, 20, 45);
            initVector(&b.vel, 2, 1);
        }


        if (in_game == 2) {


            update_striker(&strike, ss);
            striker_bounce(&strike, ss, &b);

            gotoxy(b.posi.x >> 14, b.posi.y >> 14);
            printf(" ");

            border_control(&b);
            score_counter = block_control(&b, block, score_counter);
            // Check for bounches and hits

            updatepos(&b, speed_multi);

            // Print new ball
            gotoxy(b.posi.x >> 14, b.posi.y >> 14);
            printf("%c", 254);

        }
    }

}




