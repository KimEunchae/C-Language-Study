#include <stdio.h>

/*

�Լ��� ����� �� 3������ �ؾߵǰ�
�Լ��� 3������ �����ȴ�.

*/

/*
	�Լ��� ����Ҷ� ����ؾ��ϴ� 3����.
	1. �Լ��� ����		(main�� ��)
	2. �Լ��� ȣ��		(main�� �߰�)
	3. �Լ��� ����		(main�� �Ʒ�)

	�Լ��� �����ϴ� ���	(���� & ����)
	1. �ڷ���			(��ȯ�Ѵٸ� �ش� �ڷ���,��ȯ���� �ʴ´ٸ� void)
	2. �Լ��� �̸�		(main�� �ȿ��� �Լ��� ȣ���Ҷ� �θ� �̸�)
	3. ���ڰ�			(�ܺ��� ���� ����Ѵٸ� ����ϴ� ���� �ڷ����� ������)
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
	printf("%d %d\n", hour, minutes);
	B((hour * 60) + minutes);
}

void B(int time){
	//printf("%d %d", time / 60, time % 60);
	int newtime = time - 45;
	if (newtime / 60 <= 0)
		newtime +=(60 * 24);
	printf("%d %d\n", newtime / 60, newtime % 60);

}