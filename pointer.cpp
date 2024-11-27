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
	

	class 3;
		1,pointer array
			concepetion:
				the array save pointer
		2,array pointer
			concepetion:
				the pointer point to a array
					litte limit need a two dimensional array
		3,memory area;
			four areas:
				1,栈区:
					局部函数内由系统自动生成和结束时释放的内存
						局部函数如：for 循环
				2,堆区:
					手动申请和释放的内存：
						pay atttention: to free momory
							如果不释放，再次申请就会造成内存崩溃
								所以最好在开头全部申请好
				3,代码区:
					存储的是函数
				4，静态全局区:
					存储的是静态的全局的变量，
						不允许重复申请同名变量，不会报错，但是不会分配其他内存给已经出现过的变量名
				
	


	class 4;
		struct pointer
		dynamic memory distribution
			apply fuction:(apply heap area memory)
				malloc,memset，realloc,calloc
			emit:
				free//must sure the pointer in the first address postion if not,the memory will not be free combine intact;
				
*/

int* return_heap_value() {
	int* p = (int*)malloc(1);
	*p = 8848;
	return p;
}


void apply_memory() {
	int size = 100;
	int* p_aa = (int*)malloc(100);//retrun void type pointer so it should be cast
	int* p_int = (int*)malloc(100 * sizeof(int));//define a pointer have the adress it have 100 int meory area size include itself in behind; 
	for (int i = 0; i < 100; i++)
		*(p_int + i) = i + 1;
	for (int i = 0; i < 100; i++)
		cout << "\t" << *(p_int + i);
	free(p_aa);//只能释放一级申请的内存
	free(p_int);
	int** p = (int**)malloc(size * sizeof(int*));//申请100个int*类型的内存，返回首元素地址，也就是申请到的头地址，给int**，给申请到的int*内存赋值NULL
	for (int i = 0; i < size; i++)
		p[i] = (int*)malloc((size / 10) * sizeof(int));//申请10个int类型的内存，返回首元素地址给一个int*，给申请到的int赋值0，并取消了NULL的值
	//所以跟数组是一个道理,但是指针类型不是一个类型，二维数组由于要存储2级指针，他的值是3级指针,而且得是特殊类型的，
	//指的类型必须是数组,指数组得用数组指针不能用多重指针;
	for (int i = 0; i < 100; i++)
		free (p[i]);//逐级释放，先释放最底下的，不然会找不到引用，也就是解引用要从引用对象开始
	free(p);

	char * str_p = (char*)malloc(25);
	//逐字节赋值
	memset(str_p, 'a', 25);//可以初始化地址里的数值
	for (int i = 0; i < size; i++)
		cout << *str_p << endl;

	int arr[100][10] = { 0 };
	int (*p_a)[10] = arr;
}


struct crcpp {
	long long id;
	double Hp;
	double Def;
	double Ap;
};


typedef struct nodeDate {
	int id;
	const char* title;

}node;





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

