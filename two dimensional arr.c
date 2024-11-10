// one dimensional array is continuos memory location --example 0x0 0x4 0x8(the data of int)

//pay attention :  null in origin is 0(int) in int

// two dimensional array is other continuos memory location in other direction? no,the direction is straight

//Example  the direction of arr[2][10] : 2 to y , 10 to x

//so in the other words says: this is a coordinate

#include <stdio.h>

int main(){
    /*can int arr[][];
        to make a dimensional array*/
// need to make origin
    int arr0[2][10] ={{1,2,3,4,5,6,7,8,9,10},
                    {10,9,8,7,6,5,4,3,2,1}
                    };
    int arr1[2][10] ={1,2,3,4,5,6,7,8,9,10,10,9,8,7,6,5,4,3,2,1};

// So i can get a conclusion that is read x preferentially and then to read the x of the next y;
// the way of save is same as one dimensional array;
/*example:
    arr[0][0] 1x0
    arr[1][0] 1x0 + (size of int == 4)* 10 == 1x40
    */
// the mistakes of  same original snese
// example
    /*
    int arr[];
    int arr[2][]
    int arr [][10]
    
    */
// all in all ,can't set a array of null size;

    int arr2[][3] = {
        {1,2,3},
        {3,2,1}
    }; //code auto  to get size of y ,is available

    //printf
    printf("the first example of two demension array pirnt is:\n");
    for (int i = 0; i < 3; i++)//get each line
    {
        for(int k = 0;k < 2;k++)//get each column
        {
            printf("%d",arr2[k][i]);
        }
        printf("\n");
    }
        printf("\n");
    // the example to express the most outside of for range is the first index in get and print;
    printf("the second example is:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            printf("%d",arr2[i][k]);
        }
        printf("\n");
        
    }
    //the same sense of origin
    //所谓几维数值，就是那大括号代表代表维度的方向
    // so the third dimension
printf("the third example is:\n");
    int arr3[2][3][4] = {
        {
            {1,2,3,4},
            {4,3,2,1},
            {8,8,8,8}
        },
        {
            {8,8,8,8},
            {6,6,6,6},//the second 6 coordinate is arr[1][1][1];
            {1,3,4,5}

        }
    };
    for (int i = 0; i < 2; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            for (int j = 0; j < 4; j++)
            {
                printf("%d",arr3[i][k][j]);
            }
            printf("\n");
            
        }
        printf("\n");
        
    }
    
    return 0 ;
    
}