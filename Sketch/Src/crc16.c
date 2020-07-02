#include <stdio.h>
#include <stdint.h>

static uint32_t crc_bytecalc(uint8_t byte, uint32_t crc, uint32_t polynom, uint32_t poly_width)
{
    // mask bit for poly msb
    const uint32_t msb  = (1uL << (poly_width - 1u));
    // Mask rg. to poly width
    const uint32_t mask = (poly_width < 32u) ? ~((uint32_t)((~0uL) << poly_width)) : 0xFFFFFFFFu; /* polyspace DEFECT:UINT_OVFL MISRA-C3:D4.1 [Not a defect:Low] "Intended behaviour" */
    // Calculate xor value for current byte
    const uint8_t byte_to_calc = (uint8_t)((crc >> (poly_width - 8u)) ^ byte);
    uint32_t xor_value = (uint32_t)byte_to_calc << (poly_width - 8u);
    for (uint32_t i = 0u; i < 8; ++i) {
        if ((xor_value & msb) != 0u) {
            //crc = (crc>>1)^polynom;
            xor_value = ((xor_value << 1u) ^ polynom) & mask; /* polyspace DEFECT:UINT_OVFL MISRA-C3:D4.1 [Not a defect:Low] "Intended behaviour" */
        } else {
            xor_value = (xor_value << 1u) & mask;
        }
    }
    // Now do the CRC calculation
    return ((crc << 8u) ^ xor_value) & mask; /* polyspace DEFECT:UINT_OVFL MISRA-C3:D4.1 [Not a defect:Low] "Intended behaviour" */
}

static uint16_t crc16_w1(uint16_t data, uint16_t crc, uint32_t polynom, uint32_t poly_width)
{
    uint32_t crc_ret = crc_bytecalc((uint8_t)((data >> 0u) & 0xFFu), crc, polynom, poly_width);
    crc_ret = crc_bytecalc((uint8_t)((data >> 8u) & 0xFFu), crc_ret, polynom, poly_width);
    return (uint16_t)crc_ret;
}

static uint16_t calc_crc16_sw(uint16_t const * p_data, uint16_t data_length)
{
//    uint16_t crc  = 0xffffu;
    uint16_t crc1 = 0xffffu;

//    for(uint32_t i=0u; i<256u;i+=8u) {
//        for(uint32_t j=0u; j<8u;j++) {
//            const uint16_t res = (uint16_t)crc_bytecalc((uint8_t)(i+j), 0u, 0x1021u, 16u);
//            //if (ccitt_16[i+j]!=res) {
//            //    break;
//            //}
//            DEBUG_PRINT("0x%04X ", res);
//        }
//        DEBUG_PRINT("\n");
//    }
    for (uint32_t i = 0u; i < data_length; i++) {
//        crc = crc16_w(p_data[i], crc);
        crc1 = crc16_w1(p_data[i], crc1, 0x1021u, 16u);
    }
    //DEBUG_PRINT("final CRC16: 0x%04X: / 0x%04X:\n", crc, crc1);


    return crc1;
}

int main (void)
{
    const uint16_t data = 123456789;
    printf("%x", calc_crc16_sw(&data, 16));

    return 0;
}
