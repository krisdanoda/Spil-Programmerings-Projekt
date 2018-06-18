#include "config_project.h"



void init_var_main(struct variables *var_main){
    // A function to initialize various variables used throughout the game.

    var_main->in_game           = 0;        // If 0 the menu is active, if 1 the game is initialized, if 2 the game is playing.
    var_main->level_counter     = 1;        // set start level
    var_main->life_count        = 3;        // life count updates after missed ball
    var_main->menu_counter      = 1;        // Keeps track of the menu cursor.
    var_main->nob               = 1;        // Number of ball in the game.
    var_main->old_read          = 0;        // When in the menu, the joystick is only moves the cursor one step pr push. This variable keeps track of joystick changes.
    var_main->score_counter     = 0;        // score counter increase when a block is hit
    var_main->ex_or_in_joy      = 2;        // If 1 the game is controlled by provided joystick. If 2 game is controlled by analog joystick.
    var_main->speed_multi       = 1;        // Adjusts ball speed.
    var_main->high_score[0]     = 0;        // initialize highscore
    var_main->high_score[1]     = 0;        // initialize highscore
    var_main->high_score[2]     = 0;        // initialize highscore


}


