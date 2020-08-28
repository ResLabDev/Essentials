#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

#define MHEADER_MSG_ID_BIT				28u
#define MHEADER_CRI_BIT					24u
#define MHEADER_PARAM_BIT				16u
#define MHEADER_MSG_ID_MASK				(uint8_t)0x0fu
#define MHEADER_MSG_HEADER_PROCESS_MASK	(uint32_t)0x80000000u
#define MHEADER_CRI_MASK				(uint8_t)0x0fu
#define MHEADER_PARAM_MASK				(uint8_t)0xffu
#define MSTATUS_BIT						16u
#define MSG_CMD_LONG_CALL				(uint8_t)1u
#define MSG_CMD_TYPE_MASK				(uint8_t)0x40u

typedef struct {
	uint8_t fw_msg_id;
	uint8_t cri;
	uint8_t param;
} t_msg_header;

typedef struct {
	uint8_t fw_msg_id;
	uint8_t param;
	uint32_t *p_data;
} t_msg;

static t_msg_header header = {0u, 0u, 0u};

static inline t_msg_header MPORT_header_decode(uint32_t const header) {
	t_msg_header ret_header = {0, 0, 0};

	ret_header.fw_msg_id = (header >> MHEADER_MSG_ID_BIT) & MHEADER_MSG_ID_MASK;
	ret_header.cri = (header >> MHEADER_CRI_BIT) & MHEADER_CRI_MASK;
	ret_header.param = (header >> MHEADER_PARAM_BIT) & MHEADER_PARAM_MASK;

	return ret_header;
}

int main (void)
{
    t_msg ret_msg = {0, 0, NULL};
    const uint32_t head = 0x9412abcd;
    header = MPORT_header_decode(0x9412abcdu);

    printf("HEADER PARAM: %x", header.param);
    ret_msg.param = header.param;

    return 0;
}
