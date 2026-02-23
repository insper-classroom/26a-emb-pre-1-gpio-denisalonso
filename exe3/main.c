#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

// pin vars
const int LEDr = 4;
const int BTNr = 28;
const int LEDg = 6;
const int BTNg = 26;


int main() {
  stdio_init_all();

  gpio_init(BTNr);
  gpio_set_dir(BTNr, GPIO_IN);
  gpio_pull_up(BTNr);
  gpio_init(LEDr);
  gpio_set_dir(LEDr, GPIO_OUT);

  gpio_init(BTNg);
  gpio_set_dir(BTNg, GPIO_IN);
  gpio_pull_up(BTNg);
  gpio_init(LEDg);
  gpio_set_dir(LEDg, GPIO_OUT);

  // on/off vars
  int status_r = 0;
  int status_g = 0;

  while (true) {
    if (!gpio_get(BTNr)) {
      if (status_r == 0) {
        status_r += 1;
        gpio_put(LEDr, status_r);
      } else {
        status_r -= 1;
        gpio_put(LEDr, status_r);
      }
      while (!gpio_get(BTNr)) {
      };
    }

    if (!gpio_get(BTNg)) {
      if (status_g == 0) {
        status_g += 1;
        gpio_put(LEDg, status_g);
      } else {
        status_g -= 1;
        gpio_put(LEDg, status_g);
      }
      while (!gpio_get(BTNg)) {
      };
    }
  }
}
