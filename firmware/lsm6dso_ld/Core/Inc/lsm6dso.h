#ifndef LSM6DSO_H_
#define LSM6DSO_H_

#include <stdint.h>
#include "main.h"

/* STM32 HAL uses the 7-bit I2C address shifted left by one bit.
 * The caller must validate that dev_num is 0 or 1.
 */
#define LSM6DSO_DEV_ADDRESS(dev_num)                      ((0x6AU | (dev_num)) << 1)

/* Embedded-function and sensor-hub register access. */
#define LSM6DSO_FUNC_CFG_ACCESS_REG_ADDR                  0x01U

#define LSM6DSO_FUNC_CFG_ACCESS_FUNC_CFG_ACCESS_MASK      (0x01U << 7)
#define LSM6DSO_FUNC_CFG_ACCESS_SHUB_REG_ACCESS_MASK      (0x01U << 6)

/* FIFO control register 1: watermark threshold bits 7:0. */
#define LSM6DSO_FIFO_CTRL1_REG_ADDR                       0x07U

#define LSM6DSO_FIFO_CTRL1_WTM_MASK                       0xFFU
#define LSM6DSO_FIFO_CTRL1_WTM_VALUE(th)                  ((uint8_t)((uint16_t)(th) & 0xFFU))

/* FIFO control register 2: watermark threshold bit 8. */
#define LSM6DSO_FIFO_CTRL2_REG_ADDR                       0x08U

#define LSM6DSO_FIFO_CTRL2_STOP_ON_WTM_MASK               (0x01U << 7)
#define LSM6DSO_FIFO_CTRL2_WTM8_MASK                      0x01U
#define LSM6DSO_FIFO_CTRL2_WTM8_VALUE(th)                 ((uint8_t)(((uint16_t)(th) >> 8) & 0x01U))

/* FIFO control register 3: accelerometer batch data rate. */
#define LSM6DSO_FIFO_CTRL3_REG_ADDR                       0x09U

#define LSM6DSO_FIFO_CTRL3_BDR_XL_MASK                    0x0FU
#define LSM6DSO_FIFO_CTRL3_BDR_XL_OFF                     0x00U
#define LSM6DSO_FIFO_CTRL3_BDR_XL_12_5HZ                  0x01U
#define LSM6DSO_FIFO_CTRL3_BDR_XL_26HZ                    0x02U
#define LSM6DSO_FIFO_CTRL3_BDR_XL_52HZ                    0x03U
#define LSM6DSO_FIFO_CTRL3_BDR_XL_104HZ                   0x04U
#define LSM6DSO_FIFO_CTRL3_BDR_XL_208HZ                   0x05U
#define LSM6DSO_FIFO_CTRL3_BDR_XL_417HZ                   0x06U
#define LSM6DSO_FIFO_CTRL3_BDR_XL_833HZ                   0x07U
#define LSM6DSO_FIFO_CTRL3_BDR_XL_1667HZ                  0x08U
#define LSM6DSO_FIFO_CTRL3_BDR_XL_3333HZ                  0x09U
#define LSM6DSO_FIFO_CTRL3_BDR_XL_6667HZ                  0x0AU
#define LSM6DSO_FIFO_CTRL3_BDR_XL_1_6HZ                   0x0BU

/* FIFO control register 4: timestamp decimation and FIFO mode. */
#define LSM6DSO_FIFO_CTRL4_REG_ADDR                       0x0AU

#define LSM6DSO_FIFO_CTRL4_DEC_TS_BATCH_MASK              (0x03U << 6)
#define LSM6DSO_FIFO_CTRL4_DEC_TS_BATCH_DISABLED          0x00U
#define LSM6DSO_FIFO_CTRL4_DEC_TS_BATCH_1                 (0x01U << 6)
#define LSM6DSO_FIFO_CTRL4_DEC_TS_BATCH_8                 (0x02U << 6)
#define LSM6DSO_FIFO_CTRL4_DEC_TS_BATCH_32                (0x03U << 6)

#define LSM6DSO_FIFO_CTRL4_FIFO_MODE_MASK                 0x07U
#define LSM6DSO_FIFO_CTRL4_FIFO_MODE_BYPASS               0x00U
#define LSM6DSO_FIFO_CTRL4_FIFO_MODE_FIFO                 0x01U
#define LSM6DSO_FIFO_CTRL4_FIFO_MODE_CONT_TO_FIFO         0x03U
#define LSM6DSO_FIFO_CTRL4_FIFO_MODE_BYPASS_TO_CONT       0x04U
#define LSM6DSO_FIFO_CTRL4_FIFO_MODE_CONTINUOUS           0x06U
#define LSM6DSO_FIFO_CTRL4_FIFO_MODE_BYPASS_TO_FIFO       0x07U

