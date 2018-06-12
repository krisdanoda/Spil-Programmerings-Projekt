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
void fgcolor(int foreground);
void bgcolor(int background);
void color(int foreground, int background);
void resetbgcolor();
void clrscr();
void clreol();
void gotoxy(uint8_t x, int8_t y);
void underline(uint8_t on);
void blink(uint8_t on);
void inverse(uint8_t on);
void window(int x1, int y1, int x2, int y2,char s[]);
void counter(int x1, int y1, int x2, int y2);
void block(int x1, int y1, int x2, int y2, int hit);
void del_block(int x1, int y1, int x2, int y2);



#endif /* _ANSI_H_*/

