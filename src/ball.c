#include "ball.h"

void init_ng_ball(struct ball_t *b, struct striker_t *ks){

uint8_t joy_val;


while (joy_val!= 1){
        gotoxy( (b->posi.x) >>14, (b->posi.y) >> 14);
        printf(" ");

        update_striker(ks);
        joy_val = readJoystick();
        b->posi.x = ks -> posi.x;
        b->posi.y = (ks -> posi.y) - (2 << 14);

        gotoxy( (b->posi.x) >>14 , (b->posi.y) >>14) ;
        printf("%c", 254);

}


   b->posi.x = ks -> posi.x;
   b->vel.y = ( -3 << 14 );
   b->vel.x = ( 0 << 14 );

//    b->posi.x = (75 << 14);
//    b->posi.y = ( 30 << 14);
//    b->vel.x = ( 0 << 14 );

//

}
