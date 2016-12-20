#include <stdint.h>
#ifndef __STM32L476xx__H
#define __STM32L476xx__H
#define __IO  volatile             /*!< Defines 'read / write' permissions */
#define GPIOD_BASE            (AHB2PERIPH_BASE + 0x0C00U)
#define GPIOD               ((GPIO_TypeDef *) GPIOD_BASE)
#define PERIPH_BASE           ((uint32_t)0x40000000U) /*!< Peripheral base address */
#define AHB2PERIPH_BASE       (PERIPH_BASE + 0x08000000U)
#define APB1PERIPH_BASE        PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000U)
#define SYSCFG_BASE           (APB2PERIPH_BASE + 0x0000U)
#define SYSCFG              ((SYSCFG_TypeDef *) SYSCFG_BASE)
#define EXTI                ((EXTI_TypeDef *) EXTI_BASE)
#define EXTI_BASE             (APB2PERIPH_BASE + 0x0400U)
#define NVIC_BASE           (SCS_BASE +  0x0100UL)                    /*!< NVIC Base Address */
typedef struct
{
    __IO uint32_t MODER;       /*!< GPIO port mode register,               Address offset: 0x00      */
    __IO uint32_t OTYPER;      /*!< GPIO port output type register,        Address offset: 0x04      */
    __IO uint32_t OSPEEDR;     /*!< GPIO port output speed register,       Address offset: 0x08      */
    __IO uint32_t PUPDR;       /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
    __IO uint32_t IDR;         /*!< GPIO port input data register,         Address offset: 0x10      */
    __IO uint32_t ODR;         /*!< GPIO port output data register,        Address offset: 0x14      */
    __IO uint32_t BSRR;        /*!< GPIO port bit set/reset  register,     Address offset: 0x18      */
    __IO uint32_t LCKR;        /*!< GPIO port configuration lock register, Address offset: 0x1C      */
    __IO uint32_t AFR[2];      /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
    __IO uint32_t BRR;         /*!< GPIO Bit Reset register,               Address offset: 0x28      */
    __IO uint32_t ASCR;        /*!< GPIO analog switch control register,   Address offset: 0x2C     */

} GPIO_TypeDef;
typedef struct
{
    __IO uint32_t CR1;         /*!< TIM control register 1,                   Address offset: 0x00 */
    __IO uint32_t CR2;         /*!< TIM control register 2,                   Address offset: 0x04 */
    __IO uint32_t SMCR;        /*!< TIM slave mode control register,          Address offset: 0x08 */
    __IO uint32_t DIER;        /*!< TIM DMA/interrupt enable register,        Address offset: 0x0C */
    __IO uint32_t SR;          /*!< TIM status register,                      Address offset: 0x10 */
    __IO uint32_t EGR;         /*!< TIM event generation register,            Address offset: 0x14 */
    __IO uint32_t CCMR1;       /*!< TIM capture/compare mode register 1,      Address offset: 0x18 */
    __IO uint32_t CCMR2;       /*!< TIM capture/compare mode register 2,      Address offset: 0x1C */
    __IO uint32_t CCER;        /*!< TIM capture/compare enable register,      Address offset: 0x20 */
    __IO uint32_t CNT;         /*!< TIM counter register,                     Address offset: 0x24 */
    __IO uint32_t PSC;         /*!< TIM prescaler,                            Address offset: 0x28 */
    __IO uint32_t ARR;         /*!< TIM auto-reload register,                 Address offset: 0x2C */
    __IO uint32_t RCR;         /*!< TIM repetition counter register,          Address offset: 0x30 */
    __IO uint32_t CCR1;        /*!< TIM capture/compare register 1,           Address offset: 0x34 */
    __IO uint32_t CCR2;        /*!< TIM capture/compare register 2,           Address offset: 0x38 */
    __IO uint32_t CCR3;        /*!< TIM capture/compare register 3,           Address offset: 0x3C */
    __IO uint32_t CCR4;        /*!< TIM capture/compare register 4,           Address offset: 0x40 */
    __IO uint32_t BDTR;        /*!< TIM break and dead-time register,         Address offset: 0x44 */
    __IO uint32_t DCR;         /*!< TIM DMA control register,                 Address offset: 0x48 */
    __IO uint32_t DMAR;        /*!< TIM DMA address for full transfer,        Address offset: 0x4C */
    __IO uint32_t OR1;         /*!< TIM option register 1,                    Address offset: 0x50 */
    __IO uint32_t CCMR3;       /*!< TIM capture/compare mode register 3,      Address offset: 0x54 */
    __IO uint32_t CCR5;        /*!< TIM capture/compare register5,            Address offset: 0x58 */
    __IO uint32_t CCR6;        /*!< TIM capture/compare register6,            Address offset: 0x5C */
    __IO uint32_t OR2;         /*!< TIM option register 2,                    Address offset: 0x60 */
    __IO uint32_t OR3;         /*!< TIM option register 3,                    Address offset: 0x64 */
} TIM_TypeDef;

#define GPIOA               ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB               ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC               ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOA_BASE            (AHB2PERIPH_BASE + 0x0000U)
#define GPIOB_BASE            (AHB2PERIPH_BASE + 0x0400U)
#define GPIOC_BASE            (AHB2PERIPH_BASE + 0x0800U)
#define TIM2_BASE             (APB1PERIPH_BASE + 0x0000U)
#define TIM3_BASE             (APB1PERIPH_BASE + 0x0400U)
#define TIM4_BASE             (APB1PERIPH_BASE + 0x0800U)
#define TIM5_BASE             (APB1PERIPH_BASE + 0x0C00U)
#define TIM6_BASE             (APB1PERIPH_BASE + 0x1000U)
#define TIM7_BASE             (APB1PERIPH_BASE + 0x1400U)
#define TIM2                ((TIM_TypeDef *) TIM2_BASE)
#define TIM3                ((TIM_TypeDef *) TIM3_BASE)
#define TIM4                ((TIM_TypeDef *) TIM4_BASE)
#define TIM5                ((TIM_TypeDef *) TIM5_BASE)
#define TIM6                ((TIM_TypeDef *) TIM6_BASE)
#define TIM7                ((TIM_TypeDef *) TIM7_BASE)

typedef struct
{
    __IO uint32_t CR;          /*!< RCC clock control register,                                              Address offset: 0x00 */
    __IO uint32_t ICSCR;       /*!< RCC internal clock sources calibration register,                         Address offset: 0x04 */
    __IO uint32_t CFGR;        /*!< RCC clock configuration register,                                        Address offset: 0x08 */
    __IO uint32_t PLLCFGR;     /*!< RCC system PLL configuration register,                                   Address offset: 0x0C */
    __IO uint32_t PLLSAI1CFGR; /*!< RCC PLL SAI1 configuration register,                                     Address offset: 0x10 */
    __IO uint32_t PLLSAI2CFGR; /*!< RCC PLL SAI2 configuration register,                                     Address offset: 0x14 */
    __IO uint32_t CIER;        /*!< RCC clock interrupt enable register,                                     Address offset: 0x18 */
    __IO uint32_t CIFR;        /*!< RCC clock interrupt flag register,                                       Address offset: 0x1C */
    __IO uint32_t CICR;        /*!< RCC clock interrupt clear register,                                      Address offset: 0x20 */
    uint32_t      RESERVED0;   /*!< Reserved,                                                                Address offset: 0x24 */
    __IO uint32_t AHB1RSTR;    /*!< RCC AHB1 peripheral reset register,                                      Address offset: 0x28 */
    __IO uint32_t AHB2RSTR;    /*!< RCC AHB2 peripheral reset register,                                      Address offset: 0x2C */
    __IO uint32_t AHB3RSTR;    /*!< RCC AHB3 peripheral reset register,                                      Address offset: 0x30 */
    uint32_t      RESERVED1;   /*!< Reserved,                                                                Address offset: 0x34 */
    __IO uint32_t APB1RSTR1;   /*!< RCC APB1 peripheral reset register 1,                                    Address offset: 0x38 */
    __IO uint32_t APB1RSTR2;   /*!< RCC APB1 peripheral reset register 2,                                    Address offset: 0x3C */
    __IO uint32_t APB2RSTR;    /*!< RCC APB2 peripheral reset register,                                      Address offset: 0x40 */
    uint32_t      RESERVED2;   /*!< Reserved,                                                                Address offset: 0x44 */
    __IO uint32_t AHB1ENR;     /*!< RCC AHB1 peripheral clocks enable register,                              Address offset: 0x48 */
    __IO uint32_t AHB2ENR;     /*!< RCC AHB2 peripheral clocks enable register,                              Address offset: 0x4C */
    __IO uint32_t AHB3ENR;     /*!< RCC AHB3 peripheral clocks enable register,                              Address offset: 0x50 */
    uint32_t      RESERVED3;   /*!< Reserved,                                                                Address offset: 0x54 */
    __IO uint32_t APB1ENR1;    /*!< RCC APB1 peripheral clocks enable register 1,                            Address offset: 0x58 */
    __IO uint32_t APB1ENR2;    /*!< RCC APB1 peripheral clocks enable register 2,                            Address offset: 0x5C */
    __IO uint32_t APB2ENR;     /*!< RCC APB2 peripheral clocks enable register,                              Address offset: 0x60 */
    uint32_t      RESERVED4;   /*!< Reserved,                                                                Address offset: 0x64 */
    __IO uint32_t AHB1SMENR;   /*!< RCC AHB1 peripheral clocks enable in sleep and stop modes register,      Address offset: 0x68 */
    __IO uint32_t AHB2SMENR;   /*!< RCC AHB2 peripheral clocks enable in sleep and stop modes register,      Address offset: 0x6C */
    __IO uint32_t AHB3SMENR;   /*!< RCC AHB3 peripheral clocks enable in sleep and stop modes register,      Address offset: 0x70 */
    uint32_t      RESERVED5;   /*!< Reserved,                                                                Address offset: 0x74 */
    __IO uint32_t APB1SMENR1;  /*!< RCC APB1 peripheral clocks enable in sleep mode and stop modes register 1, Address offset: 0x78 */
    __IO uint32_t APB1SMENR2;  /*!< RCC APB1 peripheral clocks enable in sleep mode and stop modes register 2, Address offset: 0x7C */
    __IO uint32_t APB2SMENR;   /*!< RCC APB2 peripheral clocks enable in sleep mode and stop modes register, Address offset: 0x80 */
    uint32_t      RESERVED6;   /*!< Reserved,                                                                Address offset: 0x84 */
    __IO uint32_t CCIPR;       /*!< RCC peripherals independent clock configuration register,                Address offset: 0x88 */
    __IO uint32_t RESERVED7;   /*!< Reserved,                                                                Address offset: 0x8C */
    __IO uint32_t BDCR;        /*!< RCC backup domain control register,                                      Address offset: 0x90 */
    __IO uint32_t CSR;         /*!< RCC clock control & status register,                                     Address offset: 0x94 */
} RCC_TypeDef;

