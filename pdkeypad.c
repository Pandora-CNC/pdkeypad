#include "pdkeypad.h"

int main(unsigned int argc, char* argv[]) {
  int fd = open("/dev/input/uinput", O_WRONLY | O_NONBLOCK);

  return 0;
}
