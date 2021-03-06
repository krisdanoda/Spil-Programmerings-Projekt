#include "ball.h"

void init_ng_ball(struct ball_t *b, struct striker_t *ks, struct variables *var_main){
// This function lets you decide when and where you place the ball. The ball is placed above the striker and is activated by pressing up on the keyboard,

uint8_t joy_val=0;


while (joy_val!= 1){ //until up is pressed
        if( get_flag()==1){
        gotoxy( (b->posi.x) >>14, (b->posi.y) >> 14); //balls position
        printf(" ");                                  //remove the printed ball

        update_striker(ks,var_main);                 //lets you move the striker
        joy_val = readJoystick(var_main);             //read the joystick value

        b->posi.x = ks -> posi.x;                     //places the ball at the striker's position, x axis
        b->posi.y = (ks -> posi.y) - (1 << 14);         //places the ball above the striker's position

        gotoxy( (b->posi.x) >>14 , (b->posi.y) >>14) ;  //prints the ball
        printf("%c", 254);
set_flag(0); //set time flag back to zero
}
}

   b->vel.y = ( -3 << 14 ); //Gives the ball with a initial velocity 3 upwards in Y-direction.
   b->vel.x = ( 0 << 14 );

}

void initVector(struct vector_t *v, int32_t x, int32_t y) {
    v->x = x << 14;
    v->y = y << 14;
}

void updatepos(struct ball_t *b, uint16_t speed_multi){

    b->posi.x = b->posi.x + FIX14_MULT(b->vel.x,(1000+speed_multi*400));
    b->posi.y = b->posi.y + FIX14_MULT(b->vel.y,(1000+speed_multi*400));
}
