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
	else if (((b->posi.y >> 14) >= BORDERY) || ((b->posi.y >> 14) <= 1))
	{
		b->vel.y = -b->vel.y;
		gotoxy((b->posi.x) >> 14, (b->posi.y) >> 14);
		printf("%c", 196);
	}
}



uint32_t block_control(struct ball_t *b, struct blockpos *block, uint32_t score_counter, uint8_t *level_counter, uint8_t *in_game) {
    uint8_t sum=0;                     // test if there are no more blocks
	uint8_t i;

	for (uint8_t j = 0; j < 27; j++) {
		if ( (((b->posi.x >> 14) >= block[j].x1) && ((b->posi.x >> 14) <= block[j].x2)) &&
		        ( ((b->posi.y >> 14) == block[j].y1) || ((b->posi.y >> 14) == block[j].y2) ) )
            {
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
		          ( ((b->posi.y >> 14) >= block[j].y1) && ((b->posi.y >> 14) <= block[j].y2) ) )
            {
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




	for (i = 0 ; i < 27 ; i++){
        sum += block[i].hit;
	}
	if (sum == 0){                    // If there are no more blocks, go up a level
        (*level_counter)++;
        (*in_game)--;
	}
    return(score_counter);
}


void init_blocks(struct blockpos *block, uint8_t level_count){
    if(level_count == 1){
                for (int i = 0 ; i < 9 ; i++) {
                block[i].x1 = 8 + i * 15;
                block[i].y1 = 5;
                block[i].x2 = 21 + i * 15;
                block[i].y2 = 10;
                block[i].hit = 3;

                block[i + 9].x1 = 8 + i * 15;
                block[i + 9].y1 = 12;
                block[i + 9].x2 = 21 + i * 15;
                block[i + 9].y2 = 18;
                block[i + 9].hit = 2;

                block[i + 18].x1 = 8 + i * 15;
                block[i + 18].y1 = 20;
                block[i + 18].x2 = 21 + i * 15;
                block[i + 18].y2 = 25;
                block[i + 18].hit = 1;

                print_Block(block[i]);
                print_Block(block[i + 9]);
                print_Block(block[i + 18]);
                }
        }
        else if(level_count == 2){
            for (int i = 0 ; i < 9 ; i++) {
                block[i].x1 = 30 + i * 10;
                block[i].y1 = 5;
                block[i].x2 = 38 + i * 10;
                block[i].y2 = 8;
                block[i].hit = 3;

                block[i + 9].x1 = 8 + i * 10;
                block[i + 9].y1 = 10;
                block[i + 9].x2 = 16 + i * 10;
                block[i + 9].y2 = 13;
                block[i + 9].hit = 2;

                block[i + 18].x1 = 30 + i * 10;
                block[i + 18].y1 = 15;
                block[i + 18].x2 = 38 + i * 10;
                block[i + 18].y2 = 18;
                block[i + 18].hit = 1;

                print_Block(block[i]);
                print_Block(block[i + 9]);
                print_Block(block[i + 18]);
                }
        }
}
