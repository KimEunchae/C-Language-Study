#include <stdio.h>
#include <Windows.h>
#include <conio.h>

struct Data{
	int stdNumber;
	int stdSession;
	int stdTotalBorrow;
	int stdCurrentBorrow;
	int stdRemainDay;
};

void Skip();
void Menu(Data*);
void Print(Data*);
void Default(Data*);
void Delete(Data*);
void Find(Data*);
void Reset(Data*);
void Count(Data*);
void Add(Data*);
int Addindex(Data*);

int main(){

	Data Student[500];
	while (1)
		Menu(Student);
}
void Menu(Data* Student){

	printf("-----Menu----\n");
	printf("\n");
	printf("0. ��ü ������ ����\n");
	printf("1. �⺻ ������ �߰�\n");
	printf("2. �л� ���\n");
	printf("3. �л� �߰�\n");
	printf("4. �л� ����\n");
	printf("5. �л� �˻�\n");
	printf("6. �� ��� �л�\n");
	printf("-------------\n");

	int Select;
	scanf_s("%d", &Select, sizeof(int));

	switch (Select){
	case 0:
		Reset(Student);
		break;
	case 1:
		Default(Student);
		break;
	case 2:
		Print(Student);
		break;
	case 3:
		Add(Student);
		break;
	case 4:
		Delete(Student);
		break;
	case 5:
		Find(Student);
		break;
	case 6:
		Count(Student);
		break;
	default:
		break;

	}
}
void Skip(){
	_getch();
	system("cls");
}
void Print(Data* Student){
	for (int i = 0; i < 500; ++i){
		if (Student[i].stdNumber!=0)
		printf("�й� : %d\n �г� : %d\n ���� �뿩 �Ǽ� : %d\n ���� �뿩 �Ǽ� : %d\n �ܿ� �ݳ��� : %d\n\n", Student[i].stdNumber, Student[i].stdSession, Student[i].stdTotalBorrow, Student[i].stdCurrentBorrow, Student[i].stdRemainDay);
	}
	Skip();
}
void Default(Data* Student){
	FILE *f;
	fopen_s(&f, "20150801_�ּ���Data.txt", "r");
	for (int i = 0; i < 500; ++i){
		fscanf_s(f, "%d %d %d %d %d\n", &Student[i].stdNumber, &Student[i].stdSession, &Student[i].stdTotalBorrow, &Student[i].stdCurrentBorrow, &Student[i].stdRemainDay);
	}
	printf("�⺻ �����Ͱ� �߰��Ǿ����ϴ�.\n");
	Skip();
	fclose(f);
}
void Delete(Data* Student){
	printf("�����Ϸ��� �л��� �й��� �Է��ϼ���.\n");
	int stdNumber;
	bool flag = false;
	scanf_s("%d", &stdNumber, sizeof(int));
	for (int i = 0; i < 500; ++i){
		if (Student[i].stdNumber == stdNumber){
			flag = true;
			printf("%d �л��� �˻��Ͽ����ϴ�.\n", stdNumber);
			printf("�ش� �л��� ������ �����մϴ�.\n");
			Student[i].stdCurrentBorrow = 0;
			Student[i].stdNumber = 0;
			Student[i].stdRemainDay = 0;
			Student[i].stdSession = 0;
			Student[i].stdTotalBorrow = 0;
		}
	}
	if (flag == false){
		printf("%d �л��� �������� �ʽ��ϴ�\n", stdNumber);
	}
	Skip();
}
void Find(Data* Student){

	printf("�˻��ϰ����ϴ� �л��� �й��� �Է��ϼ���\n");
	int stdNumber;
	bool flag = false;
	scanf_s("%d", &stdNumber, sizeof(int));

	for (int i = 0; i < 500; ++i){
		if (Student[i].stdNumber == stdNumber){
			flag = true;
			printf("%d �л��� �˻��Ͽ����ϴ�\n", stdNumber);
			printf("%d �л��� ������ ������ �����ϴ�.", stdNumber);
			printf("�й� : %d\n�г� : %d\n���� �뿩 �Ǽ� : %d\n���� �뿩 �Ǽ� : %d\n�ܿ� �뿩 �ϼ� : %d\n", Student[i].stdNumber, Student[i].stdSession, Student[i].stdTotalBorrow, Student[i].stdCurrentBorrow, Student[i].stdRemainDay);
		}
	}
	if (flag == false){
		printf("%d �л��� �������� �ʽ��ϴ�\n", stdNumber);
	}
	Skip();
}
void Reset(Data* Student){
	for (int i = 0; i < 500; ++i){
		Student[i].stdCurrentBorrow = 0;
		Student[i].stdNumber = 0;
		Student[i].stdRemainDay = 0;
		Student[i].stdSession = 0;
		Student[i].stdTotalBorrow = 0;
	}
	printf("��� �л��� ������ 0���� �ʱ�ȭ �Ǿ����ϴ�\n");
	Skip();
}
void Count(Data* Student){
	int nCount = 0;
	for (int i = 0; i < 500; ++i){
		if (Student[i].stdNumber != 0)
			nCount += 1;
	}
	printf("���� ��ϵ� �л��� �� ���� %d���Դϴ�\n", nCount);
	Skip();
}
void Add(Data* Student){
	int nIndex = Addindex(Student);
	printf("�߰��� �л��� �й��� �Է��ϼ��� : ");
	int nStdNumber;
	scanf_s("%d", &nStdNumber);
	printf("�߰��� �л��� �г��� �Է��ϼ��� : ");
	int nStdSession;
	scanf_s("%d", &nStdSession);

	Student[nIndex].stdNumber = nStdNumber;
	Student[nIndex].stdSession = nStdSession;
	printf("%d �л��� �߰��Ǿ����ϴ�.\n", nStdNumber);
}
int Addindex(Data* Student){
	bool flag = false;
	for (int i = 0; i < 500; ++i){
		if (flag == false && Student[i].stdNumber == 0){
			return i;
		}
	}
}