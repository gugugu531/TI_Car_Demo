// 循迹模组

#include <main.h>
#include <Mode/Inc/Mode_trace.h>

/////////
int trace(float speed)
{
	PID TracePID;
	float TracePID_Kp = 30, TracePID_Ki = 0, TracePID_Kd = 5;
	float TracePID_Target = 0, TracePID_MinOutput = -35, TracePID_MaxOutput = 35;
	float IntergretPID_MinOutput = -10, IntergretPID_MaxOutput = 10;
	float TracePID_Input = 0;
	PID_Init(&TracePID, TracePID_Kp, TracePID_Ki, TracePID_Kd, TracePID_Target,
			 0, 0, TracePID_MinOutput, TracePID_MaxOutput);
	float transform = 0;
	while (1) // 可在此添加跳出条件
	{
		transform = PID_Compute(&TracePID, get_Terror());
		Set_PWM(speed - transform, speed + transform);
		HAL_Delay(5);
	}
	stop();
	return 1; // 遇到十字路口返回1
}

void trace_to_cross(float speed)
{
	PID TracePID;
	float TracePID_Kp = 30, TracePID_Ki = 0, TracePID_Kd = 5;
	float TracePID_Target = 0, TracePID_MinOutput = -35, TracePID_MaxOutput = 35;
	float IntergretPID_MinOutput = -10, IntergretPID_MaxOutput = 10;
	float TracePID_Input = 0;
	PID_Init(&TracePID, TracePID_Kp, TracePID_Ki, TracePID_Kd, TracePID_Target,
			 0, 0, TracePID_MinOutput, TracePID_MaxOutput);

	float transform = 0; // 两轮基于基础巡线速度的差值

	while (1)
	{
		if (((get_T(1) && get_T(2)) || (get_T(7) && get_T(8))) && (get_T(4) || get_T(5)))
		{
			HAL_Delay(5);
			if (((get_T(1) && get_T(2)) || (get_T(7) && get_T(8))) && (get_T(4) || get_T(5)))
			{
				break;
			}
		}
		if (get_T_ALL() == 0x00)
		{
			HAL_Delay(5);
			if (get_T_ALL() == 0x00)
			{
				return; // 巡不到轨迹返回
			}
		}
		transform = PID_Compute(&TracePID, get_Terror());
		Set_PWM(speed - transform, speed + transform);
		HAL_Delay(5);
	}
	return;
}
