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



//void initVector(struct vector_t *v, int32_t x, int32_t y) {
//    v->x = x << 14;
//    v->y = y << 14;
//};



struct striker_t{
    struct vector_t posi;
    struct vector_t vel;
};


void init_striker(uint8_t BORDERX, uint8_t BORDERY, uint8_t SS, struct striker_t *ks){

 initVector(&ks->posi, ( ( ( BORDERX/2 )- ( SS/2 ) )), (BORDERY-3));
 initVector(&ks->vel, 0 << 14 , 0 << 14);


}

void print_striker(uint8_t SS, struct striker_t *ks ){

  for ( uint8_t i = 0; i < SS; i++ )
  {
    gotoxy( ( ( ( ks->posi.x ) >> 14 ) + i ) , ( ( ks->posi.y ) >> 14 )  );
    printf("%c",219);

  }
}


void update_striker(struct striker_t *ks, uint8_t SS){

int32_t old_x = ks->posi.x;

    if (readJoystick()== 4){

    ks->vel.x = -10 << 14;

//        for ( uint8_t i = 0; i < SS; i++ ){
//
//        gotoxy( ( ( ( ks->posi.x ) >> 14 ) + i ) , ( ( ks->posi.y ) >> 14 ) );
//        printf("%c", 32);
//         }

    ks->posi.x = ks->posi.x + FIX14_MULT(ks->vel.x,K);
    ks->posi.y = ks->posi.y + FIX14_MULT(ks->vel.y,K);

//    for (uint16_t k = (old_x >> 14) ; k <= ((ks->posi.x) >> 14); k--){
//      gotoxy( ( ( ( old_x ) >> 14 ) + k + 7 ) , ( ( ks->posi.y ) >> 14 ) );
//      printf("d");
//    }
//
//    int32_t dif = (old_x - (ks->posi.x)) >> 14;
//
//     for (int16_t k = 0; k <= dif ; k--){
//      gotoxy( ( ( ( old_x ) >> 14 ) + k + 7 ) , ( ( ks->posi.y ) >> 14 ) );
//      printf("d");
//    }

gotoxy( ( ( ( old_x ) >> 14 ) + SS ) , ( ( ks->posi.y ) >> 14 ) );
    printf(" ");

    print_striker(SS, ks );//update position


    }
    else if (readJoystick()== 8){

        ks->vel.x = 10 << 14;

    ks->posi.x = ks->posi.x + FIX14_MULT(ks->vel.x,K);
    ks->posi.y = ks->posi.y + FIX14_MULT(ks->vel.y,K);

    gotoxy( ( ( ( old_x ) >> 14 ) ) , ( ( ks->posi.y ) >> 14 ) );
    printf(" ");

    print_striker(SS, ks );//update position


    }
    else if(readJoystick()== 0){

        ks->vel.x = 0 << 14;

    }
}
int8_t cc = 0;

int main(void)
{
    init_usb_uart( 115200 );
      printf("%c[?25l",ESC);
    uint8_t ss = 6;
    uint8_t BORDERX = 150;
    uint8_t BORDERY = 80;
    init_joystick();

    clrscr();
    gotoxy(2,2);

    printf("~(=^%c%c^)", 250, 250);

init_joystick();
//init_striker(BORDERX, BORDERY, ss, *(striker_x), (striker_y));

 struct striker_t strike;

init_striker(BORDERX, BORDERY, ss, &strike);

  while(1)  {
update_striker(&strike, ss);
gotoxy(20,20);
printf("%c", cc);
    }
}
