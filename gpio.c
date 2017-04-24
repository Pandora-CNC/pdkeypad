#include "gpio.h"

const int gpio_reg_dir[5] = { REG_GPIOA_OMD, REG_GPIOB_OMD, REG_GPIOC_OMD, REG_GPIOD_OMD, REG_GPIOE_OMD};
const int gpio_reg_out[5] = { REG_GPIOA_DOUT, REG_GPIOB_DOUT, REG_GPIOC_DOUT, REG_GPIOD_DOUT, REG_GPIOE_DOUT};
const int gpio_reg_in[5] = { REG_GPIOA_PIN, REG_GPIOB_PIN, REG_GPIOC_PIN, REG_GPIOD_PIN, REG_GPIOE_PIN};

int memfd;
int *pIoBuffer, *pSetBuffer;

int w55fa93_gpio_init(void)
{
  if(!(memfd = open("/dev/mem", O_RDWR))) {
    fprintf(stderr, "ERR: Failed to open /dev/mem!\n");
    return false;
  }

  if(!(pSetBuffer = mmap(0, 0x1000, PROT_READ | PROT_WRITE,
    MAP_LOCKED | MAP_SHARED, memfd, 0xB8000000))) {
    fprintf(stderr, "ERR: Failed to map primary GPIO memory!\n");
    close(memfd);
    return false;
  }

  if(!(pIoBuffer = mmap(0, 0x1000, PROT_READ | PROT_WRITE,
    MAP_LOCKED | MAP_SHARED, memfd, 0xB8001000))) {
    fprintf(stderr, "ERR: Failed to map secondary GPIO memory!\n");
    close(memfd);
    return false;
  }

  return true;
}

void w55fa93_gpio_deinit(void)
{
  munmap(pIoBuffer, 0x1000);
  munmap(pSetBuffer, 0x1000);
  close(memfd);
}

int w55fa93_gpio_get(int group, int num)
{
  return (*((unsigned int*)(gpio_reg_in[group] + pIoBuffer))) & (1 << num) ? 1 : 0;
}

void w55fa93_gpio_set_input(int group, int num)
{
  *((unsigned int*)(gpio_reg_dir[group] + pIoBuffer)) &= ~(1 << num);
}

void w55fa93_gpio_set_output(int group, int num)
{
  *((unsigned int*)(gpio_reg_dir[group] + pIoBuffer)) |= (1 << num);
}

void w55fa93_gpio_set(int group, int num, int state)
{
  if(state)
    *((unsigned int*)(gpio_reg_out[group] + pIoBuffer)) |= (1 << num);
  else
    *((unsigned int*)(gpio_reg_out[group] + pIoBuffer)) &= ~(1 << num);
}

int w55fa93_gpio_configure(int group, int num)
{
	if(num > 16)
		return 0;

	switch(group) {
		case GPIO_GROUP_A:
			if(num > 11)
				return 0;
      *((unsigned int*)(REG_GPAFUN + pSetBuffer)) &= ~(0x3 << (num << 1));
		break;
		case GPIO_GROUP_B:
      *((unsigned int*)(REG_GPBFUN + pSetBuffer)) &= ~(0x3 << (num << 1));
		break;
		case GPIO_GROUP_C:
      *((unsigned int*)(REG_GPCFUN + pSetBuffer)) &= ~(0x3 << (num << 1));
		break;
		case GPIO_GROUP_D:
      *((unsigned int*)(REG_GPDFUN + pSetBuffer)) &= ~(0x3 << (num << 1));
		break;
		case GPIO_GROUP_E:
			if(num > 11)
				return 0;
      *((unsigned int*)(REG_GPEFUN + pSetBuffer)) &= ~(0x3 << (num << 1));
		break;
		default:
			return 0;
	}

	w55fa93_gpio_set_output(group, num);
	return 1;
}
