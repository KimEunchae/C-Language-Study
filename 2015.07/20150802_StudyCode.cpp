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
	printf("0. 전체 데이터 리셋\n");
	printf("1. 기본 데이터 추가\n");
	printf("2. 학생 출력\n");
	printf("3. 학생 추가\n");
	printf("4. 학생 삭제\n");
	printf("5. 학생 검색\n");
	printf("6. 총 등록 학생\n");
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
		printf("학번 : %d\n 학년 : %d\n 누적 대여 권수 : %d\n 현재 대여 권수 : %d\n 잔여 반납일 : %d\n\n", Student[i].stdNumber, Student[i].stdSession, Student[i].stdTotalBorrow, Student[i].stdCurrentBorrow, Student[i].stdRemainDay);
	}
	Skip();
}
void Default(Data* Student){
	FILE *f;
	fopen_s(&f, "20150801_최수연Data.txt", "r");
	for (int i = 0; i < 500; ++i){
		fscanf_s(f, "%d %d %d %d %d\n", &Student[i].stdNumber, &Student[i].stdSession, &Student[i].stdTotalBorrow, &Student[i].stdCurrentBorrow, &Student[i].stdRemainDay);
	}
	printf("기본 데이터가 추가되었습니다.\n");
	Skip();
	fclose(f);
}
void Delete(Data* Student){
	printf("제거하려는 학생의 학번을 입력하세요.\n");
	int stdNumber;
	bool flag = false;
	scanf_s("%d", &stdNumber, sizeof(int));
	for (int i = 0; i < 500; ++i){
		if (Student[i].stdNumber == stdNumber){
			flag = true;
			printf("%d 학생을 검색하였습니다.\n", stdNumber);
			printf("해당 학생의 정보를 제거합니다.\n");
			Student[i].stdCurrentBorrow = 0;
			Student[i].stdNumber = 0;
			Student[i].stdRemainDay = 0;
			Student[i].stdSession = 0;
			Student[i].stdTotalBorrow = 0;
		}
	}
	if (flag == false){
		printf("%d 학생은 존재하지 않습니다\n", stdNumber);
	}
	Skip();
}
void Find(Data* Student){

	printf("검색하고자하는 학생의 학번을 입력하세요\n");
	int stdNumber;
	bool flag = false;
	scanf_s("%d", &stdNumber, sizeof(int));

	for (int i = 0; i < 500; ++i){
		if (Student[i].stdNumber == stdNumber){
			flag = true;
			printf("%d 학생을 검색하였습니다\n", stdNumber);
			printf("%d 학생의 정보는 다음과 같습니다.", stdNumber);
			printf("학번 : %d\n학년 : %d\n누적 대여 권수 : %d\n현재 대여 권수 : %d\n잔여 대여 일수 : %d\n", Student[i].stdNumber, Student[i].stdSession, Student[i].stdTotalBorrow, Student[i].stdCurrentBorrow, Student[i].stdRemainDay);
		}
	}
	if (flag == false){
		printf("%d 학생은 존재하지 않습니다\n", stdNumber);
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
	printf("모든 학생의 정보가 0으로 초기화 되었습니다\n");
	Skip();
}
void Count(Data* Student){
	int nCount = 0;
	for (int i = 0; i < 500; ++i){
		if (Student[i].stdNumber != 0)
			nCount += 1;
	}
	printf("현재 등록된 학생의 총 합은 %d명입니다\n", nCount);
	Skip();
}
void Add(Data* Student){
	int nIndex = Addindex(Student);
	printf("추가할 학생의 학번을 입력하세요 : ");
	int nStdNumber;
	scanf_s("%d", &nStdNumber);
	printf("추가할 학생의 학년을 입력하세요 : ");
	int nStdSession;
	scanf_s("%d", &nStdSession);

	Student[nIndex].stdNumber = nStdNumber;
	Student[nIndex].stdSession = nStdSession;
	printf("%d 학생이 추가되었습니다.\n", nStdNumber);
}
int Addindex(Data* Student){
	bool flag = false;
	for (int i = 0; i < 500; ++i){
		if (flag == false && Student[i].stdNumber == 0){
			return i;
		}
	}
}