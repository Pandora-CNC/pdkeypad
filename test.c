#include "test.h"

int init_test(void)
{
  if(!kio_init()) {
    fprintf(stderr, "ERR: IO-Init failed!\n");
    return false;
  }

  return true;
}

void deinit_test(void)
{
  kio_deinit();
}

void run_test(void)
{
  while(true) {
    unsigned int keys = kio_keys(), i;
    for(i = 0; i < 32; i++)
      printf("%c", ((keys >> i) & 1) ? '1' : '0');
    printf("\n");
    usleep(500000);
  }
}
