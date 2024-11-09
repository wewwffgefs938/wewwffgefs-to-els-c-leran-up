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
			int*** initialize_parray(int n,int j,int k) {
				int*** p = (int***)malloc(sizeof(int**)*n); //allocate memory for a pointer variable
				for(int i=0;i<n;i++)
					p[i] = (int**)malloc(sizeof(int*)*j); //allocate memory for an array of pointers
				for(int i=0;i<n;i++)
					for(int z=0;z<k;z++)
						p[i][z] = (int*)malloc(sizeof(int)*k); //allocate memory for an array of integers
				return p; //return the pointer variable
			}
			int*** parry_func(int*** p){
				int a = 10;
				p[0][0][0] = a; //change the value of the memory location of a by pointer p.
				return p;
			}
			//让我们说中文：
			//指针就是指向地址的指标，地址就是存储变量的那个内存盒子的编号。
			//一级指针变量只指向一块内存，二级指针变量指向一块内存中的一块内存，以此类推。
			// 或者说，每一级指针代表了一个方向或者一个范围，而些方向与范围都必须有一个关联点，最终作用指向了代表地址内存盒子的那个最低级指针变量
			//虽然无论多少级指针，最终都指向的是同一种内存地址，但是级数，代表了范围与方向的抽象，决定了它与数组的必然融合关系，因为数组也能代表方向与范围的抽象,而且这样的整理可以提高寻找地址的效率。
			//example:
			//总的来说，前面都是屁话，对于一级一级的地址（指针）来说，上一级的地址就是下一级的指针，而最后一级的地址就是变量的实际值。
			//指针不是数组，指针只是地址的一种表示方式，数组只是一系列的地址的集合。
			//一个指针指向多个地址的复合体，多个指针组成的就是地址的复合体，指针就是地址，地址就是指针。
			//也就说指针的多级指针的本质就是一个地址的复合体中，一个地址指向多个地址的复合体，这些地址就是所谓的指针，这是层层递进的，当指针的地址不再是地址的复合体时，这个指针代表就是一个变量的地址，也就是最后一级指针。
int main(){
    int a = 10;
	char b = 'a';
	float c = 3.14; // a kind of variable can be saved in the memory by system.
	//so the address is also can be saved in the memory as a variable.
	//int *p = &a; //p is a pointer variable to point to the memory location of a.
	//address is a constant value,it can't be change,but the data can be change.
	int*** array = initialize_parray(2, 3, 4); //initialize a 3D array
	array = parry_func(array);
	printf("%d", array[0][0][0]); // output: 10
	return 0;
}