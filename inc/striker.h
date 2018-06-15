#ifndef STRIKER_H_INCLUDED
#define STRIKER_H_INCLUDED

#include "30010_io.h"
#include "our_timer.h"
#include "charset.h"
#include "trig.h"
#include "LUT.h"
#include "controller.h"
#include "ansi.h"
#include <stdlib.h>
#include "ball.h"
#include "config_project.h"
#include "menu.h"


struct striker_t{
    struct vector_t posi;
    struct vector_t vel;
    int8_t state;
    int32_t a;
    uint8_t s_size; // striker size
};

void init_striker(uint8_t BORDER_X, uint8_t BORDER_Y, struct striker_t *ks);

void print_striker(struct striker_t *ks );
void update_striker(struct striker_t *ks);
void striker_bounce(struct striker_t *ks, struct ball_t *b, struct variables *var_main);

#endif
