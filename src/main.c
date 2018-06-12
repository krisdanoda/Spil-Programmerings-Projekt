/*
**
**                           Main.c
**
**
**********************************************************************/
/*
   Last committed:     $Revision: 00 $
   Last changed by:    $Author: $
   Last changed date:  $Date:  $
   ID:                 $Id:  $

**********************************************************************/
#include "stm32f30x_conf.h"
#include "30010_io.h"
#include "ansi.h"
#include "LUT.h"
#include "trig.h"
#include "controller.h"
#include "timer.h"
#include <string.h>
#include "charset.h"
#include "lcd.h"
#include "ini_blocks.h"

#define BORDERX 150
#define BORDERY 80




int main(void)
{
	init_usb_uart( 115200 );
	clrscr();
	gotoxy(1, 1);
	printf("%c[?25l", ESC);
	counter(1, 1, BORDERX, BORDERY);


	struct ball_t b;

	struct blockpos block[27];
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



	initVector(&b.posi, 20, 40);
	initVector(&b.vel, 1, 1);
	while (1)
	{
		if ((b.posi.x <= (2 << 14)) || (b.posi.x >= ((BORDERX) << 14 )))
		{
			b.vel.x = -b.vel.x;
			gotoxy(b.posi.x >> 14, b.posi.y >> 14);
			printf("%c", 179);
		}
		else if ((b.posi.y >= ((BORDERY) << 14)) || (b.posi.y <= (2 << 14)))
		{
			b.vel.y = -b.vel.y;
			gotoxy(b.posi.x >> 14, b.posi.y >> 14);
			printf("%c", 196);
		}


		for (uint8_t j = 0; j < 27; j++) {
			if ( (((b.posi.x >> 14) >= block[j].x1) && ((b.posi.x >> 14) <= block[j].x2)) &&
                ( ((b.posi.y >> 14) == block[j].y1) || ((b.posi.y >> 14) == block[j].y2) ) ) {
				b.vel.y = -b.vel.y;
				block[j].hit--;
				print_Block(block[j]);
				if(block[j].hit == 0){
				    del_block(block[j].x1,block[j].y1, block[j].x2, block[j].y2);
                    block[j].x1 = 100;
                    block[j].y1 = 100;
                    block[j].x2 = 100;
                    block[j].y2 = 100;
				}
			}
			else if ( (((b.posi.x >>14) == block[j].x1) || ((b.posi.x >> 14) == block[j].x2)) &&
			         ( ((b.posi.y >>14) >= block[j].y1) && ((b.posi.y >> 14) <= block[j].y2) ) ) {
				b.vel.x = -b.vel.x;
				block[j].hit--;
				print_Block(block[j]);
				if(block[j].hit == 0){
				    del_block(block[j].x1,block[j].y1, block[j].x2, block[j].y2);
				    block[j].x1 = 100;
                    block[j].y1 = 100;
                    block[j].x2 = 100;
                    block[j].y2 = 100;
				}
			}
		}


		updatepos(&b);

		gotoxy(b.posi.x >> 14, b.posi.y >> 14);
		printf("%c", 254);


		gotoxy(b.posi.x >> 14, b.posi.y >> 14);
		printf(" ");

	}
}
