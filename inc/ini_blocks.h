#ifndef INI_BLOCK_H_INCLUDED
#define INI_BLOCK_H_INCLUDED

#include "30010_io.h"

struct blockpos {
    int x1, y1, x2, y2, hit;
};

void ini_Blocks(struct blockpos *b_1_1);
void print_Block(struct blockpos b_1_1);

#endif /* INI_BLOCK_INCLUDED */