#define RCC                 ((RCC_TypeDef *) RCC_BASE)
#define RCC_BASE              (AHB1PERIPH_BASE + 0x1000U)
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000U)
#define RCC_CR_MSION_Pos                    (0U)                               
#define RCC_CR_MSION_Msk                    (0x1U << RCC_CR_MSION_Pos)         /*!< 0x00000001 */
#define RCC_CR_MSION                        RCC_CR_MSION_Msk                   /*!< Internal Multi Speed oscillator (MSI) clock enable */
#define RCC_CR_MSIRDY_Pos                   (1U)                               
#define RCC_CR_MSIRDY_Msk                   (0x1U << RCC_CR_MSIRDY_Pos)        /*!< 0x00000002 */
#define RCC_CR_MSIRDY                       RCC_CR_MSIRDY_Msk                  /*!< Internal Multi Speed oscillator (MSI) clock ready flag */
#define RCC_CR_MSIPLLEN_Pos                 (2U)                               
#define RCC_CR_MSIPLLEN_Msk                 (0x1U << RCC_CR_MSIPLLEN_Pos)      /*!< 0x00000004 */
#define RCC_CR_MSIPLLEN                     RCC_CR_MSIPLLEN_Msk                /*!< Internal Multi Speed oscillator (MSI) PLL enable */
#define RCC_CR_MSIRGSEL_Pos                 (3U)                               
#define RCC_CR_MSIRGSEL_Msk                 (0x1U << RCC_CR_MSIRGSEL_Pos)      /*!< 0x00000008 */
#define RCC_CR_MSIRGSEL                     RCC_CR_MSIRGSEL_Msk                /*!< Internal Multi Speed oscillator (MSI) range selection */

/*!< MSIRANGE configuration : 12 frequency ranges available */
#define RCC_CR_MSIRANGE_Pos                 (4U)                               
#define RCC_CR_MSIRANGE_Msk                 (0xFU << RCC_CR_MSIRANGE_Pos)      /*!< 0x000000F0 */
#define RCC_CR_MSIRANGE                     RCC_CR_MSIRANGE_Msk                /*!< Internal Multi Speed oscillator (MSI) clock Range */
#define RCC_CR_MSIRANGE_0                   (0x0U << RCC_CR_MSIRANGE_Pos)      /*!< 0x00000000 */
#define RCC_CR_MSIRANGE_1                   (0x1U << RCC_CR_MSIRANGE_Pos)      /*!< 0x00000010 */
#define RCC_CR_MSIRANGE_2                   (0x2U << RCC_CR_MSIRANGE_Pos)      /*!< 0x00000020 */
#define RCC_CR_MSIRANGE_3                   (0x3U << RCC_CR_MSIRANGE_Pos)      /*!< 0x00000030 */
#define RCC_CR_MSIRANGE_4                   (0x4U << RCC_CR_MSIRANGE_Pos)      /*!< 0x00000040 */
#define RCC_CR_MSIRANGE_5                   (0x5U << RCC_CR_MSIRANGE_Pos)      /*!< 0x00000050 */
#define RCC_CR_MSIRANGE_6                   (0x6U << RCC_CR_MSIRANGE_Pos)      /*!< 0x00000060 */
#define RCC_CR_MSIRANGE_7                   (0x7U << RCC_CR_MSIRANGE_Pos)      /*!< 0x00000070 */
#define RCC_CR_MSIRANGE_8                   (0x8U << RCC_CR_MSIRANGE_Pos)      /*!< 0x00000080 */
#define RCC_CR_MSIRANGE_9                   (0x9U << RCC_CR_MSIRANGE_Pos)      /*!< 0x00000090 */
#define RCC_CR_MSIRANGE_10                  (0xAU << RCC_CR_MSIRANGE_Pos)      /*!< 0x000000A0 */
#define RCC_CR_MSIRANGE_11                  (0xBU << RCC_CR_MSIRANGE_Pos)      /*!< 0x000000B0 */

#define RCC_CR_HSION_Pos                    (8U)                               
#define RCC_CR_HSION_Msk                    (0x1U << RCC_CR_HSION_Pos)         /*!< 0x00000100 */
#define RCC_CR_HSION                        RCC_CR_HSION_Msk                   /*!< Internal High Speed oscillator (HSI16) clock enable */
#define RCC_CR_HSIKERON_Pos                 (9U)                               
#define RCC_CR_HSIKERON_Msk                 (0x1U << RCC_CR_HSIKERON_Pos)      /*!< 0x00000200 */
#define RCC_CR_HSIKERON                     RCC_CR_HSIKERON_Msk                /*!< Internal High Speed oscillator (HSI16) clock enable for some IPs Kernel */
#define RCC_CR_HSIRDY_Pos                   (10U)                              
#define RCC_CR_HSIRDY_Msk                   (0x1U << RCC_CR_HSIRDY_Pos)        /*!< 0x00000400 */
#define RCC_CR_HSIRDY                       RCC_CR_HSIRDY_Msk                  /*!< Internal High Speed oscillator (HSI16) clock ready flag */
#define RCC_CR_HSIASFS_Pos                  (11U)                              
#define RCC_CR_HSIASFS_Msk                  (0x1U << RCC_CR_HSIASFS_Pos)       /*!< 0x00000800 */
#define RCC_CR_HSIASFS                      RCC_CR_HSIASFS_Msk                 /*!< HSI16 Automatic Start from Stop */

#define RCC_CR_HSEON_Pos                    (16U)                              
#define RCC_CR_HSEON_Msk                    (0x1U << RCC_CR_HSEON_Pos)         /*!< 0x00010000 */
#define RCC_CR_HSEON                        RCC_CR_HSEON_Msk                   /*!< External High Speed oscillator (HSE) clock enable */
#define RCC_CR_HSERDY_Pos                   (17U)                              
#define RCC_CR_HSERDY_Msk                   (0x1U << RCC_CR_HSERDY_Pos)        /*!< 0x00020000 */
#define RCC_CR_HSERDY                       RCC_CR_HSERDY_Msk                  /*!< External High Speed oscillator (HSE) clock ready */
#define RCC_CR_HSEBYP_Pos                   (18U)                              
#define RCC_CR_HSEBYP_Msk                   (0x1U << RCC_CR_HSEBYP_Pos)        /*!< 0x00040000 */
#define RCC_CR_HSEBYP                       RCC_CR_HSEBYP_Msk                  /*!< External High Speed oscillator (HSE) clock bypass */
#define RCC_CR_CSSON_Pos                    (19U)                              
#define RCC_CR_CSSON_Msk                    (0x1U << RCC_CR_CSSON_Pos)         /*!< 0x00080000 */
#define RCC_CR_CSSON                        RCC_CR_CSSON_Msk                   /*!< HSE Clock Security System enable */

#define RCC_CR_PLLON_Pos                    (24U)                              
#define RCC_CR_PLLON_Msk                    (0x1U << RCC_CR_PLLON_Pos)         /*!< 0x01000000 */
#define RCC_CR_PLLON                        RCC_CR_PLLON_Msk                   /*!< System PLL clock enable */
#define RCC_CR_PLLRDY_Pos                   (25U)                              
#define RCC_CR_PLLRDY_Msk                   (0x1U << RCC_CR_PLLRDY_Pos)        /*!< 0x02000000 */
#define RCC_CR_PLLRDY                       RCC_CR_PLLRDY_Msk                  /*!< System PLL clock ready */
#define RCC_CR_PLLSAI1ON_Pos                (26U)                              
#define RCC_CR_PLLSAI1ON_Msk                (0x1U << RCC_CR_PLLSAI1ON_Pos)     /*!< 0x04000000 */
#define RCC_CR_PLLSAI1ON                    RCC_CR_PLLSAI1ON_Msk               /*!< SAI1 PLL enable */
#define RCC_CR_PLLSAI1RDY_Pos               (27U)                              
#define RCC_CR_PLLSAI1RDY_Msk               (0x1U << RCC_CR_PLLSAI1RDY_Pos)    /*!< 0x08000000 */
#define RCC_CR_PLLSAI1RDY                   RCC_CR_PLLSAI1RDY_Msk              /*!< SAI1 PLL ready */
#define RCC_CR_PLLSAI2ON_Pos                (28U)                              
#define RCC_CR_PLLSAI2ON_Msk                (0x1U << RCC_CR_PLLSAI2ON_Pos)     /*!< 0x10000000 */
#define RCC_CR_PLLSAI2ON                    RCC_CR_PLLSAI2ON_Msk               /*!< SAI2 PLL enable */
#define RCC_CR_PLLSAI2RDY_Pos               (29U)                              
#define RCC_CR_PLLSAI2RDY_Msk               (0x1U << RCC_CR_PLLSAI2RDY_Pos)    /*!< 0x20000000 */
#define RCC_CR_PLLSAI2RDY                   RCC_CR_PLLSAI2RDY_Msk              /*!< SAI2 PLL ready */

