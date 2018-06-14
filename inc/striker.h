#ifndef STRIKER_H_INCLUDED
#define STRIKER_H_INCLUDED

#include "30010_io.h"
#include "timer.h"
#include "charset.h"
#include "trig.h"
#include "LUT.h"
#include "controller.h"
#include "ansi.h"
#include <stdlib.h>
#include "ball.h"
#include "config_project.h"
#define BORDERX 150                                             //define the size of the window
#define BORDERY 60                                              //define the size of the window


struct striker_t{
    struct vector_t posi;
    struct vector_t vel;
    int8_t state;
    int32_t a;
};

void init_striker(uint8_t BORDER_X, uint8_t BORDER_Y, uint8_t SS, struct striker_t *ks);

void print_striker(uint8_t SS, struct striker_t *ks );
void update_striker(struct striker_t *ks, uint8_t SS);
void striker_bounce(struct striker_t *ks, uint8_t SS, struct ball_t *b, struct variables *var_main);

#endif
