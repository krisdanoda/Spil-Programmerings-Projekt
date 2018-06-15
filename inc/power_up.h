#ifndef POWER_UP_H_INCLUDED
#define POWER_UP_H_INCLUDED
#include "30010_io.h"
#include "trig.h"
#include "striker.h"
#include "config_project.h"

uint8_t create_rand(x);

void activate_pu(struct variables *var_main, struct striker_t *strike);


#endif /* POWER_UP_H_*/
