/*
 * Copyright (c) 2023, Texas Instruments Incorporated
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
 *  ============ ti_msp_dl_config.c =============
 *  Configured MSPM0 DriverLib module definitions
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */

#include "ti_msp_dl_config.h"

DL_TimerA_backupConfig gMOTOR_PWMBackup;
DL_TimerG_backupConfig gENCODER_QEIBackup;

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform any initialization needed before using any board APIs
 */
SYSCONFIG_WEAK void SYSCFG_DL_init(void)
{
    SYSCFG_DL_initPower();
    SYSCFG_DL_GPIO_init();
    /* Module-Specific Initializations*/
    SYSCFG_DL_SYSCTL_init();
    SYSCFG_DL_MOTOR_PWM_init();
    SYSCFG_DL_ENCODER_QEI_init();
    SYSCFG_DL_I2C_MPU6050_init();
    /* Ensure backup structures have no valid state */
	gMOTOR_PWMBackup.backupRdy 	= false;
	gENCODER_QEIBackup.backupRdy 	= false;

}
/*
 * User should take care to save and restore register configuration in application.
 * See Retention Configuration section for more details.
 */
SYSCONFIG_WEAK bool SYSCFG_DL_saveConfiguration(void)
{
    bool retStatus = true;

	retStatus &= DL_TimerA_saveConfiguration(MOTOR_PWM_INST, &gMOTOR_PWMBackup);
	retStatus &= DL_TimerG_saveConfiguration(ENCODER_QEI_INST, &gENCODER_QEIBackup);

    return retStatus;
}


SYSCONFIG_WEAK bool SYSCFG_DL_restoreConfiguration(void)
{
    bool retStatus = true;

	retStatus &= DL_TimerA_restoreConfiguration(MOTOR_PWM_INST, &gMOTOR_PWMBackup, false);
	retStatus &= DL_TimerG_restoreConfiguration(ENCODER_QEI_INST, &gENCODER_QEIBackup, false);

    return retStatus;
}

SYSCONFIG_WEAK void SYSCFG_DL_initPower(void)
{
    DL_GPIO_reset(GPIOA);
    DL_GPIO_reset(GPIOB);
    DL_TimerA_reset(MOTOR_PWM_INST);
    DL_TimerG_reset(ENCODER_QEI_INST);
    DL_I2C_reset(I2C_MPU6050_INST);

    DL_GPIO_enablePower(GPIOA);
    DL_GPIO_enablePower(GPIOB);
    DL_TimerA_enablePower(MOTOR_PWM_INST);
    DL_TimerG_enablePower(ENCODER_QEI_INST);
    DL_I2C_enablePower(I2C_MPU6050_INST);
    delay_cycles(POWER_STARTUP_DELAY);
}

