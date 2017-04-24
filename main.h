#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <linux/input.h>
#include <linux/uinput.h>

#include "deamon.h"
#include "test.h"

#define UINPUT_DEVICE "/dev/input/uinput"

int main(unsigned int argc, char* argv[]);

#endif
