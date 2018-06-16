#include "controller.h"


void set_RGB(uint8_t val){

if (val == 1) {
    // Port A (BLUE)
    GPIOA->ODR |= (0x0001 << 9); //Set pin PA9 to high
    // Port C (GREEN)
    GPIOC->ODR |= (0x0001 << 7); //Set pin PC7 to high
    }
    else if (val == 2) {
    // Port C (GREEN)
    GPIOC->ODR &= ~(0x0001 << 7); //Set pin PC7 to high
    // Port B (RED)
    GPIOB->ODR &= ~(0x0001 << 4); //Set pin PB4 to high
    // Port A (BLUE)
    GPIOA->ODR |= (0x0001 << 9); //Set pin PA9 to high
    }
    else if (val == 3) {
    // Port A (BLUE)
    GPIOA->ODR |= (0x0001 << 9); //Set pin PA9 to high
    // Port B (RED)
    GPIOB->ODR |= (0x0001 << 4); //Set pin PB4 to high
    }
    else if (val == 0) {
    // Port A (BLUE)
    GPIOA->ODR &= ~(0x0001 << 9); //Set pin PA9 to high
    // Port C (GREEN)
    GPIOC->ODR &= ~(0x0001 << 7); //Set pin PC7 to high
    // Port B (RED)
    GPIOB->ODR &= ~(0x0001 << 4); //Set pin PB4 to high

    }

}


void set_Led(uint8_t val){

if (val == 1) {
    // Port B (RED)
    GPIOB->ODR &= ~(0x0001 << 4); //Set pin PB4 to high
    }
    else if (val == 2) {
    // Port C (GREEN)
    GPIOC->ODR &= ~(0x0001 << 7); //Set pin PC7 to high
    }
    else if (val == 4) {
    // Port A (BLUE)
    GPIOA->ODR &= ~(0x0001 << 9); //Set pin PA9 to high
    }
    else if (val == 8) {
    // Port A (BLUE)
    GPIOA->ODR &= ~(0x0001 << 9); //Set pin PA9 to high
    // Port B (RED)
    GPIOB->ODR &= ~(0x0001 << 4); //Set pin PB4 to high
    }
    else if (val == 16) {
    // Port A (BLUE)
    GPIOA->ODR &= ~(0x0001 << 9); //Set pin PA9 to high
    // Port C (GREEN)
    GPIOC->ODR &= ~(0x0001 << 7); //Set pin PC7 to high
    // Port B (RED)
    GPIOB->ODR &= ~(0x0001 << 4); //Set pin PB4 to high
    }
    else {
    // Port A (BLUE)
    GPIOA->ODR |= (0x0001 << 9); //Set pin PA9 to high
    // Port C (GREEN)
    GPIOC->ODR |= (0x0001 << 7); //Set pin PC7 to high
    // Port B (RED)
    GPIOB->ODR |= (0x0001 << 4); //Set pin PB4 to high

    }


}

void init_RGB(){

    RCC->AHBENR |= RCC_AHBPeriph_GPIOA;
    RCC->AHBENR |= RCC_AHBPeriph_GPIOB; // Enable clock for GPIO Port B
    RCC->AHBENR |= RCC_AHBPeriph_GPIOC; // Enable clock for GPIO Port c

    // Port A Blue
    GPIOA->OSPEEDR &= ~(0x00000003 << (9 * 2));
    GPIOA->OSPEEDR |=  (0x00000002 << (9 * 2));
    GPIOA->OTYPER &= ~(0x0001 << (9));
    GPIOA->OTYPER |=  (0x0000 << (9));
    GPIOA->MODER &= ~(0x00000003 << (9 * 2));
    GPIOA->MODER |= (0x00000001 << (9 * 2));

    // Port B Red
    GPIOB->OSPEEDR &= ~(0x00000003 << (4 * 2));
    GPIOB->OSPEEDR |=  (0x00000002 << (4 * 2));
    GPIOB->OTYPER &= ~(0x0001 << (4));
    GPIOB->OTYPER |=  (0x0000 << (4));
    GPIOB->MODER &= ~(0x00000003 << (4 * 2));
    GPIOB->MODER |= (0x00000001 << (4 * 2));

    // Port C Green
    GPIOC->OSPEEDR &= ~(0x00000003 << (7 * 2));
    GPIOC->OSPEEDR |=  (0x00000002 << (7 * 2));
    GPIOC->OTYPER &= ~(0x0001 << (7));
    GPIOC->OTYPER |=  (0x0000 << (7));
    GPIOC->MODER &= ~(0x00000003 << (7 * 2));
    GPIOC->MODER |= (0x00000001 << (7 * 2));

}


