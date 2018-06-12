#ifndef TRIG_H_INCLUDED
#define TRIG_H_INCLUDED

#include "30010_io.h"
#include "LUT.h"

#define FIX14_SHIFT 14
#define FIX14_MULT(a, b) ( (a)*(b) >> FIX14_SHIFT )
#define FIX14_DIV(a, b) ( ((a) << FIX14_SHIFT) / b )
#define K 800

struct vector_t {
    int32_t x, y;
};

struct ball_t {
    struct vector_t posi;
    struct vector_t vel;
};

int32_t Sin(int32_t grader);
int32_t Cos(int32_t grader);
void initVector(struct vector_t *v, int32_t x, int32_t y);
void rotate(struct vector_t *v, int32_t angle);
void updatepos(struct ball_t *b);


#endif /* TRIG_H_INCLUDED */

