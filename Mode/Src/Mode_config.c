// 直行模组

#include <main.h>
#include <Mode/Inc/Mode_config.h>

//可以考虑
void config_show_Kyaw(){
//    char msg[9] = {0};
//    while(1){
//        sprintf(msg,"%f", yaw);
//        OLED_ShowString(0,20,msg,8,1);
//        OLED_Refresh();
//        HAL_Delay(10);
//    }
}

void config_trace_sensor(){
    char msg[9] = {0};
    while(1){
        for(uint8_t i = 0; i<8; i++){
            msg[i] = get_T(8-i) +'0';
            OLED_ShowString(0,20,msg,8,1);
            OLED_Refresh();
        }
    }
}

void config_moter_Pin(){
    while(1){
        Set_PWM(50,0);
        HAL_Delay(2000);
        Set_PWM(0,50);
        HAL_Delay(2000);
        Set_PWM(50,50);
        HAL_Delay(2000);
    }
}
















