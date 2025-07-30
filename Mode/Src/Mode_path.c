// 检测轨迹模组(并行)

#include <main.h>
#include <Mode/Inc/Mode_path.h>

#define ALTERA1 0.5
#define ALTERA2 1.2
#define ALTERA3 4.0
#define INC_ALTERA1 0.5
#define INC_ALTERA2 0.7
#define INC_ALTERA3 1.0
#define INC_ALTERA4 1.5

uint8_t get_TL1(void)
{
    if (DL_GPIO_readPins(GRAY_SENSOR_GRP_GS_PIN_3_PORT, GRAY_SENSOR_GRP_GS_PIN_3_PIN))
        return 1;
    else
        return 0;
}

uint8_t get_TL2(void)
{
    if (DL_GPIO_readPins(GRAY_SENSOR_GRP_GS_PIN_2_PORT, GRAY_SENSOR_GRP_GS_PIN_2_PIN))
        return 1;
    else
        return 0;
}
uint8_t get_TL3(void)
{
    if (DL_GPIO_readPins(GRAY_SENSOR_GRP_GS_PIN_1_PORT, GRAY_SENSOR_GRP_GS_PIN_1_PIN))
        return 1;
    else
        return 0;
}

uint8_t get_TL4(void)
{
    if (DL_GPIO_readPins(GRAY_SENSOR_GRP_GS_PIN_0_PORT, GRAY_SENSOR_GRP_GS_PIN_0_PIN))
        return 1;
    else
        return 0;
}

uint8_t get_TR1(void)
{
    if (DL_GPIO_readPins(GRAY_SENSOR_GRP_GS_PIN_4_PORT, GRAY_SENSOR_GRP_GS_PIN_4_PIN))
        return 1;
    else
        return 0;
}

uint8_t get_TR2(void)
{
    if (DL_GPIO_readPins(GRAY_SENSOR_GRP_GS_PIN_5_PORT, GRAY_SENSOR_GRP_GS_PIN_5_PIN))
        return 1;
    else
        return 0;
}

uint8_t get_TR3(void)
{
    if (DL_GPIO_readPins(GRAY_SENSOR_GRP_GS_PIN_6_PORT, GRAY_SENSOR_GRP_GS_PIN_6_PIN))
        return 1;
    else
        return 0;
}

uint8_t get_TR4(void)
{
    if (DL_GPIO_readPins(GRAY_SENSOR_GRP_GS_PIN_7_PORT, GRAY_SENSOR_GRP_GS_PIN_7_PIN))
        return 1;
    else
        return 0;
}

uint8_t get_T(uint8_t flag)
{
    uint8_t value;
    switch (flag)
    {
    case 1:
        value = get_TL4();
        break;
    case 2:
        value = get_TL3();
        break;
    case 3:
        value = get_TL2();
        break;
    case 4:
        value = get_TL1();
        break;
    case 5:
        value = get_TR1();
        break;
    case 6:
        value = get_TR2();
        break;
    case 7:
        value = get_TR3();
        break;
    case 8:
        value = get_TR4();
        break;
    default:
        break;
    }
    return value;
}

uint8_t get_T_ALL(void)
{
    uint8_t temp = 0;
    temp += get_TL4();
    temp <<= 1;
    temp += get_TL3();
    temp <<= 1;
    temp += get_TL2();
    temp <<= 1;
    temp += get_TL1();
    temp <<= 1;
    temp += get_TR1();
    temp <<= 1;
    temp += get_TR2();
    temp <<= 1;
    temp += get_TR3();
    temp <<= 1;
    temp += get_TR4();
    return temp;
}

uint8_t get_T_Sum(void)
{
    uint8_t sum = 0;
    for (uint8_t i = 0; i < 8; i++)
    {
        sum += get_T(i);
    }
    return sum;
}

float get_Terror(void)
{
    float error;
    uint8_t trace;

    trace = get_T_ALL();

    switch (trace)
    {
    case 0x18:
    case 0x10:
    case 0x08: // 00011000 00010000 00001000正
        error = 0;
        break;
    case 0x30:
    case 0x38: // 00110000 00111000 偏左
        error = -ALTERA1;
        break;
    case 0x60:
    case 0x70:
    case 0x20: // 01100000 01110000 00100000左
        error = -ALTERA2;
        break;
    case 0xC0:
    case 0xE0:
    case 0x80: // 11000000 11100000 10000000更大偏左
        error = -ALTERA3;
        break;
    case 0x0C:
    case 0x1C: // 00001100 00011100 偏右
        error = +ALTERA1;
        break;
    case 0x06:
    case 0x0E:
    case 0x04: // 00000110 00001110 00000100右
        error = +ALTERA2;
        break;
    case 0x03:
    case 0x07:
    case 0x01: // 00000011 00000111 00000001 更大偏右
        error = +ALTERA3;
        break;
    default:
        error = 0;
        break;
    }

    return error;
}