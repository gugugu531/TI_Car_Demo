/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X
#define CONFIG_MSPM0G3507

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)



#define CPUCLK_FREQ                                                     80000000



/* Defines for MOTOR_PWM */
#define MOTOR_PWM_INST                                                     TIMA0
#define MOTOR_PWM_INST_IRQHandler                               TIMA0_IRQHandler
#define MOTOR_PWM_INST_INT_IRQN                                 (TIMA0_INT_IRQn)
#define MOTOR_PWM_INST_CLK_FREQ                                         40000000
/* GPIO defines for channel 2 */
#define GPIO_MOTOR_PWM_C2_PORT                                             GPIOB
#define GPIO_MOTOR_PWM_C2_PIN                                     DL_GPIO_PIN_12
#define GPIO_MOTOR_PWM_C2_IOMUX                                  (IOMUX_PINCM29)
#define GPIO_MOTOR_PWM_C2_IOMUX_FUNC                 IOMUX_PINCM29_PF_TIMA0_CCP2
#define GPIO_MOTOR_PWM_C2_IDX                                DL_TIMER_CC_2_INDEX
/* GPIO defines for channel 2 */
#define GPIO_MOTOR_PWM_C2_CMPL_PORT                                        GPIOA
#define GPIO_MOTOR_PWM_C2_CMPL_PIN                                DL_GPIO_PIN_11
#define GPIO_MOTOR_PWM_C2_CMPL_IOMUX                             (IOMUX_PINCM22)
#define GPIO_MOTOR_PWM_C2_CMPL_IOMUX_FUNC        IOMUX_PINCM22_PF_TIMA0_CCP2_CMPL

/* GPIO defines for channel 3 */
#define GPIO_MOTOR_PWM_C3_PORT                                             GPIOB
#define GPIO_MOTOR_PWM_C3_PIN                                     DL_GPIO_PIN_13
#define GPIO_MOTOR_PWM_C3_IOMUX                                  (IOMUX_PINCM30)
#define GPIO_MOTOR_PWM_C3_IOMUX_FUNC                 IOMUX_PINCM30_PF_TIMA0_CCP3
#define GPIO_MOTOR_PWM_C3_IDX                                DL_TIMER_CC_3_INDEX
/* GPIO defines for channel 3 */
#define GPIO_MOTOR_PWM_C3_CMPL_PORT                                        GPIOA
#define GPIO_MOTOR_PWM_C3_CMPL_PIN                                DL_GPIO_PIN_18
#define GPIO_MOTOR_PWM_C3_CMPL_IOMUX                             (IOMUX_PINCM40)
#define GPIO_MOTOR_PWM_C3_CMPL_IOMUX_FUNC        IOMUX_PINCM40_PF_TIMA0_CCP3_CMPL





/* Defines for ENCODER_QEI */
#define ENCODER_QEI_INST                                                   TIMG8
#define ENCODER_QEI_INST_IRQHandler                             TIMG8_IRQHandler
#define ENCODER_QEI_INST_INT_IRQN                               (TIMG8_INT_IRQn)
/* Pin configuration defines for ENCODER_QEI PHA Pin */
#define GPIO_ENCODER_QEI_PHA_PORT                                          GPIOA
#define GPIO_ENCODER_QEI_PHA_PIN                                   DL_GPIO_PIN_1
#define GPIO_ENCODER_QEI_PHA_IOMUX                                (IOMUX_PINCM2)
#define GPIO_ENCODER_QEI_PHA_IOMUX_FUNC               IOMUX_PINCM2_PF_TIMG8_CCP0
/* Pin configuration defines for ENCODER_QEI PHB Pin */
#define GPIO_ENCODER_QEI_PHB_PORT                                          GPIOA
#define GPIO_ENCODER_QEI_PHB_PIN                                   DL_GPIO_PIN_0
#define GPIO_ENCODER_QEI_PHB_IOMUX                                (IOMUX_PINCM1)
#define GPIO_ENCODER_QEI_PHB_IOMUX_FUNC               IOMUX_PINCM1_PF_TIMG8_CCP1



