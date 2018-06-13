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

struct striker_t{
    struct vector_t posi;
    struct vector_t vel;
    int8_t state;
    int32_t a;
};

void init_striker(uint8_t BORDERX, uint8_t BORDERY, uint8_t SS, struct striker_t *ks);

void print_striker(uint8_t SS, struct striker_t *ks );

void striker_bounce(struct striker_t *ks, uint8_t SS, struct ball_t *b);

#endif