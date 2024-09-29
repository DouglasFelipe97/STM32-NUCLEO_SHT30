/*
 * Sensor_SHT30.c
 *
 *  Created on: Sep 08, 2024
 *      Author: DouglasFelipe97
 */
 
#if (SENSOR_SHT3X_SELECTED == SENSOR_SHT3X_SHT30)

/*
 * Includes
 */
#include "Sensor_SHT3X.h"
#include "driver_sht30.h"
#include "stm32l4xx_hal.h"
/* Handler */

static sht30_handle_t gs_handle;        /**< sht30 handle */

/*
 * Privates
 */
 uint8_t sht30_interface_iic_init(void){
	 return 0;
 }
 
 uint8_t sht30_interface_iic_deinit(void){
	 return 0;
 }
 
 uint8_t sht30_interface_iic_scl_read_address16(uint8_t addr, uint16_t reg, uint8_t *buf, uint16_t len){
	 uint8_t error;
	 
	error = board_sht30_write(addr, &reg, buf, sizeof(reg));
	if (error != 0){
		return 1;
	}
	error = board_sht30_read(addr, &reg, buf, len);
	if (error != 0){
		return 1;
	}

    return 0;
 }
 
 uint8_t sht30_interface_iic_write_address16(uint16_t addr, uint16_t reg, uint8_t *buf, uint16_t len){
	 HAL_StatusTypeDef error;
	uint8_t arr[32];

	arr[0] = reg;
	memcpy(arr+1, buf, len);
	error = board_sht30_write(addr, &reg, arr, (len+sizeof(reg)));
	if (error != 0){
		return 1;
	}

    return 0;
 }

 void sht30_interface_delay_ms(uint32_t ms){
	HAL_Delay(ms);
}

void sht30_interface_debug_print(){
	
}
/*
 * Publics
 */
void SensorSHT3X_Init(sht30_address_t addr_pin){

    /* Inicializa o Handle do SHT30 e atribui as funcoes */
    DRIVER_SHT30_LINK_INIT(&gs_handle, sht30_handle_t);
    DRIVER_SHT30_LINK_IIC_INIT(&gs_handle, sht30_interface_iic_init);
    DRIVER_SHT30_LINK_IIC_DEINIT(&gs_handle, sht30_interface_iic_deinit);
    DRIVER_SHT30_LINK_IIC_READ_ADDRESS16(&gs_handle, sht30_interface_iic_scl_read_address16);
    DRIVER_SHT30_LINK_IIC_WRITE_ADDRESS16(&gs_handle, sht30_interface_iic_write_address16);
    DRIVER_SHT30_LINK_DELAY_MS(&gs_handle, sht30_interface_delay_ms);
    DRIVER_SHT30_LINK_DEBUG_PRINT(&gs_handle, sht30_interface_debug_print);

    /* set addr pin */
    sht30_set_addr_pin(&gs_handle, addr_pin);
    /* sht30 init */
    sht30_init(&gs_handle);
    /* wait 10 ms */
    sht30_interface_delay_ms(10);   
    /* set default repeatability */
    sht30_set_repeatability(&gs_handle, SHT30_SHOT_DEFAULT_REPEATABILITY);   
    /* set art */
    sht30_set_art(&gs_handle);    
    /* wait 10 ms */
    sht30_interface_delay_ms(10);
    /* set default heater */
    sht30_set_heater(&gs_handle, SHT30_SHOT_DEFAULT_HEATER);
}
void SensorSHT3X_SetParam(sensor_sht3x_param_e param, uint32_t val){
	
}
uint8_t SensorSHT3X_Read(float *temperature, float *humidity){
    uint16_t temperature_raw;
    uint16_t humidity_raw;
   
    /* read data */
    if (sht30_continuous_read(&gs_handle, (uint16_t *)&temperature_raw, temperature, (uint16_t *)&humidity_raw, humidity) != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

#endif
