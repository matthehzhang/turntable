#include <stdio.h> //standard c i/o library - printf, scanf, etc

#include "freertos/FreeRTOS.h" //core free rtos ->
#include "freertos/task.h" //task api, task delay
#include "driver/gpio.h" //esp-idf gpio driver (gpio reset pin, gpio set direction)
#include "sdkconfig.h" //esp-idf config header, menuconfig settings (clock speeds, flash size, component options)

#define BLINK_GPIO 21

#define MP4080_SHDN_GPIO 15
#define MP4080_PWM_GPIO 16

#define HALL_GPIO 5

void app_main(void)
{
	gpio_reset_pin(BLINK_GPIO);
	gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);

	gpio_reset_pin(MP4080_SHDN_GPIO);
	gpio_reset_pin(MP4080_PWM_GPIO);
	gpio_set_direction(MP4080_SHDN_GPIO, GPIO_MODE_OUTPUT);
	gpio_set_direction(MP4080_PWM_GPIO, GPIO_MODE_OUTPUT);

	gpio_set_level(MP4080_SHDN_GPIO, 0);
	gpio_set_level(MP4080_PWM_GPIO, 1);
	
	gpio_reset_pin(HALL_GPIO);
	gpio_set_direction(HALL_GPIO, GPIO_MODE_INPUT);

	int hall;

	while(1){
		
		hall = gpio_get_level(HALL_GPIO);
		
		if(hall == 0) {
		gpio_set_level(BLINK_GPIO, 1);
		} else {
		gpio_set_level(BLINK_GPIO, 0);
		}

	}
}
