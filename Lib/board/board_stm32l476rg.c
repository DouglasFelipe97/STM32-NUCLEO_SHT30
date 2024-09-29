/*
 * board_stm32l476rb.c
 *
 *  Created on: Sep 15, 2024
 *      Author: DouglasFelipe97
 */


#include "board.h"

/*
 * Private includes
 */

#include <stdint.h>
#include <stdio.h>
#include <stm32l4xx.h>
#include "stm32l4xx_hal.h"
#include "i2c.h"

/*
 * Macros
 */

#define SHT30_I2C_HANDLER		&hi2c1

/*
 * Typedefs
 */

/*
 * Instances
 */


/*
 * Privates
 */

/*
 * Publics
 */

int8_t board_sht30_write(uint8_t addr, uint16_t reg, uint8_t *buf, uint16_t len){
	HAL_StatusTypeDef error;

	assert(buf != NULL);
	assert(len != 0);

		/** _i2c1_lock(); **/	/*Only in Free RTOs*/
	/*error = HAL_I2C_Master_Transmit(&hi2c1, addr, buf, len, 100);*/
	error = HAL_I2C_Mem_Write(&hi2c1, addr, reg, I2C_MEMADD_SIZE_16BIT, buf, len, 100);
		/** _i2c1_unlock(); **/			/*Only in Free RTOs*/

	if (error != HAL_OK){
		return BOARD_FAILED;
	}

    return BOARD_SUCCESS;
}

int8_t board_sht30_read(uint8_t addr, uint16_t reg, uint8_t *buf, uint16_t len){
	HAL_StatusTypeDef error;

	assert(buf != NULL);
	assert(len != 0);

		/** _i2c1_lock(); **/	/*Only in Free RTOs*/
	/*error = HAL_I2C_Master_Receive(&hi2c1, addr, buf, len, 100);*/
	error = HAL_I2C_Mem_Read(&hi2c1, addr, reg, I2C_MEMADD_SIZE_16BIT, buf, len, 100);
		/** _i2c1_unlock(); **/			/*Only in Free RTOs*/

	if (error != HAL_OK){
		return BOARD_FAILED;
	}

    return BOARD_SUCCESS;
}
