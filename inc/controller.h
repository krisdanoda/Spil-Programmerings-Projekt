#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#include "30010_io.h"


void init_RGB();

void init_joystick();

uint8_t readJoystick();

void set_Led(uint8_t val);

#endif /* CPONTROLLER_H_INCLUDED */
