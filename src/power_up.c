#include "power_up.h"


uint8_t create_rand(x){
    // Function to create random number between 0 and x.
    uint8_t num = rand() % (x + 1);
    return(num);
}


void activate_pu(struct variables *var_main, struct striker_t *strike){
    // A function that activates power-ups
    uint8_t y = create_rand(2);                     // Randomly choose which power-up to implement

    if (y==2){
        (var_main->speed_multi)--;                  // Reduces speed
        if ((var_main->speed_multi) == 0){          // Control if speed is too low
            (var_main->speed_multi)=1;              // Set speed multiplier to 1 if speed is to low
        }
    }
    else if (y==1){
        (var_main->nob)++;                          // Add an extra ball
        if (var_main->nob>3){                       // Check if there are too many balls
        (var_main->nob)=3;                          // Maximum number of balls is 3
        }
    }
    else if (y==0){
        (strike->s_size)=(strike->s_size)+9;        // Increases striker size
        if ((strike->s_size) >= 30){                // Check if striker is to big
            (strike->s_size)=(strike->s_size)-9;    // Reduce striker size if it is above 30.
        }
        print_striker(strike);                      // Print striker with new size
    }

}


