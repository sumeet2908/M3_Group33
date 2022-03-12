#include "MyStm32f407xx.h"

#define BTN_PRESSED ENABLE

void delay(void);
void lock(void);
void unlock(void);
int main(void)
{

	GPIO_Handle_t GpioLed, GPIOBtn; 

	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIO_PeriClockControl(GPIOD,ENABLE);
	GPIO_Init(&GpioLed);

	GpioLed.pGPIOx = GPIOD;
		GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
		GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
		GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
		GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
		GPIO_PeriClockControl(GPIOD,ENABLE);
		GPIO_Init(&GpioLed);

		GpioLed.pGPIOx = GPIOD;
		GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
		GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
		GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
		GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
		GPIO_PeriClockControl(GPIOD,ENABLE);
		GPIO_Init(&GpioLed);

		GpioLed.pGPIOx = GPIOD;
		GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15;
		GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
		GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
		GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
		GPIO_PeriClockControl(GPIOD,ENABLE);
		GPIO_Init(&GpioLed);



	GPIOBtn.pGPIOx = GPIOA;
	GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	GPIOBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIOBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GPIO_PeriClockControl(GPIOA,ENABLE);
	GPIO_Init(&GPIOBtn);

    uint32_t flag=0;
	while(1)
	{
		 if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0) == BTN_PRESSED)
		{
		delay();
		flag++;
		if(flag == 1)
		  {
         lock();
		 flag=0;
		  }
		else
		  {
			unlock();
			flag=0;
		  }
		 }
	}
}
	void delay(void)
{
	for (uint32_t i=0;i<50000000;i++);
}
void lock(void)
{
		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_14);
		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
}		
void unlock(void)
{
		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_14);
		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
}
