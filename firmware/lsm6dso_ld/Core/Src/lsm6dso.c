/*
 * lsm6dso.c
 *
 *  Created on: Sep 22, 2026
 *      Author: Alexander Bendezu
 */
#include <stdint.h>
#include <stdio.h>

#include "lsm6dso.h"

HAL_StatusTypeDef lsm6dso_init(lsm6dso_t *lsm6dso, I2C_HandleTypeDef *hi2c, uint8_t dev_num) {
  /*
   * Use HAL I2C function to write 38h to CTRL1_XL
   */
  if(hi2c == NULL || lsm6dso == NULL)
    return HAL_ERROR;

  if(dev_num > 1)
    return HAL_ERROR;

  lsm6dso->hi2c = hi2c;
  lsm6dso->dev_addr = LSM6DSO_DEV_ADDRESS(dev_num);
  uint8_t val = LSM6DSO_ODR_XL_52Hz | 
                LSM6DSO_FS_XL_4G;

  HAL_StatusTypeDef status = HAL_I2C_Mem_Write(lsm6dso->hi2c, 
                                               lsm6dso->dev_addr, 
                                               LSM6DSO_CTRL1_XL_REG, 
                                               I2C_MEMADD_SIZE_8BIT, 
                                               &val, 
                                               sizeof(val), 
                                               HAL_MAX_DELAY);

  if(status != HAL_OK)
    return HAL_ERROR;

  val = LSM6DSO_CTRL3_C_BDU_MASK | LSM6DSO_CTRL3_C_IF_INC_MASK;

  status = HAL_I2C_Mem_Write(lsm6dso->h2ic, 
                             lsm6dso->dev_addr,
                             LSM6DSO_CTRL3_C_REG_ADDR, 
                             I2C_MEMADD_SIZE_8BIT, 
                             &val, 
                             sizeof(val), 
                             HAL_MAX_DELAY
                             );


  if(status != HAL_OK)
    return HAL_ERROR;

  HAL_Delay(100);

  return HAL_OK;
}

HAL_StatusTypeDef lsm6dso_step1(lsm6dso_t *lsm6dso, I2C_HandleTypeDef *hi2c){

  if(hi2c == NULL || lsm6dso == NULL)
    return HAL_ERROR;

  if(dev_num > 1)
    return HAL_ERROR;

  uint8_t data_avail;

  HAL_StatusTypeDef status = HAL_I2C_Mem_Read(lsm6dso->hi2c,
                                              lsm6dso->dev_addr,
                                              LSM6DSO_STATUS_REG_ADDR,
                                              I2C_MEMADD_SIZE_8BIT,
                                              &data_avail,
                                              sizeof(data),
                                              HAL_MAX_DELAY
                                              );

  if(status != HAL_OK)
    return status;

  if(data_avail == LSM6DSO_STATUS_XLDA_MASK){
    uint8_t byte;
    uint16_t data_x = 0, data_y = 0, data_z = 0;
    status = HAL_I2C_Mem_Read(lsm6dso->hi2c,
                              lsm6dso->dev_addr,
                              LSM6DSO_OUTX_L_A_REG_ADDR,
                              I2C_MEMADD_SIZE_8BIT,
                              &byte,
                              sizeof(byte),
                              HAL_MAX_DELAY
                              );
    if(status != HAL_OK)
      return status;
    data_x |= byte;

    status = HAL_I2C_Mem_Read(lsm6dso->hi2c,
                              lsm6dso->dev_addr,
                              LSM6DSO_OUTX_H_A_REG_ADDR
                              I2C_MEMADD_SIZE_8BIT,
                              &byte,
                              sizeof(byte),
                              HAL_MAX_DELAY
                              );
    if(status != HAL_OK)
      return status;


    data_x |= ((uint16_t) byte) << 8;





  }

  return HAL_OK; 
}
