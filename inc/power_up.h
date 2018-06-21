#ifndef POWER_UP_H_INCLUDED
#define POWER_UP_H_INCLUDED
#include "30010_io.h"
#include "trig.h"
#include "striker.h"
#include "config_project.h"

uint8_t create_rand(x);     // Function to create random number between 0 and x


void activate_pu(struct variables *var_main, struct striker_t *strike, struct ball_t *b); // Function to activate power-ups



#endif /* POWER_UP_H_*/
