#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "stm32f30x_conf.h"
#include "30010_io.h"
#include "config_project.h"
#include "ansi.h"

#define BORDERX 150
#define BORDERY 60

void init_menu();
void init_help();
void clear_line(uint8_t y);
void init_high_score();

void control_menu(uint8_t read, struct variables *var_main);


#endif /* _MENU_H_*/
