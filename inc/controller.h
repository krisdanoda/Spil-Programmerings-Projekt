#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#include "30010_io.h"
#include "config_project.h"

void init_RGB();

void init_joystick();

void init_PS2joy();

//uint8_t read_PS2joy();

uint8_t readJoystick(struct variables *var_main);

uint16_t read_joystick_x();

void set_RGB(uint8_t val);

#endif /* CPONTROLLER_H_INCLUDED */
