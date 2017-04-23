#ifndef PDKEYPAD_H
#define PDKEYPAD_H

#include <linux/input.h>
#include <linux/uinput.h>

#include "kio.h"
#include "phykeydefs.h"
#include "pdkeydefs.h"

#define UINPUT_DEVICE "/dev/input/uinput"

int main(unsigned int argc, char* argv[]);
int init(char uinput_dev);

#endif
