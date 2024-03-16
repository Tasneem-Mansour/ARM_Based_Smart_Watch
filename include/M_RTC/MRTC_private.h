/*
 * MRTC_private.h
 *
 *  Created on: Mar 8, 2024
 *      Author: Tasneem
 */

#ifndef MRTC_PRIVATE_H_
#define MRTC_PRIVATE_H_

#define RTC_BASE_ADDRESS 		0X40002800
#define PWR_BASE_ADDRESS        0X40007000

typedef struct {
	uint32  PWR_CR;
	uint32  PWR_CSR;
}PWR_t;

typedef struct {
	uint32 RTC_TR;
	uint32 RTC_DR;
	uint32 RTC_CR;
	uint32 RTC_ISR;
	uint32 RTC_PRER;
	uint32 RTC_WUTR;
	uint32 RTC_CALIBR;
	uint32 RTC_ALRMAR;
	uint32 RTC_ALRMBR;
	uint32 RTC_WPR;
	uint32 RTC_SSR;
	uint32 reserved0;
	uint32 RTC_TSTR;
	uint32 reserved1;
	uint32 RTC_TSSSR;
	uint32 RTC_CALR;
	uint32 RTC_TAFCR;
	uint32 RTC_ALRMASSR;
	uint32 RTC_ALRMBSSR;
	uint32 reserved2;
	uint32 RTC_BKPxR[19];
}RTC_t;



#define RTC       ((volatile RTC_t*)(RTC_BASE_ADDRESS))
#define PWR       ((volatile PWR_t*)(PWR_BASE_ADDRESS))


#define RTC_PRESCALER_MASK    0x007F7FFF

#define PWR_CR_DBP 		8

#define RCC_CSR_LSION	0
#define	RCC_CSR_LSIRDY	1

#define RCC_BDCR_LSEON	0
#define RCC_BDCR_LSERDY 1

#define RTC_WPR_KEY1    0xCA
#define RTC_WPR_KEY2    0x53

#define RTC_ISR_INIT	7
#define RTC_ISR_INITF	6
#define RTC_ISR_INITS	4


#define RTC_PRER_PREDIV_S         0
#define RTC_PRER_PREDIV_A         16

#define RTC_CR_BYPSHAD	5
#define RTC_CR_FMT		6
#define RTC_CR_TSE		11

//#define RTC_TR_PM		22
//#define RTC_TR_HT		20
//#define RTC_TR_HU		16
//#define RTC_TR_MT		12
//#define RTC_TR_MU		8
//#define RTC_TR_ST		4
//#define RTC_TR_SU		0


//#define RTC_DR_YT		20
//#define RTC_DR_YU		16
//#define RTC_DR_WDU		13
//#define RTC_DR_MT		12
//#define RTC_DR_MU		8
//#define RTC_DR_DT		4
//#define RTC_DR_DU		0


//
//#define RTC_TR_HT_Msk		0x00300000
//#define RTC_TR_HU_Msk		0x000F0000
//#define RTC_TR_MT_Msk		0x7000
//#define RTC_TR_MU_Msk		0xF00
//#define RTC_TR_ST_Msk		0x70
//#define RTC_TR_SU_Msk		0xF

//#define RTC_DR_YT_Msk		0xF00000
//#define RTC_DR_YU_Msk		0xF0000
//#define RTC_DR_MT_Msk		0x1000
//#define RTC_DR_MU_Msk		0xF00
//#define RTC_DR_DT_Msk		0x30
//#define RTC_DR_DU_Msk		0xF




#define RTC_TR_PM_Pos                 (22U)
#define RTC_TR_PM_Msk                 (0x1UL << RTC_TR_PM_Pos)                  /*!< 0x00400000 */
#define RTC_TR_PM                     RTC_TR_PM_Msk

#define RTC_TR_HT_Pos                 (20U)
#define RTC_TR_HT_Msk                 (0x3UL << RTC_TR_HT_Pos)                  /*!< 0x00300000 */
#define RTC_TR_HT                     RTC_TR_HT_Msk
//#define RTC_TR_HT_0                   (0x1UL << RTC_TR_HT_Pos)                  /*!< 0x00100000 */
//#define RTC_TR_HT_1                   (0x2UL << RTC_TR_HT_Pos)                  /*!< 0x00200000 */

#define RTC_TR_HU_Pos                 (16U)
#define RTC_TR_HU_Msk                 (0xFUL << RTC_TR_HU_Pos)                  /*!< 0x000F0000 */
#define RTC_TR_HU                     RTC_TR_HU_Msk
//#define RTC_TR_HU_0                   (0x1UL << RTC_TR_HU_Pos)                  /*!< 0x00010000 */
//#define RTC_TR_HU_1                   (0x2UL << RTC_TR_HU_Pos)                  /*!< 0x00020000 */
//#define RTC_TR_HU_2                   (0x4UL << RTC_TR_HU_Pos)                  /*!< 0x00040000 */
//#define RTC_TR_HU_3                   (0x8UL << RTC_TR_HU_Pos)                  /*!< 0x00080000 */

#define RTC_TR_MNT_Pos                (12U)
#define RTC_TR_MNT_Msk                (0x7UL << RTC_TR_MNT_Pos)                 /*!< 0x00007000 */
#define RTC_TR_MNT                    RTC_TR_MNT_Msk
//#define RTC_TR_MNT_0                  (0x1UL << RTC_TR_MNT_Pos)                 /*!< 0x00001000 */
//#define RTC_TR_MNT_1                  (0x2UL << RTC_TR_MNT_Pos)                 /*!< 0x00002000 */
//#define RTC_TR_MNT_2                  (0x4UL << RTC_TR_MNT_Pos)                 /*!< 0x00004000 */

