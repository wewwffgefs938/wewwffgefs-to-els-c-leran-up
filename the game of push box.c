#define _CRT_SECURE_NO_WARNINGS   
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>


 void overgame(int flag);
 int getrandomnumber(int, int);
 int** initialize_area(int, int);
 int** setperson_box_end(int**, int, int);
 int inputsizeofarea();


int main() {
    printf("Welcome to the game!\n");
    int sizeofline,sizeofcolumn;
    sizeofline = inputsizeofarea(); // get the size of line of the area
    sizeofcolumn = sizeofline; // the size of column of the area is the same as the size of line
    int** arrbox = initialize_area(sizeofline, sizeofcolumn); // initialize the area of map
    arrbox = setperson_box_end(arrbox, sizeofline, sizeofcolumn); // set the coordinates of person and box and endin the area
    int x = 0, y = 0;      // to represent the coordinate of player
    int xbox = 0, ybox = 0; // to represent the coordinate of box
    int flag = 0; // to represent the flag of gameover
    while (1) {
        for (int i = 0; i < sizeofcolumn; i++) {
            for (int k = 0; k < sizeofline; k++) {
                if (arrbox[i][k] == 2) { // get the data of coordinate of player
                    x = k;
                    y = i;
                }
                if (arrbox[i][k] == 3) { // get the data of coordinate of box
                    xbox = k;
                    ybox = i;
                }
            }
        }
        system("cls"); // clear the screen

        for (int i = 0; i < sizeofcolumn; i++) { // print the area image
            for (int k = 0; k < sizeofline; k++) {
                printf("%d", arrbox[i][k]);
            }
            printf("\n");
        }
        overgame(flag);
        switch (_getch()) { // get the key of keyboard and move the player
        case 's':
            if (arrbox[y + 1][x] == 1 || arrbox[y + 1][x] == 4) {
                break;
            }
            if (arrbox[y + 1][x] == 3) {
                if (arrbox[ybox + 1][xbox] == 1) {
                    arrbox[y][x] += 1;
                    arrbox[y + 1][x] -= 1;
                    break;
                }
                else if (arrbox[ybox + 1][xbox] == 4) {
                    arrbox[ybox + 1][xbox] -= 1;
                    arrbox[ybox][xbox] -= 1;
                    arrbox[y][x] -= 2;
                    flag = 1;
                    break;
                }
                arrbox[ybox + 1][xbox] += 3;
                arrbox[ybox][xbox] -= 1;
                arrbox[y][x] -= 2;
                break;
            }
            arrbox[y][x] -= 2;
            arrbox[y + 1][x] += 2; // exchange coordinate of player
            break;

        case 'w':
            if (arrbox[y - 1][x] == 1 || arrbox[y - 1][x] == 4) {
                break;
            }
            if (arrbox[y - 1][x] == 3) {
                if (arrbox[ybox - 1][xbox] == 1) {
                    arrbox[y][x] += 1;
                    arrbox[y - 1][x] -= 1;
                    break;
                }
                else if (arrbox[ybox - 1][xbox] == 4) {
                    arrbox[ybox - 1][xbox] -= 1;
                    arrbox[ybox][xbox] -= 1;
                    arrbox[y][x] -= 2;
                    flag = 1;
                    break;
                }
                arrbox[ybox - 1][xbox] += 3;
                arrbox[ybox][xbox] -= 1;
                arrbox[y][x] -= 2;
                break;
            }
            arrbox[y][x] -= 2;
            arrbox[y - 1][x] += 2;
            break;

        case 'a':
            if (arrbox[y][x - 1] == 1 || arrbox[y][x - 1] == 4) {
                break;
            }
            if (arrbox[y][x - 1] == 3) {
                if (arrbox[ybox][xbox - 1] == 1) {
                    arrbox[y][x] += 1;
                    arrbox[y][x - 1] -= 1;
                    break;
                }
                else if (arrbox[ybox][xbox - 1] == 4) {
                    arrbox[ybox][xbox - 1] -= 1;
                    arrbox[ybox][xbox] -= 1;
                    arrbox[y][x] -= 2;
                    flag = 1;
                    break;
                }
                arrbox[ybox][xbox - 1] += 3;
                arrbox[ybox][xbox] -= 1;
                arrbox[y][x] -= 2;
                break;
            }
            arrbox[y][x] -= 2;
            arrbox[y][x - 1] += 2;
            break;

        case 'd':
            if (arrbox[y][x + 1] == 1 || arrbox[y][x + 1] == 4) {
                break;
            }
            if (arrbox[y][x + 1] == 3) {
                if (arrbox[ybox][xbox + 1] == 1) {
                    arrbox[y][x] += 1;
                    arrbox[y][x + 1] -= 1;
                    break;
                }
                else if (arrbox[ybox][xbox + 1] == 4) {
                    arrbox[ybox][xbox + 1] -= 1;
                    arrbox[ybox][xbox] -= 1;
                    arrbox[y][x] -= 2;
                    flag = 1;
                    break;
                }
                arrbox[ybox][xbox + 1] += 3;
                arrbox[ybox][xbox] -= 1;
                arrbox[y][x] -= 2;
                break;
            }
            arrbox[y][x] -= 2;
            arrbox[y][x + 1] += 2;
            break;

        default:
            break;
        }
    }
    return 0;
}


