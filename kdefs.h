/*
  pdkeypad
  An open-source reimplementation of the Pandora keypad driver
  (c) 2017 0xbmuessig, bmuessig.eu

  kdefs.h: Physical key definitions for the DDCSV1.1
*/

#ifndef KDEFS_H
#define KDEFS_H

#include "kio.h"

#define PHYK_FRO       KEY(K2, KS2)
#define PHYK_SELECT    KEY(K1, KS2)
#define PHYK_2ND       KEY(K2, KS3)
#define PHYK_MODIFY    KEY(K1, KS3)
#define PHYK_MODE      KEY(K2, KS4)
#define PHYK_CANCEL    KEY(K1, KS4)
#define PHYK_ENTER     KEY(K1, KS5)
#define PHYK_UP        KEY(K2, KS5)
#define PHYK_DOWN      KEY(K2, KS6)
#define PHYK_LEFT      KEY(K3, KS2)
#define PHYK_RIGHT     KEY(K1, KS6)
#define PHYK_START     KEY(K3, KS8)
#define PHYK_PAUSE     KEY(K3, KS7)
#define PHYK_RST       KEY(K3, KS6)
#define PHYK_PAGE      KEY(K3, KS5)
#define PHYK_TOOLPATH  KEY(K3, KS4)
#define PHYK_SPINDLE   KEY(K3, KS3)

#endif
