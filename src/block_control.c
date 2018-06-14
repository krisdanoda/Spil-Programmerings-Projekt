#include "block_control.h"
#include "ansi.h"

void print_Block(struct blockpos b_1) {
	block(b_1.x1, b_1.y1, b_1.x2, b_1.y2, b_1.hit);                                                 // draw block
}


void border_control(struct ball_t *b) {
	if (((b->posi.x >> 14) <= 1) || ((b->posi.x >> 14) >= BORDERX))                                 // control of X borders are hit
	{
		b->vel.x = -b->vel.x;                                                                       // bounce the ball back
		gotoxy((b->posi.x) >> 14, (b->posi.y) >> 14);                                               // go to the wall position
		printf("%c", 179);                                                                          // overwrite the border after it have been deleted by the ball
	}
	else if (((b->posi.y >> 14) >= BORDERY) || ((b->posi.y >> 14) <= 1))                            // control of Y borders are hit
	{
		b->vel.y = -b->vel.y;                                                                       // bounce the ball back
		gotoxy((b->posi.x) >> 14, (b->posi.y) >> 14);                                               // go to the wall position
		printf("%c", 196);                                                                          // overwrite the border after it have been deleted by the ball
	}
}



uint32_t block_control(struct ball_t *b, struct blockpos *block, uint32_t score_counter) {
	for (uint8_t j = 0; j < 27; j++) {                                                              // loop though every created block
		if ( (((b->posi.x >> 14) >= block[j].x1) && ((b->posi.x >> 14) <= block[j].x2)) &&          // check if ball hit the top or bottom of ...
		        ( ((b->posi.y >> 14) == block[j].y1) || ((b->posi.y >> 14) == block[j].y2) ) )      // a box
            {
			b->vel.y = -b->vel.y;                                                                   // bounce the ball back when block is hit
			block[j].hit--;                                                                         // decrease the life of the hit block
			print_Block(block[j]);                                                                  // print the color of the block life
			score_counter++;                                                                        // increase the score when a block is hit

			if (block[j].hit == 0) {                                                                // check if a block has zero life
				del_block(block[j].x1, block[j].y1, block[j].x2, block[j].y2);                      // delete the block
				block[j].x1 = 100;                                                                  // move the invisible block out of the map
				block[j].y1 = 100;                                                                  // -||-
				block[j].x2 = 100;                                                                  // -||-
				block[j].y2 = 100;                                                                  // -||-
			}
		}
		else if ( (((b->posi.x >> 14) == block[j].x1) || ((b->posi.x >> 14) == block[j].x2)) &&     // check if ball hit the left or right wall of ...
		          ( ((b->posi.y >> 14) >= block[j].y1) && ((b->posi.y >> 14) <= block[j].y2) ) )    // a box
            {
			b->vel.x = -b->vel.x;                                                                   // bounce the ball when block is hit
			block[j].hit--;                                                                         // decrease the life of the hit block
			print_Block(block[j]);                                                                  // print the color of the block life
			score_counter++;                                                                        // increase the score when a block is hit

			if (block[j].hit == 0) {                                                                // check if a block has zero life
				del_block(block[j].x1, block[j].y1, block[j].x2, block[j].y2);                      // delete the block
				block[j].x1 = 100;                                                                  // move the invisible block out of the map
				block[j].y1 = 100;                                                                  // -||-
				block[j].x2 = 100;                                                                  // -||-
				block[j].y2 = 100;                                                                  // -||-
			}
		}
	}
	return(score_counter);                                                                          // return the score to main
}


void init_blocks(struct blockpos *block, uint8_t level_count){                                     // initialize blocks and structure depending on level

    for(uint8_t k = 0; k < 100; k++){                                                               // initialize all possible block
                block[k].x1 = 100;                                                                  // move the invisible block out of the map
				block[k].y1 = 100;                                                                  // -||-
				block[k].x2 = 100;                                                                  // -||-
				block[k].y2 = 100;                                                                  // -||-
                block[k].hit = 0;                                                                   // life of given block
    }

    if(level_count == 1){                                                                           // level 1
                for (int i = 0 ; i < 9 ; i++) {                                                     // number for blocks in each row
                block[i].x1 = 8 + i * 15;                                                           // placement of left wall on block
                block[i].y1 = 5;                                                                    // top of box
                block[i].x2 = 21 + i * 15;                                                          // placement of right wall on block
                block[i].y2 = 10;                                                                   // bottom of box
                block[i].hit = 3;                                                                   // life of given block

                block[i + 9].x1 = 8 + i * 15;                                                       // placement of left wall on block
                block[i + 9].y1 = 12;                                                               // top of box
                block[i + 9].x2 = 21 + i * 15;                                                      // placement of right wall on block
                block[i + 9].y2 = 18;                                                               // bottom of box
                block[i + 9].hit = 2;                                                               // life of given block

                block[i + 18].x1 = 8 + i * 15;                                                      // placement of left wall on block
                block[i + 18].y1 = 20;                                                              // top of box
                block[i + 18].x2 = 21 + i * 15;                                                     // placement of right wall on block
                block[i + 18].y2 = 25;                                                              // bottom of box
                block[i + 18].hit = 1;                                                              // life of given block

                print_Block(block[i]);                                                              // print row 1
                print_Block(block[i + 9]);                                                          // print row 2
                print_Block(block[i + 18]);                                                         // print row 3
                }
        }
        else if(level_count == 2){                                                                  // same structure as above
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
