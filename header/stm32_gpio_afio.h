#ifndef STM32_GPIO_H
#define STM32_GPIO_H

#include <stdint.h>

/*
    -------------------------------------------GPIO----------------------------------------
*/

#define GPIOA_BASE                  0x40010800U
#define GPIOB_BASE                  0x40010C00U
#define GPIOC_BASE                  0x40011000U
#define GPIOD_BASE                  0x40011400U
#define GPIOE_BASE                  0x40011800U
#define GPIOF_BASE                  0x40011C00U
#define GPIOG_BASE                  0x40012000U

struct GPIO {
    uint32_t GPIO_CRL;                              /* port configuration register low */
    uint32_t GPIO_CRH;                              /* port configuration register high */
    uint32_t GPIO_IDR;                              /* port input data register */
    uint32_t GPIO_ODR;                              /* port output data register */
    uint32_t GPIO_BSRR;                             /* port bit set/reset register */
    uint32_t GPIO_BRR;                              /* port bit reset register */
    uint32_t GPIO_LCKR;                             /* port configuration lock register */
};

struct GPIO* gpio_A = (struct GPIO*)GPIOA_BASE;
struct GPIO* gpio_B = (struct GPIO*)GPIOB_BASE;
struct GPIO* gpio_C = (struct GPIO*)GPIOC_BASE;
struct GPIO* gpio_D = (struct GPIO*)GPIOD_BASE;
struct GPIO* gpio_E = (struct GPIO*)GPIOE_BASE;
struct GPIO* gpio_F = (struct GPIO*)GPIOF_BASE;
struct GPIO* gpio_G = (struct GPIO*)GPIOG_BASE;



/*
    -------------------------------------------AFIO----------------------------------------
*/

#define AFIO_BASE                   0x40010000U

struct AFIO {
    uint32_t AFIO_EVCR;                             /* event control register */
    uint32_t AFIO_MAPR;                             /* AF remap and debug I/O configuration register */
    uint32_t AFIO_EXTICR1;                          /* External interrupt configuration register 1 */
    uint32_t AFIO_EXTICR2;                          /* External interrupt configuration register 2 */
    uint32_t AFIO_EXTICR3;                          /* External interrupt configuration register 3 */
    uint32_t AFIO_EXTICR4;                          /* External interrupt configuration register 4 */
    uint32_t reserved;                              /* unuse register*/
    uint32_t AFIO_MAPR2;                            /* AF remap and debug I/O configuration register 2 */
};

struct AFIO* afio = (struct AFIO*)AFIO_BASE;


#endif //STM32_GPIO_H