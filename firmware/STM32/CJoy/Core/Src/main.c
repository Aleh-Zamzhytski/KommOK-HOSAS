/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "dma.h"
#include "usb_device.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "usbd_customhid.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
extern USBD_HandleTypeDef hUsbDeviceFS;
extern ADC_HandleTypeDef hadc1;
extern uint8_t adc_data_ready;

typedef union
{
  struct
  {
    uint16_t X;
    uint16_t Y;
    uint16_t Z;
    uint16_t RX;
    struct
    {
      uint8_t button1 : 1;
      uint8_t button2 : 1;
      uint8_t button3 : 1;
      uint8_t button4 : 1;
      uint8_t button5 : 1;
      uint8_t button6 : 1;
      uint8_t button7 : 1;
      uint8_t button8 : 1;
      uint8_t button9 : 1;
      uint8_t button10 : 1;
      uint8_t button11 : 1;
      uint8_t button12 : 1;
      uint8_t button13 : 1;
      uint8_t button14 : 1;
      uint8_t button15 : 1;
      uint8_t button16 : 1;
    } buttons;
  } values;

  uint8_t bytes[sizeof(struct {
    uint16_t X;
    uint16_t Y;
    uint16_t Z;
    uint16_t RX;
    struct
    {
      uint8_t button1 : 1;
      uint8_t button2 : 1;
      uint8_t button3 : 1;
      uint8_t button4 : 1;
      uint8_t button5 : 1;
      uint8_t button6 : 1;
      uint8_t button7 : 1;
      uint8_t button8 : 1;
      uint8_t button9 : 1;
      uint8_t button10 : 1;
      uint8_t button11 : 1;
      uint8_t button12 : 1;
      uint8_t button13 : 1;
      uint8_t button14 : 1;
      uint8_t button15 : 1;
      uint8_t button16 : 1;
    } buttons;
  })];
} JData;

JData dataToSend;

uint8_t report_buffer[10];		//Variable to receive the report buffer
uint8_t send_buffer[10];
__ALIGN_BEGIN uint16_t adc_values[4] __ALIGN_END = {0};// [0]=X, [1]=Y, [2]=Z, [3]=Rx

uint16_t filtered_values[4];
#define FILTER_SAMPLES 32

extern PCD_HandleTypeDef hpcd_USB_FS;

