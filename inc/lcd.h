#ifndef LCD_H_INCLUDED
#define LCD_H_INCLUDED

#include "30010_io.h"
#include "timer.h"
#include "charset.h"

void type_tex(char *c, uint8_t *buffer, uint8_t  *x, uint8_t  y);

void type_tex_scroll(char *c, uint8_t *buffer, uint8_t *x, uint8_t  y);

void lcd_update( uint8_t *buffer, uint8_t  *x, uint8_t  y);
#endif
