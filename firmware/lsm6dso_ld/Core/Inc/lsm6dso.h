#ifndef LSM6DSO_H_
#define LSM6DSO_H_


/* Enables access to the embedded functions configuration registers */
#define LSM6DSO_REG_FUNC_CFG_ACCESS           0x01U

#define LSM6DSO_FUNC_CFG_ACCESS_FUNC_MASK     (1U << 7)
#define LSM6DSO_FUNC_CFG_ACCESS_SHUB_MASK     (1U << 6)

/* FIFO control register 1 */
#define LSM6DSO_REG_FIFO_CTRL_1               0x07U

/* FIFO control register 2 */
#define LSM6DSO_REG_FIFO_CTRL_2               0x08U

#define LSM6DSO_STOP_ON_WTM_MASK              (1U << 7)

/* FIFO control register 3  */
#define LSM6DSO_REG_FIFO_CTRL_3               0x09U


/* Measruements are in Hz, so 12_5 is 12.5 Hz */

#define LSM6DSO_XL_NOT_BATCH                  0x0U
#define LSM6DSO_XL_BATCH_12_5                 0x1U
#define LSM6DSO_XL_BATCH_26                   0x2U
#define LSM6DSO_XL_BATCH_52                   0x3U
#define LSM6DSO_XL_BATCH_104                  0x4U
#define LSM6DSO_XL_BATCH_208                  0x5U
#define LSM6DSO_XL_BATCH_417                  0x6U
#define LSM6DSO_XL_BATCH_833                  0x7U
#define LSM6DSO_XL_BATCH_1667                 0x8U
#define LSM6DSO_XL_BATCH_3333                 0x9U
#define LSM6DSO_XL_BATCH_6667                 0xAU
#define LSM6DSO_XL_BATCH_1_6                  0xBU






#endif /* LSM6DSO_H_ */
