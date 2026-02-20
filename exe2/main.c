#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PING = 26;
const int BTN_PINB = 7;

int main() {
  stdio_init_all();

  gpio_init(BTN_PING);
  gpio_set_dir(BTN_PING, GPIO_IN);
  gpio_pull_up(BTN_PING);

  gpio_init(BTN_PINB);
  gpio_set_dir(BTN_PINB, GPIO_IN);
  gpio_pull_up(BTN_PINB);

  while (true) {
    if (!gpio_get(BTN_PING)) {
      printf("Botao 1\n");
      while (!gpio_get(BTN_PING)) {
      };
    } 
    if (!gpio_get(BTN_PINB)) {
      printf("Botao 2\n");
      while (!gpio_get(BTN_PINB)) {
      }
    }
  }
}
