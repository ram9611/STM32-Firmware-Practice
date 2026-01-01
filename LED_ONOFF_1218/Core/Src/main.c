
#include "stm32f767xx.h" // CMSIS 헤더

uint8_t Test = 0;

int main(void)
{
	//PC6에서 LED ON/OFF 시키기

	//GPIOC 클럭 활성화
	RCC -> AHB1ENR |= 0x00000004;

	//PC6를 General-purpose OUTPUT 모드로 설정
	GPIOC -> MODER &= ~0x0003000;
	GPIOC -> MODER |= 0x00001000;

	//PC6 중간 속도로 설정
	GPIOC -> OSPEEDR &= 0x00003000;
	GPIOC -> OSPEEDR |= 0x00001000;

	//
	while(1){

		if(Test==0){
		GPIOC -> ODR |= 0x00000040; // 출력 1 -> LED OFF
		}
		else{
		GPIOC -> ODR &= ~0x00000040; // 출력 0 -> LED ON
		}

	}

}
