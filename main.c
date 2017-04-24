#include "main.h"

// Application entry point
int main(unsigned int argc, char* argv[])
{
  // For testing, just init the deamon
  if(!init_deamon(UINPUT_DEVICE))
    return 1;

  return 0;
}
