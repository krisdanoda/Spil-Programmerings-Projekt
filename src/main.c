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
//#include "menu.h"

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



    // Herfra starter menu
    gotoxy(BORDERX/2-10,BORDERY/5);
    printf("New Game");
    gotoxy(BORDERX/2-10,BORDERY/5+2);
    printf("High Scores");
    gotoxy(BORDERX/2-10,BORDERY/5+4);
    printf("Help");
    uint8_t menu_counter = 1;
    uint8_t move_cursor = 0;
    uint8_t old_read = 0;
    //init_menu(&menu_counter, &move_counter, &old_read);

  while(1){

    uint8_t read = readJoystick();


    // Her ændres menu_counter så der holdes styr på cursoren
    if (read != old_read){
        if (read == 1){
            (menu_counter)--;
        }
        else if (read == 2){
            (menu_counter)++;
        }
    }

    if (menu_counter == 0){
            (menu_counter)++;
    }
    else if (menu_counter == 4) {
            (menu_counter)--;
    }


    // Her flyttes cursoren
    if (menu_counter == 1){
        gotoxy(BORDERX/2-15,BORDERY/5);
        printf("%c",175);
        gotoxy(BORDERX/2-15,BORDERY/5+2);
        printf("  ");
        gotoxy(BORDERX/2-15,BORDERY/5+4);
        printf("  ");
    }
    else if (menu_counter == 2){
        gotoxy(BORDERX/2-15,BORDERY/5);
        printf("  ");
        gotoxy(BORDERX/2-15,BORDERY/5+2);
        printf("%c",175);
        gotoxy(BORDERX/2-15,BORDERY/5+4);
        printf("  ");
    }
    else if (menu_counter == 3){
        gotoxy(BORDERX/2-15,BORDERY/5);
        printf("  ");
        gotoxy(BORDERX/2-15,BORDERY/5+2);
        printf("  ");
        gotoxy(BORDERX/2-15,BORDERY/5+4);
        printf("%c",175);
    }


    old_read = read;



  }

    }
