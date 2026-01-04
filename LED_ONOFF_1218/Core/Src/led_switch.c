#include "stm32f767xx.h"

int main(void){

	// GPIOD 활성화
	RCC -> AHB1ENR |= 0x00000008;
	RCC -> AHB1ENR |= 0x00000004;
	//PC6을 General-purpose output 모드로 설정
	GPIOC -> MODER &= ~0x000000C0;
	GPIOC -> MODER |= 0x00000040;

	//PC6 중간속도로 설정
	GPIOC -> OSPEEDR &= ~0x000000C0;
	GPIOC -> OSPEEDR |= 0x00000040;

	//PD4를 입력으로 설정(스위치)
	GPIOD -> MODER &= ~0x00000300;


}
