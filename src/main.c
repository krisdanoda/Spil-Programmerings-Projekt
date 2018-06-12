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
#include "ini_blocks.h"

#define BORDERX 150
#define BORDERY 80




int main(void)
{
    init_usb_uart( 115200 );
    clrscr();
    gotoxy(1,1);
    printf("%c[?25l",ESC);
    counter(1,1,BORDERX,BORDERY);

//    for(uint16_t i =1; i<11 ; i++){
//            block(1+i*BORDERX/12, 5, ( i+1)*BORDERX/12,10);
//
//    }

    struct ball_t b;


    struct blockpos block[27];
    for (int i = 0 ; i < 9 ; i++){
        block[i].x1 = 8 + i * 15;
        block[i].y1 = 5;
        block[i].x2 = 21 + i * 15;
        block[i].y2 = 8;

        block[i+9].x1 = 8 + i * 15;
        block[i+9].y1 = 10;
        block[i+9].x2 = 21 + i * 15;
        block[i+9].y2 = 13;

        block[i+18].x1 = 8 + i * 15;
        block[i+18].y1 = 15;
        block[i+18].x2 = 21 + i * 15;
        block[i+18].y2 = 18;

        print_Block(block[i]);
        print_Block(block[i+9]);
        print_Block(block[i+18]);
    }



    initVector(&b.posi, 3,3);
    initVector(&b.vel, 1,1);
  while(1)
  {
        if((b.posi.x <= (2 << 14)) || (b.posi.x >= ((BORDERX) << 14 )))
    {
    b.vel.x = -b.vel.x;
    gotoxy(b.posi.x >> 14,b.posi.y >> 14);
    printf("%c",179);
    }
    else if ((b.posi.y >= ((BORDERY)<< 14)) || (b.posi.y <= (2<<14)))
        {
        b.vel.y = -b.vel.y;
        gotoxy(b.posi.x >> 14,b.posi.y >> 14);
        printf("%c",196);
        }



    updatepos(&b);

    gotoxy(b.posi.x >> 14,b.posi.y >> 14);
    printf("%c",254);

    for(uint8_t j = 0; j<27; j++){
        if((b.posi.x >= (block[j].x1 << 14)) && (b.posi.x <= ((block[j].x2) << 14 )) &&
           (b.posi.y >= ((block[j].y1)<< 14)) && (b.posi.y <= ((block[j].y2)<<14)))
           {
                   if(b.posi.x >= (block[j].x1 << 14) && (b.posi.x <= ((block[j].x2) << 14 ))){
                        b.vel.y = -b.vel.y;
                        gotoxy(b.posi.x >> 14,b.posi.y >> 14);
                   }
                        else if((b.posi.y >= ((block[j].y1)<< 14)) && (b.posi.y <= ((block[j].y2)<<14))){
                            b.vel.x = -b.vel.x;
                            gotoxy(b.posi.x >> 14,b.posi.y >> 14);
                    }
//        }
//           else if((b.posi.y >= ((block[j].y1)<< 14)) && (b.posi.y <= ((block[j].y2)<<14))){
//            b.vel.y = -b.vel.y;
//            gotoxy(b.posi.x >> 14,b.posi.y >> 14);
        }
        }

    gotoxy(b.posi.x >> 14,b.posi.y >> 14);
    printf(" ");

  }
}
