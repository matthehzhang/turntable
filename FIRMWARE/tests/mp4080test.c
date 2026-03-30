#include "driver/rtc_io.h"
#include "driver/gpio.h"

void app_main(void)
{
    // 1. Release from RTC
    rtc_gpio_deinit(PIN_15);
    rtc_gpio_deinit(PIN_16);

    // 2. Reset and configure as GPIO
    gpio_reset_pin(PIN_15);
    gpio_reset_pin(PIN_16);
    gpio_reset_pin(PIN_21);

    gpio_set_direction(PIN_15, GPIO_MODE_OUTPUT);
    gpio_set_direction(PIN_16, GPIO_MODE_OUTPUT);
    gpio_set_direction(PIN_21, GPIO_MODE_OUTPUT);

    // 3. Drive levels
    gpio_set_level(PIN_15, 0);  // SHDN low = enabled
    gpio_set_level(PIN_16, 1);  // PWM high

    // Blink 21
    while (1) {
        gpio_set_level(PIN_21, 1);
        vTaskDelay(pdMS_TO_TICKS(500));
        gpio_set_level(PIN_21, 0);
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}
