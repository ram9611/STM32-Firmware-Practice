// 주소 정의
#define GPIOD_BASE 0x40020C00UL;
#define RCC_BASE 0x40023800UL;

//GPIO 레지스터 오프셋
#define GPIOD_MODER_OFFSET 0x00UL;
#define GPIOD_OTYPER_OFFSET 0x04UL;
#define GPIOD_OSPEEDR_OFFSET 0x08UL;
#define GPIOD_PUPDR_OFFSET 0x0CUL;
#define GPIOD_IDR_OFFSET 0x10UL;
#define GPIOD_ODR_OFFSET 0x14UL;

//RCC 레지스터 오프셋
#define RCC_AHB1RSTR_OFFSET 0x10UL;

//레지스터 주소 정의(포인터로 캐스팅)
#define RCC_AHB1ENR (*((volatile unit32_t *)(RCC_BASE + RCC_AHB1RSTR_OFFSET)))

#define GPIOD_MODER (*((volatile unit32_t *)(GPIOD_BASE_OFFSET + GPIOD_MODER_OFFSET)))
#define GPIOD_OTYPER (*((volatile unit32_t *)(GPIOD_BASE_OFFSET + GPIOD_OTYPER_OFFSET)))
#define GPIOD_OSPEEDR (*((volatile unit32_t *)(GPIOD_BASE_OFFSET + GPIOD_OSPEEDR_OFFSET)))
#define GPIOD_PUPDR (*((volatile unit32_t *)(GPIOD_BASE_OFFSET + GPIOD_PUPDR_OFFSET)))
#define GPIOD_IDR (*((volatile unit32_t *)(GPIOD_BASE_OFFSET + GPIOD_IDR_OFFSET)))
#define GPIOD_ODR (*((volatile unit32_t *)(GPIOD_BASE_OFFSET + GPIOD_ODR_OFFSET)))


typedef struct {
	volatile unit32_t MODER; //오프셋 0x00
	volatile unit32_t OTYPER; //오프셋 0x04
	volatile unit32_t OSPEEDR; //오프셋 0x08
	volatile unit32_t PUPDR; //오프셋 0x0C
	volatile unit32_t IDR; //오프셋 0x10
	volatile unit32_t ODR; //오프셋 0x14
	volatile unit32_t BSRR; //오프셋 0x18
	volatile unit32_t LCKR; //오프셋 0x1C
	volatile unit32_t AFR[2]; // 오프셋 0x20, 0x24
} GPIO_TypeDef

#define GPIOD ((GPIO_TypeDef *)GPIOD_BASE)
