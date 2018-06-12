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
#include "block_control.h"

#define BORDERX 150
#define BORDERY 80




int main(void)
{
	init_usb_uart( 115200 );
	clrscr();
	gotoxy(1, 1);
	printf("%c[?25l", ESC);
	counter(1, 1, BORDERX, BORDERY);

    uint32_t score_counter = 0;
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

		border_control(&b);
		score_counter = block_control(&b, &block, score_counter);



		updatepos(&b);

		gotoxy(b.posi.x >> 14, b.posi.y >> 14);
		printf("%c", 254);

        gotoxy(20,90);
        printf("Score %d", score_counter);
		gotoxy(b.posi.x >> 14, b.posi.y >> 14);
		printf(" ");


	}
}
