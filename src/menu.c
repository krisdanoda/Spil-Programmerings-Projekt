//#include "menu.h"
//
//#define BORDERX 144
//#define BORDERY 80
//
//
//void init_menu(){
//    gotoxy(BORDERX/2-10,BORDERY/5);
//    printf("New Game");
//    gotoxy(BORDERX/2-10,BORDERY/5+2);
//    printf("High Scores");
//    gotoxy(BORDERX/2-10,BORDERY/5+4);
//    printf("Help");
//}
//
//
//
//void control_menu(uint8_t read){
//
//
//    // Her ændres menu_counter så der holdes styr på cursoren
//    if (read != old_read){
//        if (read == 1){
//            (*menu_counter)--;
//        }
//        else if (read == 2){
//            (*menu_counter)++;
//        }
//    }
//
//    if (*menu_counter == 0){
//            (*menu_counter)++;
//    }
//    else if (*menu_counter == 4) {
//            (*menu_counter)--;
//    }
//
//
//    // Her flyttes cursoren
//
//    if (*menu_counter == 1){
//        gotoxy(BORDERX/2-15,BORDERY/5);
//        printf("%c",175);
//        gotoxy(BORDERX/2-15,BORDERY/5+2);
//        printf("  ");
//        gotoxy(BORDERX/2-15,BORDERY/5+4);
//        printf("  ");
//    }
//    else if (*menu_counter == 2){
//        gotoxy(BORDERX/2-15,BORDERY/5);
//        printf("  ");
//        gotoxy(BORDERX/2-15,BORDERY/5+2);
//        printf("%c",175);
//        gotoxy(BORDERX/2-15,BORDERY/5+4);
//        printf("  ");
//    }
//    else if (*menu_counter == 3){
//        gotoxy(BORDERX/2-15,BORDERY/5);
//        printf("  ");
//        gotoxy(BORDERX/2-15,BORDERY/5+2);
//        printf("  ");
//        gotoxy(BORDERX/2-15,BORDERY/5+4);
//        printf("%c",175);
//    }
//
//
//    old_read = read;
//}
