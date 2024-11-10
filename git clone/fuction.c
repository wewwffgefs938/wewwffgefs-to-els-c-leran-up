//#include <stdio.h>
//
////fuction is an encapsulated tool box to solve the problem
////fuction define mode
//
///*
//    the type of return value fuction name(parameter list
//    {
//        //fuction body
//    }
//    fuction name is sign symbol
//*/
//
//// if don't need return define fuction type as void
//
//int One(){
//    
//    return 3;//3 is data of int type
//}
//
//void Two(){//print 9*9 mutiplication table
//    for(int i = 1; i < 10; i++){
//        for(int j = 1;j <= i; j++){
//            printf("%d*%d=%d\t",j,i,i*j);
//        }
//        printf("\n");
//    }
//}//no return value
//
//int Three(int num_1,int num_2){//return the sum of two number ,num_1 and num_2 is form parameter
//
//    return num_1 + num_2;
//}//return value
////the way that make actual parameter to form parameter is called transmit value
//
//int One_end();//fuction statement
//
//
///*
//    Global variables:
//    if your add the variable in global area,it can be used in any fuction,and don't renamed it in another fuction
//    and in same but back logic fuction,limit area variable(privacy area variable)  can't be used in the public area  fuction.
//    The reason is the box of private used to store the data of fuction will free in the end of the fuction.
//    In the other word,the apple box is no apple in the box,so it will be a banana box or not,computer don't know,so it should be renamed,if you want to use the box to save stuffs.
//    
//*/
//int Global_int = 100;
////pay attention to the fuction name is appeal to same name
////the use like dump a public box apple to private box apple,free variable is means to free the box (the memory),not data!
//void Private_int(){
//    Global_int = 50;
//}//the person can use the public,but the public can't use the private
//
///*
//    the static(solid) fuction and variable : // they are only be identified once in the program,it will be free in the end of the program
//    the memory area:
//        all have four area:
//            1,static global area: to save global variable and static variable
//            2,stack area: to save limit fuction area variable,int box,the memory will be auto applied and auto free by system
//            3,
//            4,code area:
//*/
//static int static_num_1 = 10;//save in the static global area
//int limit_fuction(){
//    int private_num_1 = 10;//save in the stack area
//    return private_num_1;
//}//the memory of private_num_1 will be free in the end of the fuction
//
//static int static_num_2 = 11;//save in the static global area
//
//int example_num_1(){
//    for (int i = 0; i < 10; i++)
//    {
//        static int static_num_2 = 10;//save in the static global area,but the static_num_2 is not be free,apply memory box and stuff is with original data will fail
//        static_num_2++;
//        printf("%d\n",static_num_2);//so print 11- 20
//    }
//   
//    return static_num_2;
//}
////Pay attention static int static_num_2 in public area is not be apply,be static num is not be apply in first so it is 10 be stuff the box and apply the box;
////in easy is = 10 this sentence first to apply the box,and the box is not be change before the program killed.
//
//
//
//int main(){//the main fuction is the entry of the program
///*
//    Two();
//    return 0;
//*/
//    /*
//    int sum = Three(1,2);//1 and 2 is actual parameter
//    printf("%d",sum);
//    */
//
//    example_num_1();
//    return 0;// to show the program is end,stop clip fuction
//}
//
//int One_end(){
//
//    return 3;
//}











#include <stdio.h>
#include <stdlib.h>

//1.address tansmit value
//2,array to be a parameter in fuction
//3,Recursion of functions

//adress:
	//when we int the variable,array,fuction etc,it will be distribute in the memory by system,it put data in these memory.
	//so address is a pointer number of the memory location.
	//&;&a //& is a symbol to get adress of a,a is a variable.
