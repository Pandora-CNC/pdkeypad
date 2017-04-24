/*
  pdkeypad
  An open-source reimplementation of the Pandora keypad driver
  (c) 2017 0xbmuessig, bmuessig.eu

  kio.c: Keypad low-level I/O driver
*/

#include <stdio.h>
#include <stdbool.h>
#include "kio.h"
#include "gpio.h"

int kio_init(void)
{
  // Initialize the GPIO driver
  if(!w55fa93_gpio_init()) {
    fprintf(stderr, "ERR: GPIO-Init failed!");
    return false;
  }

  // Configure the DIO line to: Output, HIGH
  w55fa93_gpio_set_output(DIO_GRP, DIO_PIN);
  w55fa93_gpio_set(DIO_GRP, DIO_PIN, HIGH);

  // Configure the CLK line to: Output, LOW
  w55fa93_gpio_set_output(CLK_GRP, CLK_PIN);
  w55fa93_gpio_set(CLK_GRP, CLK_PIN, LOW);

  // Configure the STB line to: Output, HIGH
  w55fa93_gpio_set_output(STB_GRP, STB_PIN);
  w55fa93_gpio_set(STB_GRP, STB_PIN, HIGH);

  // Configure the unknown pins to: Input
  w55fa93_gpio_set_input(UK0_GRP, UK0_PIN);
  w55fa93_gpio_set_input(UK1_GRP, UK1_PIN);

  // Return success
  return true;
}

void kio_deinit(void)
{
  // Configure the DIO line to: Input
  w55fa93_gpio_set_input(DIO_GRP, DIO_PIN);

  // Configure the CLK line to: Input
  w55fa93_gpio_set_input(CLK_GRP, CLK_PIN);

  // Configure the STB line to: Input
  w55fa93_gpio_set_input(STB_GRP, STB_PIN);

  // Deinitialize the GPIO driver
  w55fa93_gpio_deinit();
}

void kio_begin_transaction(void)
{
  // Set the clock low (since data is latched on the rising edge)
  w55fa93_gpio_set(CLK_GRP, CLK_PIN, LOW);
  // Enable the serial interface
  w55fa93_gpio_set(STB_GRP, STB_PIN, LOW);
  // Sleep until the serial interface is ready
  usleep(SIF_TTI);
}

void kio_end_transaction(void)
{
  // Disable the serial interface
  w55fa93_gpio_set(STB_GRP, STB_PIN, HIGH);
  // Set the clock low (since data is latched on the rising edge)
  w55fa93_gpio_set(CLK_GRP, CLK_PIN, LOW);
}

void kio_write(unsigned char data)
{
  int bit;

  // Set the DIO to an output
  w55fa93_gpio_set_output(DIO_GRP, DIO_PIN);

  for(bit = 0; bit < 8; bit++) {
    // Set the clock to low
    w55fa93_gpio_set(CLK_GRP, CLK_PIN, LOW);
    // Put the correct bit LSB-first onto DIO
    w55fa93_gpio_set(DIO_GRP, DIO_PIN, (data >> bit) & 1);
    // Wait for the pins to settle
    usleep(SIF_CLP);
    // Rise the clock
    w55fa93_gpio_set(CLK_GRP, CLK_PIN, HIGH);
    // Wait for the second half of the clock period
    usleep(SIF_CLP);
  }
}

unsigned char kio_read(void)
{
  int bit;
  unsigned char word = 0;

  // Set the DIO to an input
  w55fa93_gpio_set_input(DIO_GRP, DIO_PIN);

  for(bit = 0; bit < 8; bit++) {
    // Set the clock to low
    w55fa93_gpio_set(CLK_GRP, CLK_PIN, LOW);
    // Wait for the pins to settle
    usleep(SIF_CLP);
    // Read the current bit LSB-first on DIO and store it
    if(w55fa93_gpio_get(DIO_GRP, DIO_PIN))
      word |= (1 << bit);
    // Rise the clock again
    w55fa93_gpio_set(CLK_GRP, CLK_PIN, HIGH);
  }
}

unsigned int kio_keys(void)
{
  int word, buffer = 0;

  // Start the transfer
  kio_begin_transaction();
  // Transmit the instruction byte
  kio_write(INS_RKR);
  // Wait until the device is surely ready
  usleep(SIF_TTD);
  // Read 4 bytes to buf: [MSB] W0W1W2W3 [LSB]
  for(word = 0; word < 4; word++)
    buffer = (buffer << 8) | (kio_read() & 0xFF);
  // End the transfer
  kio_end_transaction();
  // Return the buffer
  return buffer;
}