/********************  Bit definition for RCC_PLLCFGR register  ***************/
#define RCC_PLLCFGR_PLLSRC_Pos              (0U)                               
#define RCC_PLLCFGR_PLLSRC_Msk              (0x3U << RCC_PLLCFGR_PLLSRC_Pos)   /*!< 0x00000003 */
#define RCC_PLLCFGR_PLLSRC                  RCC_PLLCFGR_PLLSRC_Msk             

#define RCC_PLLCFGR_PLLSRC_MSI_Pos          (0U)                               
#define RCC_PLLCFGR_PLLSRC_MSI_Msk          (0x1U << RCC_PLLCFGR_PLLSRC_MSI_Pos) /*!< 0x00000001 */
#define RCC_PLLCFGR_PLLSRC_MSI              RCC_PLLCFGR_PLLSRC_MSI_Msk         /*!< MSI oscillator source clock selected */
#define RCC_PLLCFGR_PLLSRC_HSI_Pos          (1U)                               
#define RCC_PLLCFGR_PLLSRC_HSI_Msk          (0x1U << RCC_PLLCFGR_PLLSRC_HSI_Pos) /*!< 0x00000002 */
#define RCC_PLLCFGR_PLLSRC_HSI              RCC_PLLCFGR_PLLSRC_HSI_Msk         /*!< HSI16 oscillator source clock selected */
#define RCC_PLLCFGR_PLLSRC_HSE_Pos          (0U)                               
#define RCC_PLLCFGR_PLLSRC_HSE_Msk          (0x3U << RCC_PLLCFGR_PLLSRC_HSE_Pos) /*!< 0x00000003 */
#define RCC_PLLCFGR_PLLSRC_HSE              RCC_PLLCFGR_PLLSRC_HSE_Msk         /*!< HSE oscillator source clock selected */

#define RCC_PLLCFGR_PLLM_Pos                (4U)                               
#define RCC_PLLCFGR_PLLM_Msk                (0x7U << RCC_PLLCFGR_PLLM_Pos)     /*!< 0x00000070 */
#define RCC_PLLCFGR_PLLM                    RCC_PLLCFGR_PLLM_Msk               
#define RCC_PLLCFGR_PLLM_0                  (0x1U << RCC_PLLCFGR_PLLM_Pos)     /*!< 0x00000010 */
#define RCC_PLLCFGR_PLLM_1                  (0x2U << RCC_PLLCFGR_PLLM_Pos)     /*!< 0x00000020 */
#define RCC_PLLCFGR_PLLM_2                  (0x4U << RCC_PLLCFGR_PLLM_Pos)     /*!< 0x00000040 */

#define RCC_PLLCFGR_PLLN_Pos                (8U)                               
#define RCC_PLLCFGR_PLLN_Msk                (0x7FU << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00007F00 */
#define RCC_PLLCFGR_PLLN                    RCC_PLLCFGR_PLLN_Msk               
#define RCC_PLLCFGR_PLLN_0                  (0x01U << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00000100 */
#define RCC_PLLCFGR_PLLN_1                  (0x02U << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00000200 */
#define RCC_PLLCFGR_PLLN_2                  (0x04U << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00000400 */
#define RCC_PLLCFGR_PLLN_3                  (0x08U << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00000800 */
#define RCC_PLLCFGR_PLLN_4                  (0x10U << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00001000 */
#define RCC_PLLCFGR_PLLN_5                  (0x20U << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00002000 */
#define RCC_PLLCFGR_PLLN_6                  (0x40U << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00004000 */

#define RCC_PLLCFGR_PLLPEN_Pos              (16U)                              
#define RCC_PLLCFGR_PLLPEN_Msk              (0x1U << RCC_PLLCFGR_PLLPEN_Pos)   /*!< 0x00010000 */
#define RCC_PLLCFGR_PLLPEN                  RCC_PLLCFGR_PLLPEN_Msk             
#define RCC_PLLCFGR_PLLP_Pos                (17U)                              
#define RCC_PLLCFGR_PLLP_Msk                (0x1U << RCC_PLLCFGR_PLLP_Pos)     /*!< 0x00020000 */
#define RCC_PLLCFGR_PLLP                    RCC_PLLCFGR_PLLP_Msk               
#define RCC_PLLCFGR_PLLQEN_Pos              (20U)                              
#define RCC_PLLCFGR_PLLQEN_Msk              (0x1U << RCC_PLLCFGR_PLLQEN_Pos)   /*!< 0x00100000 */
#define RCC_PLLCFGR_PLLQEN                  RCC_PLLCFGR_PLLQEN_Msk             

#define RCC_PLLCFGR_PLLQ_Pos                (21U)                              
#define RCC_PLLCFGR_PLLQ_Msk                (0x3U << RCC_PLLCFGR_PLLQ_Pos)     /*!< 0x00600000 */
#define RCC_PLLCFGR_PLLQ                    RCC_PLLCFGR_PLLQ_Msk               
#define RCC_PLLCFGR_PLLQ_0                  (0x1U << RCC_PLLCFGR_PLLQ_Pos)     /*!< 0x00200000 */
#define RCC_PLLCFGR_PLLQ_1                  (0x2U << RCC_PLLCFGR_PLLQ_Pos)     /*!< 0x00400000 */

