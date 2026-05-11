#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "soc/gpio_struct.h"
#include "soc/gpio_reg.h"

#include "driver/periph_ctrl.h"
#include "soc/io_mux_reg.h"

#include "esp_timer.h"
#include "rom/ets_sys.h"

#define TRIG_PIN 5
#define ECHO_PIN 18

static inline void gpio_output_enable(int pin)
{
    GPIO.enable_w1ts = (1 << pin);
}

static inline void gpio_input_enable(int pin)
{
    GPIO.enable_w1tc = (1 << pin);
}

static inline void gpio_set_high(int pin)
{
    GPIO.out_w1ts = (1 << pin);
}

static inline void gpio_set_low(int pin)
{
    GPIO.out_w1tc = (1 << pin);
}

static inline int gpio_read(int pin)
{
    return (GPIO.in >> pin) & 0x1;
}

void ultrasonic_task(void *arg)
{
    // Configure GPIO matrix / mux
    PIN_FUNC_SELECT(IO_MUX_GPIO5_REG, PIN_FUNC_GPIO);
    PIN_FUNC_SELECT(IO_MUX_GPIO18_REG, PIN_FUNC_GPIO);

    gpio_output_enable(TRIG_PIN);
    gpio_input_enable(ECHO_PIN);

    while (1)
    {
        // Ensure LOW
        gpio_set_low(TRIG_PIN);
        ets_delay_us(2);

        // 10us trigger pulse
        gpio_set_high(TRIG_PIN);
        ets_delay_us(10);
        gpio_set_low(TRIG_PIN);

        // Wait for echo HIGH
        int64_t timeout = esp_timer_get_time();

        while (!gpio_read(ECHO_PIN))
        {
            if (esp_timer_get_time() - timeout > 30000)
            {
                printf("Timeout HIGH\n");
                goto delay_label;
            }
        }

        int64_t echo_start = esp_timer_get_time();

        // Wait for echo LOW
        while (gpio_read(ECHO_PIN))
        {
            if (esp_timer_get_time() - echo_start > 30000)
            {
                printf("Timeout LOW\n");
                goto delay_label;
            }
        }

        int64_t echo_end = esp_timer_get_time();

        int64_t pulse_us = echo_end - echo_start;

        float distance_cm = pulse_us * 0.0343f / 2.0f;

        printf("Distance: %.2f cm\n", distance_cm);

    delay_label:
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

extern void app_main()
{
    xTaskCreate(
        ultrasonic_task,
        "ultrasonic",
        4096,
        NULL,
        5,
        NULL
    );
}