/* Defines for I2C_MPU6050 */
#define I2C_MPU6050_INST                                                    I2C1
#define I2C_MPU6050_INST_IRQHandler                              I2C1_IRQHandler
#define I2C_MPU6050_INST_INT_IRQN                                  I2C1_INT_IRQn
#define I2C_MPU6050_BUS_SPEED_HZ                                          400000
#define GPIO_I2C_MPU6050_SDA_PORT                                          GPIOB
#define GPIO_I2C_MPU6050_SDA_PIN                                   DL_GPIO_PIN_3
#define GPIO_I2C_MPU6050_IOMUX_SDA                               (IOMUX_PINCM16)
#define GPIO_I2C_MPU6050_IOMUX_SDA_FUNC                IOMUX_PINCM16_PF_I2C1_SDA
#define GPIO_I2C_MPU6050_SCL_PORT                                          GPIOB
#define GPIO_I2C_MPU6050_SCL_PIN                                   DL_GPIO_PIN_2
#define GPIO_I2C_MPU6050_IOMUX_SCL                               (IOMUX_PINCM15)
#define GPIO_I2C_MPU6050_IOMUX_SCL_FUNC                IOMUX_PINCM15_PF_I2C1_SCL



/* Port definition for Pin Group GPIO_MPU6050 */
#define GPIO_MPU6050_PORT                                                (GPIOB)

/* Defines for PIN_MPU6050_INT: GPIOB.23 with pinCMx 51 on package pin 22 */
// groups represented: ["KEY_GRP","GPIO_MPU6050"]
// pins affected: ["KEY0","KEY1","KEY2","PIN_MPU6050_INT"]
#define GPIO_MULTIPLE_GPIOB_INT_IRQN                            (GPIOB_INT_IRQn)
#define GPIO_MULTIPLE_GPIOB_INT_IIDX            (DL_INTERRUPT_GROUP1_IIDX_GPIOB)
#define GPIO_MPU6050_PIN_MPU6050_INT_IIDX                   (DL_GPIO_IIDX_DIO23)
#define GPIO_MPU6050_PIN_MPU6050_INT_PIN                        (DL_GPIO_PIN_23)
#define GPIO_MPU6050_PIN_MPU6050_INT_IOMUX                       (IOMUX_PINCM51)
/* Port definition for Pin Group OLED_GPIO_GRP */
#define OLED_GPIO_GRP_PORT                                               (GPIOB)

