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

void initVector(struct vector_t *v, int32_t x, int32_t y) {
    v->x = x << 14;
    v->y = y << 14;
}

void rotate(struct vector_t *v, int32_t angle){
    int32_t x1 = v->x;
    v->x = FIX14_MULT(v->x,Cos(angle))-FIX14_MULT(v->y,Sin(angle));
    v->y = FIX14_MULT(x1,Sin(angle))+FIX14_MULT(v->y,Cos(angle));
}

void updatepos(struct ball_t *b, uint16_t speed_multi){

    b->posi.x = b->posi.x + FIX14_MULT(b->vel.x,(450+speed_multi*150));
    b->posi.y = b->posi.y + FIX14_MULT(b->vel.y,(450+speed_multi*150));
}

