/************************************************************************************
 *
 * Module		: HC-SR04 Ultrasoinc sensor
 *
 * File Name 	: HC-SR04.h
 *
 * Description	: Header file for atmega16 HC-SR04 Ultrasoinc sensor
 *
 * Author		: Mohamed Sherif
 *
 **************************************************************************************/

#ifndef HC_SR04_H_
#define HC_SR04_H_

#include "std_types.h"


/*******************************************************************************
 *                      Functions Prototypes                                  *
 *******************************************************************************/
/*
 * Description:
 * 	1.Initialize the ICU driver as required.
 * 	2.Setup the ICU call back function.
 * 	3.Setup the direction for the trigger pin as output pin through the GPIO driver.
 */
void Ultrasonic_init(void);

/*
 *Description:
 * Send the Trigger pulse to the ultrasonic
 */
void Ultrasonic_Trigger(void);

/*
 * Description
 * Send the trigger pulse by using Ultrasonic_Trigger function.
 * Start the measurements by the ICU from this moment
 */
uint16 Ultrasonic_readDistance(void);

/*
 * Description:
 * This is the call back function called by the ICU driver.
 * This is used to calculate the high time (pulse time) generated by the ultrasonic sensor
 */
void Ultrasonic_edgeProcessing(void);

#endif /* HC_SR04_H_ */
