/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

// source
// https://www.electronicshub.org/program-raspberry-pi-pico-using-c/
// https://www.youtube.com/watch?v=B5rQSoOmR5w
// https://www.electromaker.io/blog/article/getting-started-with-the-raspberry-pi-pico-w-cc-sdk
// https://www.electromaker.io/blog/article/getting-started-with-the-raspberry-pi-pico-w-cc-sdk

// board is pico w
//
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"


/*
int main() {
#ifndef PICO_DEFAULT_LED_PIN
#warning blink example requires a board with a regular LED
#else
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    while (true) {
        gpio_put(LED_PIN, 1);
        sleep_ms(250);
        gpio_put(LED_PIN, 0);
        sleep_ms(250);
    }
#endif
}
*/

int main() {
    stdio_init_all();
    while (true) {
        
        printf("LED on\n");
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
        sleep_ms(2500);
        printf("LED off\n");
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        sleep_ms(2500);

    }
    return 0;
}
/*
#include "pico/stdlib.h"

int main() {
    const uint LED_PIN = 25;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    while (true) {
        gpio_put(LED_PIN, 1);
        sleep_ms(250);
        gpio_put(LED_PIN, 0);
        sleep_ms(250);
    }
}

*/