uint16_t ADC_Read_Axis(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_ADC1_Init();
  MX_USB_DEVICE_Init();
  /* USER CODE BEGIN 2 */
  if (HAL_ADCEx_Calibration_Start(&hadc1) != HAL_OK)
  {
	  Error_Handler();
  }

  ADC_Start_DMA_Conversion();

  //  if (HAL_ADC_Start_DMA(&hadc1, (uint32_t *)adc_values, 4) != HAL_OK)
  //  {
	//    Error_Handler();
  //  }
  memset(&dataToSend, 0, sizeof(dataToSend));
  memset(send_buffer, 0, 10);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  uint32_t last_send_time = 0;
  uint32_t counter = 0;
  const uint32_t send_interval = 20; // Send at ~50Hz
  static uint32_t filter_buf[4];

  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
    uint32_t now = HAL_GetTick();
    if (!adc_data_ready)
    {
      continue;
    }

    adc_data_ready= 0;

        //   uint16_t X = ADC_Read_Axis(X_Axis_GPIO_Port, X_Axis_Pin);
        //   uint16_t Y =  ADC_Read_Axis(Y_Axis_GPIO_Port, Y_Axis_Pin);
        //    uint16_t Z =ADC_Read_Axis(Z_Axis_GPIO_Port, Z_Axis_Pin);

        // static uint16_t filter_buf[4][FILTER_SAMPLES];
        // static uint8_t filter_idx = 0;
        // for (int i = 0; i < 4; i++)
        // {
        //   filter_buf[i][filter_idx] = adc_values[i];
        // }
        // filter_idx = (filter_idx + 1) % FILTER_SAMPLES;

        // for (int i = 0; i < 4; i++)
        // {
        //   uint32_t sum = 0;
        //   for (int j = 0; j < FILTER_SAMPLES; j++)
        //   {
        //     sum += filter_buf[i][j];
        //   }
        //   filtered_values[i] = sum / FILTER_SAMPLES;
        // }

        // for (int adcChanelIndex = 0; adcChanelIndex < 4; adcChanelIndex++)
        // {
        //   filter_buf[adcChanelIndex] = adc_values[adcChanelIndex];
        // }

        // for(int filterCount = 0; filterCount < FILTER_SAMPLES; filterCount++)
        // {
        //   for (int adcChanelIndex = 0; adcChanelIndex < 4; adcChanelIndex++)
        //   {
        //      uint32_t prevValue = filter_buf[adcChanelIndex];
        //      filter_buf[adcChanelIndex] = (prevValue + adc_values[adcChanelIndex])/2;
        //   }
        // }

        // uint16_t x_axis = filter_buf[0];
        // uint16_t y_axis = filter_buf[1];
        // uint16_t z_axis = filter_buf[2];
        // uint16_t rx_axis = filter_buf[3];

    dataToSend.values.X = ADC_GetFilteredValue(0);
    dataToSend.values.Y = ADC_GetFilteredValue(1);
    dataToSend.values.Z = ADC_GetFilteredValue(2);
    dataToSend.values.RX = ADC_GetFilteredValue(3);

    // dataToSend.values.X = filtered_values[0];
    // dataToSend.values.Y = filtered_values[1];
    // dataToSend.values.Z = filtered_values[2];
    // dataToSend.values.RX = filtered_values[3];

    //   send_buffer[0] = (uint8_t)(x_axis & 0xFF);       // X low
    //   send_buffer[1] = (uint8_t)((x_axis >> 8) & 0xFF);// X high

    //   send_buffer[2] = (uint8_t)(y_axis & 0xFF);       // Y low
    //   send_buffer[3] = (uint8_t)((y_axis >> 8) & 0xFF);// Y high

    //   send_buffer[4] = (uint8_t)(z_axis & 0xFF);       // Z low
    //   send_buffer[5] = (uint8_t)((z_axis >> 8) & 0xFF);// Z high

    //   send_buffer[6] = (uint8_t)(rx_axis & 0xFF);       // RX low
    //   send_buffer[7] = (uint8_t)((rx_axis >> 8) & 0xFF);// RX high

    //  if((now - last_send_time) >= send_interval){
    //     send_buffer[8] = 1 & 0x01;
    //     send_buffer[9] = 1 & 0x01;
    //    counter = 0;
    //  }

     dataToSend.values.buttons.button1 = HAL_GPIO_ReadPin(BTN_1_GPIO_Port, BTN_1_Pin) == GPIO_PIN_RESET;
     dataToSend.values.buttons.button2 = HAL_GPIO_ReadPin(BTN_2_GPIO_Port, BTN_2_Pin) == GPIO_PIN_RESET;
     dataToSend.values.buttons.button3 = HAL_GPIO_ReadPin(BTN_3_GPIO_Port, BTN_3_Pin) == GPIO_PIN_RESET;
     dataToSend.values.buttons.button4 = HAL_GPIO_ReadPin(BTN_4_GPIO_Port, BTN_4_Pin) == GPIO_PIN_RESET;
     dataToSend.values.buttons.button5 = HAL_GPIO_ReadPin(BTN_5_GPIO_Port, BTN_5_Pin) == GPIO_PIN_RESET;

    if ((now - last_send_time) >= send_interval)
    {
      /* hhid->state == CUSTOM_HID_BUSY, пока идёт IN-передача отчёта:
       * ставится в USBD_CUSTOM_HID_SendReport(), снимается в
       * USBD_CUSTOM_HID_DataIn() по завершении передачи. Отдельный
       * признак "отправка в процессе" не нужен. */
      USBD_CUSTOM_HID_HandleTypeDef *hhid = hUsbDeviceFS.pClassData;
      if (hhid->state != CUSTOM_HID_IDLE)
      {
        continue;
      }

      USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, dataToSend.bytes, 10);
      last_send_time = now;
    }
    }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL6;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC|RCC_PERIPHCLK_USB;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV4;
  PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_PLL;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
static uint32_t get_adc_channel(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) {
    // Для STM32F1xx серии
    if (GPIOx == GPIOA) {
        switch (GPIO_Pin) {
            case GPIO_PIN_1: return ADC_CHANNEL_1;  // X_Axis
            case GPIO_PIN_2: return ADC_CHANNEL_2;  // Y_Axis
            case GPIO_PIN_3: return ADC_CHANNEL_3;  // Z_Axis
            case GPIO_PIN_0: return ADC_CHANNEL_0;
            case GPIO_PIN_4: return ADC_CHANNEL_4;
            case GPIO_PIN_5: return ADC_CHANNEL_5;
            case GPIO_PIN_6: return ADC_CHANNEL_6;
            case GPIO_PIN_7: return ADC_CHANNEL_7;
        }
    }
    return 0; // Неверный пин
}

// Чтение сырого значения с оси
uint16_t ADC_Read_Axis(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) {
   // if (hadc1 == NULL) return 0;

    uint32_t channel = get_adc_channel(GPIOx, GPIO_Pin);
    if (channel == 0) return 0;

    ADC_ChannelConfTypeDef sConfig = {0};
    sConfig.Channel = channel;
    sConfig.Rank = 1;
    sConfig.SamplingTime = ADC_SAMPLETIME_28CYCLES_5;

    HAL_ADC_ConfigChannel(&hadc1, &sConfig);

    // Запуск и чтение
    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
    uint16_t value = HAL_ADC_GetValue(&hadc1);
    HAL_ADC_Stop(&hadc1);

    return value;
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
