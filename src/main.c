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

#define BORDERX 150
#define BORDERY 80


int main(void)
{
    init_usb_uart( 115200 );
    clrscr();
    gotoxy(1,1);
    printf("%c[?25l",ESC);
    counter(1,1,BORDERX,BORDERY);

    struct ball_t b;
    initVector(&b.posi, 25,10);
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
if ((b.posi.x <= (BORDERX/2+6 << 14)) && (b.posi.x >= ((BORDERX/2-6) << 14 ))
    && (b.posi.y <= (BORDERY/2+2 << 14)) && (b.posi.y >= ((BORDERY/2-2) << 14 ))) {}
 //  counter(borderX/2-5,borderY/2-1,borderX/2+5,borderY/2+1);

    else {


    gotoxy(b.posi.x >> 14,b.posi.y >> 14);
    printf("o");

    gotoxy(b.posi.x >> 14,b.posi.y >> 14);
    printf(" ");
    }
  }
}
