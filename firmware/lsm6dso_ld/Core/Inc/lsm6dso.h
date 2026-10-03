#ifndef LSM6DSO_H_
#define LSM6DSO_H_

#define "main.h"

#define LSM6DSO_DEV_ADDRESS(dev_num)          (((0x6AU) | dev_num) << 1)

/* Enables access to the embedded functions configuration registers */
#define LSM6DSO_REG_FUNC_CFG_ACCESS           0x01U

#define LSM6DSO_FUNC_CFG_ACCESS_FUNC_MASK     (1U << 7)
#define LSM6DSO_FUNC_CFG_ACCESS_SHUB_MASK     (1U << 6)

/* FIFO control register 1 */
#define LSM6DSO_REG_FIFO_CTRL_1               0x07U

#define LSM6DSO_REG_WTM_CTRL_1(th)            ((uint8_t)((th) & 0xFFU))

/* FIFO control register 2 */
#define LSM6DSO_REG_FIFO_CTRL_2               0x08U

#define LSM6DSO_REG_WTM_CTRL_2                ((uint8_t)(((th) >> 8) & 0x01U))
#define LSM6DSO_STOP_ON_WTM_MASK              (1U << 7)

/* FIFO control register 3  */
#define LSM6DSO_REG_FIFO_CTRL_3               0x09U

/* Measruements are in Hz, so 12_5 is 12.5 Hz */
#define LSM6DSO_XL_NOT_BATCH                  0x00U
#define LSM6DSO_XL_BATCH_12_5Hz               0x01U
#define LSM6DSO_XL_BATCH_26Hz                 0x02U
#define LSM6DSO_XL_BATCH_52Hz                 0x03U
#define LSM6DSO_XL_BATCH_104Hz                0x04U
#define LSM6DSO_XL_BATCH_208Hz                0x05U
#define LSM6DSO_XL_BATCH_417Hz                0x06U
#define LSM6DSO_XL_BATCH_833Hz                0x07U
#define LSM6DSO_XL_BATCH_1667Hz               0x08U
#define LSM6DSO_XL_BATCH_3333Hz               0x09U
#define LSM6DSO_XL_BATCH_6667Hz               0x0AU
#define LSM6DSO_XL_BATCH_1_6Hz                0x0BU
#define LSM6DSO_XL_BATCH_MASK                 0X0FU

/* FIFO control register 4  */
#define LSM6DSO_REG_FIFO_CTRL_4               0X0AU

#define LSM6DSO_DEC_TS_BATCH_DISABLE          0X00U
#define LSM6DSO_DEC_TS_BATCH_1                (0X01 << 6)  
#define LSM6DSO_DEC_TS_BATCH_8                (0X02 << 6)
#define LSM6DSO_DEC_TS_BATCH_32               (0X03 << 6)
#define LSM6DSO_FIFO_DISABLE                  0X00U 
#define LSM6DSO_FIFO_MODE                     0x01U
#define LSM6DSO_CONT_TO_FIFO_MODE             0x03U
#define LSM6DSO_BYPASS_TO_CONT_MODE           0X04U
#define LSM6DSO_CONTINUOUS_MODE               0X06U
#define LSM6DSO_BYPASS_TO_FIFO_MODE           0X07U

/* Counter batch data rate register 1*/
#define LSM6DSO_COUNTER_BDR_REG_1             0X0BU

#define LSM6DSO_DATA_READY_LATCHED_MODE       0x00U
#define LSM6DSO_DATA_READY_PULSED_MODE        (0x01U << 7)
#define LSM6DSO_RST_COUNTER_BDR_MASK          (0x01U << 6)

#define LSM6DSO_CNT_BDR_TH_10_8(th)           (((uint8_t)((th) >> 8)) & 0x07U)

/* Counter batch data rate register 2 */
#define LSM6DSO_COUNTER_BDR_REG_2             0x0CU

#define LSM6DSO_CNT_BRD_TH_7_0(th)            ((uint8_t)((th) & 0xFFU))

/* INT1 pin control register */
#define LSM6DS0_INT1_CTRL_REG                 0X0DU

#define LSM6DS0_DEN_DRDY_FLAG
#define LSM6DSO_INT1_CNT_BDR_MASK             (0x01U << 6)
#define LSM6DSO_INT1_FIFO_FULL_MASK           (0x01U << 5)
#define LSM6DSO_INT1_FIFO_OVR_MASK            (0x01U << 4)
#define LSM5DSO_INT1_FIFO_TH_MASK             (0x01U << 3)
#define LSM5DSO_INT1_BOOT_MASK                (0x01U << 2)
#define LSM6DSO_INT1_DRDY_XL_MASK             0x01U


/* INT2 pin control register */
#define LSM6DSO_INT2_CTRL_REG                 0x0EU

#define LSM6DSO_INT2_CNT_BDR_MASK   

/* WHO_AM_I register */
#define LSM6DSO_WHO_AM_I_REG                  0X0FU

#define LSM6DSO_WHO_AM_I_VALUE                0x6CU

/* Accelerometer control register 1 */
#define LSM6DSO_CTRL1_XL_REG                  0x10U

#define LSM6DSO_ODR_XL_OFF                    0x00U

#define LSM6DSO_ODR_XL_1_6_LPERF              (0x0BU << 4)
#define LSM6DSO_ODR_XL_12_5_HPERF             (0x0BU << 4)

/* These modes are the same when XL_HM_MODE = 1 | 0 but dpends on CTRL6_C*/
#define LSM6DSO_ODR_XL_12_5Hz                 (0x01U << 4)
#define LSM6DSO_ODR_XL_26Hz                   (0x02U << 4)
#define LSM6DSO_ODR_XL_52Hz                   (0x03U << 4)
#define LSM6DSO_ODR_XL_104Hz                  (0x04U << 4)
#define LSM6DSO_ODR_XL_208Hz                  (0x05U << 4)
#define LSM6DSO_ODR_XL_416Hz                  (0x06U << 4)
#define LSM6DSO_ODR_XL_833Hz                  (0x07U << 4)
#define LSM6DSO_ODR_XL_1_66kHz                (0x08U << 4)
#define LSM6DSO_ODR_XL_3_33kHz                (0x09U << 4)
#define LSM6DSO_ODR_XL_6_66kHz                (0x0AU << 4)

// not finished here depends on CTRL8_XL
#define LSM6DSO_FS_XL_2G                      0x00U
#define LSM6DSO_FS_XL_16G                     (0x01U << 2)
#define LSM6DSO_FS_XL_4G                      (0x02U << 2)
#define LSM6DSO_fL_FS_8G                      (0x03U << 2)

#define LSM6DSO_LPF_XL_EN_MASK                (0x01U << 1)


typedef struct{
  I2C_HandleTypeDef *hi2c;
  SPI_HandleTypeDef *hspi;
  uint8_t dev_addr;
}lsm6dso_t;


#endif /* LSM6DSO_H_ */
