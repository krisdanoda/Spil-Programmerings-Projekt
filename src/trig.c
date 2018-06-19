#include "trig.h"

int32_t Sin(int32_t grader){
 grader = grader%512;
    if (grader<0)
        grader = grader +512;

    int32_t sinus = SIN[grader];
    return sinus;
}

int32_t Cos(int32_t grader){
     grader = (128+grader)%512;
    if (grader<0)
        grader = grader +512;

    int32_t cosinus = SIN[grader];
    return cosinus;
}


void rotate(struct vector_t *v, int32_t angle){
    int32_t x1 = v->x;
    v->x = FIX14_MULT(v->x,Cos(angle))-FIX14_MULT(v->y,Sin(angle));
    v->y = FIX14_MULT(x1,Sin(angle))+FIX14_MULT(v->y,Cos(angle));
}



