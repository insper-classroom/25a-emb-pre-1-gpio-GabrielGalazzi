#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN_BLUE = 7;
const int BTN_PIN_GREEN= 26;

int main() {
  stdio_init_all();

  gpio_init(BTN_PIN_GREEN);
  gpio_set_dir(BTN_PIN_GREEN, GPIO_IN);
  gpio_pull_up(BTN_PIN_GREEN) ;

  gpio_init(BTN_PIN_BLUE);
  gpio_set_dir(BTN_PIN_BLUE, GPIO_IN);
  gpio_pull_up(BTN_PIN_BLUE);

  while (true) {
    if (!gpio_get(BTN_PIN_BLUE)) {
      printf("Botao 1\n");
      while (!gpio_get(BTN_PIN_BLUE)) {
      };
    }
    if (!gpio_get(BTN_PIN_GREEN)) {
      printf("Botao 2\n");
      while (!gpio_get(BTN_PIN_GREEN)) {
      };
    }
  }
}
