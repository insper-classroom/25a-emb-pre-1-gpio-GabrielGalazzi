#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN_RED = 28;
const int BTN_PIN_GREEN= 26;

const int LED_PIN_RED = 4;
const int LED_PIN_GREEN = 6;

int main() {

  int flagRed = 0;
  int flagGreen = 0;

  stdio_init_all();

  gpio_init(LED_PIN_RED);
  gpio_init(LED_PIN_GREEN);
  gpio_set_dir(LED_PIN_RED, GPIO_OUT);
  gpio_set_dir(LED_PIN_GREEN, GPIO_OUT);


  gpio_init(BTN_PIN_GREEN);
  gpio_set_dir(BTN_PIN_GREEN, GPIO_IN);
  gpio_pull_up(BTN_PIN_GREEN) ;

  gpio_init(BTN_PIN_RED);
  gpio_set_dir(BTN_PIN_RED, GPIO_IN);
  gpio_pull_up(BTN_PIN_RED) ;

  while (true) {

    if (!gpio_get(BTN_PIN_GREEN)) {
      if (flagGreen == 0){
        flagGreen = 1;
        gpio_put(LED_PIN_GREEN, 1);
      }
      else{
        flagGreen = 0;
        gpio_put(LED_PIN_GREEN, 0);

      }
      while (!gpio_get(BTN_PIN_GREEN)) {
      };
    }

    if (!gpio_get(BTN_PIN_RED)) {
      if (flagRed == 0){
        flagRed = 1;
        gpio_put(LED_PIN_RED, 1);
      }
      else{
        flagRed = 0;
        gpio_put(LED_PIN_RED, 0);
      }
      while (!gpio_get(BTN_PIN_RED)) {
      };
    }
  }
}
