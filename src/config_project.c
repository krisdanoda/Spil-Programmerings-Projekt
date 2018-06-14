#include "config_project.h"



void init_var_main(struct variables *var_main){
    var_main->in_game           = 0;
    var_main->level_counter     = 1;
    var_main->life_count        = 3;
    var_main->menu_counter      = 1;
    var_main->nob               = 1;
    var_main->old_read          = 0;
    var_main->score_counter     = 0;
    var_main->speed_multi       = 1;
}
