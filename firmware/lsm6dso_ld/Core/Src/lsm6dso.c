/*
 * lsm6dso.c
 *
 *  Created on: Sep 22, 2026
 *      Author: Alexander Bendezu
 */

#include <stdint.h>
#include <stdio.h>

#include "lsm6dso.h"

HAL_StatusTypeDef lsm6dso_init(lsm6dso_t *lsm6dso, I2C_HandleTypeDef *hi2c, uint8_t dev_num){
  /*
   * Use HAL I2C function to write 38h to CTRL1_XL
   */
  if(hi2c == NULL || lsm6dso == NULL){
    return HAL_ERROR;
  }

  if(dev_num > 1){
    return HAL_ERROR;
  }

  lsm6dso->hi2c = hi2c;
  lsm6dso->dev_addr = LSM6DSO_DEV_ADDRESS(dev_num);
  uint8_t val = LSM6DSO_CTRL1_XL_ODR_XL_52HZ | LSM6DSO_CTRL1_XL_FS_XL_4G;

  HAL_StatusTypeDef status = HAL_I2C_Mem_Write(lsm6dso->hi2c,
                                               lsm6dso->dev_addr,
                                               LSM6DSO_CTRL1_XL_REG_ADDR,
                                               I2C_MEMADD_SIZE_8BIT,
                                               &val,
                                               sizeof(val),
                                               HAL_MAX_DELAY);

  if(status != HAL_OK){
    return HAL_ERROR;
  }

  val = LSM6DSO_CTRL3_C_BDU_MASK | LSM6DSO_CTRL3_C_IF_INC_MASK;

  status = HAL_I2C_Mem_Write(lsm6dso->hi2c,
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

HAL_StatusTypeDef lsm6dso_read_xl(lsm6dso_t *lsm6dso, I2C_HandleTypeDef *hi2c){
  if (lsm6dso == NULL || hi2c == NULL){
    return HAL_ERROR;
  }

  int32_t sum_x = 0;
  int32_t sum_y = 0;
  int32_t sum_z = 0;
  uint32_t counter = 0U;
  uint32_t wait_start = HAL_GetTick();

  while (counter < LSM6DSO_NUM_OF_SAMPLES) {
    if ((uint32_t)(HAL_GetTick() - wait_start) >= 1000U) {
      return HAL_TIMEOUT;
    }

    uint8_t data_avail;
    HAL_StatusTypeDef status;

    status = HAL_I2C_Mem_Read(hi2c,
                              lsm6dso->dev_addr,
                              LSM6DSO_STATUS_REG_ADDR,
                              I2C_MEMADD_SIZE_8BIT,
                              &data_avail,
                              sizeof(data_avail),
                              100U
                              );

    if (status != HAL_OK) {
      return status;
    }

    if ((data_avail & LSM6DSO_STATUS_XLDA_MASK) == 0U) {
      HAL_Delay(1U);
      continue;
    }

    uint8_t byte;
    uint16_t data_x = 0U;
    uint16_t data_y = 0U;
    uint16_t data_z = 0U;

    status = HAL_I2C_Mem_Read(hi2c,
                              lsm6dso->dev_addr,
                              LSM6DSO_OUTX_L_A_REG_ADDR,
                              I2C_MEMADD_SIZE_8BIT,
                              &byte,
                              sizeof(byte),
                              100U
                              );

    if (status != HAL_OK) {
      return status;
    }
    data_x = byte;

    status = HAL_I2C_Mem_Read(hi2c,
                              lsm6dso->dev_addr,
                              LSM6DSO_OUTX_H_A_REG_ADDR,
                              I2C_MEMADD_SIZE_8BIT,
                              &byte,
                              sizeof(byte),
                              100U
                              );

    if (status != HAL_OK) {
      return status;
    }
    data_x |= ((uint16_t)byte) << 8;

    status = HAL_I2C_Mem_Read(hi2c,
                              lsm6dso->dev_addr,
                              LSM6DSO_OUTY_L_A_REG_ADDR,
                              I2C_MEMADD_SIZE_8BIT,
                              &byte,
                              sizeof(byte),
                              100U
                              );

    if (status != HAL_OK) {
      return status;
    }
    data_y = byte;

    status = HAL_I2C_Mem_Read(hi2c,
                              lsm6dso->dev_addr,
                              LSM6DSO_OUTY_H_A_REG_ADDR,
                              I2C_MEMADD_SIZE_8BIT,
                              &byte,
                              sizeof(byte),
                              100U
                              );

    if (status != HAL_OK) {
      return status;
    }
    data_y |= ((uint16_t)byte) << 8;

    status = HAL_I2C_Mem_Read(hi2c,
                              lsm6dso->dev_addr,
                              LSM6DSO_OUTZ_L_A_REG_ADDR,
                              I2C_MEMADD_SIZE_8BIT,
                              &byte,
                              sizeof(byte),
                              100U
                              );

    if (status != HAL_OK) {
      return status;
    }
    data_z = byte;

    status = HAL_I2C_Mem_Read(hi2c,
                              lsm6dso->dev_addr,
                              LSM6DSO_OUTZ_H_A_REG_ADDR,
                              I2C_MEMADD_SIZE_8BIT,
                              &byte,
                              sizeof(byte),
                              100U
                              );

    if (status != HAL_OK) {
      return status;
    }
    data_z |= ((uint16_t)byte) << 8;

    sum_x += (int16_t)data_x;
    sum_y += (int16_t)data_y;
    sum_z += (int16_t)data_z;

    counter++;
    wait_start = HAL_GetTick();
  }

  lsm6dso->data_x = (int16_t)(sum_x / (int32_t)LSM6DSO_NUM_OF_SAMPLES);
  lsm6dso->data_y = (int16_t)(sum_y / (int32_t)LSM6DSO_NUM_OF_SAMPLES);
  lsm6dso->data_z = (int16_t)(sum_z / (int32_t)LSM6DSO_NUM_OF_SAMPLES);

  return HAL_OK;
}
