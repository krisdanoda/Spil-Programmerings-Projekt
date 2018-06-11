/*
**
**                           Main.c
**
**
**********************************************************************/
/*
   Last committed:     $Revision: 00 $
   Last changed by:    $Author: $
   Last changed date:  $Date:  $
   ID:                 $Id:  $

**********************************************************************/
#include "stm32f30x_conf.h"
#include "30010_io.h"
#include "ansi.h"
#include "LUT.h"
#include "trig.h"

int main(void)
{
    init_usb_uart( 115200 );
    clrscr();
    gotoxy(1,1);
    counter(1,1,150,80);
  while(1)
  {

  }
}