#define RCC_PLLCFGR_PLLREN_Pos              (24U)                              
#define RCC_PLLCFGR_PLLREN_Msk              (0x1U << RCC_PLLCFGR_PLLREN_Pos)   /*!< 0x01000000 */
#define RCC_PLLCFGR_PLLREN                  RCC_PLLCFGR_PLLREN_Msk             
#define RCC_PLLCFGR_PLLR_Pos                (25U)                              
#define RCC_PLLCFGR_PLLR_Msk                (0x3U << RCC_PLLCFGR_PLLR_Pos)     /*!< 0x06000000 */
#define RCC_PLLCFGR_PLLR                    RCC_PLLCFGR_PLLR_Msk               
#define RCC_PLLCFGR_PLLR_0                  (0x1U << RCC_PLLCFGR_PLLR_Pos)     /*!< 0x02000000 */
#define RCC_PLLCFGR_PLLR_1                  (0x2U << RCC_PLLCFGR_PLLR_Pos)     /*!< 0x04000000 */
/********************  Bit definition for RCC_APB1ENR1 register  ***************/
#define RCC_APB1ENR1_TIM2EN_Pos             (0U)                               
#define RCC_APB1ENR1_TIM2EN_Msk             (0x1U << RCC_APB1ENR1_TIM2EN_Pos)  /*!< 0x00000001 */
#define RCC_APB1ENR1_TIM2EN                 RCC_APB1ENR1_TIM2EN_Msk            
#define RCC_APB1ENR1_TIM3EN_Pos             (1U)                               
#define RCC_APB1ENR1_TIM3EN_Msk             (0x1U << RCC_APB1ENR1_TIM3EN_Pos)  /*!< 0x00000002 */
#define RCC_APB1ENR1_TIM3EN                 RCC_APB1ENR1_TIM3EN_Msk            
#define RCC_APB1ENR1_TIM4EN_Pos             (2U)                               
#define RCC_APB1ENR1_TIM4EN_Msk             (0x1U << RCC_APB1ENR1_TIM4EN_Pos)  /*!< 0x00000004 */
#define RCC_APB1ENR1_TIM4EN                 RCC_APB1ENR1_TIM4EN_Msk            
#define RCC_APB1ENR1_TIM5EN_Pos             (3U)                               
#define RCC_APB1ENR1_TIM5EN_Msk             (0x1U << RCC_APB1ENR1_TIM5EN_Pos)  /*!< 0x00000008 */
#define RCC_APB1ENR1_TIM5EN                 RCC_APB1ENR1_TIM5EN_Msk            
#define RCC_APB1ENR1_TIM6EN_Pos             (4U)                               
#define RCC_APB1ENR1_TIM6EN_Msk             (0x1U << RCC_APB1ENR1_TIM6EN_Pos)  /*!< 0x00000010 */
#define RCC_APB1ENR1_TIM6EN                 RCC_APB1ENR1_TIM6EN_Msk            
#define RCC_APB1ENR1_TIM7EN_Pos             (5U)                               
#define RCC_APB1ENR1_TIM7EN_Msk             (0x1U << RCC_APB1ENR1_TIM7EN_Pos)  /*!< 0x00000020 */
#define RCC_APB1ENR1_TIM7EN                 RCC_APB1ENR1_TIM7EN_Msk            
#define RCC_APB1ENR1_LCDEN_Pos              (9U)                               
#define RCC_APB1ENR1_LCDEN_Msk              (0x1U << RCC_APB1ENR1_LCDEN_Pos)   /*!< 0x00000200 */
#define RCC_APB1ENR1_LCDEN                  RCC_APB1ENR1_LCDEN_Msk             
#define RCC_APB1ENR1_WWDGEN_Pos             (11U)                              
#define RCC_APB1ENR1_WWDGEN_Msk             (0x1U << RCC_APB1ENR1_WWDGEN_Pos)  /*!< 0x00000800 */
#define RCC_APB1ENR1_WWDGEN                 RCC_APB1ENR1_WWDGEN_Msk            
#define RCC_APB1ENR1_SPI2EN_Pos             (14U)                              
#define RCC_APB1ENR1_SPI2EN_Msk             (0x1U << RCC_APB1ENR1_SPI2EN_Pos)  /*!< 0x00004000 */
#define RCC_APB1ENR1_SPI2EN                 RCC_APB1ENR1_SPI2EN_Msk            
#define RCC_APB1ENR1_SPI3EN_Pos             (15U)                              
#define RCC_APB1ENR1_SPI3EN_Msk             (0x1U << RCC_APB1ENR1_SPI3EN_Pos)  /*!< 0x00008000 */
#define RCC_APB1ENR1_SPI3EN                 RCC_APB1ENR1_SPI3EN_Msk            
#define RCC_APB1ENR1_USART2EN_Pos           (17U)                              
#define RCC_APB1ENR1_USART2EN_Msk           (0x1U << RCC_APB1ENR1_USART2EN_Pos) /*!< 0x00020000 */
#define RCC_APB1ENR1_USART2EN               RCC_APB1ENR1_USART2EN_Msk          
#define RCC_APB1ENR1_USART3EN_Pos           (18U)                              
#define RCC_APB1ENR1_USART3EN_Msk           (0x1U << RCC_APB1ENR1_USART3EN_Pos) /*!< 0x00040000 */
#define RCC_APB1ENR1_USART3EN               RCC_APB1ENR1_USART3EN_Msk          
#define RCC_APB1ENR1_UART4EN_Pos            (19U)                              
#define RCC_APB1ENR1_UART4EN_Msk            (0x1U << RCC_APB1ENR1_UART4EN_Pos) /*!< 0x00080000 */
#define RCC_APB1ENR1_UART4EN                RCC_APB1ENR1_UART4EN_Msk           
#define RCC_APB1ENR1_UART5EN_Pos            (20U)                              
#define RCC_APB1ENR1_UART5EN_Msk            (0x1U << RCC_APB1ENR1_UART5EN_Pos) /*!< 0x00100000 */
#define RCC_APB1ENR1_UART5EN                RCC_APB1ENR1_UART5EN_Msk           
#define RCC_APB1ENR1_I2C1EN_Pos             (21U)                              
#define RCC_APB1ENR1_I2C1EN_Msk             (0x1U << RCC_APB1ENR1_I2C1EN_Pos)  /*!< 0x00200000 */
#define RCC_APB1ENR1_I2C1EN                 RCC_APB1ENR1_I2C1EN_Msk            
#define RCC_APB1ENR1_I2C2EN_Pos             (22U)                              
#define RCC_APB1ENR1_I2C2EN_Msk             (0x1U << RCC_APB1ENR1_I2C2EN_Pos)  /*!< 0x00400000 */
#define RCC_APB1ENR1_I2C2EN                 RCC_APB1ENR1_I2C2EN_Msk            
#define RCC_APB1ENR1_I2C3EN_Pos             (23U)                              
#define RCC_APB1ENR1_I2C3EN_Msk             (0x1U << RCC_APB1ENR1_I2C3EN_Pos)  /*!< 0x00800000 */
#define RCC_APB1ENR1_I2C3EN                 RCC_APB1ENR1_I2C3EN_Msk            
#define RCC_APB1ENR1_CAN1EN_Pos             (25U)                              
#define RCC_APB1ENR1_CAN1EN_Msk             (0x1U << RCC_APB1ENR1_CAN1EN_Pos)  /*!< 0x02000000 */
#define RCC_APB1ENR1_CAN1EN                 RCC_APB1ENR1_CAN1EN_Msk            
#define RCC_APB1ENR1_PWREN_Pos              (28U)                              
#define RCC_APB1ENR1_PWREN_Msk              (0x1U << RCC_APB1ENR1_PWREN_Pos)   /*!< 0x10000000 */
#define RCC_APB1ENR1_PWREN                  RCC_APB1ENR1_PWREN_Msk             
#define RCC_APB1ENR1_DAC1EN_Pos             (29U)                              
#define RCC_APB1ENR1_DAC1EN_Msk             (0x1U << RCC_APB1ENR1_DAC1EN_Pos)  /*!< 0x20000000 */
#define RCC_APB1ENR1_DAC1EN                 RCC_APB1ENR1_DAC1EN_Msk            
#define RCC_APB1ENR1_OPAMPEN_Pos            (30U)                              
#define RCC_APB1ENR1_OPAMPEN_Msk            (0x1U << RCC_APB1ENR1_OPAMPEN_Pos) /*!< 0x40000000 */
#define RCC_APB1ENR1_OPAMPEN                RCC_APB1ENR1_OPAMPEN_Msk           
#define RCC_APB1ENR1_LPTIM1EN_Pos           (31U)                              
#define RCC_APB1ENR1_LPTIM1EN_Msk           (0x1U << RCC_APB1ENR1_LPTIM1EN_Pos) /*!< 0x80000000 */
#define RCC_APB1ENR1_LPTIM1EN               RCC_APB1ENR1_LPTIM1EN_Msk          
/*******************  Bit definition for TIM_CR1 register  ********************/
#define TIM_CR1_CEN_Pos           (0U)                                         
#define TIM_CR1_CEN_Msk           (0x1U << TIM_CR1_CEN_Pos)                    /*!< 0x00000001 */
#define TIM_CR1_CEN               TIM_CR1_CEN_Msk                              /*!<Counter enable */
#define TIM_CR1_UDIS_Pos          (1U)                                         
#define TIM_CR1_UDIS_Msk          (0x1U << TIM_CR1_UDIS_Pos)                   /*!< 0x00000002 */
#define TIM_CR1_UDIS              TIM_CR1_UDIS_Msk                             /*!<Update disable */
#define TIM_CR1_URS_Pos           (2U)                                         
#define TIM_CR1_URS_Msk           (0x1U << TIM_CR1_URS_Pos)                    /*!< 0x00000004 */
#define TIM_CR1_URS               TIM_CR1_URS_Msk                              /*!<Update request source */
#define TIM_CR1_OPM_Pos           (3U)                                         
#define TIM_CR1_OPM_Msk           (0x1U << TIM_CR1_OPM_Pos)                    /*!< 0x00000008 */
#define TIM_CR1_OPM               TIM_CR1_OPM_Msk                              /*!<One pulse mode */
#define TIM_CR1_DIR_Pos           (4U)                                         
#define TIM_CR1_DIR_Msk           (0x1U << TIM_CR1_DIR_Pos)                    /*!< 0x00000010 */
#define TIM_CR1_DIR               TIM_CR1_DIR_Msk                              /*!<Direction */

#define TIM_CR1_CMS_Pos           (5U)                                         
#define TIM_CR1_CMS_Msk           (0x3U << TIM_CR1_CMS_Pos)                    /*!< 0x00000060 */
#define TIM_CR1_CMS               TIM_CR1_CMS_Msk                              /*!<CMS[1:0] bits (Center-aligned mode selection) */
#define TIM_CR1_CMS_0             (0x1U << TIM_CR1_CMS_Pos)                    /*!< 0x00000020 */
#define TIM_CR1_CMS_1             (0x2U << TIM_CR1_CMS_Pos)                    /*!< 0x00000040 */

#define TIM_CR1_ARPE_Pos          (7U)                                         
#define TIM_CR1_ARPE_Msk          (0x1U << TIM_CR1_ARPE_Pos)                   /*!< 0x00000080 */
#define TIM_CR1_ARPE              TIM_CR1_ARPE_Msk                             /*!<Auto-reload preload enable */

#define TIM_CR1_CKD_Pos           (8U)                                         
#define TIM_CR1_CKD_Msk           (0x3U << TIM_CR1_CKD_Pos)                    /*!< 0x00000300 */
#define TIM_CR1_CKD               TIM_CR1_CKD_Msk                              /*!<CKD[1:0] bits (clock division) */
#define TIM_CR1_CKD_0             (0x1U << TIM_CR1_CKD_Pos)                    /*!< 0x00000100 */
#define TIM_CR1_CKD_1             (0x2U << TIM_CR1_CKD_Pos)                    /*!< 0x00000200 */

