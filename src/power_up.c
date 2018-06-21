#include "power_up.h"


uint8_t create_rand(x){
    // Function to create random number between 0 and x.
    uint8_t num = rand() % (x + 1);
    return(num);
}


void activate_pu(struct variables *var_main, struct striker_t *strike, struct ball_t *b){
    // A function that activates power-ups
    uint8_t y = create_rand(2);                                     // Randomly choose which power-up to implement

    if (y==2){
        (var_main->speed_multi)++;                                  // Increase speed
    }
    else if (y==1){
        (var_main->nob)++;                                          // Add an extra ball
        if (var_main->nob>3){                                       // Check if there are too many balls
            (var_main->nob)=3;                                      // Maximum number of balls is 3

        }
        else {
            for(uint8_t k = 0; k<3; k++){
                if((b[k].ball_life) == 0){                          // find a ball not in play
                    (b[k].ball_life) = 1;                           // set ball life to 1
                    initVector(&b[k].posi, BORDERX/2, BORDERY-5);   // set start position of ball
                    initVector(&b[k].vel, 2, -2);                   // set velocity that is manipulated later
                    break;                                          // the above should only be done once pr power up
                }
            }
        }
    }
    else if (y==0){
        (strike->s_size)=(strike->s_size)+8;                        // Increases striker size
        if ((strike->s_size) >= 30){                                // Check if striker is to big
            (strike->s_size)=(strike->s_size)-8;                    // Reduce striker size if it is above 30.
        }
        print_striker(strike);                                      // Print striker with new size
    }

}