void overgame(int flag) {// overgame function
    if (flag) {
        char Judgmentsymbols;
        printf("Press this level\n ");
        printf("Do you want to play again? (Y/N) ");
        // 清除输入缓冲区中的换行符
        getchar(); // 读取上次输入后的换行符
        scanf("%c", &Judgmentsymbols);
        if (Judgmentsymbols == 'Y' || Judgmentsymbols == 'y') {
            system("cls");
            main(); // 递归调用 main 重新开始游戏
        }
        else {
            printf("Game Over!\n");
            system("pause");
            exit(0);
        }
    }
    return;
}


int getrandomnumber(int min, int max) {
    srand((unsigned)time(NULL)); // initialize the random number generator
    return rand() % (max - min + 1) + min; // generate a random number between min and max
}

int** initialize_area(int sizeofline, int sizeofcolumn) {// initialize the area of map
    int** arrmalloc = (int**)malloc(sizeofline * sizeof(int*)); //mallocate the line memory of the area
    for (int i = 0; i < sizeofline; i++)
        arrmalloc[i] = (int*)malloc(sizeofcolumn * sizeof(int)); //mallocate the column memory of the area
    for (int i = 0; i < sizeofcolumn; i++)//initialize the area of map
    {
        for (int k = 0; k < sizeofline; k++) {
            if (i == 0 || i == sizeofcolumn - 1) {
                arrmalloc[k][i] = 1; // set the across border of the area
            }
            else if (k == 0 || k == sizeofline - 1) {
                arrmalloc[k][i] = 1; // set the vertical border of the area
            }
            else {
                arrmalloc[k][i] = 0; // set the empty space of the area
            }
        }
    }
    return arrmalloc;
}

int** setperson_box_end(int** arrbox, int sizeofline, int sizeofcolumn) {
    int x = 0, y = 0; // to represent the coordinate of player
    int xbox = 0, ybox = 0; // to represent the coordinate of box
    int endx = 0, endy = 0; // to represent the coordinate of end
    //first set the people in the middles of the area
    arrbox[sizeofline / 2][sizeofcolumn / 2] = 2;//the regular cooridinate of player so can see the length of sizeof area is need biger than 3
    x = sizeofline / 2;//get the line coordinate of player
    y = sizeofcolumn / 2;//get the column coordinate of player
    //set the box in the area random ,the random seed is time(NULL)
    do {
        int xbox = getrandomnumber(1, sizeofcolumn - 2); // generate a random number between 1 and sizeofcolumn-2
        int ybox = getrandomnumber(1, sizeofline - 2); // generate a random number between 1 and sizeofline-2
        if (arrbox[ybox][xbox] == 0) {// check if the person is in the area
            arrbox[ybox][xbox] = 3; // set the box in the area
            break;
        }
    } while (1);
    //set the end in the area random
    do {
        int endx = getrandomnumber(1, sizeofcolumn - 2); // generate a random number between 1 and sizeofcolumn-2
        int endy = getrandomnumber(1, sizeofline - 2); // generate a random number between 1 and sizeofline-2
        if (arrbox[endy][endx] == 0) {// check if the person is in the area
            arrbox[endy][endx] = 4; // set the end in the area
            break;
        }
    } while (1);
    return arrbox;// set the person and box in the area
}

int inputsizeofarea() {
    printf("Please input the size of line == column of the area:\n ");
    printf("reminding ! size shoud be bigger than 1 !\n");
    int sizeofarea; scanf("%d", &sizeofarea); // the size of line of the area

    return sizeofarea+2;
}

