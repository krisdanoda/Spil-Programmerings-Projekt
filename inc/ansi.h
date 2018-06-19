#ifndef _ANSI_ESCAPE_CODES_H_
#define _ANSI_ESCAPE_CODES_H_

#include "30010_io.h"
#define ESC 0x1B
//
///* Includes ------------------------------------------------------------------*/
#include <string.h>
///* Exported types ------------------------------------------------------------*/
///* Exported constants --------------------------------------------------------*/
///* Exported macro ------------------------------------------------------------*/
//
//
///* Exported functions ------------------------------------------------------- */
void clrscr();                                                  // clear screen
void gotoxy(uint8_t x, int8_t y);                               // go to a given position
void counter(int x1, int y1, int x2, int y2);                   // create a plain window
void block(int x1, int y1, int x2, int y2, int hit);            // print a block with a color depending on life
void del_block(int x1, int y1, int x2, int y2);                 // delete a block when it is hit



#endif /* _ANSI_H_*/

        // initialize highscore