/* Batch-event counter register 1: threshold bits 10:8.
 * COUNTER_BDR_REG1 is the register name used in the datasheet.
 */
#define LSM6DSO_COUNTER_BDR_REG1_REG_ADDR                 0x0BU

#define LSM6DSO_COUNTER_BDR_REG1_DATAREADY_PULSED_MASK    (0x01U << 7)
#define LSM6DSO_COUNTER_BDR_REG1_DATAREADY_PULSED_LATCHED 0x00U
#define LSM6DSO_COUNTER_BDR_REG1_DATAREADY_PULSED_PULSED  (0x01U << 7)
#define LSM6DSO_COUNTER_BDR_REG1_RST_COUNTER_BDR_MASK     (0x01U << 6)
#define LSM6DSO_COUNTER_BDR_REG1_CNT_BDR_TH_MASK          0x07U
#define LSM6DSO_COUNTER_BDR_REG1_CNT_BDR_TH_VALUE(th)     ((uint8_t)(((uint16_t)(th) >> 8) & 0x07U))

/* Batch-event counter register 2: threshold bits 7:0. */
#define LSM6DSO_COUNTER_BDR_REG2_REG_ADDR                 0x0CU

#define LSM6DSO_COUNTER_BDR_REG2_CNT_BDR_TH_MASK          0xFFU
#define LSM6DSO_COUNTER_BDR_REG2_CNT_BDR_TH_VALUE(th)     ((uint8_t)((uint16_t)(th) & 0xFFU))

/* INT1 pin control register. */
#define LSM6DSO_INT1_CTRL_REG_ADDR                        0x0DU

#define LSM6DSO_INT1_CTRL_DEN_DRDY_FLAG_MASK              (0x01U << 7)
#define LSM6DSO_INT1_CTRL_INT1_CNT_BDR_MASK               (0x01U << 6)
#define LSM6DSO_INT1_CTRL_INT1_FIFO_FULL_MASK             (0x01U << 5)
#define LSM6DSO_INT1_CTRL_INT1_FIFO_OVR_MASK              (0x01U << 4)
#define LSM6DSO_INT1_CTRL_INT1_FIFO_TH_MASK               (0x01U << 3)
#define LSM6DSO_INT1_CTRL_INT1_BOOT_MASK                  (0x01U << 2)
#define LSM6DSO_INT1_CTRL_INT1_DRDY_XL_MASK               0x01U

/* INT2 pin control register. */
#define LSM6DSO_INT2_CTRL_REG_ADDR                        0x0EU

#define LSM6DSO_INT2_CTRL_INT2_CNT_BDR_MASK               (0x01U << 6)

/* Device identification register. */
#define LSM6DSO_WHO_AM_I_REG_ADDR                         0x0FU
#define LSM6DSO_WHO_AM_I_VALUE                            0x6CU

/* Accelerometer control register 1. */
#define LSM6DSO_CTRL1_XL_REG_ADDR                         0x10U

#define LSM6DSO_CTRL1_XL_ODR_XL_MASK                      (0x0FU << 4)
#define LSM6DSO_CTRL1_XL_ODR_XL_OFF                       0x00U

/* The 0xB ODR encoding depends on CTRL6_C.XL_HM_MODE:
 * 1: 1.6 Hz low power; 0: 12.5 Hz high performance.
 */
#define LSM6DSO_CTRL1_XL_ODR_XL_1_6HZ_LOW_POWER           (0x0BU << 4)
#define LSM6DSO_CTRL1_XL_ODR_XL_12_5HZ_HIGH_PERFORMANCE   (0x0BU << 4)

