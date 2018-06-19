#include "our_timer.h"

volatile int8_t t_flag;

int8_t get_flag() {
    return t_flag;
}

void set_flag(int8_t val) {
    t_flag = val;
}


void init_timer(uint16_t priority) {
    RCC->APB1ENR |= RCC_APB1Periph_TIM2;
    TIM2->CR1 = 0x0000; // Disable time
    TIM2->ARR = 639999; // Set auto reload value (100e-2*64e6)-1
    TIM2->PSC = 0;
    TIM2->DIER |=0x0001;
    NVIC_SetPriority(TIM2_IRQn, priority);
    NVIC_EnableIRQ(TIM2_IRQn);

    TIM2->CR1 |= 0x0001; // enable time
}

void our_time(struct interrupt_t *t){
    t->h = 0;
    t->m = 0;
    t->s = 0;
    t->hs = 0;

}

void TIM2_IRQHandler(void){
    t_flag =1;

    //printf("kris da noda jedi master son of Goku\n");

    t.hs++;
    if (t.hs == 100){
    t.hs=0;
    t.s++;
    }
    if (t.s==60){
    t.s=0;
    t.m++;
    }
    if (t.m==60){
    t.m=0;
    t.h++;
    }

    TIM2->SR &= ~0x0001; // clear interrupt bit
}

