#ifndef __OLED_H__
#define __OLED_H__ 

#include <main.h>
#include "stdlib.h"	
#include "stdint.h"

//-----------------OLED�˿ڶ���---------------- 

#define OLED_D0_GPIO_Port OLED_GPIO_GRP_PORT
#define OLED_D0_Pin OLED_GPIO_GRP_OLED_D0_PIN
#define OLED_D1_GPIO_Port OLED_GPIO_GRP_PORT
#define OLED_D1_Pin OLED_GPIO_GRP_PORT
#define OLED_RES_GPIO_Port OLED_GPIO_GRP_PORT
#define OLED_RES_Pin OLED_GPIO_GRP_OLED_RES_PIN
#define OLED_DC_GPIO_Port OLED_GPIO_GRP_PORT
#define OLED_DC_Pin OLED_GPIO_GRP_OLED_DC_PIN
#define OLED_CS_GPIO_Port OLED_GPIO_GRP_PORT
#define OLED_CS_Pin OLED_GPIO_GRP_OLED_CS_PIN
#define RESET 0
#define SET 1

//�˴��ĳ��Լ��趨�Ķ˿�
//����ʹ��MX�Դ�SPI��ֱ�����ö˿�Ϊ�������������Ĭ�ϸߵ�ƽ����
//ʹ�ã�
//include "oled.h"���ɣ���Ҫ��include "oledfont.h"
//����Init��ʹ��ShowString�Ⱥ����������Refresh���������򲻻���ʾ

#define OLED_SCL_Clr() DL_GPIO_clearPins(OLED_GPIO_GRP_PORT, OLED_GPIO_GRP_OLED_D0_PIN)//SCL������D0
#define OLED_SCL_Set() DL_GPIO_setPins(OLED_GPIO_GRP_PORT, OLED_GPIO_GRP_OLED_D0_PIN)

#define OLED_SDA_Clr() DL_GPIO_clearPins(OLED_GPIO_GRP_PORT, OLED_GPIO_GRP_OLED_D1_PIN)//SDA������D1
#define OLED_SDA_Set() DL_GPIO_setPins(OLED_GPIO_GRP_PORT, OLED_GPIO_GRP_OLED_D1_PIN)

#define OLED_RES_Clr() DL_GPIO_clearPins(OLED_GPIO_GRP_PORT, OLED_GPIO_GRP_OLED_RES_PIN)//RES
#define OLED_RES_Set() DL_GPIO_setPins(OLED_GPIO_GRP_PORT, OLED_GPIO_GRP_OLED_RES_PIN)

#define OLED_DC_Clr()  DL_GPIO_clearPins(OLED_GPIO_GRP_PORT, OLED_GPIO_GRP_OLED_DC_PIN)//DC
#define OLED_DC_Set()  DL_GPIO_setPins(OLED_GPIO_GRP_PORT, OLED_GPIO_GRP_OLED_DC_PIN)

#define OLED_CS_Clr()  DL_GPIO_clearPins(OLED_GPIO_GRP_PORT, OLED_GPIO_GRP_OLED_CS_PIN)//CS
#define OLED_CS_Set()  DL_GPIO_setPins(OLED_GPIO_GRP_PORT, OLED_GPIO_GRP_OLED_CS_PIN)

#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t

#define OLED_CMD  0	//д����
#define OLED_DATA 1	//д����

void OLED_ClearPoint(u8 x,u8 y);
void OLED_ColorTurn(u8 i);
void OLED_DisplayTurn(u8 i);
void OLED_WR_Byte(u8 dat,u8 mode);
void OLED_DisPlay_On(void);
void OLED_DisPlay_Off(void);
void OLED_Refresh(void);
void OLED_Clear(void);
void OLED_Interval_On(void);
void OLED_Dot_All_On(void);
void OLED_DrawPoint(u8 x,u8 y,u8 t);
void OLED_DrawLine(u8 x1,u8 y1,u8 x2,u8 y2,u8 mode);
void OLED_DrawCircle(u8 x,u8 y,u8 r);
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 size1,u8 mode);
void OLED_ShowChar6x8(u8 x,u8 y,u8 chr,u8 mode);
void OLED_ShowString(u8 x,u8 y,u8 *chr,u8 size1,u8 mode);
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size1,u8 mode);
void OLED_ShowChinese(u8 x,u8 y,u8 num,u8 size1,u8 mode);
void OLED_ScrollDisplay(u8 num,u8 space,u8 mode);
void OLED_ShowPicture(u8 x,u8 y,u8 sizex,u8 sizey,u8 BMP[],u8 mode);
void OLED_Init(void);

#endif

