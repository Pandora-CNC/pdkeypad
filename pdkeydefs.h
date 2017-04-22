/*
  pdkeypad
  An open-source reimplementation of the Pandora keypad driver
  (c) 2017 0xbmuessig, bmuessig.eu

  phykeydefs.h: Virtal scan code key definitions for the DDCSV1.1
*/

#ifndef PDKEYDEFS_H
#define PDKEYDEFS_H

#include <linux/input.h>

#define K_FRO       KEY_F1
#define K_SELECT    KEY_F2
#define K_2ND       KEY_LEFTSHIFT
#define K_MODIFY    KEY_F3
#define K_MODE      KEY_F4
#define K_CANCEL    KEY_ESC
#define K_ENTER     KEY_ENTER
#define K_UP        KEY_UP
#define K_DOWN      KEY_DOWN
#define K_LEFT      KEY_LEFT
#define K_RIGHT     KEY_RIGHT
#define K_START     KEY_PLAY
#define K_PAUSE     KEY_PAUSE
#define K_RST       KEY_STOP
#define K_PAGE      KEY_TAB
#define K_TOOLPATH  KEY_F5
#define K_SPINDLE   KEY_F6

#endif
