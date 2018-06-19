#include "striker.h"


void init_striker(uint8_t BORDER_X, uint8_t BORDER_Y, struct striker_t *ks)
{

    initVector(&ks->posi, ( ( ( BORDER_X / 2 ) - ( (ks->s_size) / 2 ) )), (BORDER_Y - 3)); //Places the striker somewhere close to the middle near the bottom
    initVector(&ks->vel, 0 << 14 , 0 << 14);                                                //Initialises the velocity of striker to 0. This is probably not needed.
    // int8_t *state = 0;
    ks -> k_speed = 100;

    print_striker(ks );
}


void print_striker(struct striker_t *ks )               // print striker
{
    //This function is self explanatory. It prints the a striker using the x and y coordinates of the striker

gotoxy(  ( ( ks->posi.x  - (ks->s_size/2 << 14) )>> 14  ) , ( ( ks->posi.y ) >> 14 )  );

    if (ks->state == 1){
            if (ks->s_size == 9){
                printf(" (^>_<^) ");
            }
            else if (ks->s_size == 18){
                printf(" (-(-_(-_-)_-)-) ");
            }
            else if (ks->s_size == 27){
                printf(" (^>_<^) (^>_<^) (^>_<^)  ");
            }
    }
     else{
            if (ks->s_size == 9){
                printf(" (^._.^) ");
            }
            else if (ks->s_size == 18){
                printf(" (.(._(._.)_.).) ");
            }
            else if (ks->s_size == 27){
                printf(" (^._.^) (^._.^) (^._.^)  ");
            }
     }

}



void update_striker(struct striker_t *ks, struct variables * var_main)
// This function moves the striker using a joystick.
{
    int8_t K = ks->k_speed; // a speed constant

    int16_t x_value = read_joystick_x()-2000; //read the joystick value and normalize it around 0
    uint8_t dead_zone = 50; //A deadzone value, so that the analog joystick is only triggered when the pressure exceeds this value

    if (abs(x_value)<50){ // Not to do anything when within dead zone
    //nothing

    }
    else if( x_value >= dead_zone){ // if press left, move left

     ks->vel.x = ( (x_value-dead_zone) << 14);  //gives the velocity a value dependent on the analog, making it pressure sensative

    ks->posi.x = ks->posi.x + FIX14_MULT(ks->vel.x,K/100); // velocity is multiplied by the speed constants and then added to the position

        if ( ks->posi.x > ( (150 - 2 - (ks->s_size) / 2) << 14)) //striker cannot move outside the boundaries
        {
            ks->posi.x = ((150 - 2 - (ks->s_size) / 2) << 14);

        }

    print_striker(ks );//update position
    }
 else if(  x_value <= - dead_zone ){ //if press right, move right

       ks->vel.x = ( (x_value+dead_zone) << 14);    ////gives the velocity a value dependent on the analog, making it pressure sensitive

        ks->posi.x = ks->posi.x + FIX14_MULT(ks->vel.x, K/100);     // velocity is multiplied by the speed constants and then added to the position


 if ( ks->posi.x < ( (2 + (ks->s_size) / 2) << 14))
        {
            ks->posi.x = ((2 + (ks->s_size) / 2) << 14);
        }

    print_striker(ks );//update position
    }


    //    if (ks->a > 700){
    //    ks -> state = 0;
    //    print_striker(SS, ks );
    //    }
    //    (ks ->a)= (ks ->a)+1;
}



// Script For striker bounce AND MISS
void striker_bounce(struct striker_t *ks, struct ball_t *b, struct variables * var_main, uint8_t sum)
{
    if  ( ( (ks->posi.y) >> 14 ==  (b->posi.y) >> 14 ) && ( (  b->posi.x >> 14 ) >= ( ( ( ks->posi.x) >> 14 ) - (ks->s_size) / 2 ) ) && ( ( ( b->posi.x >> 14 )  ) <= ( ( ( ks->posi.x ) >> 14 ) + (ks->s_size) / 2 ) ) ) //Check if the ball is within the bounds of the striker
    {


             int32_t i_angle; //angle of incidence on the half circle surface


        //This part of the function finds the angle, theta, for a given sin(theta). So it basically finds the inverse sin of a x, angle is then used to rotate the appropriately for the bounce
        int32_t mini = 100000 <<14 ;


        uint32_t dif = abs(b-> posi.x - ks -> posi.x) * 2 / (ks->s_size); //finds the distance x, our sin(theta)



        for (uint32_t i = 0 ; i <= 128; i++ )// this loops through all decimal values of lute file and looks through values to find the appropriate sin(theta) in lute file and looks for
        {
            int32_t it =  (uint32_t)(expand(SIN[i]) & 0xFFFF) >> 2; //finds the decimal value in the lute file

            if ( (mini) > (abs(dif - it)))     //if the
            {
                mini = abs(dif - it);
                i_angle = i; // we use then use the position of the given
            }
        }




    i_angle = i_angle / 2 ;
        if ( (b-> posi.x - ks -> posi.x) <= 0)
        {

        }
        else if ( (b-> posi.x - ks -> posi.x) >= 0)
        {
  i_angle = - i_angle;
        }

        //To bounce the angle against a surface with a incidence angle of i_angle, we rotate the coordinate system with an angle i_angle, mirror the angle in the y-axis, then rotate it back

        int32_t x1 = b->vel.x;
        b->vel.x = FIX14_MULT(b->vel.x, Cos(i_angle)) - FIX14_MULT(b->vel.y, Sin(i_angle));
        b->vel.y = FIX14_MULT(x1, Sin(i_angle)) + FIX14_MULT(b->vel.y, Cos(i_angle));
        b->vel.y =  -(b->vel.y);

        x1 = b->vel.x;

        b->vel.x = FIX14_MULT(b->vel.x, Cos(-i_angle)) - FIX14_MULT(b->vel.y, Sin(-i_angle));
        b->vel.y = FIX14_MULT(x1, Sin(-i_angle)) + FIX14_MULT(b->vel.y, Cos(-i_angle));

        b->posi.y =  b->posi.y - ( 2 << 14 );

        ks->state = 1;
        ks->a = 0;

        print_striker( ks );
    }
    else if ( ( (ks->posi.y) + (1 << 14) <=  (b->posi.y)  ) && ( ( (  b->posi.x >> 14 ) < ( ( ks->posi.x - (((ks->s_size) / 2) << 14)) >> 14 ) ) || ( ( ( b->posi.x >> 14 )  ) > ( ( ( ks->posi.x + (((ks->s_size) / 2) << 14)) >> 14 ) ) ) ) )
    {

      //   gotoxy( (b->posi.x >> 14 ) , ( b-> posi.y >>14) ); // Remove the previous ball
        //    printf(" ");
            clear_line(BORDERY-1);

        if (sum == 1){                      // sum is the number of balls in play

            (var_main->life_count)--;       // reduce remaining life
            set_RGB(var_main->life_count); // Display life_count on RGB

            if ((var_main->life_count) >= 1)
            {
                init_ng_ball(b, ks, var_main);

            }
            if ((var_main->life_count) == 0)
            {
                test_hs(var_main);          // test if the score is higher than a high score
                game_over(var_main, ks);
            }
        }
        else {
                b->ball_life=0;             // remove ball from game
                b->posi.x=BORDERX+5;        // move ball outside window
                b->posi.y=5;                // move ball outside window
                b->vel.x=0;                 // set ball velocity to 0
                b->vel.y=0;                 // set ball velocity to 0
        }
    }
}


