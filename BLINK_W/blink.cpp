// source
// https://www.electronicshub.org/program-raspberry-pi-pico-using-c/
// https://www.youtube.com/watch?v=B5rQSoOmR5w
// https://www.electromaker.io/blog/article/getting-started-with-the-raspberry-pi-pico-w-cc-sdk
// https://www.electromaker.io/blog/article/getting-started-with-the-raspberry-pi-pico-w-cc-sdk
// https://github.com/LearnEmbeddedSystems/pico-w-webserver-template
// video that explains how to create a server
// https://www.youtube.com/watch?v=C_O0MXGBHsw 

// set board is pico w

#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

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