#define TIM_CR1_UIFREMAP_Pos      (11U)                                        
#define TIM_CR1_UIFREMAP_Msk      (0x1U << TIM_CR1_UIFREMAP_Pos)               /*!< 0x00000800 */
#define TIM_CR1_UIFREMAP          TIM_CR1_UIFREMAP_Msk                         /*!<Update interrupt flag remap */
/*******************  Bit definition for TIM_EGR register  ********************/
#define TIM_EGR_UG_Pos            (0U)                                         
#define TIM_EGR_UG_Msk            (0x1U << TIM_EGR_UG_Pos)                     /*!< 0x00000001 */
#define TIM_EGR_UG                TIM_EGR_UG_Msk                               /*!<Update Generation */
#define TIM_EGR_CC1G_Pos          (1U)                                         
#define TIM_EGR_CC1G_Msk          (0x1U << TIM_EGR_CC1G_Pos)                   /*!< 0x00000002 */
#define TIM_EGR_CC1G              TIM_EGR_CC1G_Msk                             /*!<Capture/Compare 1 Generation */
#define TIM_EGR_CC2G_Pos          (2U)                                         
#define TIM_EGR_CC2G_Msk          (0x1U << TIM_EGR_CC2G_Pos)                   /*!< 0x00000004 */
#define TIM_EGR_CC2G              TIM_EGR_CC2G_Msk                             /*!<Capture/Compare 2 Generation */
#define TIM_EGR_CC3G_Pos          (3U)                                         
#define TIM_EGR_CC3G_Msk          (0x1U << TIM_EGR_CC3G_Pos)                   /*!< 0x00000008 */
#define TIM_EGR_CC3G              TIM_EGR_CC3G_Msk                             /*!<Capture/Compare 3 Generation */
#define TIM_EGR_CC4G_Pos          (4U)                                         
#define TIM_EGR_CC4G_Msk          (0x1U << TIM_EGR_CC4G_Pos)                   /*!< 0x00000010 */
#define TIM_EGR_CC4G              TIM_EGR_CC4G_Msk                             /*!<Capture/Compare 4 Generation */
#define TIM_EGR_COMG_Pos          (5U)                                         
#define TIM_EGR_COMG_Msk          (0x1U << TIM_EGR_COMG_Pos)                   /*!< 0x00000020 */
#define TIM_EGR_COMG              TIM_EGR_COMG_Msk                             /*!<Capture/Compare Control Update Generation */
#define TIM_EGR_TG_Pos            (6U)                                         
#define TIM_EGR_TG_Msk            (0x1U << TIM_EGR_TG_Pos)                     /*!< 0x00000040 */
#define TIM_EGR_TG                TIM_EGR_TG_Msk                               /*!<Trigger Generation */
#define TIM_EGR_BG_Pos            (7U)                                         
#define TIM_EGR_BG_Msk            (0x1U << TIM_EGR_BG_Pos)                     /*!< 0x00000080 */
#define TIM_EGR_BG                TIM_EGR_BG_Msk                               /*!<Break Generation */
#define TIM_EGR_B2G_Pos           (8U)                                         
#define TIM_EGR_B2G_Msk           (0x1U << TIM_EGR_B2G_Pos)                    /*!< 0x00000100 */
#define TIM_EGR_B2G               TIM_EGR_B2G_Msk                              /*!<Break 2 Generation */
/****************** Bit definition for GPIO_AFRL register *********************/
#define GPIO_AFRL_AFSEL0_Pos                 (0U)                              
#define GPIO_AFRL_AFSEL0_Msk                 (0xFU << GPIO_AFRL_AFSEL0_Pos)    /*!< 0x0000000F */
#define GPIO_AFRL_AFSEL0                     GPIO_AFRL_AFSEL0_Msk              
#define GPIO_AFRL_AFSEL0_0                   (0x1U << GPIO_AFRL_AFSEL0_Pos)    /*!< 0x00000001 */
#define GPIO_AFRL_AFSEL0_1                   (0x2U << GPIO_AFRL_AFSEL0_Pos)    /*!< 0x00000002 */
#define GPIO_AFRL_AFSEL0_2                   (0x4U << GPIO_AFRL_AFSEL0_Pos)    /*!< 0x00000004 */
#define GPIO_AFRL_AFSEL0_3                   (0x8U << GPIO_AFRL_AFSEL0_Pos)    /*!< 0x00000008 */
#define GPIO_AFRL_AFSEL1_Pos                 (4U)                              
#define GPIO_AFRL_AFSEL1_Msk                 (0xFU << GPIO_AFRL_AFSEL1_Pos)    /*!< 0x000000F0 */
#define GPIO_AFRL_AFSEL1                     GPIO_AFRL_AFSEL1_Msk              
#define GPIO_AFRL_AFSEL1_0                   (0x1U << GPIO_AFRL_AFSEL1_Pos)    /*!< 0x00000010 */
#define GPIO_AFRL_AFSEL1_1                   (0x2U << GPIO_AFRL_AFSEL1_Pos)    /*!< 0x00000020 */
#define GPIO_AFRL_AFSEL1_2                   (0x4U << GPIO_AFRL_AFSEL1_Pos)    /*!< 0x00000040 */
#define GPIO_AFRL_AFSEL1_3                   (0x8U << GPIO_AFRL_AFSEL1_Pos)    /*!< 0x00000080 */
#define GPIO_AFRL_AFSEL2_Pos                 (8U)                              
#define GPIO_AFRL_AFSEL2_Msk                 (0xFU << GPIO_AFRL_AFSEL2_Pos)    /*!< 0x00000F00 */
#define GPIO_AFRL_AFSEL2                     GPIO_AFRL_AFSEL2_Msk              
#define GPIO_AFRL_AFSEL2_0                   (0x1U << GPIO_AFRL_AFSEL2_Pos)    /*!< 0x00000100 */
#define GPIO_AFRL_AFSEL2_1                   (0x2U << GPIO_AFRL_AFSEL2_Pos)    /*!< 0x00000200 */
#define GPIO_AFRL_AFSEL2_2                   (0x4U << GPIO_AFRL_AFSEL2_Pos)    /*!< 0x00000400 */
#define GPIO_AFRL_AFSEL2_3                   (0x8U << GPIO_AFRL_AFSEL2_Pos)    /*!< 0x00000800 */
#define GPIO_AFRL_AFSEL3_Pos                 (12U)                             
#define GPIO_AFRL_AFSEL3_Msk                 (0xFU << GPIO_AFRL_AFSEL3_Pos)    /*!< 0x0000F000 */
#define GPIO_AFRL_AFSEL3                     GPIO_AFRL_AFSEL3_Msk              
#define GPIO_AFRL_AFSEL3_0                   (0x1U << GPIO_AFRL_AFSEL3_Pos)    /*!< 0x00001000 */
#define GPIO_AFRL_AFSEL3_1                   (0x2U << GPIO_AFRL_AFSEL3_Pos)    /*!< 0x00002000 */
#define GPIO_AFRL_AFSEL3_2                   (0x4U << GPIO_AFRL_AFSEL3_Pos)    /*!< 0x00004000 */
#define GPIO_AFRL_AFSEL3_3                   (0x8U << GPIO_AFRL_AFSEL3_Pos)    /*!< 0x00008000 */
#define GPIO_AFRL_AFSEL4_Pos                 (16U)                             
#define GPIO_AFRL_AFSEL4_Msk                 (0xFU << GPIO_AFRL_AFSEL4_Pos)    /*!< 0x000F0000 */
#define GPIO_AFRL_AFSEL4                     GPIO_AFRL_AFSEL4_Msk              
#define GPIO_AFRL_AFSEL4_0                   (0x1U << GPIO_AFRL_AFSEL4_Pos)    /*!< 0x00010000 */
#define GPIO_AFRL_AFSEL4_1                   (0x2U << GPIO_AFRL_AFSEL4_Pos)    /*!< 0x00020000 */
#define GPIO_AFRL_AFSEL4_2                   (0x4U << GPIO_AFRL_AFSEL4_Pos)    /*!< 0x00040000 */
#define GPIO_AFRL_AFSEL4_3                   (0x8U << GPIO_AFRL_AFSEL4_Pos)    /*!< 0x00080000 */
#define GPIO_AFRL_AFSEL5_Pos                 (20U)                             
#define GPIO_AFRL_AFSEL5_Msk                 (0xFU << GPIO_AFRL_AFSEL5_Pos)    /*!< 0x00F00000 */
#define GPIO_AFRL_AFSEL5                     GPIO_AFRL_AFSEL5_Msk              
#define GPIO_AFRL_AFSEL5_0                   (0x1U << GPIO_AFRL_AFSEL5_Pos)    /*!< 0x00100000 */
#define GPIO_AFRL_AFSEL5_1                   (0x2U << GPIO_AFRL_AFSEL5_Pos)    /*!< 0x00200000 */
#define GPIO_AFRL_AFSEL5_2                   (0x4U << GPIO_AFRL_AFSEL5_Pos)    /*!< 0x00400000 */
#define GPIO_AFRL_AFSEL5_3                   (0x8U << GPIO_AFRL_AFSEL5_Pos)    /*!< 0x00800000 */
#define GPIO_AFRL_AFSEL6_Pos                 (24U)                             
#define GPIO_AFRL_AFSEL6_Msk                 (0xFU << GPIO_AFRL_AFSEL6_Pos)    /*!< 0x0F000000 */
#define GPIO_AFRL_AFSEL6                     GPIO_AFRL_AFSEL6_Msk              
#define GPIO_AFRL_AFSEL6_0                   (0x1U << GPIO_AFRL_AFSEL6_Pos)    /*!< 0x01000000 */
#define GPIO_AFRL_AFSEL6_1                   (0x2U << GPIO_AFRL_AFSEL6_Pos)    /*!< 0x02000000 */
#define GPIO_AFRL_AFSEL6_2                   (0x4U << GPIO_AFRL_AFSEL6_Pos)    /*!< 0x04000000 */
#define GPIO_AFRL_AFSEL6_3                   (0x8U << GPIO_AFRL_AFSEL6_Pos)    /*!< 0x08000000 */
#define GPIO_AFRL_AFSEL7_Pos                 (28U)                             
#define GPIO_AFRL_AFSEL7_Msk                 (0xFU << GPIO_AFRL_AFSEL7_Pos)    /*!< 0xF0000000 */
#define GPIO_AFRL_AFSEL7                     GPIO_AFRL_AFSEL7_Msk              
#define GPIO_AFRL_AFSEL7_0                   (0x1U << GPIO_AFRL_AFSEL7_Pos)    /*!< 0x10000000 */
#define GPIO_AFRL_AFSEL7_1                   (0x2U << GPIO_AFRL_AFSEL7_Pos)    /*!< 0x20000000 */
#define GPIO_AFRL_AFSEL7_2                   (0x4U << GPIO_AFRL_AFSEL7_Pos)    /*!< 0x40000000 */
#define GPIO_AFRL_AFSEL7_3                   (0x8U << GPIO_AFRL_AFSEL7_Pos)    /*!< 0x80000000 */
/******************  Bit definition for TIM_CCMR1 register  *******************/
#define TIM_CCMR1_CC1S_Pos        (0U)                                         
#define TIM_CCMR1_CC1S_Msk        (0x3U << TIM_CCMR1_CC1S_Pos)                 /*!< 0x00000003 */
#define TIM_CCMR1_CC1S            TIM_CCMR1_CC1S_Msk                           /*!<CC1S[1:0] bits (Capture/Compare 1 Selection) */
#define TIM_CCMR1_CC1S_0          (0x1U << TIM_CCMR1_CC1S_Pos)                 /*!< 0x00000001 */
#define TIM_CCMR1_CC1S_1          (0x2U << TIM_CCMR1_CC1S_Pos)                 /*!< 0x00000002 */

