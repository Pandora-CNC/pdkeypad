#ifndef DEAMON_H
#define DEAMON_H

#include <sys/fcntl.h>
#include <sys/ioctl.h>
#include <linux/input.h>
#include <linux/uinput.h>
#include <unistd.h>

#include "kio.h"
#include "kdefs.h"
#include "idefs.h"

int init_deamon(char* uinput_dev);
void deinit_deamon(void);
void run_deamon(void);

#endif
