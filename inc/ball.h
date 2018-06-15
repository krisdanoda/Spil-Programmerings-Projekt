#ifndef _BALL_H
#define _BALL_H

#include "striker.h"
#include "30010_io.h"
#include "our_timer.h"
#include "charset.h"
#include "trig.h"
#include "LUT.h"
#include "controller.h"
#include "ansi.h"
#include <stdlib.h>
#include "config_project.h"

//void init_ng_ball(struct ball_t *b, struct striker_t *cat, uint8_t striker, struct vector_t *v);
void init_ng_ball(struct ball_t *b, struct striker_t *ks, struct variables *var_main);



#endif

