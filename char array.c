#include <stdio.h>


// char array
//\0 appear the end of the array
//%s appear to print the array until face \0


int main(){
    char str[10];//create a char array sizeof 10
    str[0] = 'a';//put a char in the array
    char str1[10] = {"abcdefgif"};// pay attention if full may error

    // so the end of the array is '\0'
    str[9] = '\0';//put the end of the array
    //if no \0 appear the array will print the random data such as mess code ‘烫’

    printf("%s",str1);//print the array
    printf("\n");

    char str2[10];
    str2[0] = 'a';
    str2[1] = 'b';
    str2[2] ='\0';
    str[3] = 'c';
    printf("%s",str2);
    printf("\n");
    printf("%c",str2[3]);
    //can see the c is not print
    //and the c is not put in the array so if face the \0 the array will stop put the data


    return 0;
}