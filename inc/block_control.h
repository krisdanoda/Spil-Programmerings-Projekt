#ifndef BLOCK_CONTROL_H_INCLUDED
#define BLOCK_CONTROL_H_INCLUDED

#include "30010_io.h"
#include "trig.h"
#define BORDERX 150
#define BORDERY 60


struct blockpos {
	int x1, y1, x2, y2, hit;
};

void print_Block(struct blockpos b_1);
void border_control(struct ball_t *b);
uint32_t block_control(struct ball_t *b, struct blockpos *block, uint32_t score_counnter);
#endif /* BLOCK_CONTROL_INCLUDED */

