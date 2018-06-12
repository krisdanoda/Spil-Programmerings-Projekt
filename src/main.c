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
#include "menu.h"

#define BORDERX 144
#define BORDERY 80


int main(void)
{
    init_usb_uart( 115200 );
    clrscr();
    gotoxy(1,1);
    printf("%c[?25l",ESC);
    counter(1,1,BORDERX,BORDERY);
    init_joystick();
    init_RGB();


    // Herfra starter menu
    uint8_t in_game = 0;
    uint8_t menu_counter = 1;
    uint8_t old_read = 0;
    uint8_t life_count = 3;
    init_menu();

  while(1){
    // Her kører menuen
    uint8_t read = readJoystick();

    set_RGB(life_count);

    control_menu(read, &menu_counter, &old_read, &in_game);




  }

    }