#define TIM_CCMR1_OC1FE_Pos       (2U)                                         
#define TIM_CCMR1_OC1FE_Msk       (0x1U << TIM_CCMR1_OC1FE_Pos)                /*!< 0x00000004 */
#define TIM_CCMR1_OC1FE           TIM_CCMR1_OC1FE_Msk                          /*!<Output Compare 1 Fast enable */
#define TIM_CCMR1_OC1PE_Pos       (3U)                                         
#define TIM_CCMR1_OC1PE_Msk       (0x1U << TIM_CCMR1_OC1PE_Pos)                /*!< 0x00000008 */
#define TIM_CCMR1_OC1PE           TIM_CCMR1_OC1PE_Msk                          /*!<Output Compare 1 Preload enable */

#define TIM_CCMR1_OC1M_Pos        (4U)                                         
#define TIM_CCMR1_OC1M_Msk        (0x1007U << TIM_CCMR1_OC1M_Pos)              /*!< 0x00010070 */
#define TIM_CCMR1_OC1M            TIM_CCMR1_OC1M_Msk                           /*!<OC1M[2:0] bits (Output Compare 1 Mode) */
#define TIM_CCMR1_OC1M_0          (0x0001U << TIM_CCMR1_OC1M_Pos)              /*!< 0x00000010 */
#define TIM_CCMR1_OC1M_1          (0x0002U << TIM_CCMR1_OC1M_Pos)              /*!< 0x00000020 */
#define TIM_CCMR1_OC1M_2          (0x0004U << TIM_CCMR1_OC1M_Pos)              /*!< 0x00000040 */
#define TIM_CCMR1_OC1M_3          (0x1000U << TIM_CCMR1_OC1M_Pos)              /*!< 0x00010000 */

#define TIM_CCMR1_OC1CE_Pos       (7U)                                         
#define TIM_CCMR1_OC1CE_Msk       (0x1U << TIM_CCMR1_OC1CE_Pos)                /*!< 0x00000080 */
#define TIM_CCMR1_OC1CE           TIM_CCMR1_OC1CE_Msk                          /*!<Output Compare 1 Clear Enable */

#define TIM_CCMR1_CC2S_Pos        (8U)                                         
#define TIM_CCMR1_CC2S_Msk        (0x3U << TIM_CCMR1_CC2S_Pos)                 /*!< 0x00000300 */
#define TIM_CCMR1_CC2S            TIM_CCMR1_CC2S_Msk                           /*!<CC2S[1:0] bits (Capture/Compare 2 Selection) */
#define TIM_CCMR1_CC2S_0          (0x1U << TIM_CCMR1_CC2S_Pos)                 /*!< 0x00000100 */
#define TIM_CCMR1_CC2S_1          (0x2U << TIM_CCMR1_CC2S_Pos)                 /*!< 0x00000200 */

#define TIM_CCMR1_OC2FE_Pos       (10U)                                        
#define TIM_CCMR1_OC2FE_Msk       (0x1U << TIM_CCMR1_OC2FE_Pos)                /*!< 0x00000400 */
#define TIM_CCMR1_OC2FE           TIM_CCMR1_OC2FE_Msk                          /*!<Output Compare 2 Fast enable */
#define TIM_CCMR1_OC2PE_Pos       (11U)                                        
#define TIM_CCMR1_OC2PE_Msk       (0x1U << TIM_CCMR1_OC2PE_Pos)                /*!< 0x00000800 */
#define TIM_CCMR1_OC2PE           TIM_CCMR1_OC2PE_Msk                          /*!<Output Compare 2 Preload enable */

#define TIM_CCMR1_OC2M_Pos        (12U)                                        
#define TIM_CCMR1_OC2M_Msk        (0x1007U << TIM_CCMR1_OC2M_Pos)              /*!< 0x01007000 */
#define TIM_CCMR1_OC2M            TIM_CCMR1_OC2M_Msk                           /*!<OC2M[2:0] bits (Output Compare 2 Mode) */
#define TIM_CCMR1_OC2M_0          (0x0001U << TIM_CCMR1_OC2M_Pos)              /*!< 0x00001000 */
#define TIM_CCMR1_OC2M_1          (0x0002U << TIM_CCMR1_OC2M_Pos)              /*!< 0x00002000 */
#define TIM_CCMR1_OC2M_2          (0x0004U << TIM_CCMR1_OC2M_Pos)              /*!< 0x00004000 */
#define TIM_CCMR1_OC2M_3          (0x1000U << TIM_CCMR1_OC2M_Pos)              /*!< 0x01000000 */

#define TIM_CCMR1_OC2CE_Pos       (15U)                                        
#define TIM_CCMR1_OC2CE_Msk       (0x1U << TIM_CCMR1_OC2CE_Pos)                /*!< 0x00008000 */
#define TIM_CCMR1_OC2CE           TIM_CCMR1_OC2CE_Msk                          /*!<Output Compare 2 Clear Enable */

/*----------------------------------------------------------------------------*/
#define TIM_CCMR1_IC1PSC_Pos      (2U)                                         
#define TIM_CCMR1_IC1PSC_Msk      (0x3U << TIM_CCMR1_IC1PSC_Pos)               /*!< 0x0000000C */
#define TIM_CCMR1_IC1PSC          TIM_CCMR1_IC1PSC_Msk                         /*!<IC1PSC[1:0] bits (Input Capture 1 Prescaler) */
#define TIM_CCMR1_IC1PSC_0        (0x1U << TIM_CCMR1_IC1PSC_Pos)               /*!< 0x00000004 */
#define TIM_CCMR1_IC1PSC_1        (0x2U << TIM_CCMR1_IC1PSC_Pos)               /*!< 0x00000008 */

#define TIM_CCMR1_IC1F_Pos        (4U)                                         
#define TIM_CCMR1_IC1F_Msk        (0xFU << TIM_CCMR1_IC1F_Pos)                 /*!< 0x000000F0 */
#define TIM_CCMR1_IC1F            TIM_CCMR1_IC1F_Msk                           /*!<IC1F[3:0] bits (Input Capture 1 Filter) */
#define TIM_CCMR1_IC1F_0          (0x1U << TIM_CCMR1_IC1F_Pos)                 /*!< 0x00000010 */
#define TIM_CCMR1_IC1F_1          (0x2U << TIM_CCMR1_IC1F_Pos)                 /*!< 0x00000020 */
#define TIM_CCMR1_IC1F_2          (0x4U << TIM_CCMR1_IC1F_Pos)                 /*!< 0x00000040 */
#define TIM_CCMR1_IC1F_3          (0x8U << TIM_CCMR1_IC1F_Pos)                 /*!< 0x00000080 */

#define TIM_CCMR1_IC2PSC_Pos      (10U)                                        
#define TIM_CCMR1_IC2PSC_Msk      (0x3U << TIM_CCMR1_IC2PSC_Pos)               /*!< 0x00000C00 */
#define TIM_CCMR1_IC2PSC          TIM_CCMR1_IC2PSC_Msk                         /*!<IC2PSC[1:0] bits (Input Capture 2 Prescaler) */
#define TIM_CCMR1_IC2PSC_0        (0x1U << TIM_CCMR1_IC2PSC_Pos)               /*!< 0x00000400 */
#define TIM_CCMR1_IC2PSC_1        (0x2U << TIM_CCMR1_IC2PSC_Pos)               /*!< 0x00000800 */

