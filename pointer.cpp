#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/*
pointer learing
	class 1:
		
		conception:
		1,address:is the name of the data box,and it is a const value as stream;
		2.pointer:origin of address
		2-1,pointer value:save the address
		potiner value equal waht potiner what
			potiner variable occupy 8bytes in 64 digits system.half in 32
		2-2;the declines in using *
			:when intialize express get value to adress.给予引用
				when using data express get adress to value.解除引用


	class 2;
		
		special pointer:

			1,fuction potiner
				how to define:
					morrior fuction type (*pointer name)(form parameter)
				fuction:
					
			2,pointer fuction:
				conception:
					return value is pointer
			3,const potiner
				not need to intialize;
				fuction:
					to protect the value in adress pointer,the value be pointer can't be revised
					can be revised pointer area
			4,pointer const
				need to intialize;
				fuction;
					to protect the adress can't be revised
					can,t be revised pointer area,because pointer is const
			谁是常量谁无法被修改，并且可以定义常量指针指向常量
			5,big or litte-endian storage:(4个字节对于4个存储地址位置
				sameple:
					a adress of memory:
						0x12345678 it has 4 bytes ,data storage in 0x0-0x3; 
						such as:
							12 in 0x0 , 34 in 0x1 ......
								is called big-endian storage
						litte-endian:
							is morrior
								0x0 78 0x1 56 ........
								computer use it;

				
*/


struct crcpp {
	long long id;
	double Hp;
	double Def;
	double Ap;
};


//const pointer
	
const int* cp;

//pointer const
int* const pc = NULL;
	
//const pointer const

const int* const cpc = NULL;
//potinter fuction

//int (*pF)(int,int);

typedef int(*pF)(int, int);//如果用此方式定义了一种函数指针的类型，不需要取别名，指针的名字成为别名，并且无法被赋值了，因为指针的名字已经变成了一种对应指针的数据类型，
//所以每次使用的时候都需要重新定义一个别命的对应类型的指针 如pF name

int	*fun_a(int *p) {
	static int a  = 11; //make merory of a in static area,the live with porgram;
	p = &a;
	return p;
}


void (*pfun_p)(int a,int b);

void fun_p(int a, int b) {
	
	cout << a + b << endl;
}

int mulit(int x, int y) {

	return x * y;
}

void fun_p2p(int(*pF)(int,int),int x,int y) {//int ,int occupy paramater
	
	cout << pF(x, y) << endl;
}

void fun_p3p(pF mulit, int x, int y) {
	cout << mulit(x,y) << endl;
}


void fuction_1 (int* x,int* y) {
	*x += *y;
}

int compare(const void* a, const void* b) {
	const crcpp	*cpr_a = (const crcpp*)a;
	const crcpp	*cpr_b = (const crcpp*)b;
	if (cpr_a->Hp != cpr_b->Hp)
		return cpr_b->Hp - cpr_a->Hp;
	return cpr_a->id - cpr_b->id;
}


int main() {
	/*
	* class 1;
	* 
	int a = 10;
	int* p = &a;//save the address of value data
	int  b = 0, c = 1, d = 2;
	int* bp = &b, * cp = &c, * dp = &d;//if not intialize may will aprear wild potiner
	//so we also can idefine  NULL in potiner,and NULL also as a adress we can vise
	int* np = NULL;
	cout << sizeof(b) << endl;


	fuction_1(bp, cp);
	cout << *bp << " " << *cp << endl;


	int arr[10] = { 0 };
	int* parr = arr;//potiner the adrress of the fist value of array;
	for (int i = 0; i < 10; i++) {
		cout << parr + i << endl;
	}


	const char* str = "hello";
	char* str_v = (char*)malloc(100 * sizeof(char));
	if(str_v)
	strcpy(str_v, "hello word");
	for (int i = 0; i < strlen(str); i++)
		cout << *(str + i);
	cout << endl;
	if (str_v)
		for (int i = 0; i < strlen(str_v); i++)
			cout << *(str_v + i);
	cout << endl;
	//mondatroy transformation
	int int_arr[] = { 0,1,2,3,4,5,6,7,8,9 };
	double* pdl = (double*)int_arr;
	pdl++;
	cout << *((int*)pdl);// to understand the fuction in potiner move of define data type size of bytes;
	//and potiner varibale have the type,the type will be used to consle move btyes in adress;


	*/
	crcpp crp[3] = {
		{1001,1,1,1},
		{1002,2,2,2},
		{1003,3,3,3}
	};



	int a_value = 1, b_value = 2;
	int* get_value = NULL;
	get_value = fun_a(get_value);
	cout << *get_value << endl;
	pfun_p = fun_p;//fuction pointer
	pfun_p(a_value,b_value);
	fun_p2p(mulit, a_value, b_value);
	fun_p3p(mulit,b_value, a_value);

	qsort(crp, sizeof(crp) / sizeof(crcpp) ,sizeof(crcpp ), compare);
	for (int i = 0; i < sizeof(crp) / sizeof(crcpp); i++)
		cout << crp[i].id << "\t" << crp[i].Hp << "\t"<<crp[i].Def<<"\t"<<crp[i].Ap<<endl;
	return 0;
}