#ifndef GPIO_H
#define GPIO_H

#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdbool.h>

#define GPIO_GROUP_A 0
#define GPIO_GROUP_B 1
#define GPIO_GROUP_C 2
#define GPIO_GROUP_D 3
#define GPIO_GROUP_E 4

#define REG_GPIOA_OMD 0
#define REG_GPIOB_OMD 16
#define REG_GPIOC_OMD 32
#define REG_GPIOD_OMD 48
#define REG_GPIOE_OMD 64

#define REG_GPIOA_DOUT 8
#define REG_GPIOB_DOUT 24
#define REG_GPIOC_DOUT 40
#define REG_GPIOD_DOUT 56
#define REG_GPIOE_DOUT 72

#define REG_GPIOA_PIN 12
#define REG_GPIOB_PIN 28
#define REG_GPIOC_PIN 44
#define REG_GPIOD_PIN 60
#define REG_GPIOE_PIN 76

#define REG_GPAFUN 128
#define REG_GPBFUN 132
#define REG_GPCFUN 136
#define REG_GPDFUN 140
#define REG_GPEFUN 144

int w55fa93_gpio_init(void);
void w55fa93_gpio_deinit(void);
int w55fa93_gpio_get(int group, int num);
void w55fa93_gpio_set_input(int group, int num);
void w55fa93_gpio_set_output(int group, int num);
void w55fa93_gpio_set(int group, int num, int state);
int w55fa93_gpio_configure(int group, int num);

#endif
