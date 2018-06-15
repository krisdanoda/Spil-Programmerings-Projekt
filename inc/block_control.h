#ifndef BLOCK_CONTROL_H_INCLUDED
#define BLOCK_CONTROL_H_INCLUDED

#include "30010_io.h"
#include "trig.h"
#include "ansi.h"
#include "config_project.h"
#include "striker.h"

#define BORDERX 150
#define BORDERY 60


struct blockpos {
	int x1, y1, x2, y2, hit;                                                                    // initialize struct of a block
};

void print_Block(struct blockpos b_1);                                                          // print each initialized block
void border_control(struct ball_t *b);                                                          // check if ball is out if window and bounces it back if it is
void block_control(struct ball_t *b, struct blockpos *block, struct variables *var_main, struct striker_t *strike);      // control of block is hit, life, score of blocks
void init_blocks(struct blockpos *block, uint8_t level_count);                                  // initialize map layout of a given level
#endif /* BLOCK_CONTROL_INCLUDED */

