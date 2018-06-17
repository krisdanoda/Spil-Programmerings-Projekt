#include "ansi.h"
#include "LUT.h"
void fgcolor(int foreground) {
  /*  Value      foreground     Value     foreground
      ------------------------------------------------
        0        Black            8       Dark Gray
        1        Red              9       Light Red
        2        Green           10       Light Green
        3        Brown           11       Yellow
        4        Blue            12       Light Blue
        5        Purple          13       Light Purple
        6        Cyan            14       Light Cyan
        7        Light Gray      15       White
  */
  int type = 22;             // normal text
  if (foreground > 7) {
    type = 1;                // bold text
    foreground -= 8;
  }
  printf("%c[%d;%dm", ESC, type, foreground + 30);
}

void bgcolor(int background) {
  /* IMPORTANT:   When you first use this function you cannot get back to true white background in HyperTerminal.
     Why is that? Because ANSI does not support true white background (ANSI white is gray to most human eyes).
                  The designers of HyperTerminal, however, preferred black text on white background, which is why
                  the colors are initially like that, but when the background color is first changed there is no
                  way comming back.
     Hint:        Use resetbgcolor(); clrscr(); to force HyperTerminal into gray text on black background.

      Value      Color
      ------------------
        0        Black
        1        Red
        2        Green
        3        Brown
        4        Blue
        5        Purple
        6        Cyan
        7        Gray
  */
  printf("%c[%dm", ESC, background + 40);
}

void color(int foreground, int background) {
// combination of fgcolor() and bgcolor() - uses less bandwidth
  int type = 22;             // normal text
  if (foreground > 7) {
    type = 1;                // bold text
    foreground -= 8;
  }
  printf("%c[%d;%d;%dm", ESC, type, foreground + 30, background + 40);
}

void resetbgcolor() {
// gray on black text, no underline, no blink, no reverse
  printf("%c[m", ESC);
}


void clrscr() {
// Clear screen and home cursor
  printf("%c[2J", ESC);
}

void clreol() {
  //Clear to end of line
  printf("%c[K", ESC);
}


void gotoxy(uint8_t x, int8_t y) {
//moves the cursor to position (x,y)
  printf("%c[%d;%dH", ESC, y, x);
}

void underline(uint8_t on) {
// turn on / off underline
  if (on == 1)
    printf("%c[04m", ESC);
  else
    printf("%c[24m", ESC);
}

void blink(uint8_t on) {
//blink on and off
  if (on == 1)
    printf("%c[05", ESC);
  else
    printf("%c[25", ESC);
}

void inverse(uint8_t on) {
//inversed coloured text on and off
  if (on == 1)
    printf("%c[07", ESC);
  else
    printf("%c[27", ESC);
}

void window(int x1, int y1, int x2, int y2, char s[]) {

  int i;
  gotoxy(x1, y1);  // Øverste vandrette linje
  int chl = strlen(s);
  uint8_t tspace = x2 - chl - 7;
  char ctspace[tspace];
  memset(ctspace, 32, tspace);
  ctspace[tspace] = 0;
  //inverse(1);
  printf("%c%c%c%c%s%s%c%c%c", 218, 196, 179, 32, s, ctspace, 179, 196, 191);

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


  gotoxy(x1, y2);
  printf("%c", 192); // Laver hjørne nederst til venstre

  gotoxy(x2, y2);
  printf("%c", 217); // Laver hjørne nederst til højre

}


void counter(int x1, int y1, int x2, int y2) {

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
  printf("%c", 218); // Laver hjørne øverst til venstre

  gotoxy(x2, y1);
  printf("%c", 191); // Laver hjørne øverst til højre

  gotoxy(x1, y2);
  printf("%c", 192); // Laver hjørne nederst til venstre

  gotoxy(x2, y2);
  printf("%c", 217); // Laver hjørne nederst til højre
}

void block(int x1, int y1, int x2, int y2, int hit) {

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
  gotoxy(x1, y2);                                               // bottom horizontal line                                               // nederste vandrette linje
  for (i = x1; i <= x2; ++i) {
    gotoxy(i, y2);                                              // update cursor position
    printf("%c", 223);                                          // print -
  }
  printf("%c[37m", ESC);                                        // set color back to normal
}

void del_block(int x1, int y1, int x2, int y2) {

  int i;

  gotoxy(x1, y1);             // Højre lodrette linje
  for (i = y1 + 1; i <= y2; ++i) {
    gotoxy(x1, i);
    printf("%c", 32);
  }
  gotoxy(x2, y1);             // Højre lodrette linje
  for (i = y1 + 1; i <= y2; ++i) {
    gotoxy(x2, i);
    printf("%c", 32);
  }
  gotoxy(x1, y1);  // Øverste vandrette linje
  for (i = x1; i <= x2; ++i) {
    gotoxy(i, y1);
    printf("%c", 32);
  }
  gotoxy(x1, y2);             // nederste vandrette linje
  for (i = x1; i <= x2; ++i) {
    gotoxy(i, y2);
    printf("%c", 32);
  }
}


