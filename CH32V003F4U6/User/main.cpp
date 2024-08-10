/********************************** (C) COPYRIGHT *******************************
 * File Name          : main.c
 * Author             : WCH
 * Version            : V1.0.0
 * Date               : 2023/12/25
 * Description        : Main program body.
 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for 
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/

/*
 *@Note
 *Multiprocessor communication mode routine:
 *Master:USART1_Tx(PD5)\USART1_Rx(PD6).
 *This routine demonstrates that USART1 receives the data sent by CH341 and inverts
 *it and sends it (baud rate 115200).
 *
 *Hardware connection:PD5 -- Rx
 *                     PD6 -- Tx
 *
 */

#include "debug.h"
#include <sml.hpp>

using namespace boost::sml;

/* Global Variable */

/*********************************************************************
 * @fn      USARTx_CFG
 *
 * @brief   Initializes the USART2 & USART3 peripheral.
 *
 * @return  none
 */

struct timer_event {};

auto action_led_on = [] {
		GPIO_WriteBit(GPIOC, GPIO_Pin_4, Bit_SET);
};
auto action_led_off = [] {
		GPIO_WriteBit(GPIOC, GPIO_Pin_4, Bit_RESET);
};

class BlinkingLED {
public:
   auto operator()(){
     return make_transition_table(
       *"state_led_off"_s + event<timer_event> / action_led_on ="state_led_on"_s
      ,"state_led_on"_s + event<timer_event> / action_led_off ="state_led_off"_s
   );
   }
};

sm<BlinkingLED> state_machine;

//void USARTx_CFG(void)
//{
//    GPIO_InitTypeDef  GPIO_InitStructure = {0};
//    USART_InitTypeDef USART_InitStructure = {0};
//
//    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD | RCC_APB2Periph_USART1, ENABLE);
//
//    /* USART1 TX-->D.5   RX-->D.6 */
//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
//    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//    GPIO_Init(GPIOD, &GPIO_InitStructure);
//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
//    GPIO_Init(GPIOD, &GPIO_InitStructure);
//
//    USART_InitStructure.USART_BaudRate = 115200;
//    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
//    USART_InitStructure.USART_StopBits = USART_StopBits_1;
//    USART_InitStructure.USART_Parity = USART_Parity_No;
//    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
//    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
//
//    USART_Init(USART1, &USART_InitStructure);
//    USART_Cmd(USART1, ENABLE);
//}

void GPIO_Toggle_INIT(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
}

/*********************************************************************
 * @fn      main
 *
 * @brief   Main program.
 *
 * @return  none
 *
 * UML HSM based on:
 * https://github.com/RafNie/BoostSML_Stm32_hello_world/blob/master/Core/Src/main.cpp
 */
int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    SystemCoreClockUpdate();
    Delay_Init();
//#if (SDI_PRINT == SDI_PR_OPEN)
//    SDI_Printf_Enable();
//#else
//    USART_Printf_Init(115200);
//#endif
//    printf("SystemClk:%d\r\n",SystemCoreClock);
//    printf( "ChipID:%08x\r\n", DBGMCU_GetCHIPID() );

    //USARTx_CFG();
    GPIO_Toggle_INIT();

    while(1)
    {
        Delay_Ms(500);
        state_machine.process_event(timer_event{});
    }

//    while(1)
//    {
//
//        while(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET)
//        {
//            /* waiting for receiving finish */
//        }
//        val = (USART_ReceiveData(USART1));
//        USART_SendData(USART1, ~val);
//        while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET)
//        {
//            /* waiting for sending finish */
//        }
//
//    }
}