void init_joystick() {

    RCC->AHBENR |= RCC_AHBPeriph_GPIOA;
    RCC->AHBENR |= RCC_AHBPeriph_GPIOB; // Enable clock for GPIO Port B
    RCC->AHBENR |= RCC_AHBPeriph_GPIOC; // Enable clock for GPIO Port c
    // Port A (up)
    // Enable clock for GPIO Port A
    // Set pin PA4 to input
    GPIOA->MODER &= ~(0x00000003 << (4 * 2)); // Clear mode register
    GPIOA->MODER |=  (0x00000000 << (4 * 2)); // Set mode register (0x00 - Input,
    //0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
    GPIOA->PUPDR &= ~(0x00000003 << (4 * 2)); // Clear push/pull register
    GPIOA->PUPDR |=  (0x00000000 << (4 * 2)); // Set push/pull register (0x00 -
    //No pull, 0x01 - Pull-up, 0x02 - Pull-down)


    // Port B (down)
       // Set pin PB_0 to input
    GPIOB->MODER &= ~(0x00000003 << (0 * 2)); // Clear mode register
    GPIOB->MODER |=  (0x00000000 << (0 * 2)); // Set mode register (0x00 - Input,
    //0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
    GPIOB->PUPDR &= ~(0x00000003 << (0 * 2)); // Clear push/pull register
    GPIOB->PUPDR |=  (0x00000000 << (0 * 2)); // Set push/pull register (0x00 -
    //No pull, 0x01 - Pull-up, 0x02 - Pull-down)

        // Port C(right)
    // Set pin PC0 to input
    GPIOC->MODER &= ~(0x00000003 << (0 * 2)); // Clear mode register
    GPIOC->MODER |=  (0x00000000 << (0 * 2)); // Set mode register (0x00 - Input,
    //0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
    GPIOC->PUPDR &= ~(0x00000003 << (0 * 2)); // Clear push/pull register
    GPIOC->PUPDR |=  (0x00000000 << (0 * 2)); // Set push/pull register (0x00 -
    //No pull, 0x01 - Pull-up, 0x02 - Pull-down)


     // Port C(left)
    // Set pin PC1 to input
    GPIOC->MODER &= ~(0x00000003 << (1 * 2)); // Clear mode register
    GPIOC->MODER |=  (0x00000000 << (1 * 2)); // Set mode register (0x00 - Input,
    //0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
    GPIOC->PUPDR &= ~(0x00000003 << (1 * 2)); // Clear push/pull register
    GPIOC->PUPDR |=  (0x00000000 << (1 * 2)); // Set push/pull register (0x00 -
    //No pull, 0x01 - Pull-up, 0x02 - Pull-down)


      // PortB(Center)

    // Set pin PB5 to input
    GPIOB->MODER &= ~(0x00000003 << (5 * 2)); // Clear mode register
    GPIOB->MODER |=  (0x00000000 << (5 * 2)); // Set mode register (0x00 - Input,
    //0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
    GPIOB->PUPDR &= ~(0x00000003 << (5 * 2)); // Clear push/pull register
    GPIOB->PUPDR |=  (0x00000000 << (5 * 2)); // Set push/pull register (0x00 -
    //No pull, 0x01 - Pull-up, 0x02 - Pull-down)

}


