/*
 * Sensor_SHT3X.h
 *
 *  Created on: Sep 08, 2024
 *      Author: DouglasFelipe97
 */

#ifndef SENSORS_DRIVERS_SENSOR_SHT3X_H_
#define SENSORS_DRIVERS_SENSOR_SHT3X_H_

/*
 * Includes
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <assert.h>

#include "board.h"

// TODO this include must be removed later
// All calls involving sht30 must be wrapped
#include "driver_sht30.h"

/*
 * Macros
 */

#ifndef SENSOR_SHT3X_SELECTED
#define SENSOR_SHT3X_SELECTED			SENSOR_SHT3X_SHT30
#endif

#define SHT30_SHOT_DEFAULT_CLOCK_STRETCHING     SHT30_BOOL_TRUE                 /**< enable clock stretching */
#define SHT30_SHOT_DEFAULT_REPEATABILITY        SHT30_REPEATABILITY_HIGH        /**< set high */
#define SHT30_SHOT_DEFAULT_HEATER               SHT30_BOOL_FALSE                /**< disable heater */

/*
 * Enumerates
 */

typedef enum{
	SENSOR_SHT3X_PARAM_CHANNEL,
	SENSOR_SHT3X_PARAM_RANGE,
	SENSOR_SHT3X_PARAM_RATE
}sensor_sht3x_param_e;

/*
 * Function Typedefs
 */


/*
 * Structs
 */


/*
 * Extern Drivers
 */

/*
 * Publics
 */

void SensorSHT3X_Init(sht30_address_t addr_pin);

void SensorSHT3X_SetParam(sensor_sht3x_param_e param, uint32_t val);

uint8_t SensorSHT3X_Read(float *temperature, float *humidity);

#endif /* SENSORS_DRIVERS_SENSOR_SHT3X_H_ */
