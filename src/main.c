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

int main(void)
{
    init_usb_uart( 115200 );
    clrscr();
    gotoxy(1,1);
    counter(1,1,150,80);
  while(1)
  {

  }
}



/*
int main(void){
    init_usb_uart( 115200 );
   clrscr();
   // showCursor(false);
   int32_t borderX = 50; // Skal være et lige tal
   int32_t borderY = 20; // Skal være et lige tal
   int32_t cunt = 0;

    window(1,1,borderX,borderY, "hello Video game player!");
    counter(borderX/2-5,borderY/2-1,borderX/2+5,borderY/2+1);
    struct ball_t b;
    initVector(&b.posi, 25,10);
    initVector(&b.vel, 1,1);
    gotoxy(borderX/2-4,borderY/2);
    printf("Hits: 0");
 //   rotate(&v,-50);
 //   printFix(expand(v.x));
 //   printf("\n");
 //   printFix(expand(v.y));

   while(1){


    if((b.posi.x <= (2 << 14)) || (b.posi.x >= ((borderX) << 14 )))
    {
    b.vel.x = -b.vel.x;
    gotoxy(b.posi.x >> 14,b.posi.y >> 14);
    printf("%c",179);
    cunt++;
    gotoxy(borderX/2+2,borderY/2);
    printf("%d",cunt);
    }
    else if ((b.posi.y >= ((borderY)<< 14)))
        {
        b.vel.y = -b.vel.y;
        gotoxy(b.posi.x >> 14,b.posi.y >> 14);
        printf("%c",196);
        cunt++;
        gotoxy(borderX/2+2,borderY/2);
        printf("%d",cunt);
        }
    else if (b.posi.y <= (3<<14))
        {
            b.vel.y = -b.vel.y;
            cunt++;
            gotoxy(borderX/2+2,borderY/2);
            printf("%d",cunt);
        }

updatepos(&b);
if ((b.posi.x <= (borderX/2+6 << 14)) && (b.posi.x >= ((borderX/2-6) << 14 ))
    && (b.posi.y <= (borderY/2+2 << 14)) && (b.posi.y >= ((borderY/2-2) << 14 ))) {}
 //  counter(borderX/2-5,borderY/2-1,borderX/2+5,borderY/2+1);

    else {


    gotoxy(b.posi.x >> 14,b.posi.y >> 14);
    printf("o");

    gotoxy(b.posi.x >> 14,b.posi.y >> 14);
    printf(" ");

}


//    gotoxy(borderX+1,borderY+1);
//    printf("x = %d : y = %d",b.posi.x >>14,b.posi.y>>14);



    }
}
*/
