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
void time(struct interrupt_t *t);
void TIM2_IRQHandler(void);
void init_stopwatch();
void stopwatch(uint8_t js, uint8_t *ss, uint8_t *push);
uint8_t ret();

int8_t get_flag();
void set_flag(int8_t val);

#endif /* TIMER_H_INCLUDED */
