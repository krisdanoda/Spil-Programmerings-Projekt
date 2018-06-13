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
    int8_t state;
    int32_t a;
};


void init_striker(uint8_t BORDERX, uint8_t BORDERY, uint8_t SS, struct striker_t *ks){

 initVector(&ks->posi, ( ( ( BORDERX/2 )- ( SS/2 ) )), (BORDERY-3));
 initVector(&ks->vel, 0 << 14 , 0 << 14);
 int8_t *state =0;

 print_striker(SS, ks );

}

void print_striker(uint8_t SS, struct striker_t *ks ){

//  for ( uint8_t i = 0; i < SS; i++ )
//  {
//    gotoxy( ( ( ( ks->posi.x ) >> 14 ) + i - SS/2 ) , ( ( ks->posi.y ) >> 14 )  );
//    printf("%c",219);
//
//  }
if (ks->state == 1){
  gotoxy(  ( ( ks->posi.x  - (SS/2 << 14) )>> 14  ) , ( ( ks->posi.y ) >> 14 )  );
printf(" (^>_<^) ");
}
 else{
         gotoxy(  ( ( ks->posi.x  - (SS/2 << 14) )>> 14  ) , ( ( ks->posi.y ) >> 14 )  );
printf(" (^._.^) ");
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

gotoxy( ( ( ( old_x ) >> 14 ) + SS/2 ) , ( ( ks->posi.y ) >> 14 ) );
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

    if (ks->a > 700){
    ks -> state = 0;
    print_striker(SS, ks );
    }
    (ks ->a)= (ks ->a)+1;
}

striker_bounce(struct striker_t *ks, uint8_t SS, struct ball_t *b){
if  ( ( (ks->posi.y) >> 14 ==  (b->posi.y) >> 14 ) && ( (  b->posi.x >> 14 ) >= ( ( ks->posi.x - ((SS/2) << 14)) >> 14 ) ) && ( ( ( b->posi.x >> 14 )  ) <= ( ( ( ks->posi.x + ((SS/2) << 14)) >> 14 ) ) ) ) {
int32_t mini = 10000;
int32_t g_angle;
 //  b->vel.y = -(b->vel.y);

uint32_t dif = abs(b-> posi.x - ks -> posi.x)*2 / SS;


for (uint32_t i = 0 ; i <= 128; i++ )
    {
int32_t it = 10000 * (uint32_t)(expand(SIN[i]) & 0xFFFF) >> 16;

        if (mini > ((abs(dif - it)*10000))<<14){
        mini = ((abs(dif - it)*10000)<<14);
        g_angle = i;
        }
    }


//rotate(&b.vel, g_angle);
//b -> vel.y = - (b -> vel.y);
//rotate(*b.vel, -g_angle);
gotoxy(20,20);


if ( (b-> posi.x - ks -> posi.x) <= 0){


}
else if( (b-> posi.x - ks -> posi.x) >= 0){

g_angle = - g_angle;
}

printf("%d \n", g_angle);
printf("%d \i",( b-> posi.x - ks -> posi.x) >> 14);



int32_t x1 = b->vel.x;
 b->vel.x = FIX14_MULT(b->vel.x,Cos(g_angle))-FIX14_MULT(b->vel.y,Sin(g_angle));
    b->vel.y = FIX14_MULT(x1,Sin(g_angle))+FIX14_MULT(b->vel.y,Cos(g_angle));
 b->vel.y =  -(b->vel.y);

x1 = b->vel.x;
    b->vel.x = FIX14_MULT(b->vel.x,Cos(-g_angle))-FIX14_MULT(b->vel.y,Sin(-g_angle));
    b->vel.y = FIX14_MULT(x1,Sin(-g_angle))+FIX14_MULT(b->vel.y,Cos(-g_angle));

     b->posi.y =  b->posi.y - (2 << 14);

    ks->state =1;
    ks->a =0;

    print_striker(SS, ks );
}
}

//( (ks->posi.y) >> 14 ==  (b->posi.y) >> 14 )


int main(void)
{
    init_usb_uart( 115200 );
      printf("%c[?25l",ESC);
    uint8_t ss = 7;
    uint8_t BORDERX = 150;
    uint8_t BORDERY = 80;
    init_joystick();

    clrscr();
    gotoxy(2,2);



init_joystick();
//init_striker(BORDERX, BORDERY, ss, *(striker_x), (striker_y));

 struct striker_t strike;
struct ball_t b;

init_striker(BORDERX, BORDERY, ss, &strike);
 initVector(&b.posi, BORDERX/2,20);
 initVector(&b.vel, 0,1);



  while(1)  {
update_striker(&strike, ss);

updatepos(&b);
striker_bounce(&strike, ss, &b);
   gotoxy(b.posi.x >> 14,b.posi.y >> 14);
    printf("%c", 220 );

    gotoxy(b.posi.x >> 14,b.posi.y >> 14);
    printf(" ");
    }

}
