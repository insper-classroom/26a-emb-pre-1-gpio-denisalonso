#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int BTN1 = 26;
const int BTN2 = 7;

int main() {
    stdio_init_all();

    gpio_init(BTN1);
    gpio_set_dir(BTN1, GPIO_IN);
    gpio_pull_up(BTN1);

    gpio_init(BTN2);
    gpio_set_dir(BTN2, GPIO_IN);
    gpio_pull_up(BTN2);

    int cnt_1 = 0;
    int cnt_2 = 0;
    bool last_state_btn1 = true;
    bool last_state_btn2 = true;

    while (true) {
        bool current_state_1 = gpio_get(BTN1);
        if (last_state_btn1 == true && current_state_1 == false) {
            cnt_1++;
            printf("Botao 1: %d\n", cnt_1);
        }
        last_state_btn1 = current_state_1;
        sleep_ms(10);

        bool current_state_2 = gpio_get(BTN2);
        if (last_state_btn2 == true && current_state_2 == false) {
            cnt_2++;
            printf("Botao 2: %d\n", cnt_2);
        }
        last_state_btn2 = current_state_2;
        sleep_ms(10);
    }
}