#define RTC_TR_MNU_Pos                (8U)
#define RTC_TR_MNU_Msk                (0xFUL << RTC_TR_MNU_Pos)                 /*!< 0x00000F00 */
#define RTC_TR_MNU                    RTC_TR_MNU_Msk
//#define RTC_TR_MNU_0                  (0x1UL << RTC_TR_MNU_Pos)                 /*!< 0x00000100 */
//#define RTC_TR_MNU_1                  (0x2UL << RTC_TR_MNU_Pos)                 /*!< 0x00000200 */
//#define RTC_TR_MNU_2                  (0x4UL << RTC_TR_MNU_Pos)                 /*!< 0x00000400 */
//#define RTC_TR_MNU_3                  (0x8UL << RTC_TR_MNU_Pos)                 /*!< 0x00000800 */

#define RTC_TR_ST_Pos                 (4U)
#define RTC_TR_ST_Msk                 (0x7UL << RTC_TR_ST_Pos)                  /*!< 0x00000070 */
#define RTC_TR_ST                     RTC_TR_ST_Msk
//#define RTC_TR_ST_0                   (0x1UL << RTC_TR_ST_Pos)                  /*!< 0x00000010 */
//#define RTC_TR_ST_1                   (0x2UL << RTC_TR_ST_Pos)                  /*!< 0x00000020 */
//#define RTC_TR_ST_2                   (0x4UL << RTC_TR_ST_Pos)                  /*!< 0x00000040 */

#define RTC_TR_SU_Pos                 (0U)
#define RTC_TR_SU_Msk                 (0xFUL << RTC_TR_SU_Pos)                  /*!< 0x0000000F */
#define RTC_TR_SU                     RTC_TR_SU_Msk
//#define RTC_TR_SU_0                   (0x1UL << RTC_TR_SU_Pos)                  /*!< 0x00000001 */
//#define RTC_TR_SU_1                   (0x2UL << RTC_TR_SU_Pos)                  /*!< 0x00000002 */
//#define RTC_TR_SU_2                   (0x4UL << RTC_TR_SU_Pos)                  /*!< 0x00000004 */
//#define RTC_TR_SU_3                   (0x8UL << RTC_TR_SU_Pos)                  /*!< 0x00000008 */


/*******************************************************************************************************/
//#define RTC_TR_RESERVED_MASK    0x007F7F7F
//#define RTC_DR_RESERVED_MASK    0x00FFFF3F

#define RTC_TR_RESERVED_MASK    ((uint32)(RTC_TR_HT  | RTC_TR_HU  | \
                                            RTC_TR_MNT | RTC_TR_MNU | \
                                            RTC_TR_ST  | RTC_TR_SU  | \
                                            RTC_TR_PM))

#define RTC_DR_RESERVED_MASK    ((uint32)(RTC_DR_YT  | RTC_DR_YU  | \
											RTC_DR_MT | RTC_DR_MU | \
											RTC_DR_DT  | RTC_DR_DU  | \
											RTC_DR_WDU))

/*******************************************************************************************************/
#define RTC_DR_YT_Pos                 (20U)
#define RTC_DR_YT_Msk                 (0xFUL << RTC_DR_YT_Pos)                  /*!< 0x00300000 */
#define RTC_DR_YT                     RTC_DR_YT_Msk
//#define RTC_DR_YT_0                   (0x1UL << RTC_DR_YT_Pos)                  /*!< 0x00100000 */
//#define RTC_DR_YT_1                   (0x2UL << RTC_DR_YT_Pos)                  /*!< 0x00200000 */

#define RTC_DR_YU_Pos                 (16U)
#define RTC_DR_YU_Msk                 (0xFUL << RTC_DR_YU_Pos)                  /*!< 0x000F0000 */
#define RTC_DR_YU                     RTC_DR_YU_Msk
//#define RTC_DR_YU_0                   (0x1UL << RTC_DR_YU_Pos)                  /*!< 0x00010000 */
//#define RTC_DR_YU_1                   (0x2UL << RTC_DR_YU_Pos)                  /*!< 0x00020000 */
//#define RTC_DR_YU_2                   (0x4UL << RTC_DR_YU_Pos)                  /*!< 0x00040000 */
//#define RTC_DR_YU_3                   (0x8UL << RTC_DR_YU_Pos)                  /*!< 0x00080000 */

#define RTC_DR_WDU_Pos                (13U)
#define RTC_DR_WDU_Msk                (0x7UL << RTC_DR_WDU_Pos)                  /*!< 0x00300000 */
#define RTC_DR_WDU                    RTC_DR_WDU_Msk

#define RTC_DR_MT_Pos                 (12U)
#define RTC_DR_MT_Msk                 (0x1UL << RTC_DR_MT_Pos)                 /*!< 0x00007000 */
#define RTC_DR_MT                     RTC_DR_MT_Msk

#define RTC_DR_MU_Pos                 (8U)
#define RTC_DR_MU_Msk                 (0xFUL << RTC_DR_MU_Pos)                 /*!< 0x00000F00 */
#define RTC_DR_MU                     RTC_DR_MU_Msk

#define RTC_DR_DT_Pos                 (4U)
#define RTC_DR_DT_Msk                 (0x3UL << RTC_DR_DT_Pos)                 /*!< 0x00007000 */
#define RTC_DR_DT                     RTC_DR_DT_Msk

#define RTC_DR_DU_Pos                 (0U)
#define RTC_DR_DU_Msk                 (0xFUL << RTC_DR_DU_Pos)                 /*!< 0x00000F00 */
#define RTC_DR_DU 					  RTC_DR_DU_Msk
#endif /* MRTC_PRIVATE_H_ */