#define TIM_CCMR1_IC2F_Pos        (12U)                                        
#define TIM_CCMR1_IC2F_Msk        (0xFU << TIM_CCMR1_IC2F_Pos)                 /*!< 0x0000F000 */
#define TIM_CCMR1_IC2F            TIM_CCMR1_IC2F_Msk                           /*!<IC2F[3:0] bits (Input Capture 2 Filter) */
#define TIM_CCMR1_IC2F_0          (0x1U << TIM_CCMR1_IC2F_Pos)                 /*!< 0x00001000 */
#define TIM_CCMR1_IC2F_1          (0x2U << TIM_CCMR1_IC2F_Pos)                 /*!< 0x00002000 */
#define TIM_CCMR1_IC2F_2          (0x4U << TIM_CCMR1_IC2F_Pos)                 /*!< 0x00004000 */
#define TIM_CCMR1_IC2F_3          (0x8U << TIM_CCMR1_IC2F_Pos)                 /*!< 0x00008000 */
/*******************  Bit definition for TIM_CCER register  *******************/
#define TIM_CCER_CC1E_Pos         (0U)                                         
#define TIM_CCER_CC1E_Msk         (0x1U << TIM_CCER_CC1E_Pos)                  /*!< 0x00000001 */
#define TIM_CCER_CC1E             TIM_CCER_CC1E_Msk                            /*!<Capture/Compare 1 output enable */
#define TIM_CCER_CC1P_Pos         (1U)                                         
#define TIM_CCER_CC1P_Msk         (0x1U << TIM_CCER_CC1P_Pos)                  /*!< 0x00000002 */
#define TIM_CCER_CC1P             TIM_CCER_CC1P_Msk                            /*!<Capture/Compare 1 output Polarity */
#define TIM_CCER_CC1NE_Pos        (2U)                                         
#define TIM_CCER_CC1NE_Msk        (0x1U << TIM_CCER_CC1NE_Pos)                 /*!< 0x00000004 */
#define TIM_CCER_CC1NE            TIM_CCER_CC1NE_Msk                           /*!<Capture/Compare 1 Complementary output enable */
#define TIM_CCER_CC1NP_Pos        (3U)                                         
#define TIM_CCER_CC1NP_Msk        (0x1U << TIM_CCER_CC1NP_Pos)                 /*!< 0x00000008 */
#define TIM_CCER_CC1NP            TIM_CCER_CC1NP_Msk                           /*!<Capture/Compare 1 Complementary output Polarity */
#define TIM_CCER_CC2E_Pos         (4U)                                         
#define TIM_CCER_CC2E_Msk         (0x1U << TIM_CCER_CC2E_Pos)                  /*!< 0x00000010 */
#define TIM_CCER_CC2E             TIM_CCER_CC2E_Msk                            /*!<Capture/Compare 2 output enable */
#define TIM_CCER_CC2P_Pos         (5U)                                         
#define TIM_CCER_CC2P_Msk         (0x1U << TIM_CCER_CC2P_Pos)                  /*!< 0x00000020 */
#define TIM_CCER_CC2P             TIM_CCER_CC2P_Msk                            /*!<Capture/Compare 2 output Polarity */
#define TIM_CCER_CC2NE_Pos        (6U)                                         
#define TIM_CCER_CC2NE_Msk        (0x1U << TIM_CCER_CC2NE_Pos)                 /*!< 0x00000040 */
#define TIM_CCER_CC2NE            TIM_CCER_CC2NE_Msk                           /*!<Capture/Compare 2 Complementary output enable */
#define TIM_CCER_CC2NP_Pos        (7U)                                         
#define TIM_CCER_CC2NP_Msk        (0x1U << TIM_CCER_CC2NP_Pos)                 /*!< 0x00000080 */
#define TIM_CCER_CC2NP            TIM_CCER_CC2NP_Msk                           /*!<Capture/Compare 2 Complementary output Polarity */
#define TIM_CCER_CC3E_Pos         (8U)                                         
#define TIM_CCER_CC3E_Msk         (0x1U << TIM_CCER_CC3E_Pos)                  /*!< 0x00000100 */
#define TIM_CCER_CC3E             TIM_CCER_CC3E_Msk                            /*!<Capture/Compare 3 output enable */
#define TIM_CCER_CC3P_Pos         (9U)                                         
#define TIM_CCER_CC3P_Msk         (0x1U << TIM_CCER_CC3P_Pos)                  /*!< 0x00000200 */
#define TIM_CCER_CC3P             TIM_CCER_CC3P_Msk                            /*!<Capture/Compare 3 output Polarity */
#define TIM_CCER_CC3NE_Pos        (10U)                                        
#define TIM_CCER_CC3NE_Msk        (0x1U << TIM_CCER_CC3NE_Pos)                 /*!< 0x00000400 */
#define TIM_CCER_CC3NE            TIM_CCER_CC3NE_Msk                           /*!<Capture/Compare 3 Complementary output enable */
#define TIM_CCER_CC3NP_Pos        (11U)                                        
#define TIM_CCER_CC3NP_Msk        (0x1U << TIM_CCER_CC3NP_Pos)                 /*!< 0x00000800 */
#define TIM_CCER_CC3NP            TIM_CCER_CC3NP_Msk                           /*!<Capture/Compare 3 Complementary output Polarity */
#define TIM_CCER_CC4E_Pos         (12U)                                        
#define TIM_CCER_CC4E_Msk         (0x1U << TIM_CCER_CC4E_Pos)                  /*!< 0x00001000 */
#define TIM_CCER_CC4E             TIM_CCER_CC4E_Msk                            /*!<Capture/Compare 4 output enable */
#define TIM_CCER_CC4P_Pos         (13U)                                        
#define TIM_CCER_CC4P_Msk         (0x1U << TIM_CCER_CC4P_Pos)                  /*!< 0x00002000 */
#define TIM_CCER_CC4P             TIM_CCER_CC4P_Msk                            /*!<Capture/Compare 4 output Polarity */
#define TIM_CCER_CC4NP_Pos        (15U)                                        
#define TIM_CCER_CC4NP_Msk        (0x1U << TIM_CCER_CC4NP_Pos)                 /*!< 0x00008000 */
#define TIM_CCER_CC4NP            TIM_CCER_CC4NP_Msk                           /*!<Capture/Compare 4 Complementary output Polarity */
#define TIM_CCER_CC5E_Pos         (16U)                                        
#define TIM_CCER_CC5E_Msk         (0x1U << TIM_CCER_CC5E_Pos)                  /*!< 0x00010000 */
#define TIM_CCER_CC5E             TIM_CCER_CC5E_Msk                            /*!<Capture/Compare 5 output enable */
#define TIM_CCER_CC5P_Pos         (17U)                                        
#define TIM_CCER_CC5P_Msk         (0x1U << TIM_CCER_CC5P_Pos)                  /*!< 0x00020000 */
#define TIM_CCER_CC5P             TIM_CCER_CC5P_Msk                            /*!<Capture/Compare 5 output Polarity */
#define TIM_CCER_CC6E_Pos         (20U)                                        
#define TIM_CCER_CC6E_Msk         (0x1U << TIM_CCER_CC6E_Pos)                  /*!< 0x00100000 */
#define TIM_CCER_CC6E             TIM_CCER_CC6E_Msk                            /*!<Capture/Compare 6 output enable */
#define TIM_CCER_CC6P_Pos         (21U)                                        
#define TIM_CCER_CC6P_Msk         (0x1U << TIM_CCER_CC6P_Pos)                  /*!< 0x00200000 */
#define TIM_CCER_CC6P             TIM_CCER_CC6P_Msk                            /*!<Capture/Compare 6 output Polarity */
typedef struct
{
    __IO uint32_t IMR1;        /*!< EXTI Interrupt mask register 1,             Address offset: 0x00 */
    __IO uint32_t EMR1;        /*!< EXTI Event mask register 1,                 Address offset: 0x04 */
    __IO uint32_t RTSR1;       /*!< EXTI Rising trigger selection register 1,   Address offset: 0x08 */
    __IO uint32_t FTSR1;       /*!< EXTI Falling trigger selection register 1,  Address offset: 0x0C */
    __IO uint32_t SWIER1;      /*!< EXTI Software interrupt event register 1,   Address offset: 0x10 */
    __IO uint32_t PR1;         /*!< EXTI Pending register 1,                    Address offset: 0x14 */
    uint32_t      RESERVED1;   /*!< Reserved, 0x18                                                   */
    uint32_t      RESERVED2;   /*!< Reserved, 0x1C                                                   */

    __IO uint32_t IMR2;        /*!< EXTI Interrupt mask register 2,             Address offset: 0x20 */
    __IO uint32_t EMR2;        /*!< EXTI Event mask register 2,                 Address offset: 0x24 */
    __IO uint32_t RTSR2;       /*!< EXTI Rising trigger selection register 2,   Address offset: 0x28 */
    __IO uint32_t FTSR2;       /*!< EXTI Falling trigger selection register 2,  Address offset: 0x2C */
    __IO uint32_t SWIER2;      /*!< EXTI Software interrupt event register 2,   Address offset: 0x30 */
    __IO uint32_t PR2;         /*!< EXTI Pending register 2,                    Address offset: 0x34 */
} EXTI_TypeDef;
/*******************  Bit definition for EXTI_IMR1 register  ******************/
#define EXTI_IMR1_IM0_Pos                    (0U)                              
#define EXTI_IMR1_IM0_Msk                    (0x1U << EXTI_IMR1_IM0_Pos)       /*!< 0x00000001 */
#define EXTI_IMR1_IM0                        EXTI_IMR1_IM0_Msk                 /*!< Interrupt Mask on line 0 */
#define EXTI_IMR1_IM1_Pos                    (1U)                              
#define EXTI_IMR1_IM1_Msk                    (0x1U << EXTI_IMR1_IM1_Pos)       /*!< 0x00000002 */
#define EXTI_IMR1_IM1                        EXTI_IMR1_IM1_Msk                 /*!< Interrupt Mask on line 1 */
#define EXTI_IMR1_IM2_Pos                    (2U)                              
#define EXTI_IMR1_IM2_Msk                    (0x1U << EXTI_IMR1_IM2_Pos)       /*!< 0x00000004 */
#define EXTI_IMR1_IM2                        EXTI_IMR1_IM2_Msk                 /*!< Interrupt Mask on line 2 */
#define EXTI_IMR1_IM3_Pos                    (3U)                              
#define EXTI_IMR1_IM3_Msk                    (0x1U << EXTI_IMR1_IM3_Pos)       /*!< 0x00000008 */
#define EXTI_IMR1_IM3                        EXTI_IMR1_IM3_Msk                 /*!< Interrupt Mask on line 3 */
#define EXTI_IMR1_IM4_Pos                    (4U)                              
#define EXTI_IMR1_IM4_Msk                    (0x1U << EXTI_IMR1_IM4_Pos)       /*!< 0x00000010 */
#define EXTI_IMR1_IM4                        EXTI_IMR1_IM4_Msk                 /*!< Interrupt Mask on line 4 */
#define EXTI_IMR1_IM5_Pos                    (5U)                              
#define EXTI_IMR1_IM5_Msk                    (0x1U << EXTI_IMR1_IM5_Pos)       /*!< 0x00000020 */
#define EXTI_IMR1_IM5                        EXTI_IMR1_IM5_Msk                 /*!< Interrupt Mask on line 5 */
#define EXTI_IMR1_IM6_Pos                    (6U)                              
#define EXTI_IMR1_IM6_Msk                    (0x1U << EXTI_IMR1_IM6_Pos)       /*!< 0x00000040 */
#define EXTI_IMR1_IM6                        EXTI_IMR1_IM6_Msk                 /*!< Interrupt Mask on line 6 */
#define EXTI_IMR1_IM7_Pos                    (7U)                              
#define EXTI_IMR1_IM7_Msk                    (0x1U << EXTI_IMR1_IM7_Pos)       /*!< 0x00000080 */
#define EXTI_IMR1_IM7                        EXTI_IMR1_IM7_Msk                 /*!< Interrupt Mask on line 7 */
#define EXTI_IMR1_IM8_Pos                    (8U)                              
#define EXTI_IMR1_IM8_Msk                    (0x1U << EXTI_IMR1_IM8_Pos)       /*!< 0x00000100 */
#define EXTI_IMR1_IM8                        EXTI_IMR1_IM8_Msk                 /*!< Interrupt Mask on line 8 */
#define EXTI_IMR1_IM9_Pos                    (9U)                              
#define EXTI_IMR1_IM9_Msk                    (0x1U << EXTI_IMR1_IM9_Pos)       /*!< 0x00000200 */
#define EXTI_IMR1_IM9                        EXTI_IMR1_IM9_Msk                 /*!< Interrupt Mask on line 9 */
#define EXTI_IMR1_IM10_Pos                   (10U)                             
#define EXTI_IMR1_IM10_Msk                   (0x1U << EXTI_IMR1_IM10_Pos)      /*!< 0x00000400 */
#define EXTI_IMR1_IM10                       EXTI_IMR1_IM10_Msk                /*!< Interrupt Mask on line 10 */
#define EXTI_IMR1_IM11_Pos                   (11U)                             
#define EXTI_IMR1_IM11_Msk                   (0x1U << EXTI_IMR1_IM11_Pos)      /*!< 0x00000800 */
#define EXTI_IMR1_IM11                       EXTI_IMR1_IM11_Msk                /*!< Interrupt Mask on line 11 */
#define EXTI_IMR1_IM12_Pos                   (12U)                             
#define EXTI_IMR1_IM12_Msk                   (0x1U << EXTI_IMR1_IM12_Pos)      /*!< 0x00001000 */
#define EXTI_IMR1_IM12                       EXTI_IMR1_IM12_Msk                /*!< Interrupt Mask on line 12 */
#define EXTI_IMR1_IM13_Pos                   (13U)                             
#define EXTI_IMR1_IM13_Msk                   (0x1U << EXTI_IMR1_IM13_Pos)      /*!< 0x00002000 */
#define EXTI_IMR1_IM13                       EXTI_IMR1_IM13_Msk                /*!< Interrupt Mask on line 13 */
#define EXTI_IMR1_IM14_Pos                   (14U)                             
#define EXTI_IMR1_IM14_Msk                   (0x1U << EXTI_IMR1_IM14_Pos)      /*!< 0x00004000 */
#define EXTI_IMR1_IM14                       EXTI_IMR1_IM14_Msk                /*!< Interrupt Mask on line 14 */
#define EXTI_IMR1_IM15_Pos                   (15U)                             
#define EXTI_IMR1_IM15_Msk                   (0x1U << EXTI_IMR1_IM15_Pos)      /*!< 0x00008000 */
#define EXTI_IMR1_IM15                       EXTI_IMR1_IM15_Msk                /*!< Interrupt Mask on line 15 */
#define EXTI_IMR1_IM16_Pos                   (16U)                             
#define EXTI_IMR1_IM16_Msk                   (0x1U << EXTI_IMR1_IM16_Pos)      /*!< 0x00010000 */
#define EXTI_IMR1_IM16                       EXTI_IMR1_IM16_Msk                /*!< Interrupt Mask on line 16 */
#define EXTI_IMR1_IM17_Pos                   (17U)                             
#define EXTI_IMR1_IM17_Msk                   (0x1U << EXTI_IMR1_IM17_Pos)      /*!< 0x00020000 */
#define EXTI_IMR1_IM17                       EXTI_IMR1_IM17_Msk                /*!< Interrupt Mask on line 17 */
#define EXTI_IMR1_IM18_Pos                   (18U)                             
#define EXTI_IMR1_IM18_Msk                   (0x1U << EXTI_IMR1_IM18_Pos)      /*!< 0x00040000 */
#define EXTI_IMR1_IM18                       EXTI_IMR1_IM18_Msk                /*!< Interrupt Mask on line 18 */
#define EXTI_IMR1_IM19_Pos                   (19U)                             
#define EXTI_IMR1_IM19_Msk                   (0x1U << EXTI_IMR1_IM19_Pos)      /*!< 0x00080000 */
#define EXTI_IMR1_IM19                       EXTI_IMR1_IM19_Msk                /*!< Interrupt Mask on line 19 */
#define EXTI_IMR1_IM20_Pos                   (20U)                             
#define EXTI_IMR1_IM20_Msk                   (0x1U << EXTI_IMR1_IM20_Pos)      /*!< 0x00100000 */
#define EXTI_IMR1_IM20                       EXTI_IMR1_IM20_Msk                /*!< Interrupt Mask on line 20 */
#define EXTI_IMR1_IM21_Pos                   (21U)                             
#define EXTI_IMR1_IM21_Msk                   (0x1U << EXTI_IMR1_IM21_Pos)      /*!< 0x00200000 */
#define EXTI_IMR1_IM21                       EXTI_IMR1_IM21_Msk                /*!< Interrupt Mask on line 21 */
#define EXTI_IMR1_IM22_Pos                   (22U)                             
#define EXTI_IMR1_IM22_Msk                   (0x1U << EXTI_IMR1_IM22_Pos)      /*!< 0x00400000 */
#define EXTI_IMR1_IM22                       EXTI_IMR1_IM22_Msk                /*!< Interrupt Mask on line 22 */
#define EXTI_IMR1_IM23_Pos                   (23U)                             
#define EXTI_IMR1_IM23_Msk                   (0x1U << EXTI_IMR1_IM23_Pos)      /*!< 0x00800000 */
#define EXTI_IMR1_IM23                       EXTI_IMR1_IM23_Msk                /*!< Interrupt Mask on line 23 */
#define EXTI_IMR1_IM24_Pos                   (24U)                             
#define EXTI_IMR1_IM24_Msk                   (0x1U << EXTI_IMR1_IM24_Pos)      /*!< 0x01000000 */
#define EXTI_IMR1_IM24                       EXTI_IMR1_IM24_Msk                /*!< Interrupt Mask on line 24 */
#define EXTI_IMR1_IM25_Pos                   (25U)                             
#define EXTI_IMR1_IM25_Msk                   (0x1U << EXTI_IMR1_IM25_Pos)      /*!< 0x02000000 */
#define EXTI_IMR1_IM25                       EXTI_IMR1_IM25_Msk                /*!< Interrupt Mask on line 25 */
#define EXTI_IMR1_IM26_Pos                   (26U)                             
#define EXTI_IMR1_IM26_Msk                   (0x1U << EXTI_IMR1_IM26_Pos)      /*!< 0x04000000 */
#define EXTI_IMR1_IM26                       EXTI_IMR1_IM26_Msk                /*!< Interrupt Mask on line 26 */
#define EXTI_IMR1_IM27_Pos                   (27U)                             
#define EXTI_IMR1_IM27_Msk                   (0x1U << EXTI_IMR1_IM27_Pos)      /*!< 0x08000000 */
#define EXTI_IMR1_IM27                       EXTI_IMR1_IM27_Msk                /*!< Interrupt Mask on line 27 */
#define EXTI_IMR1_IM28_Pos                   (28U)                             
#define EXTI_IMR1_IM28_Msk                   (0x1U << EXTI_IMR1_IM28_Pos)      /*!< 0x10000000 */
#define EXTI_IMR1_IM28                       EXTI_IMR1_IM28_Msk                /*!< Interrupt Mask on line 28 */
#define EXTI_IMR1_IM29_Pos                   (29U)                             
#define EXTI_IMR1_IM29_Msk                   (0x1U << EXTI_IMR1_IM29_Pos)      /*!< 0x20000000 */
#define EXTI_IMR1_IM29                       EXTI_IMR1_IM29_Msk                /*!< Interrupt Mask on line 29 */
#define EXTI_IMR1_IM30_Pos                   (30U)                             
#define EXTI_IMR1_IM30_Msk                   (0x1U << EXTI_IMR1_IM30_Pos)      /*!< 0x40000000 */
#define EXTI_IMR1_IM30                       EXTI_IMR1_IM30_Msk                /*!< Interrupt Mask on line 30 */
#define EXTI_IMR1_IM31_Pos                   (31U)                             
#define EXTI_IMR1_IM31_Msk                   (0x1U << EXTI_IMR1_IM31_Pos)      /*!< 0x80000000 */
#define EXTI_IMR1_IM31                       EXTI_IMR1_IM31_Msk                /*!< Interrupt Mask on line 31 */
#define EXTI_IMR1_IM_Pos                     (0U)                              
#define EXTI_IMR1_IM_Msk                     (0xFFFFFFFFU << EXTI_IMR1_IM_Pos) /*!< 0xFFFFFFFF */
#define EXTI_IMR1_IM                         EXTI_IMR1_IM_Msk                  /*!< Interrupt Mask All */
typedef struct
{
    __IO uint32_t MEMRMP;      /*!< SYSCFG memory remap register,                      Address offset: 0x00      */
    __IO uint32_t CFGR1;       /*!< SYSCFG configuration register 1,                   Address offset: 0x04      */
    __IO uint32_t EXTICR[4];   /*!< SYSCFG external interrupt configuration registers, Address offset: 0x08-0x14 */
    __IO uint32_t SCSR;        /*!< SYSCFG SRAM2 control and status register,          Address offset: 0x18      */
    __IO uint32_t CFGR2;       /*!< SYSCFG configuration register 2,                   Address offset: 0x1C      */
    __IO uint32_t SWPR;        /*!< SYSCFG SRAM2 write protection register,            Address offset: 0x20      */
    __IO uint32_t SKR;         /*!< SYSCFG SRAM2 key register,                         Address offset: 0x24      */
} SYSCFG_TypeDef;


#endif

