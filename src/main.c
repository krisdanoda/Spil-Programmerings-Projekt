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
//
//#define BORDERX 150
//#define BORDERY 80

void print_striker(uint8_t SS,  uint8_t *striker_x, uint8_t striker_y){
/*
  *(striker_x) = (BORDERX/2-(SS/2));
  *(striker_y) = (BORDERY-3);
*/


  gotoxy((striker_x)*, (striker_y)*);
  for (int i = 0; i < SS; ++i)
  {
    printf("%c",219);
  }
  


}





void init_striker(uint8_t BORDERX, uint8_t BORDERY, uint8_t SS, uint8_t *striker_x, uint8_t striker_y){
*striker_x = (BORDERX/2)-(SS/2);
*striker_y = (BORDERY)-3;

  print_striker(SS, *striker_x, striker_y);

}

void move_striker(uint8_t SS, uint8_t *striker_x, uint8_t striker_y){
  uint8_t movement;

    if (readJoystick( )==3){
    movement = -3;
    }
    else if( readJoystick == 4){
      movement = 3;
  }



  *(striker_x)= *(striker_x) + movement;

}

int main(void)
{




    init_usb_uart( 115200 );
    uint8_t ss = 6;
    uint8_t BORDERX = 152;
    uint8_t BORDERY = 80;

    init_joystick();

 
    clrscr();
    gotoxy(1,1);

init_joystick;
init_striker;


  while(1)  {


move_striker(SS, *striker_x, striker_y);

//        if((b.posi.x <= (2 << 14)) || (b.posi.x >= ((BORDERX) << 14 )))
//    {
//    b.vel.x = -b.vel.x;
//    gotoxy(b.posi.x >> 14,b.posi.y >> 14);
//    printf("%c",179);
//    }
//    else if ((b.posi.y >= ((BORDERY)<< 14)) || (b.posi.y <= (2<<14)))
//        {
//        b.vel.y = -b.vel.y;
//        gotoxy(b.posi.x >> 14,b.posi.y >> 14);
//        printf("%c",196);
//        }
//
//
//    updatepos(&b);
//if ((b.posi.x <= (BORDERX/2+6 << 14)) && (b.posi.x >= ((BORDERX/2-6) << 14 ))
//    && (b.posi.y <= (BORDERY/2+2 << 14)) && (b.posi.y >= ((BORDERY/2-2) << 14 ))) {}
// //  counter(borderX/2-5,borderY/2-1,borderX/2+5,borderY/2+1);
//
//    else {
//
//
//    gotoxy(b.posi.x >> 14,b.posi.y >> 14);
//    printf("o");
//
//    gotoxy(b.posi.x >> 14,b.posi.y >> 14);
//    printf(" ");
    }
  }

