#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define PIN_15 GPIO_NUM_15
#define PIN_16 GPIO_NUM_16
#define PIN_21 GPIO_NUM_21

void app_main(void)
{
    gpio_reset_pin(PIN_15);
    gpio_reset_pin(PIN_16);
    gpio_reset_pin(PIN_21);

    gpio_set_direction(PIN_15, GPIO_MODE_OUTPUT);
    gpio_set_direction(PIN_16, GPIO_MODE_OUTPUT);
    gpio_set_direction(PIN_21, GPIO_MODE_OUTPUT);

    // Drive 15 and 16 high
    gpio_set_level(PIN_15, 1);
    gpio_set_level(PIN_16, 1);

    // Blink GPIO 21
    while (1) {
        gpio_set_level(PIN_21, 1);
        vTaskDelay(pdMS_TO_TICKS(500));
        gpio_set_level(PIN_21, 0);
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}
