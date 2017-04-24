#ifndef DEAMON_H
#define DEAMON_H

#include "kio.h"
#include "kdefs.h"
#include "idefs.h"

int init_deamon(char* uinput_dev);
void deinit_deamon(void);
void run_deamon(void);

#endif
