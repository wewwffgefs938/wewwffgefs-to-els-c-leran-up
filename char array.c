#include <stdio.h>
#include <windows.h>
#include <string.h>

// char array
//\0 appear the end of the array
//%s appear to print the array until face \0

/// @brief
/// @return
int main()
{
    /*

    char str[10];                  // create a char array sizeof 10
    str[0] = 'a';                  // put a char in the array
    char str1[10] = {"abcdefgif"}; // pay attention if full may error

    // so the end of the array is '\0'
    str[9] = '\0'; // put the end of the array
    // if no \0 appear the array will print the random data such as mess code ‘烫’

    printf("%s", str1); // print the array
    printf("\n");

    */
    /*

    char str2[10];
    str2[0] = 'a';
    str2[1] = 'b';
    str2[2] = '\0';
    str[3] = 'c';
    printf("%s", str2);
    printf("\n");
    printf("%c", str2[3]);
    // can see the c is not print
    // and the c is not put in the array so if face the \0 the array will stop put the data

    */

    /*char str3[10];
    scanf("%s", str3);  // not lonely variable don,t use the & to appear abs path
    printf("%s", str3); // the chinese char is same as char but it will be stuff 2 bytes
    // so if we want to scanf chinese char we can initialize the array  sizeof length double bigger than english char
    //  and don't forget the /0 in the end of the array so sizeof array should be plus one
    */

    /*
    char str4[10];
    scanf("%s", str4);
    //if we put char sting "abc def" in the array it will only print abc
    printf("%s", str4);
    //because though the print of \0 is mess code but it is appear the empty space(input by scanf(the original input way in windows system)) in the array
    //and scanf will stop the array when face the \0
    //in the deep expression is in the windows system scanf the space is appear input \0
    //More pay attention is printf not will stop the array until face the space if the initialize data include space
    //because the space in the array that initialized will be express " ",this str
    //and input char by scanf will be express \0
    //so if your put space in the array it will print the char stirng which before space
    //!Pay attention but if your put " abc def" in the array it will print "abc"
    //so i push the conclusion that array is need not empty put and then use \0 or space to stop the array in the other words

ALL in all if using scanf to put char string space will be express \0 and result string behind it will not be input in char array

    */

    //another way to input or output the char string,use other fuction

    /*
    char str5[10];
    gets(str5);//it can avoid the space stop input string because it express space to " ",this str,i push it not use the origin put in windows,it make the extra fuction to express \0 to " ",this str
    puts(str5);
    //this two is good fuction to deal with char string

    */

    //but the different is that gets with puts can input space and scanf with printf can't
    
    /*

//the two dimension char array;

    char str6[4][10] =
    {
        {"吕哥"},
        {"刘哥"}
    };
    //printf("%s", str6[0]);//to print "吕哥"
    //printf("\n");
    //printf("%s", str6[0][0,1]);//to print "吕"
    //it is mistake to print the char string by index if it is a chinese char
    //the right way is: in under of this line
        //printf("%c%c",str6[0][0],str6[0][1]);//to print "吕"
        //system("pause");//to stop the system wait use put the any key to continue

    */

/*
//the usual fuction of char string need to include string.h
    char str_a[10] = "aaaa";
    char str_b[10] = "aaaa";
    char str_c[10] = "bbbb";
    
    //one compare the string is same or not
    strcmp(str_a,str_b);//to compare the ASCLL code of the string
    //if str_a == str_b return 0
    //if str_a > str_b return value > 0
    //if str_a < str_b return value < 0
    //the compare priority is the first different char in the string
    //if have compared the  in the string the return value of it will be push
    
    sizeof(str_a);//to get the size of the string
    strlen(str_a);//to get the length of the string record the length of the string without \0
    

    strcat(str_a,str_c);//to splicing the two string append str_c to str_a
    //pay attention the str_a must have enough space to append the str_c
    printf("%s",str_a);

    printf("\n");

    strcpy(str_a,str_c);//to copy the str_c to str_a all cover
    printf("%s",str_a);

    //str_b = "qqqq" is a mistake
    //because str_b is a constant string can't be changed
    //if we want to change the string we can use strcpy
    strcpy(str_b,"qqqq");
    puts(str_b);

    */
    system("pause");
    return 0;

}