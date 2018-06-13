#include "stm32f30x_conf.h"
#include "30010_io.h"
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void init_menu();
void init_help();
void clear_line(uint8_t y);
void init_high_score();

void control_menu(uint8_t read, uint8_t *menu_counter, uint8_t *old_read, uint8_t *in_game);


#endif /* _MENU_H_*/
