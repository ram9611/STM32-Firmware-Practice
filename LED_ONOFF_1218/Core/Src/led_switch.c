#include "stm32f767xx.h"

int main(void){

	// GPIOD 활성화
	RCC -> AHB1ENR |= 0x00000008;
	RCC -> AHB1ENR |= 0x00000004;

	//PC6을 General-purpose output 모드로 설정
	GPIOC -> MODER &= ~0x00003000; //clear 13,12 bit
	GPIOC -> MODER |= 0x00000040; //PC6 output mode

	//PC6 중간속도로 설정
	GPIOC -> OSPEEDR &= ~0x00003000; //clear 13,12 bit
	GPIOC -> OSPEEDR |= 0x00000040; //PC6 Medium speed

	//PD4를 입력으로 설정(스위치)
	GPIOD -> MODER &= ~0x00000300; //bit 8,9번 clear

	while(1)
	{
		//IDR 레지스터 읽기: bit4 확인
		if((GPIOD->IDR & 0x00000010)==0){
			// 스위치 눌림 -> LED ON
			GPIOC ->ODR &= ~0x00000040; // clear bit6
		}
		else{
			//스위치 떼짐 -> LED OFF
			GPIOC -> ODR |= 0x00000040; // set bit 6
		}
	}


}
