#ifndef CONFIG_PROJECT_H_INCLUDED
#define CONFIG_PROJECT_H_INCLUDED

#include <time.h>
#include <stdlib.h>
#include "30010_io.h"

#define BORDERX 150
#define BORDERY 60

struct variables{
    uint8_t in_game, menu_counter, old_read, life_count;
    uint8_t level_counter, nob, ex_or_in_joy;
    uint16_t speed_multi;
    uint32_t score_counter;
    uint32_t high_score[3];
};

void init_var_main(struct variables *var_main);




#endif /* CONFIG_PROJECT_H_INCLUDED */
