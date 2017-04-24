#include "deamon.h"

// The uinput file ptr
int uinput_fd;

// Initializes the deamon
int init_deamon(char* uinput_dev)
{
  if(!(uinput_fd = open(uinput_dev, O_WRONLY | O_NONBLOCK))) {
    fprintf(stderr, "ERR: Opening uinput device failed!\n");
    return false;
  }

  int err = 0;

  // Enable press and release synchronisation events
  err |= (ioctl(uinput_fd, UI_SET_EVBIT, EV_KEY) < 0);
  err |= (ioctl(uinput_fd, UI_SET_EVBIT, EV_SYN) < 0);

  if(err) {
    fprintf(stderr, "ERR: Registering uinput events failed!\n");
    return false;
  }

  // Enable events for all keys we care about
  err = (ioctl(uinput_fd, UI_SET_KEYBIT, K_FRO) < 0);
  err |= (ioctl(uinput_fd, UI_SET_KEYBIT, K_SELECT) < 0);
  err |= (ioctl(uinput_fd, UI_SET_KEYBIT, K_2ND) < 0);
  err |= (ioctl(uinput_fd, UI_SET_KEYBIT, K_MODIFY) < 0);
  err |= (ioctl(uinput_fd, UI_SET_KEYBIT, K_MODE) < 0);
  err |= (ioctl(uinput_fd, UI_SET_KEYBIT, K_CANCEL) < 0);
  err |= (ioctl(uinput_fd, UI_SET_KEYBIT, K_ENTER) < 0);
  err |= (ioctl(uinput_fd, UI_SET_KEYBIT, K_UP) < 0);
  err |= (ioctl(uinput_fd, UI_SET_KEYBIT, K_DOWN) < 0);
  err |= (ioctl(uinput_fd, UI_SET_KEYBIT, K_LEFT) < 0);
  err |= (ioctl(uinput_fd, UI_SET_KEYBIT, K_RIGHT) < 0);
  err |= (ioctl(uinput_fd, UI_SET_KEYBIT, K_START) < 0);
  err |= (ioctl(uinput_fd, UI_SET_KEYBIT, K_PAUSE) < 0);
  err |= (ioctl(uinput_fd, UI_SET_KEYBIT, K_RST) < 0);
  err |= (ioctl(uinput_fd, UI_SET_KEYBIT, K_PAGE) < 0);
  err |= (ioctl(uinput_fd, UI_SET_KEYBIT, K_TOOLPATH) < 0);
  err |= (ioctl(uinput_fd, UI_SET_KEYBIT, K_SPINDLE) < 0);

  if(err) {
    fprintf(stderr, "ERR: Registering uinput keys failed!\n");
    return false;
  }

  kio_init();

  return true;
}

// Deinitializes the deamon
void deinit_deamon(void)
{

}

// Runs the deamon
void run_deamon(void)
{

}
