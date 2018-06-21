#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#include "30010_io.h"
#include "ansi.h"
#include "controller.h"

struct interrupt_t{
     int16_t h, m, s, hs;
};
volatile struct interrupt_t t;

void init_timer(uint16_t priority);
void our_time(struct interrupt_t *t);
void TIM2_IRQHandler(void);

int8_t get_flag();
void set_flag(int8_t val);

#endif /* TIMER_H_INCLUDED */
