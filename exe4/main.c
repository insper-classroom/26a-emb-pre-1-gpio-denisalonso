#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int LED0 = 5;
const int LED1 = 8;
const int LED2 = 11;
const int LED3 = 15;
const int BTN = 28;


int main() {
  
  stdio_init_all();
  gpio_init(BTN);
  gpio_set_dir(BTN, GPIO_IN);
  gpio_pull_up(BTN);

  gpio_init(LED0);
  gpio_set_dir(LED0, GPIO_OUT);
  gpio_init(LED1);
  gpio_set_dir(LED1, GPIO_OUT);
  gpio_init(LED2);
  gpio_set_dir(LED2, GPIO_OUT);
  gpio_init(LED3);
  gpio_set_dir(LED3, GPIO_OUT);
  

  while (true) {
    if (!gpio_get(BTN)) {
      gpio_put(LED0, 1);
      sleep_ms(300);
      gpio_put(LED1, 1);
      gpio_put(LED0, 0);
      sleep_ms(300);
      gpio_put(LED2, 1);
      gpio_put(LED1, 0);
      sleep_ms(300);
      gpio_put(LED3, 1);
      gpio_put(LED2, 0);
      sleep_ms(300);
      gpio_put(LED3, 0);

      // espera o botão ser solto (evita repetir enquanto estiver segurando)
      while (!gpio_get(BTN)) {
      }
    }
  }
}
