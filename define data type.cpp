#define  _CRT_SECURE_NO_WARNINGS
//C plus plus konwledge
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

1,strucutre definition
	define:
	struct name {
		struct numbers
		type number 1,
		type number 2,
		type number 3,......
	}

	typedef:
		make the other name for data type
*/

struct student {
	long long  id;
	char name[21];
	float score; //one varriable for one value
};

typedef struct timein {
	int year;
	int month;
	int day;
}TimeIn; // maybe it used to make define more confident

//if not define the name of stucture,it will use the other name
typedef struct {
	char name[21];
	int cost;
}furit;

//if not define all name but use varibale in the other name's postion it will as the varibale data in global;
// as the struct and make the variable body,define the bone structure for these variables.

struct Hero {
	char name[21];
	long long ATK;
	long long DEF;
};


struct {
	char name[21];
	int ATK;
	int DEF;
}hero1,hero2,qero[3];//编译分配已完成 compile allocation is complete can,t intialize data in main fuctiopn
//strcut nesting
struct cycle_a {
	struct cycle_b {
		int a;
		int b;
	}cb;
};
//the compute may of struct body

struct stc_one {
	int a;
	int b;
	float c;
};
//sizeof stc_one ---> 12 bytes
//the memory sort same head standard of struct,compare the biggest type of foundation data make memory head in a same line
//make pointer  to feek data memory address accuretly


struct stc_two {
	int a;
	char b[10];//the array is not a foundation data,it is only need a countinue address,it can be add in memory;
	float c;//such as stc_three shows
};
//sizeof stc_two ---> 20 bytes


struct stc_three {
	double a;
	int b;
	char c[10];//只有字符数组才能没有内存剩余顾虑与数据大小倍数对齐的限制，因为其连续的地址性，无法很好的被定义倍数性，所以可以随意的占据剩余内存；


};
//sizeof stc_three ---> 24 bytes
struct stc_four {
	int a;
	char b[10];
	char c;
	double d;
};
//in last define box of 8 bytes,故言，使头对齐，对应的倍数头上只能是数据的头指针，使指针好找数据对应的地址 
//sizeof stc_four ---> 24 bytes

struct stc_five {
	char a;
	int b;
	char c[10];
	double d;
};
//sizeof stc_five ---> 32 bytes
//----》接一个int，后面根据char的连续地址性，占了2个double的大小的内存，第3个内存框剩下6个bytes，不够8的也就是下面那个double内存大小的倍数，所以再分配了一个

struct str_memory_test {
	int a;
	char b;
	double c;
	int d;
	char arr[11];
	int t;
	char p;
	int crr[2];
};

int main() {
	//how to use
	student student_1 = { 2826610077,"Els_Rction",85.5 }; // it like a fuction mix the arr with mixed data type
	//use the variable name in struct to apply the value

	student student_2; //declare the variable
	student_2.id = 2826614514;
	//student_1.name = "Els_Rction";//error 
	//beacuse the pointer is not point all char in string;
	strcpy(student_2.name, "wewwffgefs");//use the function to copy the string
	student_2.score = 85.1;
	printf("ID:%lld\tName:%s\tScore:%f\n",student_1.id, student_1.name, student_1.score);
	printf("ID:%lld\tName:%s\tScore:%f\n", student_2.id, student_2.name, student_2.score);
	printf("\n");
	/*
	timein time_1 = { 2021,12,25 };
	TimeIn time_2 = { 2022,1,1 };
	printf("Year:%d\tMonth:%d\tDay:%d\n", time_1.year, time_1.month, time_1.day);
	printf("Year:%d\tMonth:%d\tDay:%d\n", time_2.year, time_2.month, time_2.day);
	printf("\n");
	furit fruit_1 = { "apple", 10 };
	furit fruit_2 = { "banana", 5 };
	printf("Fruit:%s\tCost:%d\n", fruit_1.name, fruit_1.cost);
	printf("Fruit:%s\tCost:%d\n", fruit_2.name, fruit_2.cost);
	printf("\n"); 
	hero1 = { "Superman", 100, 50 };
	hero2 = { "Batman", 100, 50 };
	printf("Hero1:%s\tATK:%d\tDEF:%d\n", hero1.name, hero1.ATK, hero1.DEF);
	printf("Hero2:%s\tATK:%d\tDEF:%d\n", hero2.name, hero2.ATK, hero2.DEF);
	printf("\n");
	
	Hero hero[3] = { { "Superman", 100, 50 }, { "Batman", 100, 50 }, { "Wonder Woman", 100, 50 } };
	qero[0] = { "Superman", 100, 50 };
	qero[1] = { "Batman", 100, 50 };
	qero[2] = { "Wonder Woman", 100, 50 };
	for (int i = 0; i < sizeof(qero) / sizeof(qero[0]); i++)
	{
		printf("Hero%d:%s\tATK:%d\tDEF:%d\n", i + 1, qero[i].name, qero[i].ATK, qero[i].DEF);
	}
	*/
	/*
	Hero heroarr[4] = {
		{"球伞曰",100,50},
		{"宏七餐",100,50},
		{"图肺丸",100,50},
		{"阳花哪",100,50}
	};

	for (int i = 0; i < 4; i++)
	{
		printf("Hero%d:%s\tATK:%lld\tDEF:%lld\n", i + 1, heroarr[i].name, heroarr[i].ATK, heroarr[i].DEF);
	}
	*/
	//11
	cycle_a ca;
	ca.cb.a = 10;
	printf("%d\n", sizeof(struct stc_one));
	printf("%d\n", sizeof(struct stc_two));
	printf("%d\n", sizeof(struct stc_three));
	printf("%d\n", sizeof(struct stc_four));
	printf("%d\n", sizeof(struct stc_five));


	return 0;


}