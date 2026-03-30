#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"

#define BLINK_GPIO 21

#define MP4080_SHDN_GPIO 15
#define MP4080_PWM_GPIO 16


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


	while(1){

		gpio_set_level(BLINK_GPIO, 1);
		vTaskDelay(1000 / portTICK_PERIOD_MS);
		
		gpio_set_level(BLINK_GPIO, 0);
		vTaskDelay(1000 / portTICK_PERIOD_MS);

	}
}
