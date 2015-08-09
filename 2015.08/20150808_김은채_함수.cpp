#include <stdio.h>

//	함수의 선언
//	자료형	함수의 이름(함수에 들어갈 인자값)

//	자료형 : 반환할 자료
//	함수의 이름 : 함수의 이름 ( 호출할 때 부른 이름 )
//	함수에 들어갈 인자값 ( 함수 외부에서 함수 내부로 적용되는 값 )

int Number();
double Number2();
int Number3(int);
void Number4();
int Number5(int, int);

struct Data{
	int a;
	int b;
	int c;
};

int main(){

	int a;
	double b;
	int c;
	int c_1;

	int d;
	int f;

	d = 3;
	f = 4;

	int g;

	//g = Number5(d, f);
	//printf("%d\n", g);
	//	함수의 호출
	//a = Number();
	//printf("%d\n", a);

	//b = Number2();
	//printf("%f\n", b);

	//c = 100;
	//c_1 = Number3(c);
	//printf("%d\n", c_1);
	Data x[500];

	char add[2];
	bool flag = true;

	for (int i = 0; i < 500; ++i){
		x[i].a = 0;
		x[i].b = 0;
		x[i].c = 0;
	}

	while (flag){
		int i = 20;
		if (x[i].a == 0){
			//scanf_s("%d %d %d", &x[i].a, &x[i].b, &x[i].c);
			printf("추가되었습니다.\n");
			printf("Y / N");
			scanf_s("%c", &add);
			if (add == "Y")
				flag = false;
			else
				continue;
		}
	}
}

//	함수의 정의

int Number(){
	return 100;
}

double Number2(){
	return 3.14;
}

int Number3(int a){
	int b = 0;
	for (int i = 0; i < 10; ++i){
		b++;
	}
	return a + b;
}

void Number4(){
	printf("Number4\n");
}

int Number5(int a, int b){

	return a + b;
}