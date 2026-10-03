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
  uint8_t val = 0x38;

  return HAL_I2C_Mem_Write(
      lsm6dso->hi2c,
      lsm6dso->dev_addr,
      LSM6DSO_CTRL1_XL_REG,
      I2C_MEMADD_SIZE_8BIT,
      &val,
      sizeof(val),
      HAL_MAX_DELAY
  );
}
