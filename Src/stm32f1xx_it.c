/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f1xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f1xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <string.h>
#include "ssd1306.h"
#include "global.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
 
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern I2C_HandleTypeDef hi2c1;
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M3 Processor Interruption and Exception Handlers          */ 
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */

  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Prefetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F1xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f1xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles TIM2 global interrupt.
  */
void TIM2_IRQHandler(void)
{
  /* USER CODE BEGIN TIM2_IRQn 0 */
  LL_TIM_ClearFlag_UPDATE(TIM2);
  if (HAL_GPIO_ReadPin(GPIOKEY,BUTTON_1)==0)
  {
    if (Enable_Player1==1)
      Timer=Timer1;
    
  }
  else
  {
    if (HAL_GPIO_ReadPin(GPIOKEY,BUTTON_2)==0)
    {
      if (Enable_Player2==1)
        Timer=Timer2;
    }
    else
    {
      if (HAL_GPIO_ReadPin(GPIOKEY,BUTTON_3)==0)
      {
        Reset_State();
      }
    }
  }
 // WRITE_REG(TIM2->SR, ~(TIM_SR_UIF));
  /* USER CODE END TIM2_IRQn 0 */
  /* USER CODE BEGIN TIM2_IRQn 1 */

  /* USER CODE END TIM2_IRQn 1 */
}

/**
  * @brief This function handles TIM3 global interrupt.
  */
void TIM3_IRQHandler(void)
{
  /* USER CODE BEGIN TIM3_IRQn 0 */
LL_TIM_ClearFlag_UPDATE(TIM3);
//WRITE_REG(TIM3->CNT, 0x0000);
  //WRITE_REG(TIM3->DIER, 0x0000001);
  //WRITE_REG(TIM3->SR, 0x0000);
  //WRITE_REG(TIM3->CNT, 0x0000);
  //WRITE_REG(TIM3->CNT, 0x0000);
  switch(Timer)
  {
  case Timer1:
    if (Enable_Player1==1)
    {
      if(T1_msec==0)
      {
        if(T1_min==0&&T1_sec==0&&T1_msec==0)
            {
              if (Enable_Player2==0)
              {
                //LL_TIM_DisableIT_UPDATE(TIM3);
                //LL_TIM_DisableCounter(TIM3);
                ssd1306_Fill(FON);
                ssd1306_SetCursor(23,30);
                ssd1306_WriteString("FINISH",Font_11x18,COLOR);
                ssd1306_UpdateScreen();
                ssd1306_Fill(FON);
                //ssd1306_UpdateScreen();
                //HAL_Delay(1);
                Reset_State();
                //LL_TIM_EnableIT_UPDATE(TIM3);
                //LL_TIM_EnableCounter(TIM3);
              }
              else
              {
                Enable_Player1=0;
                Timer=Timer2;
              }
              break;
            }
        T1_msec=8;
        
        if(T1_sec==0)
        {
          T1_sec=59;
          T1_min--;
        }
        else
        {
          T1_sec--;
        }
      }
      else
      {
        T1_msec-=2;

      }
    }
    break;

  case Timer2:
    if (Enable_Player2==1)
    {
      if(T2_msec==0)
      {
        if(T2_min==0&&T2_sec==0&&T2_msec==0)
            {
              if (Enable_Player1==0)
              {
                //LL_TIM_DisableIT_UPDATE(TIM3);
                //LL_TIM_DisableCounter(TIM3);
                ssd1306_Fill(FON);
                ssd1306_SetCursor(23,30);
                ssd1306_WriteString("FINISH",Font_11x18,COLOR);
                ssd1306_UpdateScreen();
                ssd1306_Fill(FON);
                //ssd1306_UpdateScreen();
                //HAL_Delay(1);
                Reset_State();
                //LL_TIM_EnableIT_UPDATE(TIM3);
                //LL_TIM_EnableCounter(TIM3);
              }
              else
              {
                Enable_Player2=0;
                Timer=Timer1;
              }
              break;
            }
        T2_msec=8;
        
        if(T2_sec==0)
        {
          T2_sec=59;
          T2_min--;
        }
        else
        {
          T2_sec--;
        }
      }
      else
      {
        T2_msec-=2;;
      }
    }
    break;
    //break;
  }
  WriteClock(T1_min,T1_sec,T1_msec,23);
  WriteClock(T2_min,T2_sec,T2_msec,43);
  ssd1306_UpdateScreen();
  /* USER CODE END TIM3_IRQn 0 */
  /* USER CODE BEGIN TIM3_IRQn 1 */
//WRITE_REG(TIM3->SR, ~(TIM_SR_UIF));
  /* USER CODE END TIM3_IRQn 1 */
}

/**
  * @brief This function handles I2C1 event interrupt.
  */
void I2C1_EV_IRQHandler(void)
{
  /* USER CODE BEGIN I2C1_EV_IRQn 0 */

  /* USER CODE END I2C1_EV_IRQn 0 */
  HAL_I2C_EV_IRQHandler(&hi2c1);
  /* USER CODE BEGIN I2C1_EV_IRQn 1 */

  /* USER CODE END I2C1_EV_IRQn 1 */
}

/**
  * @brief This function handles I2C1 error interrupt.
  */
void I2C1_ER_IRQHandler(void)
{
  /* USER CODE BEGIN I2C1_ER_IRQn 0 */

  /* USER CODE END I2C1_ER_IRQn 0 */
  HAL_I2C_ER_IRQHandler(&hi2c1);
  /* USER CODE BEGIN I2C1_ER_IRQn 1 */

  /* USER CODE END I2C1_ER_IRQn 1 */
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