/* Defines for OLED_D0: GPIOB.9 with pinCMx 26 on package pin 61 */
#define OLED_GPIO_GRP_OLED_D0_PIN                                (DL_GPIO_PIN_9)
#define OLED_GPIO_GRP_OLED_D0_IOMUX                              (IOMUX_PINCM26)
/* Defines for OLED_D1: GPIOB.8 with pinCMx 25 on package pin 60 */
#define OLED_GPIO_GRP_OLED_D1_PIN                                (DL_GPIO_PIN_8)
#define OLED_GPIO_GRP_OLED_D1_IOMUX                              (IOMUX_PINCM25)
/* Defines for OLED_RES: GPIOB.10 with pinCMx 27 on package pin 62 */
#define OLED_GPIO_GRP_OLED_RES_PIN                              (DL_GPIO_PIN_10)
#define OLED_GPIO_GRP_OLED_RES_IOMUX                             (IOMUX_PINCM27)
/* Defines for OLED_DC: GPIOB.11 with pinCMx 28 on package pin 63 */
#define OLED_GPIO_GRP_OLED_DC_PIN                               (DL_GPIO_PIN_11)
#define OLED_GPIO_GRP_OLED_DC_IOMUX                              (IOMUX_PINCM28)
/* Defines for OLED_CS: GPIOB.14 with pinCMx 31 on package pin 2 */
#define OLED_GPIO_GRP_OLED_CS_PIN                               (DL_GPIO_PIN_14)
#define OLED_GPIO_GRP_OLED_CS_IOMUX                              (IOMUX_PINCM31)
/* Defines for GS_PIN_0: GPIOA.27 with pinCMx 60 on package pin 31 */
#define GRAY_SENSOR_GRP_GS_PIN_0_PORT                                    (GPIOA)
#define GRAY_SENSOR_GRP_GS_PIN_0_PIN                            (DL_GPIO_PIN_27)
#define GRAY_SENSOR_GRP_GS_PIN_0_IOMUX                           (IOMUX_PINCM60)
/* Defines for GS_PIN_1: GPIOA.24 with pinCMx 54 on package pin 25 */
#define GRAY_SENSOR_GRP_GS_PIN_1_PORT                                    (GPIOA)
#define GRAY_SENSOR_GRP_GS_PIN_1_PIN                            (DL_GPIO_PIN_24)
#define GRAY_SENSOR_GRP_GS_PIN_1_IOMUX                           (IOMUX_PINCM54)
/* Defines for GS_PIN_2: GPIOB.24 with pinCMx 52 on package pin 23 */
#define GRAY_SENSOR_GRP_GS_PIN_2_PORT                                    (GPIOB)
#define GRAY_SENSOR_GRP_GS_PIN_2_PIN                            (DL_GPIO_PIN_24)
#define GRAY_SENSOR_GRP_GS_PIN_2_IOMUX                           (IOMUX_PINCM52)
/* Defines for GS_PIN_3: GPIOB.25 with pinCMx 56 on package pin 27 */
#define GRAY_SENSOR_GRP_GS_PIN_3_PORT                                    (GPIOB)
#define GRAY_SENSOR_GRP_GS_PIN_3_PIN                            (DL_GPIO_PIN_25)
#define GRAY_SENSOR_GRP_GS_PIN_3_IOMUX                           (IOMUX_PINCM56)
/* Defines for GS_PIN_4: GPIOA.22 with pinCMx 47 on package pin 18 */
#define GRAY_SENSOR_GRP_GS_PIN_4_PORT                                    (GPIOA)
#define GRAY_SENSOR_GRP_GS_PIN_4_PIN                            (DL_GPIO_PIN_22)
#define GRAY_SENSOR_GRP_GS_PIN_4_IOMUX                           (IOMUX_PINCM47)
/* Defines for GS_PIN_5: GPIOB.20 with pinCMx 48 on package pin 19 */
#define GRAY_SENSOR_GRP_GS_PIN_5_PORT                                    (GPIOB)
#define GRAY_SENSOR_GRP_GS_PIN_5_PIN                            (DL_GPIO_PIN_20)
#define GRAY_SENSOR_GRP_GS_PIN_5_IOMUX                           (IOMUX_PINCM48)
/* Defines for GS_PIN_6: GPIOA.15 with pinCMx 37 on package pin 8 */
#define GRAY_SENSOR_GRP_GS_PIN_6_PORT                                    (GPIOA)
#define GRAY_SENSOR_GRP_GS_PIN_6_PIN                            (DL_GPIO_PIN_15)
#define GRAY_SENSOR_GRP_GS_PIN_6_IOMUX                           (IOMUX_PINCM37)
/* Defines for GS_PIN_7: GPIOA.14 with pinCMx 36 on package pin 7 */
#define GRAY_SENSOR_GRP_GS_PIN_7_PORT                                    (GPIOA)
#define GRAY_SENSOR_GRP_GS_PIN_7_PIN                            (DL_GPIO_PIN_14)
#define GRAY_SENSOR_GRP_GS_PIN_7_IOMUX                           (IOMUX_PINCM36)
/* Defines for LED_G: GPIOB.22 with pinCMx 50 on package pin 21 */
#define LED_GRP_LED_G_PORT                                               (GPIOB)
#define LED_GRP_LED_G_PIN                                       (DL_GPIO_PIN_22)
#define LED_GRP_LED_G_IOMUX                                      (IOMUX_PINCM50)
/* Defines for LED1: GPIOA.13 with pinCMx 35 on package pin 6 */
#define LED_GRP_LED1_PORT                                                (GPIOA)
#define LED_GRP_LED1_PIN                                        (DL_GPIO_PIN_13)
#define LED_GRP_LED1_IOMUX                                       (IOMUX_PINCM35)
/* Defines for LED2: GPIOA.12 with pinCMx 34 on package pin 5 */
#define LED_GRP_LED2_PORT                                                (GPIOA)
#define LED_GRP_LED2_PIN                                        (DL_GPIO_PIN_12)
#define LED_GRP_LED2_IOMUX                                       (IOMUX_PINCM34)
/* Defines for LED3: GPIOA.29 with pinCMx 4 on package pin 36 */
#define LED_GRP_LED3_PORT                                                (GPIOA)
#define LED_GRP_LED3_PIN                                        (DL_GPIO_PIN_29)
#define LED_GRP_LED3_IOMUX                                        (IOMUX_PINCM4)
/* Port definition for Pin Group KEY_GRP */
#define KEY_GRP_PORT                                                     (GPIOB)

