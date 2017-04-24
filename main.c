#include "main.h"

// Application entry point
int main(unsigned int argc, char* argv[])
{
  // For testing, just init the test
  if(!init_test())
    return 1;

  // Run the test
  run_test();

  return 0;
}
