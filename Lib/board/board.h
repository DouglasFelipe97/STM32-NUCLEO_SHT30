/*
 * board.h
 *
 *  Created on: Sep 15, 2024
 *      Author: pablo-jean
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdarg.h>
#include <assert.h>


/*
 * Macros
 */

#define BOARD_SUCCESS				(0)
#define BOARD_FAILED				(-1)

#define BOARD_TASK_PRIO_LOWEST		(1)
#define BOARD_TASK_PRIO_LOWER		(2)
#define BOARD_TASK_PRIO_LOW			(3)
#define BOARD_TASK_PRIO_MID			(4)
#define BOARD_TASK_PRIO_HIGH		(5)
#define BOARD_TASK_PRIO_HIGHER		(6)
#define BOARD_TASK_PRIO_HIGHEST		(7)

#define loop						while(1)

/*
 * Externs
 */


/*
 * Publics
 */

int8_t board_sht30_write(uint8_t addr, uint16_t reg, uint8_t *buf, uint16_t len);

int8_t board_sht30_read(uint8_t addr, uint16_t reg, uint8_t *buf, uint16_t len);

#endif /* BOARD_H_ */