SYSCONFIG_WEAK void SYSCFG_DL_GPIO_init(void)
{

    DL_GPIO_initPeripheralOutputFunction(GPIO_MOTOR_PWM_C2_IOMUX,GPIO_MOTOR_PWM_C2_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_MOTOR_PWM_C2_PORT, GPIO_MOTOR_PWM_C2_PIN);
    DL_GPIO_initPeripheralOutputFunction(GPIO_MOTOR_PWM_C2_CMPL_IOMUX,GPIO_MOTOR_PWM_C2_CMPL_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_MOTOR_PWM_C2_CMPL_PORT, GPIO_MOTOR_PWM_C2_CMPL_PIN);
    DL_GPIO_initPeripheralOutputFunction(GPIO_MOTOR_PWM_C3_IOMUX,GPIO_MOTOR_PWM_C3_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_MOTOR_PWM_C3_PORT, GPIO_MOTOR_PWM_C3_PIN);
    DL_GPIO_initPeripheralOutputFunction(GPIO_MOTOR_PWM_C3_CMPL_IOMUX,GPIO_MOTOR_PWM_C3_CMPL_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_MOTOR_PWM_C3_CMPL_PORT, GPIO_MOTOR_PWM_C3_CMPL_PIN);

    DL_GPIO_initPeripheralInputFunction(GPIO_ENCODER_QEI_PHA_IOMUX,GPIO_ENCODER_QEI_PHA_IOMUX_FUNC);
    DL_GPIO_initPeripheralInputFunction(GPIO_ENCODER_QEI_PHB_IOMUX,GPIO_ENCODER_QEI_PHB_IOMUX_FUNC);

    DL_GPIO_initPeripheralInputFunctionFeatures(GPIO_I2C_MPU6050_IOMUX_SDA,
        GPIO_I2C_MPU6050_IOMUX_SDA_FUNC, DL_GPIO_INVERSION_DISABLE,
        DL_GPIO_RESISTOR_NONE, DL_GPIO_HYSTERESIS_DISABLE,
        DL_GPIO_WAKEUP_DISABLE);
    DL_GPIO_initPeripheralInputFunctionFeatures(GPIO_I2C_MPU6050_IOMUX_SCL,
        GPIO_I2C_MPU6050_IOMUX_SCL_FUNC, DL_GPIO_INVERSION_DISABLE,
        DL_GPIO_RESISTOR_NONE, DL_GPIO_HYSTERESIS_DISABLE,
        DL_GPIO_WAKEUP_DISABLE);
    DL_GPIO_enableHiZ(GPIO_I2C_MPU6050_IOMUX_SDA);
    DL_GPIO_enableHiZ(GPIO_I2C_MPU6050_IOMUX_SCL);

    DL_GPIO_initDigitalInputFeatures(GPIO_MPU6050_PIN_MPU6050_INT_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalOutput(OLED_GPIO_GRP_OLED_D0_IOMUX);

    DL_GPIO_initDigitalOutput(OLED_GPIO_GRP_OLED_D1_IOMUX);

    DL_GPIO_initDigitalOutput(OLED_GPIO_GRP_OLED_RES_IOMUX);

    DL_GPIO_initDigitalOutput(OLED_GPIO_GRP_OLED_DC_IOMUX);

    DL_GPIO_initDigitalOutput(OLED_GPIO_GRP_OLED_CS_IOMUX);

    DL_GPIO_initDigitalInputFeatures(GRAY_SENSOR_GRP_GS_PIN_0_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(GRAY_SENSOR_GRP_GS_PIN_1_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(GRAY_SENSOR_GRP_GS_PIN_2_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(GRAY_SENSOR_GRP_GS_PIN_3_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(GRAY_SENSOR_GRP_GS_PIN_4_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(GRAY_SENSOR_GRP_GS_PIN_5_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(GRAY_SENSOR_GRP_GS_PIN_6_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(GRAY_SENSOR_GRP_GS_PIN_7_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalOutput(LED_GRP_LED_G_IOMUX);

    DL_GPIO_initDigitalOutput(LED_GRP_LED1_IOMUX);

    DL_GPIO_initDigitalOutput(LED_GRP_LED2_IOMUX);

    DL_GPIO_initDigitalOutput(LED_GRP_LED3_IOMUX);

    DL_GPIO_initDigitalInputFeatures(KEY_GRP_KEY0_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(KEY_GRP_KEY1_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(KEY_GRP_KEY2_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalOutput(MOTORA_GRP_AIN_1_IOMUX);

    DL_GPIO_initDigitalOutput(MOTORA_GRP_AIN_2_IOMUX);

    DL_GPIO_initDigitalOutput(MOTORB_GRP_BIN_1_IOMUX);

    DL_GPIO_initDigitalOutput(MOTORB_GRP_BIN_2_IOMUX);

    DL_GPIO_clearPins(GPIOA, LED_GRP_LED1_PIN |
		LED_GRP_LED2_PIN |
		LED_GRP_LED3_PIN |
		MOTORA_GRP_AIN_1_PIN |
		MOTORA_GRP_AIN_2_PIN);
    DL_GPIO_enableOutput(GPIOA, LED_GRP_LED1_PIN |
		LED_GRP_LED2_PIN |
		LED_GRP_LED3_PIN |
		MOTORA_GRP_AIN_1_PIN |
		MOTORA_GRP_AIN_2_PIN);
    DL_GPIO_clearPins(GPIOB, OLED_GPIO_GRP_OLED_D0_PIN |
		OLED_GPIO_GRP_OLED_D1_PIN |
		OLED_GPIO_GRP_OLED_RES_PIN |
		OLED_GPIO_GRP_OLED_DC_PIN |
		OLED_GPIO_GRP_OLED_CS_PIN |
		LED_GRP_LED_G_PIN |
		MOTORB_GRP_BIN_1_PIN |
		MOTORB_GRP_BIN_2_PIN);
    DL_GPIO_enableOutput(GPIOB, OLED_GPIO_GRP_OLED_D0_PIN |
		OLED_GPIO_GRP_OLED_D1_PIN |
		OLED_GPIO_GRP_OLED_RES_PIN |
		OLED_GPIO_GRP_OLED_DC_PIN |
		OLED_GPIO_GRP_OLED_CS_PIN |
		LED_GRP_LED_G_PIN |
		MOTORB_GRP_BIN_1_PIN |
		MOTORB_GRP_BIN_2_PIN);
    DL_GPIO_setLowerPinsPolarity(GPIOB, DL_GPIO_PIN_7_EDGE_FALL |
		DL_GPIO_PIN_6_EDGE_FALL);
    DL_GPIO_setUpperPinsPolarity(GPIOB, DL_GPIO_PIN_23_EDGE_FALL |
		DL_GPIO_PIN_21_EDGE_RISE);
    DL_GPIO_setLowerPinsInputFilter(GPIOB, DL_GPIO_PIN_7_INPUT_FILTER_8_CYCLES |
		DL_GPIO_PIN_6_INPUT_FILTER_8_CYCLES);
    DL_GPIO_clearInterruptStatus(GPIOB, GPIO_MPU6050_PIN_MPU6050_INT_PIN |
		KEY_GRP_KEY0_PIN |
		KEY_GRP_KEY1_PIN |
		KEY_GRP_KEY2_PIN);
    DL_GPIO_enableInterrupt(GPIOB, GPIO_MPU6050_PIN_MPU6050_INT_PIN |
		KEY_GRP_KEY0_PIN |
		KEY_GRP_KEY1_PIN |
		KEY_GRP_KEY2_PIN);

}


static const DL_SYSCTL_SYSPLLConfig gSYSPLLConfig = {
    .inputFreq              = DL_SYSCTL_SYSPLL_INPUT_FREQ_16_32_MHZ,
	.rDivClk2x              = 1,
	.rDivClk1               = 0,
	.rDivClk0               = 0,
	.enableCLK2x            = DL_SYSCTL_SYSPLL_CLK2X_ENABLE,
	.enableCLK1             = DL_SYSCTL_SYSPLL_CLK1_DISABLE,
	.enableCLK0             = DL_SYSCTL_SYSPLL_CLK0_DISABLE,
	.sysPLLMCLK             = DL_SYSCTL_SYSPLL_MCLK_CLK2X,
	.sysPLLRef              = DL_SYSCTL_SYSPLL_REF_SYSOSC,
	.qDiv                   = 4,
	.pDiv                   = DL_SYSCTL_SYSPLL_PDIV_2
};
SYSCONFIG_WEAK void SYSCFG_DL_SYSCTL_init(void)
{

	//Low Power Mode is configured to be SLEEP0
    DL_SYSCTL_setBORThreshold(DL_SYSCTL_BOR_THRESHOLD_LEVEL_0);
    DL_SYSCTL_setFlashWaitState(DL_SYSCTL_FLASH_WAIT_STATE_2);

    
	DL_SYSCTL_setSYSOSCFreq(DL_SYSCTL_SYSOSC_FREQ_BASE);
	/* Set default configuration */
	DL_SYSCTL_disableHFXT();
	DL_SYSCTL_disableSYSPLL();
    DL_SYSCTL_configSYSPLL((DL_SYSCTL_SYSPLLConfig *) &gSYSPLLConfig);
    DL_SYSCTL_setULPCLKDivider(DL_SYSCTL_ULPCLK_DIV_2);
    DL_SYSCTL_setMCLKSource(SYSOSC, HSCLK, DL_SYSCTL_HSCLK_SOURCE_SYSPLL);
    /* INT_GROUP1 Priority */
    NVIC_SetPriority(GPIOB_INT_IRQn, 2);

}


/*
 * Timer clock configuration to be sourced by  / 2 (40000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   40000000 Hz = 40000000 Hz / (2 * (0 + 1))
 */
static const DL_TimerA_ClockConfig gMOTOR_PWMClockConfig = {
    .clockSel = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_2,
    .prescale = 0U
};

static const DL_TimerA_PWMConfig gMOTOR_PWMConfig = {
    .pwmMode = DL_TIMER_PWM_MODE_EDGE_ALIGN_UP,
    .period = 10000,
    .isTimerWithFourCC = true,
    .startTimer = DL_TIMER_START,
};

SYSCONFIG_WEAK void SYSCFG_DL_MOTOR_PWM_init(void) {

    DL_TimerA_setClockConfig(
        MOTOR_PWM_INST, (DL_TimerA_ClockConfig *) &gMOTOR_PWMClockConfig);

    DL_TimerA_initPWMMode(
        MOTOR_PWM_INST, (DL_TimerA_PWMConfig *) &gMOTOR_PWMConfig);

    // Set Counter control to the smallest CC index being used
    DL_TimerA_setCounterControl(MOTOR_PWM_INST,DL_TIMER_CZC_CCCTL2_ZCOND,DL_TIMER_CAC_CCCTL2_ACOND,DL_TIMER_CLC_CCCTL2_LCOND);

    DL_TimerA_setCaptureCompareOutCtl(MOTOR_PWM_INST, DL_TIMER_CC_OCTL_INIT_VAL_LOW,
		DL_TIMER_CC_OCTL_INV_OUT_DISABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
		DL_TIMERA_CAPTURE_COMPARE_2_INDEX);

    DL_TimerA_setCaptCompUpdateMethod(MOTOR_PWM_INST, DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE, DL_TIMERA_CAPTURE_COMPARE_2_INDEX);
    DL_TimerA_setCaptureCompareValue(MOTOR_PWM_INST, 0, DL_TIMER_CC_2_INDEX);

    DL_TimerA_setCaptureCompareOutCtl(MOTOR_PWM_INST, DL_TIMER_CC_OCTL_INIT_VAL_LOW,
		DL_TIMER_CC_OCTL_INV_OUT_DISABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
		DL_TIMERA_CAPTURE_COMPARE_3_INDEX);

    DL_TimerA_setCaptCompUpdateMethod(MOTOR_PWM_INST, DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE, DL_TIMERA_CAPTURE_COMPARE_3_INDEX);
    DL_TimerA_setCaptureCompareValue(MOTOR_PWM_INST, 0, DL_TIMER_CC_3_INDEX);

    DL_TimerA_enableClock(MOTOR_PWM_INST);


    
    DL_TimerA_setCCPDirection(MOTOR_PWM_INST , DL_TIMER_CC2_OUTPUT | DL_TIMER_CC3_OUTPUT );


}


static const DL_TimerG_ClockConfig gENCODER_QEIClockConfig = {
    .clockSel = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_4,
    .prescale = 0U
};


SYSCONFIG_WEAK void SYSCFG_DL_ENCODER_QEI_init(void) {

    DL_TimerG_setClockConfig(
        ENCODER_QEI_INST, (DL_TimerG_ClockConfig *) &gENCODER_QEIClockConfig);

    DL_TimerG_configQEI(ENCODER_QEI_INST, DL_TIMER_QEI_MODE_2_INPUT,
        DL_TIMER_CC_INPUT_INV_NOINVERT, DL_TIMER_CC_0_INDEX);
    DL_TimerG_configQEI(ENCODER_QEI_INST, DL_TIMER_QEI_MODE_2_INPUT,
        DL_TIMER_CC_INPUT_INV_NOINVERT, DL_TIMER_CC_1_INDEX);
    DL_TimerG_setLoadValue(ENCODER_QEI_INST, 8000);
    DL_TimerG_enableInterrupt(ENCODER_QEI_INST , DL_TIMER_EVENT_ZERO_EVENT);

    NVIC_SetPriority(ENCODER_QEI_INST_INT_IRQN, 2);
    DL_TimerG_enableClock(ENCODER_QEI_INST);
}


static const DL_I2C_ClockConfig gI2C_MPU6050ClockConfig = {
    .clockSel = DL_I2C_CLOCK_BUSCLK,
    .divideRatio = DL_I2C_CLOCK_DIVIDE_1,
};

SYSCONFIG_WEAK void SYSCFG_DL_I2C_MPU6050_init(void) {

    DL_I2C_setClockConfig(I2C_MPU6050_INST,
        (DL_I2C_ClockConfig *) &gI2C_MPU6050ClockConfig);
    DL_I2C_setAnalogGlitchFilterPulseWidth(I2C_MPU6050_INST,
        DL_I2C_ANALOG_GLITCH_FILTER_WIDTH_50NS);
    DL_I2C_enableAnalogGlitchFilter(I2C_MPU6050_INST);

    /* Configure Controller Mode */
    DL_I2C_resetControllerTransfer(I2C_MPU6050_INST);
    /* Set frequency to 400000 Hz*/
    DL_I2C_setTimerPeriod(I2C_MPU6050_INST, 9);
    DL_I2C_setControllerTXFIFOThreshold(I2C_MPU6050_INST, DL_I2C_TX_FIFO_LEVEL_EMPTY);
    DL_I2C_setControllerRXFIFOThreshold(I2C_MPU6050_INST, DL_I2C_RX_FIFO_LEVEL_BYTES_1);
    DL_I2C_enableControllerClockStretching(I2C_MPU6050_INST);


    /* Enable module */
    DL_I2C_enableController(I2C_MPU6050_INST);


}

