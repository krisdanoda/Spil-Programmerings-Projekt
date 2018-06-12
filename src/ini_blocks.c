#include "ini_blocks.h"
#include "ansi.h"

void ini_Blocks(struct blockpos *b_1_1){
    b_1_1->x1 = 6;
    b_1_1->y1 = 5;
    b_1_1->x2 = 19;
    b_1_1->y2 = 8;
}

void print_Block(struct blockpos b_1_1){
    block(b_1_1.x1, b_1_1.y1, b_1_1.x2, b_1_1.y2, b_1_1.hit);
}

