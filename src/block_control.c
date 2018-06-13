#include "block_control.h"
#include "ansi.h"

void print_Block(struct blockpos b_1) {
	block(b_1.x1, b_1.y1, b_1.x2, b_1.y2, b_1.hit);
}


void border_control(struct ball_t *b) {
	if (((b->posi.x >> 14) <= 1) || ((b->posi.x >> 14) >= BORDERX))
	{
		b->vel.x = -b->vel.x;
		gotoxy((b->posi.x) >> 14, (b->posi.y) >> 14);
		printf("%c", 179);
	}
	else if (((b->posi.y >> 14) >= BORDERY) || ((b->posi.y >> 14) <= 2))
	{
		b->vel.y = -b->vel.y;
		gotoxy((b->posi.x) >> 14, (b->posi.y) >> 14);
		printf("%c", 196);
	}
}

uint32_t block_control(struct ball_t *b, struct blockpos *block, uint32_t score_counter) {
	for (uint8_t j = 0; j < 27; j++) {
		if ( (((b->posi.x >> 14) >= block[j].x1) && ((b->posi.x >> 14) <= block[j].x2)) &&
		        ( ((b->posi.y >> 14) == block[j].y1) || ((b->posi.y >> 14) == block[j].y2) ) ) {
			b->vel.y = -b->vel.y;
			block[j].hit--;
			print_Block(block[j]);
			score_counter++;

			if (block[j].hit == 0) {
				del_block(block[j].x1, block[j].y1, block[j].x2, block[j].y2);
				block[j].x1 = 100;
				block[j].y1 = 100;
				block[j].x2 = 100;
				block[j].y2 = 100;
			}
		}
		else if ( (((b->posi.x >> 14) == block[j].x1) || ((b->posi.x >> 14) == block[j].x2)) &&
		          ( ((b->posi.y >> 14) >= block[j].y1) && ((b->posi.y >> 14) <= block[j].y2) ) ) {
			b->vel.x = -b->vel.x;
			block[j].hit--;
			print_Block(block[j]);
			score_counter++;
			if (block[j].hit == 0) {
				del_block(block[j].x1, block[j].y1, block[j].x2, block[j].y2);
				block[j].x1 = 100;
				block[j].y1 = 100;
				block[j].x2 = 100;
				block[j].y2 = 100;
			}
		}
	}
}
