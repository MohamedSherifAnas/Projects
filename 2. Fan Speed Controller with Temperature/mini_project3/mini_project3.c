/*
 ========================================================================
  File Name: mini_project3.c
  Author : Mohamed Sherif
  Description: Temperature-controlled fan using ATmega16 microcontroller
  Date : Oct 7, 2021
 ========================================================================
 */

#include "DC-motor.h"
#include "lcd.h"
#include "lm35.h"
#include "adc.h"

uint16 g_temp=0;

int main()
{
	ADC_ConfigType ADC_Config = {InternalVoltage,F_CPU_8};

	LCD_init();
	DcMotor_Init();
	ADC_init(&ADC_Config);

	LCD_displayStringRowColumn(0,3,"FAN IS ");
	LCD_displayStringRowColumn(1,3,"Temp =    C");

	while(1)
	{

		g_temp =LM35_getTemperature();

		LCD_moveCursor(0,9);

		if(g_temp<30)
		{
			LCD_displayString(" OFF");

			DcMotor_Rotate(CW,0);
		}
		else if ((g_temp >=30) && (g_temp<60))
		{
			LCD_displayString(" ON");
			LCD_displayCharacter(' ');

			DcMotor_Rotate(CW,25);
		}
		else if ((g_temp >=60) && (g_temp<90))
		{
			LCD_displayString(" ON");
			LCD_displayCharacter(' ');

			DcMotor_Rotate(CW,50);
		}
		else if ((g_temp >=90) && (g_temp<120))
		{
			LCD_displayString(" ON");
			LCD_displayCharacter(' ');

			DcMotor_Rotate(CW,75);
		}
		else if ( (g_temp>=120))
		{
			LCD_displayString(" ON");
			LCD_displayCharacter(' ');

			DcMotor_Rotate(CW,100);
		}


		LCD_moveCursor(1,9);

		if(g_temp >= 100)
		{
			LCD_intgerToString(g_temp);
		}
		else
		{
			LCD_intgerToString(g_temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
	}
}

