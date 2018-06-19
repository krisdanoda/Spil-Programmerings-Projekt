#ifndef LCD_H_INCLUDED
#define LCD_H_INCLUDED

#include "30010_io.h"
#include "our_timer.h"
#include "charset.h"

void write_score(uint32_t score);

void write_level(uint8_t level);

void type_tex(char *c, uint8_t *buffer, uint8_t  *x, uint8_t  y);

#endif
