#include <stdio.h>

/*

함수를 사용할 때 3가지를 해야되고
함수는 3가지로 구성된다.

*/

/*
	함수를 사용할때 사용해야하는 3가지.
	1. 함수의 선언		(main문 위)
	2. 함수의 호출		(main문 중간)
	3. 함수의 정의		(main문 아래)

	함수를 구성하는 요소	(선언 & 정의)
	1. 자료형			(반환한다면 해당 자료형,반환하지 않는다면 void)
	2. 함수의 이름		(main문 안에서 함수를 호출할때 부를 이름)
	3. 인자값			(외부의 값을 사용한다면 사용하는 값의 자료형과 변수명)
*/

void A();
void B(int);

int main(){
	while (1)
		A();
}

void A(){

	int hour, minutes;
	scanf_s("%d %d", &hour, &minutes);
	B((hour * 60) + minutes);
}

void B(int time){
	int newtime = time - 45;

	if (newtime / 60 <= 0)
		newtime += (60 * 24);
	printf("%d %d\n", newtime / 60, newtime % 60);
}

