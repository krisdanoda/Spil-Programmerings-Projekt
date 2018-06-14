#ifndef _BALL_H
#define _BALL_H

#include "striker.h"
#include "30010_io.h"
#include "timer.h"
#include "charset.h"
#include "trig.h"
#include "LUT.h"
#include "controller.h"
#include "ansi.h"
#include <stdlib.h>

//void init_ng_ball(struct ball_t *b, struct striker_t *cat, uint8_t striker, struct vector_t *v);
void init_ng_ball(struct ball_t *b, struct striker_t *ks, uint8_t SS);


#endif

