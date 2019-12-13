/*#include "registers.h"
#include <stdint.h>
#include <time.h>

volatile uint32_t* reg_ptr;

void gpio_port_c_rcc_init(void);
void led_init(void);
void led_flash(void);
void delay(void);

int main(void)
{
	//asm ("bkpt");
	led_init();
	
	while(1)
	{
		led_flash();
		delay();
	}
	
	return 0;
}

// this function initialize rcc registers for using gpio pins on port C
void gpio_port_c_rcc_init(void)
{
	// Note!!! should not reset port C on RCC_APB2RSTR register
	reg_ptr = (volatile uint32_t*) RCC_APB2ENR;
	*reg_ptr = 0x10;									// set bit 4 in RCC_APB2ENR register
}

// this function ititialize port C pin 14 for output
void led_init(void)
{
	uint32_t tmp;
	
	gpio_port_c_rcc_init();
	
	reg_ptr = (volatile uint32_t*) GPIOC_CRH;
	tmp = *reg_ptr;
	
	tmp |= 0x2000000;				// for PC14 (set bit 25 (mode 14))
	tmp &= 0xF3FFFFFF;				// for PC14
	
	*reg_ptr = tmp;
}

// flash switch PC14 from high to low and from low to high
void led_flash(void)
{	
	reg_ptr = (volatile uint32_t*) GPIOC_ODR;	
	*reg_ptr ^= 0x4000;				// XOR on bit 14
}

void delay(void)
{
	int i = 0x000FFFFF;
	//int j = 0xFFFFFFFF;
	while(i > 0)
	{
		i--;
		/*while(j > 0)
			j--;
	}
}*/

#include <Arduino.h>
#define RED_PIN PB1
#define GREEN_PIN PB0
#define BLUE_PIN PA7

int RED = 255, GREEN = 255, BLUE = 255;

void setup(){
	Serial.begin(115200);
	pinMode(RED_PIN, OUTPUT);
	pinMode(GREEN_PIN, OUTPUT);
	pinMode(BLUE_PIN, OUTPUT);
	setLed(RED,GREEN,BLUE);
}

void loop(){
	//digitalWrite(red, HIGHT);

}

void RGB_FADE(){
	LED.setfunction(fade);


}

void setLed(int RED, int GREEN, int BLUE){
	analogWrite(RED_PIN, RED);
	analogWrite(GREEN_PIN, GREEN);
	analogWrite(BLUE_PIN, BLUE);
}
