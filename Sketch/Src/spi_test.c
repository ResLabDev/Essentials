#include "main.h"

#define DFF_8BIT        0
#define DFF_16BIT       1

void SPI_Send (void)
{
    char buffer[] = "HELLO FROM SPI1";
    uint8_t *p_TxBuffer = (uint8_t *)buffer;
    uint32_t len = strlen(buffer);
    uint8_t dff = DFF_16BIT;
    uint16_t spiDR;

    uint8_t log[20][2];

    printf("%d\n", (int)DIM_OF(log));

    printf("Buffer size: %u\n", len);
    spiDR = *(uint16_t *)p_TxBuffer;

    printf("%c|%c\n", (char)(spiDR & 0xff), (char)((spiDR >> 8) & 0xff));

    // (uint16_t *)p_TxBuffer++;   // ==> DOES NOT WORK!!!
    (*(uint16_t **)&p_TxBuffer)++;

    spiDR = *(uint16_t *)p_TxBuffer;
    printf("%c|%c\n", (char)(spiDR & 0xff), (char)((spiDR >> 8) & 0xff));

    puts("");
    p_TxBuffer = (uint8_t *)buffer;
    while (len)
	{
		if (dff)
		{
			// 2 Bytes Data Frame Format
			if (len != 1)
			{
			    spiDR = *((uint16_t *)p_TxBuffer);
                len--;
                p_TxBuffer++;
			}
			else
            {
                spiDR = (*((uint16_t *)p_TxBuffer)) & 0xff;
            }
			printf("%c%c", (char)(spiDR & 0xff), (char)((spiDR >> 8) & 0xff));
		}
		else
		{
			// 1 Byte Data Frame Format
			spiDR = *((uint16_t *)p_TxBuffer);
			printf("%c", (char)(spiDR & 0xff));
		}

		len--;
        p_TxBuffer++;
	}

	printf("\n%x|%x", (char)(spiDR & 0xff), (char)((spiDR >> 8) & 0xff));
}