/* Defines for KEY0: GPIOB.21 with pinCMx 49 on package pin 20 */
#define KEY_GRP_KEY0_IIDX                                   (DL_GPIO_IIDX_DIO21)
#define KEY_GRP_KEY0_PIN                                        (DL_GPIO_PIN_21)
#define KEY_GRP_KEY0_IOMUX                                       (IOMUX_PINCM49)
/* Defines for KEY1: GPIOB.7 with pinCMx 24 on package pin 59 */
#define KEY_GRP_KEY1_IIDX                                    (DL_GPIO_IIDX_DIO7)
#define KEY_GRP_KEY1_PIN                                         (DL_GPIO_PIN_7)
#define KEY_GRP_KEY1_IOMUX                                       (IOMUX_PINCM24)
/* Defines for KEY2: GPIOB.6 with pinCMx 23 on package pin 58 */
#define KEY_GRP_KEY2_IIDX                                    (DL_GPIO_IIDX_DIO6)
#define KEY_GRP_KEY2_PIN                                         (DL_GPIO_PIN_6)
#define KEY_GRP_KEY2_IOMUX                                       (IOMUX_PINCM23)
/* Port definition for Pin Group MOTORA_GRP */
#define MOTORA_GRP_PORT                                                  (GPIOA)

/* Defines for AIN_1: GPIOA.17 with pinCMx 39 on package pin 10 */
#define MOTORA_GRP_AIN_1_PIN                                    (DL_GPIO_PIN_17)
#define MOTORA_GRP_AIN_1_IOMUX                                   (IOMUX_PINCM39)
/* Defines for AIN_2: GPIOA.16 with pinCMx 38 on package pin 9 */
#define MOTORA_GRP_AIN_2_PIN                                    (DL_GPIO_PIN_16)
#define MOTORA_GRP_AIN_2_IOMUX                                   (IOMUX_PINCM38)
/* Port definition for Pin Group MOTORB_GRP */
#define MOTORB_GRP_PORT                                                  (GPIOB)

/* Defines for BIN_1: GPIOB.18 with pinCMx 44 on package pin 15 */
#define MOTORB_GRP_BIN_1_PIN                                    (DL_GPIO_PIN_18)
#define MOTORB_GRP_BIN_1_IOMUX                                   (IOMUX_PINCM44)
/* Defines for BIN_2: GPIOB.17 with pinCMx 43 on package pin 14 */
#define MOTORB_GRP_BIN_2_PIN                                    (DL_GPIO_PIN_17)
#define MOTORB_GRP_BIN_2_IOMUX                                   (IOMUX_PINCM43)

/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_MOTOR_PWM_init(void);
void SYSCFG_DL_ENCODER_QEI_init(void);
void SYSCFG_DL_I2C_MPU6050_init(void);


bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
