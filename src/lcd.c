#include "lcd.h"

void write_score(uint32_t score){

    char str[8];
    sprintf(str, "%u",score);

    uint8_t buffer[512];

    memset(buffer, 0x00, 512);
    type_tex("The score is:",  buffer, 0, 0);
    lcd_push_buffer(buffer);
    type_tex(str, buffer, 0, 1);
    lcd_push_buffer(buffer);


}


void write_level(uint8_t level){
char str[8];
sprintf(str,"%u",level);

uint8_t buffer[512];

//    memset(buffer, 0x00, 512);
    type_tex("You have reached level:",  buffer, 0, 2);
    lcd_push_buffer(buffer);
    type_tex(str, buffer, 0, 3);
    lcd_push_buffer(buffer);

}



void init_disp_score(){

    uint8_t buffer[512];

    memset(buffer, 0x00, 512);
    type_tex("The score is:",  buffer, 0, 0);
    lcd_push_buffer(buffer);
    }





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
