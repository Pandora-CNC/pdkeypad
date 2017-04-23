/*
  pdkeypad
  An open-source reimplementation of the Pandora keypad driver
  (c) 2017 0xbmuessig, bmuessig.eu

  kio.h: Keypad I/O header
*/

#ifndef KIO_H
#define KIO_H

#include <mach/w55fa93_gpio.h>
#include <unistd.h>

// For readability, define HIGH and LOW constants
#define HIGH 1
#define LOW 0

// Key columns
#define K1 2
#define K2 1
#define K3 0

// Key rows
#define KS1 28
#define KS2 24
#define KS3 20
#define KS4 16
#define KS5 12
#define KS6 8
#define KS7 4
#define KS8 0

// Macro to get key bit offset
#define KEY(K, KS) ((KS) + (K))

// Macro to test if key is pressed
#define KEY_TEST(KEY, VAL) (((unsigned int)(VAL)) >> (KEY) & 1)

// Read keys instruction
#define INS_RKR 0x42

// Duration in usecs until the serial interface is ready
#define SIF_TTI 1
// Duration in usecs for the clock pulse
#define SIF_CLP 1
// Duration in usecs for the data to appear
#define SIF_TTD 1

// DIO (digital I/O) I/O definition
#define DIO_GRP GPIO_GROUP_D
#define DIO_PIN 0
// CLK (clock) I/O definition
#define CLK_GRP GPIO_GROUP_D
#define CLK_PIN 1
// STB (chip select) I/O definition
#define STB_GRP GPIO_GROUP_D
#define STB_PIN 2

// TODO: Find out, what UK0 and UK1 do
#define UK0_GRP GPIO_GROUP_D
#define UK0_PIN 12
#define UK1_GRP GPIO_GROUP_D
#define UK1_PIN 13

void kio_init(void);
void kio_deinit(void);
void kio_begin_transaction(void);
void kio_end_transaction(void);
void kio_write(unsigned char data);
unsigned char kio_read(void);
unsigned int kio_keys(void);

#endif
