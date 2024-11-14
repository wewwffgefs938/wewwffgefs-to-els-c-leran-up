#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


//FLIE
//Type
//1,text file the person can read and write
//2,binary file the computer can read and write
	//compiler:make text to binary .c .cpp ----->.obj--save the binary code

//How to handle file:
		//FILE * name(path in fact)_of_file;//pointer to file
		//fopen (path of file, mode of file);
//the fuction of file in consle is:
		//1,fopen(path of file, mode of file);
		//2,fclose(pointer to file);
		//3,fputs(string to write, pointer to file);
		//4,fgetc(pointer to file);
		//5,fgets(string to read, size of string, pointer to file);
		//6,fseek(pointer to file, offset, origin);
//How:to read the whole file:

int main() {
	char strc;
	int a = 10;//10 compile to binary is 0000 1010
	int b = 10;
	/*
	FILE* path_of_test_txt_file;//pointer to file path;
	path_of_test_txt_file = fopen("D:\\Learn\\setC\\git clone\\File\\Text_File_Test.txt", "w");//open file in write mode 打开文件函数的目录初始化在项目的根目录下，所以无法用相对路径打开打开File目录，得用绝对路径打开，并且要小心转译字符，路径翻页用\\path\\fpath\\ffpath，文件名不能有中文，否则会报错。
	//所以建议把东西都写在项目文件夹下，然后就都可以用相对路径打开了。
	//本质上就是外部导入外部找，函数内部打开内部找的问题，打开文件这个行为本应在项目内部打开。
	if (path_of_test_txt_file != NULL) {
    printf("File opened successfully\n");
    fputs("Hello File", path_of_test_txt_file);
    fputc('c', path_of_test_txt_file);
	
    fflush(path_of_test_txt_file); // 确保所有数据都已写入

    //fseek(path_of_test_txt_file, 0, SEEK_SET); // 移动文件指针到开头
	
    char s[1024] = {0}; // 初始化字符数组
	path_of_test_txt_file = fopen("D:\\Learn\\setC\\git clone\\File\\Text_File_Test.txt", "r");//前面的操作不奏效，故要重新打开文件
	fgets(s, sizeof(s) / sizeof(s[0] - 1), path_of_test_txt_file);
    printf("%s", s); // 输出读取的内容
	printf("\n");
	fgets(s, sizeof(s) / sizeof(s[0]), path_of_test_txt_file);
    printf("%s", s); // 输出读取的内容
	path_of_test_txt_file = fopen("D:\\Learn\\setC\\git clone\\File\\Text_File_Test.txt", "r");//前面的操作不奏效，故要重新打开文件
	printf("\t");
	strc = fgetc(path_of_test_txt_file); // 读取下一个字符
	printf("%c", strc); // 输出读取的字符
	strc = fgetc(path_of_test_txt_file); // 读取下一个字符
	printf("%c", strc); // 输出读取的字符
	strc = fgetc(path_of_test_txt_file); // 读取下一个字符
	printf("%c", strc); // 输出读取的字符
	strc = fgetc(path_of_test_txt_file); // 读取下一个字符
	printf("%c", strc); // 输出读取的字符
	strc = fgetc(path_of_test_txt_file); // 读取下一个字符
	printf("%c", strc); // 输出读取的字符

    fclose(path_of_test_txt_file);
	}
	*/
	const char *path = "D:\\Learn\\setC\\git clone\\File\\Text_File_Test.txt";
	FILE *file = fopen(path, "r");
	char str[1024] = {0};//不初始化就会越界，输出就会乱码//英文未初始化的就是0，是个数字，当成输出会乱码，当成数值占用最小
	int i = 0;
	while (!feof(file)) {
		str[i] = fgetc(file);
		i++;
	}
	str[i-1] = '\0';//最后一个字符对应的是'-1'(不知道为什么),所以要手动赋值为'\0'，否则会输出乱码
	printf("%s", str);
	return 0;
}