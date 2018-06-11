#include "lcd.h"


void type_tex(char *c, uint8_t *buffer, uint8_t  *x, uint8_t  y)
{
    uint8_t k = 0;

    while (c[k] != 0x00)
    {
        for (uint8_t i = 0 ; i < 5 ; i++)
        {

            buffer[*x + y * 128 + i + k*5] = character_data[c[k] - 0x20][i];
        }
        k++;
    }
}

void type_tex_scroll(char *c, uint8_t *buffer, uint8_t  *x, uint8_t  y)
{
    uint8_t k = 0;
    while (c[k] != 0x00)
    {
        for (uint8_t i = 0 ; i < 5 ; i++)
        {

            buffer[(y * 128) + (*x + i + k*5) % 128] = character_data[c[k] - 0x20][i];
        }
        k++;
    }
    if(*x == 127)
        *x=1;
    (*x)++;
    printf("%d\n",*x);

}


void lcd_update( uint8_t *buffer, uint8_t  *x, uint8_t  y)
{
    memset(buffer, 0x00, 512);
    type_tex_scroll("kris da noda er",  buffer,  x,  y);
}
