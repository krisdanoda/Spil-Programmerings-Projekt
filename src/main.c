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
#define BORDERX 150
#define BORDERY 80

#include "menu.h"
#include "block_control.h"


#define BORDERX 150
#define BORDERY 60





int main(void)
{
    //init_usb_uart( 115200 );
    init_usb_uart( 200000 );
      printf("%c[?25l",ESC);

    //uint8_t BORDERX = 150;
    //uint8_t BORDERY = 80;
    init_joystick();

    clrscr();
    gotoxy(1,1);
    printf("%c[?25l",ESC);
    counter(1,1,BORDERX,BORDERY);
    init_joystick();
    init_RGB();
    init_spi_lcd();
    init_menu();
    init_disp_score();

    // Variables in main
    uint8_t ss = 9;
    uint8_t in_game = 0;
    uint8_t menu_counter = 1;       // used in menu
    uint8_t old_read = 0;           // used in menu
    uint8_t life_count = 3;         // to show with RGB
    uint32_t score_counter = 0;     // to print on LCD
    uint16_t speed_multi = 0;       // Used to adjust speed

    // Init balls
    struct ball_t b;

    // Init blocks
	struct blockpos block[27];


  while(1){

    // Display life_count on RGB
    set_RGB(life_count);
    // Display score_counter on LCD
    write_score(score_counter);

    // Navigate menu with joystick
    uint8_t read = readJoystick();
    control_menu(read, &menu_counter, &old_read, &in_game);

    if ((in_game) == 1){
            uint8_t text_line_1=BORDERY/5;
            clear_line(text_line_1);   // Delete old text
            clear_line(text_line_1+2);
            clear_line(text_line_1+4);

        	for (int i = 0 ; i < 9 ; i++) { // Initialize and print blocks
                block[i].x1 = 8 + i * 15;
                block[i].y1 = 5;
                block[i].x2 = 21 + i * 15;
                block[i].y2 = 10;
                block[i].hit = 3;

                block[i + 9].x1 = 8 + i * 15;
                block[i + 9].y1 = 12;
                block[i + 9].x2 = 21 + i * 15;
                block[i + 9].y2 = 18;
                block[i + 9].hit = 2;

                block[i + 18].x1 = 8 + i * 15;
                block[i + 18].y1 = 20;
                block[i + 18].x2 = 21 + i * 15;
                block[i + 18].y2 = 25;
                block[i + 18].hit = 1;

                print_Block(block[i]);
                print_Block(block[i + 9]);
                print_Block(block[i + 18]);


	}
        in_game++;

        initVector(&b.posi, 20, 45);
        initVector(&b.vel, 1, 1);
    }

	if (in_game == 2){

init_joystick();
//init_striker(BORDERX, BORDERY, ss, *(striker_x), (striker_y));

 struct striker_t strike;
struct ball_t b;

init_striker(BORDERX, BORDERY, ss, &strike);
 initVector(&b.posi, BORDERX/2,20);
 initVector(&b.vel, 0,1);



  while(1)  {
update_striker(&strike, ss);


    striker_bounce(&strike, ss, &b);


        // Check for bounches and hits
        border_control(&b);
		score_counter = block_control(&b, &block, score_counter);

		updatepos(&b, speed_multi);

        // Print new ball
		gotoxy(b.posi.x >> 14, b.posi.y >> 14);
		printf("%c", 254);


        // Overwrite old ball
        gotoxy(b.posi.x >> 14, b.posi.y >> 14);
		printf(" ");
	}
    }


}

    }