#define LSM6DSO_CTRL1_XL_ODR_XL_12_5HZ                    (0x01U << 4)
#define LSM6DSO_CTRL1_XL_ODR_XL_26HZ                      (0x02U << 4)
#define LSM6DSO_CTRL1_XL_ODR_XL_52HZ                      (0x03U << 4)
#define LSM6DSO_CTRL1_XL_ODR_XL_104HZ                     (0x04U << 4)
#define LSM6DSO_CTRL1_XL_ODR_XL_208HZ                     (0x05U << 4)
#define LSM6DSO_CTRL1_XL_ODR_XL_416HZ                     (0x06U << 4)
#define LSM6DSO_CTRL1_XL_ODR_XL_833HZ                     (0x07U << 4)
#define LSM6DSO_CTRL1_XL_ODR_XL_1_66KHZ                   (0x08U << 4)
#define LSM6DSO_CTRL1_XL_ODR_XL_3_33KHZ                   (0x09U << 4)
#define LSM6DSO_CTRL1_XL_ODR_XL_6_66KHZ                   (0x0AU << 4)

/* Full-scale choices below assume CTRL8_XL.XL_FS_MODE = 0. */
#define LSM6DSO_CTRL1_XL_FS_XL_MASK                       (0x03U << 2)
#define LSM6DSO_CTRL1_XL_FS_XL_2G                         0x00U
#define LSM6DSO_CTRL1_XL_FS_XL_16G                        (0x01U << 2)
#define LSM6DSO_CTRL1_XL_FS_XL_4G                         (0x02U << 2)
#define LSM6DSO_CTRL1_XL_FS_XL_8G                         (0x03U << 2)

#define LSM6DSO_CTRL1_XL_LPF2_XL_EN_MASK                  (0x01U << 1)

/* Control register 3. */
#define LSM6DSO_CTRL3_C_REG_ADDR                          0x12U

#define LSM6DSO_CTRL3_C_BOOT_MASK                         (0x01U << 7)
#define LSM6DSO_CTRL3_C_BDU_MASK                          (0x01U << 6)
#define LSM6DSO_CTRL3_C_H_LACTIVE_MASK                    (0x01U << 5)
#define LSM6DSO_CTRL3_C_PP_OD_MASK                        (0x01U << 4)
#define LSM6DSO_CTRL3_C_SIM_MASK                          (0x01U << 3)
#define LSM6DSO_CTRL3_C_IF_INC_MASK                       (0x01U << 2)
#define LSM6DSO_CTRL3_C_SW_RESET_MASK                     0x01U

/* Status register read through the primary I2C/SPI/I3C interface. */
#define LSM6DSO_STATUS_REG_ADDR                           0x1EU

#define LSM6DSO_STATUS_TDA_MASK                           (0x01U << 2)
#define LSM6DSO_STATUS_GDA_MASK                           (0x01U << 1)
#define LSM6DSO_STATUS_XLDA_MASK                          0x01U

/* X-axis accelerometer output registers: low byte, then high byte. */
#define LSM6DSO_OUTX_L_A_REG_ADDR                         0x28U
#define LSM6DSO_OUTX_H_A_REG_ADDR                         0x29U

/* Byte-extraction helpers: these do not access hardware registers. */
#define LSM6DSO_OUTX_LOW_BYTE(raw)                        ((uint8_t)((uint16_t)(raw) & 0xFFU))
#define LSM6DSO_OUTX_HIGH_BYTE(raw)                       ((uint8_t)(((uint16_t)(raw) >> 8) & 0xFFU))

#define LSM6DSO_OUTY_L_A_REG_ADDR                         0x2AU
#define LSM6DSO_OUTY_H_A_REG_ADDR                         0x2BU

#define LSM6DSO_OUTY_LOW_BYTE(raw)                        ((uint8_t)((uint16_t)(raw) & 0xFFU))
#define LSM6DSO_OUTY_HIGH_BYTE(raw)                       ((uint8_t)(((uint16_t)(raw) >> 8) & 0xFFU))

#define LSM6DSO_OUTZ_L_A_REG_ADDR                         0x2CU
#define LSM6DSO_OUTZ_H_A_REG_ADDR                         0x2DU

#define LSM6DSO_OUTZ_LOW_BYTE(raw)                        ((uint8_t)((uint16_t)(raw) & 0xFFU))
#define LSM6DSO_OUTZ_HIGH_BYTE(raw)                       ((uint8_t)(((uint16_t)(raw) >> 8) & 0xFFU))

#define 


typedef struct {
    I2C_HandleTypeDef *hi2c;
    SPI_HandleTypeDef *hspi;
    uint8_t dev_addr;
    uint32_t data_x;
    uint32_t data_y;
    uint32_t data_z;
} lsm6dso_t;

#endif /* LSM6DSO_H_ */
