#include <stdio.h>

//	�Լ��� ����
//	�ڷ���	�Լ��� �̸�(�Լ��� �� ���ڰ�)

//	�ڷ��� : ��ȯ�� �ڷ�
//	�Լ��� �̸� : �Լ��� �̸� ( ȣ���� �� �θ� �̸� )
//	�Լ��� �� ���ڰ� ( �Լ� �ܺο��� �Լ� ���η� ����Ǵ� �� )

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
	//	�Լ��� ȣ��
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
			printf("�߰��Ǿ����ϴ�.\n");
			printf("Y / N");
			scanf_s("%c", &add);
			if (add == "Y")
				flag = false;
			else
				continue;
		}
	}
}

//	�Լ��� ����

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