void init_PS2joy(){
    RCC->CFGR2  &= ~RCC_CFGR2_ADCPRE12;         // Clear ADC12 prescaler bits
    RCC->CFGR2  |=  RCC_CFGR2_ADCPRE12_DIV6;    // Set ADC12 prescaler to 6
    RCC->AHBENR |=  RCC_AHBPeriph_ADC12;        // Enable clock for ADC12

    ADC1->CR    = 0x00000000;                   // Clear CR register
    ADC1->CFGR &=  0xFDFFC007;                  // Clear ADC1 config register
    ADC1->SQR1 &= ~ADC_SQR1_L;                  // Clear regular sequence register 1

    ADC1->CR |= 0x10000000;                     // Enable internal ADC voltage regulator
    for(int i = 0 ; i < 1000 ; i++) {}          // Wait for about 16 microseconds

    ADC1->CR |= 0x80000000;                     // Start ADC1 calibration
    while (!(ADC1->CR & 0x80000000));           // Wait for calibration to finish
        for (int i = 0 ; i < 100 ; i++) {}      // Wait for a little while

    ADC1->CR |= 0x00000001;                     // Enable ADC1 (0x01 -Enable, 0x02 -Disable)
    while (!(ADC1->ISR& 0x00000001));           // Wait until ready
}


uint8_t readJoystick(struct variables *var_main){

    if(var_main->ex_or_in_joy == 1)
    {
    uint16_t valup = GPIOA->IDR & (0x001 << 4);
 //   uint16_t valup0 = (valup >> 4);

    uint16_t valdown = GPIOB->IDR & (0x001 << 0);

    uint16_t valright = GPIOC->IDR & (0x001 << 0);

    uint16_t valleft = GPIOC->IDR & (0x001 << 1);

    uint16_t valcenter = GPIOB->IDR & (0x001 << 5);

    if(valup){
    valup = 1;
    }

    if(valdown){
    valdown = 1;
    }

if(valright){
    valright = 1;
    }

    if(valleft){
    valleft = 1;
    }

    if(valcenter){
    valcenter = 1;
    }
//printf("000%d%d%d%d%d\n",valcenter,valright,valleft,valdown,valup);

    int8_t val1 = (valdown << 1);
    int8_t val2 = (valleft << 2);
    int8_t val3 = (valright << 3);
    int8_t val4 = (valcenter << 4);

    int8_t output = valup |= val1 |= val2 |= val3 |= val4;

    // printf("%d\n",output);

    return(output);
    }

    else if(var_main->ex_or_in_joy == 2){
    ADC_RegularChannelConfig(ADC1, ADC_Channel_8, 1, ADC_SampleTime_1Cycles5);

    ADC_StartConversion(ADC1);                  // Start ADC read
    while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == 0); // Wait for ADC read

    uint16_t x = ADC_GetConversionValue(ADC1);  // Read the ADC value

    ADC_RegularChannelConfig(ADC1, ADC_Channel_9, 1, ADC_SampleTime_1Cycles5);
    ADC_StartConversion(ADC1);                  // Start ADC read
    while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == 0); // Wait for ADC read

    uint16_t y = ADC_GetConversionValue(ADC1);  // Read the ADC value

    uint8_t output = 0;
    if(y < 1000){
            output = 2;
    }
    else if(y > 3000){
            output = 1;
    }
    else if(x < 1000){
            output = 4;
    }
    else if(x > 3000){
            output = 8;
    }
    else output = 0;

    return(output);

    }

}

 uint16_t  read_joystick_x (){


 ADC_RegularChannelConfig(ADC1, ADC_Channel_8, 1, ADC_SampleTime_1Cycles5);

    ADC_StartConversion(ADC1);                  // Start ADC read
    while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == 0); // Wait for ADC read

return   ADC_GetConversionValue(ADC1);  // Read the ADC value
 }
