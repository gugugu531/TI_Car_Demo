#include <Hardware/Inc/TB6612.h>
#include <main.h>

volatile int8_t encoder_flag; //此处注意修改

void Set_PWM(float PWML_in, float PWMR_in) // 设置两轮速度 //finished
{
	int PWMR = PWMR_in * PWM_Period / 100;
	int PWML = PWML_in * PWM_Period / 100;
	/* ���A������ƣ�PC0/PC13�� */
	if (PWMR > 0)
	{
		//HAL_GPIO_WritePin(AIN2_GPIO_Port, AIN2_Pin, GPIO_PIN_SET);	 // AIN2�ߵ�ƽ
		//HAL_GPIO_WritePin(AIN1_GPIO_Port, AIN1_Pin, GPIO_PIN_RESET); // AIN1�͵�ƽ
        DL_GPIO_clearPins(MOTORA_GRP_PORT, MOTORA_GRP_AIN_2_PIN);
        DL_GPIO_writePins(MOTORA_GRP_PORT, MOTORA_GRP_AIN_1_PIN);
	}
	else
	{
		//HAL_GPIO_WritePin(AIN1_GPIO_Port, AIN1_Pin, GPIO_PIN_SET);	 // AIN1�ߵ�ƽ
		//HAL_GPIO_WritePin(AIN2_GPIO_Port, AIN2_Pin, GPIO_PIN_RESET); // AIN2�͵�ƽ
        DL_GPIO_clearPins(MOTORA_GRP_PORT, MOTORA_GRP_AIN_1_PIN);
        DL_GPIO_writePins(MOTORA_GRP_PORT, MOTORA_GRP_AIN_2_PIN);
		PWMR = -PWMR;												 // ȡ����ֵ
	}

	/* ���B������ƣ�PB10/PE14�� */
	if (PWML > 0)
	{
		//HAL_GPIO_WritePin(BIN2_GPIO_Port, BIN2_Pin, GPIO_PIN_SET);	 // BIN2�ߵ�ƽ
		//HAL_GPIO_WritePin(BIN1_GPIO_Port, BIN1_Pin, GPIO_PIN_RESET); // BIN1�͵�ƽ
        DL_GPIO_clearPins(MOTORB_GRP_PORT, MOTORB_GRP_BIN_2_PIN);
        DL_GPIO_writePins(MOTORB_GRP_PORT, MOTORB_GRP_BIN_1_PIN);
	}
	else
	{
		//HAL_GPIO_WritePin(BIN1_GPIO_Port, BIN1_Pin, GPIO_PIN_SET);	 // BIN1�ߵ�ƽ
		//HAL_GPIO_WritePin(BIN2_GPIO_Port, BIN2_Pin, GPIO_PIN_RESET); // BIN2�͵�ƽ
        DL_GPIO_clearPins(MOTORB_GRP_PORT, MOTORB_GRP_BIN_1_PIN);
		DL_GPIO_writePins(MOTORB_GRP_PORT, MOTORB_GRP_BIN_2_PIN);
		PWML = -PWML;												 // ȡ����ֵ
	}

	/* ����PWMռ�ձȣ�TIM2ͨ��1��TIM3ͨ��3��(PA0,PB0) */
	DL_Timer_setCaptureCompareValue(MOTOR_PWM_INST, PWMR, DL_TIMER_CC_2_INDEX); // ����TIM2_CH1ռ�ձ�
	DL_Timer_setCaptureCompareValue(MOTOR_PWM_INST, PWML, DL_TIMER_CC_3_INDEX); // ����TIM3_CH3ռ�ձ�
}

void TB6612_Init(void)// 初始化TB6612相关模组
{ 
//	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
//	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
//	HAL_TIM_Encoder_Start(&htim1, TIM_CHANNEL_ALL);
//	HAL_TIM_Encoder_Start(&htim4, TIM_CHANNEL_ALL);
//	__HAL_TIM_ENABLE_IT(&htim7, TIM_IT_UPDATE);
//	__HAL_TIM_SET_PRESCALER(&htim2, PWM_Prescaler);
//	__HAL_TIM_SET_AUTORELOAD(&htim2, PWM_Period);
//	__HAL_TIM_SET_PRESCALER(&htim3, PWM_Prescaler);
//	__HAL_TIM_SET_AUTORELOAD(&htim3, PWM_Period);
//	__HAL_TIM_SET_COUNTER(&htim7, 0);
	DL_Timer_startCounter(ENCODER_QEI_INST);
	DL_Timer_setTimerCount(ENCODER_QEI_INST, 0);
	//编码器初始化

	//PWM产生
	DL_Timer_setCaptureCompareValue(MOTOR_PWM_INST, 0, DL_TIMER_CC_2_INDEX);
	DL_Timer_setCaptureCompareValue(MOTOR_PWM_INST, 0, DL_TIMER_CC_3_INDEX);
	DL_Timer_startCounter(MOTOR_PWM_INST);
} // PWM_Prescaler��PWM_Period��TB6612.h�ļ����޸ģ�Ϊ����PWM���ļ�������Ԥ��Ƶ�����Զ���װ��ֵ

void reset_encoder() //重置编码器
{
	//__HAL_TIM_SET_COUNTER(&htim1, 0);
	//__HAL_TIM_SET_COUNTER(&htim4, 0);
	//HAL_TIM_Encoder_Start(&htim1, TIM_CHANNEL_ALL);
	//HAL_TIM_Encoder_Start(&htim4, TIM_CHANNEL_ALL);
	DL_Timer_setTimerCount(ENCODER_QEI_INST, 0);
	DL_TimerG_startCounter(ENCODER_QEI_INST);
}

void read_encoder(int16_t encoder[])//阅读两编码器的值，函数接口应重新确定
{
	uint16_t counter;
	counter = ENCODER_QEI_INST->COUNTERREGS.CTR;
}
