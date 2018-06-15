#include "striker.h"

void init_striker(uint8_t BORDER_X, uint8_t BORDER_Y, uint8_t SS, struct striker_t *ks){

 initVector(&ks->posi, ( ( ( BORDER_X/2 )- ( SS/2 ) )), (BORDER_Y-3));
 initVector(&ks->vel, 0 << 14 , 0 << 14);
// int8_t *state = 0;

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
int32_t K = 800;
int32_t old_x = ks->posi.x;

    if (readJoystick()== 4){

    ks->vel.x = -10 << 14;

                           //        for ( uint8_t i = 0; i < SS; i++ ){
                           //
                           //        gotoxy( ( ( ( ks->posi.x ) >> 14 ) + i ) , ( ( ks->posi.y ) >> 14 ) );
                           //        printf("%c", 32);
                           //         }

    ks->posi.x = ks->posi.x + FIX14_MULT(ks->vel.x,K);
                           // ks->posi.y = ks->posi.y + FIX14_MULT(ks->vel.y,K);




    if ( ks->posi.x < ( (2 + SS/2) << 14)){
    ks->posi.x = ((2 + SS/2) << 14);
    }

gotoxy( ( ( ( old_x ) >> 14 ) + SS/2 ) , ( ( ks->posi.y ) >> 14 ) );
    printf(" ");

    print_striker(SS, ks );//update position


    }
    else if (readJoystick()== 8){

        ks->vel.x = 10 << 14;

    ks->posi.x = ks->posi.x + FIX14_MULT(ks->vel.x,K);
                           //ks->posi.y = ks->posi.y + FIX14_MULT(ks->vel.y,K);

    if ( ks->posi.x > ( (150-1-SS/2) << 14)){
    ks->posi.x = ((150-1-SS/2) << 14);
    }

    gotoxy( ( ( ( old_x ) >> 14 ) ) , ( ( ks->posi.y ) >> 14 ) );
    printf(" ");

    print_striker(SS, ks );//update position


    }
    else if(readJoystick()== 0){

        ks->vel.x = 0 << 14;

    }

                           //    if (ks->a > 700){
                           //    ks -> state = 0;
                           //    print_striker(SS, ks );
                           //    }
                           //    (ks ->a)= (ks ->a)+1;
}

// Script For striker bounce AND MISS
void striker_bounce(struct striker_t *ks, uint8_t SS, struct ball_t *b, struct variables *var_main){
if  ( ( (ks->posi.y) >> 14 ==  (b->posi.y) >> 14 ) && ( (  b->posi.x >> 14 ) >= ( ( ( ks->posi.x) >> 14 ) - SS/2 ) ) && ( ( ( b->posi.x >> 14 )  ) <= ( ( ( ks->posi.x ) >> 14 ) + SS/2 ) ) ) {

//b->vel.y = -(b->vel.y);
//
//int8_t divis = 5;
//int32_t divs = (ss << 14)/divis;
//
//int32_t x = ( b->posi.x - ks->posi.x);
//int32_t v_k = power( ( ( power( (b->vel.y) >> 14, 2) << 14 ) + power( (b->vel.y) >> 14, 2) ) );



int32_t mini = 10000;
int32_t g_angle;
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


//


if ( (b-> posi.x - ks -> posi.x) <= 0){


}
else if( (b-> posi.x - ks -> posi.x) >= 0){

g_angle = - g_angle;
}
g_angle = g_angle / 2 ;


int32_t x1 = b->vel.x;
 b->vel.x = FIX14_MULT(b->vel.x,Cos(g_angle))-FIX14_MULT(b->vel.y,Sin(g_angle));
b->vel.y = FIX14_MULT(x1,Sin(g_angle))+FIX14_MULT(b->vel.y,Cos(g_angle));
 b->vel.y =  -(b->vel.y);

x1 = b->vel.x;

    b->vel.x = FIX14_MULT(b->vel.x,Cos(-g_angle))-FIX14_MULT(b->vel.y,Sin(-g_angle));
    b->vel.y = FIX14_MULT(x1,Sin(-g_angle))+FIX14_MULT(b->vel.y,Cos(-g_angle));

     b->posi.y =  b->posi.y - ( 2 << 14 );

    ks->state = 1;
    ks->a =0;

    print_striker(SS, ks );

}
else if( ( (ks->posi.y) + (1<< 14) <=  (b->posi.y)  ) && ( ( (  b->posi.x >> 14 ) < ( ( ks->posi.x - ((SS/2) << 14)) >> 14 ) ) || ( ( ( b->posi.x >> 14 )  ) > ( ( ( ks->posi.x + ((SS/2) << 14)) >> 14 ) ) ) ) )
    {


        // hp goes down;
    (var_main->life_count)--;


        //checks if hp is larger than 0
    if (var_main->life_count > 0){
    // New game
    init_ng_ball(b, ks , SS);
    }
    else if ( (var_main -> life_count) <= 0 ){
// Game over
    game_over(var_main,ks,SS);



    }



//    b->posi.x = (90 << 14);
//    b->posi.y = ( 30 << 14);
//    b->vel.x = ( 0 << 14 );
//    b->vel.y = ( 3 << 14 );



    }
}
