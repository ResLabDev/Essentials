#include "main.h"

static int test = 8;

int main (int argc, char **argv)
{
    // SPI_Send();
    // CycleTest();

	char buffer[] = "HELLO FROM SPI1";
	uint8_t *p_buffer = (uint8_t *)buffer;
	char receive = '0';
	p_buffer = (uint8_t *)(&receive);
	*p_buffer = buffer[0];
	printf("%c\n", receive);

	const uint32_t reg = 0xfefefefe;
	const uint32_t data = 0xabababab;
	uint8_t readReg = reg & (1 << 1);
	uint8_t readData = data & (1 << 3);

	printf("%x, %x\n", readReg, readData);

	printf("Test: %d\n", test);
	test *= 2;
	printf("Test: %d\n", test);

    return 0;
}
