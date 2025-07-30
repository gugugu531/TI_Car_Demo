#ifndef __MAIN_H__
#define __MAIN_H__
/*
* Headers of TI, automatically generated
*/
#include <ti/driverlib/m0p/dl_interrupt.h>
#include <Debug/ti_msp_dl_config.h>

/*
* Headers of user
*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "delay.h"
#include <Mode/Inc/Mode.h>
#include <Task/Inc/task.h>
#include <Hardware/Inc/hardware.h>
//#include <Mode/Inc/Mode.h>
//#include <Task/Inc/task.h>


#define HAL_Delay(x) delay_ms(x)

extern volatile bool key1state;
extern volatile bool key2state;

#endif