int*** initialize_parray(int n, int j, int k) {
	int*** p = (int***)malloc(sizeof(int**) * n); //allocate memory for a pointer variable
	for (int i = 0; i < n; i++)
		p[i] = (int**)malloc(sizeof(int*) * j); //allocate memory for an array of pointers
	for (int i = 0; i < n; i++)
		for (int z = 0; z < j; z++)
			p[i][z] = (int*)malloc(sizeof(int) * k); //allocate memory for an array of integers
	return p; //return the pointer variable
}
int*** parry_func(int*** p) {
	int a = 10;
	p[0][0][0] = a; //change the value of the memory location of a by pointer p.
	return p;
}
void getaddress(float* p) {
	printf("%f", *p); //output the value of the memory address of the pointer variable p.
		// * �������ʱ����������Ϊ��ʾ�������ã�ȡ���ݡ�
		//& ��������ʱ����������Ϊ�������ݣ�ȡ��ַ�������á�
	*p = 7.777; //change the value in the memory location of the variable p.so it is penetrability(free pass) of the program.
				//but different the global can be use the name to pass,it is use the memory that never be free  adress to pass fuctuion to change the value.
}
//������˵���ģ�
//ָ�����ָ���ַ��ָ�꣬��ַ���Ǵ洢�������Ǹ��ڴ���ӵı�š�
//һ��ָ�����ָֻ��һ���ڴ棬����ָ�����ָ��һ���ڴ��е�һ���ڴ棬�Դ����ơ�
// ����˵��ÿһ��ָ�������һ���������һ����Χ����Щ�����뷶Χ��������һ�������㣬��������ָ���˴�����ַ�ڴ���ӵ��Ǹ���ͼ�ָ�����
//��Ȼ���۶��ټ�ָ�룬���ն�ָ�����ͬһ���ڴ��ַ�����Ǽ����������˷�Χ�뷽��ĳ��󣬾�������������ı�Ȼ�ںϹ�ϵ����Ϊ����Ҳ�ܴ��������뷶Χ�ĳ���,���������������������Ѱ�ҵ�ַ��Ч�ʡ�
//example:
//�ܵ���˵��ǰ�涼��ƨ��������һ��һ���ĵ�ַ��ָ�룩��˵����һ���ĵ�ַ������һ����ָ�룬�����һ���ĵ�ַ���Ǳ�����ʵ��ֵ��
//ָ�벻�����飬ָ��ֻ�ǵ�ַ��һ�ֱ�ʾ��ʽ������ֻ��һϵ�еĵ�ַ�ļ��ϡ�
//һ��ָ��ָ������ַ�ĸ����壬���ָ����ɵľ��ǵ�ַ�ĸ����壬ָ����ǵ�ַ����ַ����ָ�롣
//Ҳ��˵ָ��Ķ༶ָ��ı��ʾ���һ����ַ�ĸ������У�һ����ַָ������ַ�ĸ����壬��Щ��ַ������ν��ָ�룬���ǲ��ݽ��ģ���ָ��ĵ�ַ�����ǵ�ַ�ĸ�����ʱ�����ָ���������һ�������ĵ�ַ��Ҳ�������һ��ָ�롣

/*
	1,how to add the variable to save in the memory? :  use  the pointer variable that save the adress to point to the memory location of the variable.
	2,how to get the adress of the variable? : use the & symbol to get the adress of the variable? ; use the symbol & to get.
	3.how to through the pointer variable to get the value of the variable? : use the * symbol to get the value of the variable.
	//and or if it is a various variables can use the name of pointer variable plus the index of pointer variable to get the final address of the variable.
*/


//array fuction:
void array_print_func(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}


//Recursion of functions:
	//one sentence to express it: a function can call itself.
void recursion_func_1() {
	printf("recursion_func_1\n");
	recursion_func_1();
}

void recursion_func_2() {
	static int count = 0;
	if (count < 10){
		count++;
		recursion_func_2();
	}
	printf("recursion_func_2\n"); //the recursion_func_2 will be called 10times and plus the first one ,so it will be print 11 times.�������Ҫ���ִ�д���������print ����ѭ���ڣ�������������õĴ����Ρ�
}

void recursion_func_3(int n) {// to the each of the digit of the number
	printf("%d ", n % 10);
	n /= 10;
	if (n > 0) {
		recursion_func_3(n);//
	}
	else {
		printf("\n");
	}
	printf("count>>>");
}

