#include "ansi.h"
#include "LUT.h"


void clrscr() {
// Clear screen and home cursor
  printf("%c[2J", ESC);
}


void gotoxy(uint8_t x, int8_t y) {
//moves the cursor to position (x,y)
  printf("%c[%d;%dH", ESC, y, x);
}


void border_window(int x1, int y1, int x2, int y2) {

  int i;
  gotoxy(x1, y1);  // Øverste vandrette linje
  for (i = x1; i < x2; ++i) {
    gotoxy(i, y1);
    printf("%c", 196);
  }


  gotoxy(x1, y2);             // nederste vandrette linje
  for (i = x1; i < x2; ++i) {
    gotoxy(i, y2);
    printf("%c", 196);
  }

  gotoxy(x1, y1);             // Højre lodrette linje
  for (i = y1 + 1; i < y2; ++i) {
    gotoxy(x1, i);
    printf("%c", 179);
  }


  gotoxy(x2, y1);             // Højre lodrette linje
  for (i = y1 + 1; i < y2; ++i) {
    gotoxy(x2, i);
    printf("%c", 179);
  }

  gotoxy(x1, y1);
  printf("%c", 218);                                            // print top left corner

  gotoxy(x2, y1);
  printf("%c", 191);                                            // print top right corner

  gotoxy(x1, y2);
  printf("%c", 192);                                            // print bottom left corner

  gotoxy(x2, y2);
  printf("%c", 217);                                            // print bottom right corner
}

void block(int x1, int y1, int x2, int y2, int hit) {           // print block on screen

  int i;

  if (hit == 3)
    printf("%c[31m", ESC);                                      // print red color
  else if (hit == 2)
    printf("%c[33m", ESC);                                      // print yellow color
  else
    printf("%c[32m", ESC);                                      // print green color

  gotoxy(x1, y1);                                               // left vertical line
  for (i = y1 + 1; i <= y2; ++i) {
    gotoxy(x1, i);                                              // update cursor position
    printf("%c", 178);                                          // print |
  }
  gotoxy(x2, y1);                                               // right vertical line
  for (i = y1 + 1; i <= y2; ++i) {
    gotoxy(x2, i);                                              // update cursor position
    printf("%c", 178);                                          // print |
  }
  gotoxy(x1, y1);                                               // top horizontal line
  for (i = x1; i <= x2; ++i) {
    gotoxy(i, y1);                                              // update cursor position
    printf("%c", 220);                                          // print -
  }
  gotoxy(x1, y2);                                               // bottom horizontal line
  for (i = x1; i <= x2; ++i) {
    gotoxy(i, y2);                                              // update cursor position
    printf("%c", 223);                                          // print -
  }
  printf("%c[37m", ESC);                                        // set color back to normal
}

void del_block(int x1, int y1, int x2, int y2) {                // delete block on screen

  int i;

  gotoxy(x1, y1);                                               // left vertical line
  for (i = y1 + 1; i <= y2; ++i) {
    gotoxy(x1, i);                                              // update cursor position
    printf("%c", 32);                                           // print space
  }
  gotoxy(x2, y1);                                               // right vertical line
  for (i = y1 + 1; i <= y2; ++i) {
    gotoxy(x2, i);                                              // update cursor position
    printf("%c", 32);                                           // print space
  }
  gotoxy(x1, y1);                                               // top horizontal line
  for (i = x1; i <= x2; ++i) {
    gotoxy(i, y1);                                              // update cursor position
    printf("%c", 32);                                           // print space
  }
  gotoxy(x1, y2);                                               // bottom horizontal line
  for (i = x1; i <= x2; ++i) {
    gotoxy(i, y2);                                              // update cursor position
    printf("%c", 32);                                           // print space
  }
}


