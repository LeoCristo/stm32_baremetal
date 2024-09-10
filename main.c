#include <stdint.h>

#define RCC_BASE    0x40021000
#define GPIOC_BASE  0x40011000
#define RCC_APB2ENR *(volatile uint32_t *)(RCC_BASE + 0x18)
#define GPIOC_CRH   *(volatile uint32_t *)(GPIOC_BASE + 0x04)
#define GPIOC_ODR   *(volatile uint32_t *)(GPIOC_BASE + 0x0C)

#define RCC_IOPCEN (1<<4)
#define GPIOC13 (1UL<<13)

void main(void){
    RCC_APB2ENR |= RCC_IOPCEN;
    GPIOC_CRH   |= 0x44244444;
    while(1){
        GPIOC_ODR |= GPIOC13;
        for (int i = 0; i < 500000; i++);
        GPIOC_ODR &= ~GPIOC13;
        for (int i = 0; i < 500000; i++);

        
    }


}