//쳲���������.....��n��Ԫ�ص���ֵ���� ��n-1��Ԫ�ص���ֵ���ϵ�n-2��Ԫ�ص���ֵ��
int fibonacci(int n) {
	static int x1 = 1, x2 = 1;
	static int count = 2;
	if (count == n) {
		return x2;
	}
	else if (n == 1) {
		return x1;
	}
	else if (n == 2) {
		return x2;
	}
	else {
		int temp = x1 + x2;
		x1 = x2;
		x2 = temp;
		count++;
		return fibonacci(n);
	}
}
//other way to get the Fibonacci number:
int fibonacci_num(int n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	return fibonacci_num(n - 1) + fibonacci_num(n - 2);//�����˲����ϲ��Ĺ��̣��ݹ�Ĺ��̡�
}

//homework:
	//monkey eat ���ӣ�ժ��n�����ӣ�ÿ���һ���һ����
	//�õݹ麯����� �ڵ�days��ʱ����ֻʣһ���������ӡ�
int mokey_eat_peach(int days) {
	static int n = 1;
	days--;
	if (days == 0) {
		return n;
	}
	else {
		n =(n + 1)*2;
		mokey_eat_peach(days);
	}
}

int me_eat_peach_func(int days) {
	static int n = 1;
	static int count = 1;
	if (days == count) {
		return n;
	}
	n = (n + 1) * 2;
	count++;
	me_eat_peach_func(days);
}

int meonkey_eat_peach_func(int days) {
	static int n = 1;
	days--;
	if (days == 0) {
		return n;
	}
	n = (n + 1) * 2;
	return meonkey_eat_peach_func(days);
}

//��ָ����߼���ʵ����ͬ�ģ�����ָ��return��ȡ������ֵ�����á�

int main() {
	int a = 10;
	char b = 'a';
	float c = 3.14; // a kind of variable can be saved in the memory by system.
	//so the address is also can be saved in the memory as a variable.
	//int *p = &a; //p is a pointer variable to point to the memory location of a.
	//address is a constant value,it can't be change,but the data can be change.
	int*** array = initialize_parray(2, 3, 4); //initialize a 3D array
	array = parry_func(array);
	printf("%d", array[0][0][0]); // output: 10
	printf("\n");
	getaddress(&c); // output: 3.14 &c is the address of c,also as the pointer variable to point to the memory location of c.
	//printf("%d", ***array); // output: 0
	printf("\n");
	printf("%f", c); // output: 7.777
	printf("\t");

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			free(array[i][j]); //free the memory of the array
		}
		free(array[i]); //free the memory of the array
	}
	free(array); //free the memory of the array
	

	int arr[] = { 1, 2, 3, 4, 5 };
	int len = sizeof(arr) / sizeof(arr[0]); //get the length of the array
	array_print_func(arr, len); //output: 1 2 3 4 5

	//recursion_func_1(); //output: recursion_func_1 recursion_func_1 recursion_func_1...
	recursion_func_2(); //output: recursion_func_2 recursion_func_2 recursion_func_2...
	int numb = 123456789;
	recursion_func_3(numb); //output: 9 8 7 6 5 4 3 2 1

	printf("\n");

	int fib_num = fibonacci(10); //output: 55 the tenth number of the Fibonacci sequence.
	printf("%d", fib_num);
	printf("\n");
	int peach_num = mokey_eat_peach(25); //when the number of peach express the days is reched,
	printf("%d", peach_num);
	printf("\n");
	int me_peach_num = me_eat_peach_func(10); //output: 1023
	printf("%d", me_peach_num);
	printf("\n");
	int meonkey_peach_num = meonkey_eat_peach_func(10); //output: 1023
	printf("%d", meonkey_peach_num);
	return 0;
}


//�ݹ麯����
	//����û�г��׽�����Ǿ���ͬһ�����Ӽ����ھ�ֱ�����������⣬���ÿһ���ھ���涼��һ�����죬�͵���ͨ��һ�������