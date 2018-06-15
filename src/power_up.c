#include "power_up.h"


uint8_t create_rand(x){
    uint8_t num = rand() % (x + 1 - 0) + 0;
    return(num);
}


void activate_pu(struct variables *var_main, struct striker_t *strike){
    // A function that activates power-ups
    uint8_t y = create_rand(1);
    if (y==2){
        (var_main->speed_multi)--;
    }
    else if (y==1){
        (var_main->nob)++;
    }
    else if (y==0){
        (strike->s_size)=(strike->s_size)+9;
    }
}



//void make_pu
//
//    if (k>=1){
//        gotoxy(160,20+k);
//        printf("You got a power-up!");
//        uint8_t y =create_rand(2);
//        if (y==0){
//            (var_main->speed_multi)--;
//        }
//        else if (y==1){
//            (var_main->nob)++;
//        }
//        else if (y==2){
//            // Set striker size here
//        }
//        k++;
//    }
//
