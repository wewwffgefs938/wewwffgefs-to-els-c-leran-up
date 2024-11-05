#define _CRT_SECURE_NO_WARNINGS   
#include <stdio.h>
#include <windows.h>
#include <conio.h>

void overgame(int flag) {// overgame function
    if (flag) {
        printf("Game Over!\n");
        system("pause");
        exit(0);
    }
    return;
}

int main() {

    int arrbox[5][5] = { // a arr express area ,the 2 express the box
        {1, 1, 1, 1, 1},
        {1, 4, 0, 0, 1},
        {1, 0, 2, 3, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1}
    };

    int x = 0, y = 0;      // to represent the coordinate of player
    int xbox = 0, ybox = 0; // to represent the coordinate of box
    int flag = 0; // to represent the flag of game over
    while (1) {
        for (int i = 0; i < 5; i++) {
            for (int k = 0; k < 5; k++) {
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

        for (int i = 0; i < 5; i++) { // print the area image
            for (int k = 0; k < 5; k++) {
                printf("%d", arrbox[i][k]);
            }
            printf("\n");
        }
        overgame(flag);
        switch (_getch()) { // get the key of keyboard
        case 's':
            if (arrbox[y + 1][x] == 1) {
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
            if (arrbox[y - 1][x] == 1) {
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
            if (arrbox[y][x - 1] == 1) {
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
            if (arrbox[y][x + 1] == 1) {
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
