#include <main.h>
#include <Task/Inc/basic_task.h>

void task1()
{
    trace_to_cross(60);
    autoturn(60);
    trace_to_cross(60);
    stop();
}

void task2()
{
    trace(60);
    stop();
}

void task3()
{
    char msg[10] = "hello"
    while (1) {
        DL_UART_fillTXFIFO(K230_UART_INST, msg, 5);
        while (DL_UART_Main_isBusy(K230_UART_INST))
            ;
    }
}

void task4()
{
}