void print_arr (int (*p)[3]){
	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 3; k++) {
			cout << p[i][k];
		}
		cout << "\n";
	}
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

	/*
	* class 2:
	*
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
	*/


	/*
	int arr_2d[3][3] = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	int (*p_2d)[3] = arr_2d;// an array pointer
	int arr_3d[3][3][3] = { 0 };
	int (*p_3d)[3][3] = arr_3d;
	//int *p point int int (*p) [3]
	//数组指针就是指向一个维度的数组的地址，这个地址应该是下级数组的一个数组或者值的地址[?]表示偏移与解引用，
	//如果使用最底层的地址来处理这件事情，那么偏移的过程的量就会十分复杂且直观写法并不具体
	//这里理解为，编译器为数组添加了额外的共用地址，比如2维数组中的一维数组有各自的共用地址吗，arr[i][j]就表示在连续的共用地址上偏移i个长度并解开引用获得一个一维数组的头元素地址；
	//同理对于三维数组的数组指针就是an[j][k][l],在二维数组的共用地址上偏移j个长度（一个j就代表一个二维数组大小的对应数据的指针偏移量），解开引用，获得对应的那个二维数组的头上元素的一列一维数组的共用地址，
	//于是又偏移k个长度（一个k就代表一个一维数组的指针变化量），解开引用得到一个数据共用的共用地址，也就是那个一维数组对应的首地址，
	//再偏移l个长度，（一个l就对应了1个数据对应的指针量化量）所以其本质就是经过层层包装的一个首地址进行指针的偏移传递
	//大概是一种通过定义节点的树状查找法则，节点间间隙一致


	//数组名字就是一种数组指针,通过偏移与解引用来获得对应的数据，
	//二维数组用里面的首元素的地址来表示，也就是第一个一维数组的地址，偏移解引用后得到一个一维数组，一维数组由首元素的地址表示，也就是得到了第一个元素的地址



	int* pa[3] = { arr_2d[0],arr_2d[1],arr_2d[2] };//like a array have a public adress
	print_arr(p_2d);

	int n[3][4] = {
		{1,2,3,4},
		{8,7,6,5},
		{9,10,11,12}
	};
	int(*pn)[4] = n;
	int* p[3] = {n[0],n[1],n[2]};
	int** pp = p; //数组p 相当于就是一个数套了2层引用所以可以赋给2级指针

	int c = 0;
	int* cp = &c;
	int** cpp = &cp;
	int*** cppp = &cpp;
	cout << *cp <<" " << *cpp<<" "<< *cppp<<endl;
	cout << *(*(pp + 1) + 2)<<endl;
	cout << *(*(pp + 2) - 3)<<endl;
	cout << *(*pp+1) << endl;//push the adress of 2;the proiorty of * is bigger than ++ the class if very high
	cout << *pp++<< endl;//指针的留存，不归零++是个赋值语句
	cout << *(pp[1] + 2) << endl;//指针位置留存了，数值没有改变；
	const char* progress[4]{
		"我喜欢流萤	1",
		"我喜欢流萤 2",
		"我喜欢流萤 3",
		"我喜欢流萤 4"
	};
	for (int i = 0; i < 4; i++)
		cout << progress[i] << endl;

		*/

		/*
		int id;
		node newn = {
			114514,"我的世界"
		};
		node* pn = &newn;
		id = newn.id;//名字，也就是结构体的值，用.偏移到id的位置解一次引用

		id = pn->id;//对应类型的指针，也就是结构体的地址，用->解一次引用然后偏移到id的位置再解一次引用

		node* p[100];
		node origin = {
			1001,"今天是11月27号"
		};
		p[0] = &origin;
		cout << (*(p[0])).id << endl;
		cout << (*(p[0])).title << endl;
		id = ((*p[0]).id);
		const char* put = (*p[0]).title;
		int id_smae = (p[0])->id;//->解2次引用，也就是通过一个对应数组类型的指针直接指向数组中对应的值，这个值在这个具体的结构体中用id表示


		node n[5]{
			{1,"aaa"},
			{2,"bbb"},
			{3,"ccc"},
			{4,"dddd"},
			{5,"tttt"}
		};
		node* crp[5] = { &n[3],&n[4] };
		cout << crp[0]->id << "\t" << crp[0]->title<< endl;
		*/

		/*
			node n[5]{
				{1,"aaa"},
				{2,"bbb"},
				{3,"ccc"},
				{4,"dddd"},
				{5,"tttt"}
			};

			node* pn = n;
			(*pn).id;//解引用获得第一个元素的值，也就是结构体的第一个数值的地址，其他数值与他自动并列对齐，所以通过特殊下标找到对应地址进行解引用获得对应的值，也就是变量名id的下的整数数据
			cout << (*pn).title << endl;
			//apply_memory();
			int* p_r = (int*)malloc(sizeof(int) * 25);
			for (int i = 0; i < 25; i++)
				p_r[i] = i + 1;
			p_r = (int*)realloc(p_r, sizeof(int) * 50);//重新分配内存，可以make
			for (int i = 0; i < 50; i++)
				cout << p_r[i]<<"\t";
			p_r = (int*)realloc(p_r, sizeof(int) * 10);
			for (int i = 0; i < 50; i++)
				cout << p_r[i]<<"\t";
			free(p_r);//使内存都指向空,但没有删除指针的数值，也就是内存编号
			//注意指针必须在首地址位置才能完全释放内存,不过编译器会自动报错
		*/

	int* p = (int*)calloc(25, sizeof(int));//给申请的地址赋0值，不好用，不能给int**用，搞不了存地址的内存区域
	for (int i = 0; i < 25; i++) {
		cout << p[i] << "\t";
	}

	//if a fuction return the value in heap area it should be free in main in same time
	int* pr = return_heap_value();
	cout << *pr << endl;
	free(p);


	//train

	int* pt = (int*)malloc(sizeof(int) * 10);
	for (int i = 0; i < 10; i++)
		pt[i] = i + 1;
	int* ptr = (int*)malloc(sizeof(int) * 10 * 2);
	for (int i = 0; i < 10; i++) {
		ptr[i] = pt[i];
		ptr[i + 10] = 11 + i;
	}
	free(pt);
	pt = ptr;
	for (int i = 0; i < 20; i++)
		cout << pt[i]<<" ";
	free(ptr);
	return 0;
}