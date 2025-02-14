#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

char boardnum[10]= {'0','1','2','3','4','5','6','7','8','9'};
void board() {
    clrscr();
    printf("×××××TIC-TAC-TOE××××× \n\n");
    printf("      |      |      \n");
    printf("   %c  |  %c   |  %c  \n",boardnum[1],boardnum[2],boardnum[3]);
    printf("______|______|______ \n");
    printf("      |      |       \n");
    printf("   %c  |  %c   |  %c   \n",boardnum[4],boardnum[5],boardnum[6]);
    printf("______|______|______ \n");
    printf("      |      |       \n");
    printf("   %c  |  %c   |  %c  \n",boardnum[7],boardnum[8],boardnum[9]);
    printf("      |      |      \n\n");

}

int win() {
    if(boardnum[1]==boardnum[2] && boardnum[2]==boardnum[3]) {
    return 1;
    }
    if(boardnum[4]==boardnum[5] && boardnum[5]==boardnum[6]) {
    return 1;
    }
    if(boardnum[7]==boardnum[8] && boardnum[8]==boardnum[9]) {
    return 1;
    }
    if(boardnum[1]==boardnum[5] && boardnum[5]==boardnum[9]) {
    return 1;
    }
    if(boardnum[3]==boardnum[5] && boardnum[5]==boardnum[7]) {
    return 1;
    }
    if(boardnum[1]==boardnum[4] && boardnum[4]==boardnum[7]) {
    return 1;
    }
    if(boardnum[2]==boardnum[5] && boardnum[5]==boardnum[8]) {
    return 1;
    }
    if(boardnum[3]==boardnum[6] && boardnum[6]==boardnum[9]) {
    return 1;
    } 
}

int draw() {
    int count=0;
        for(int a=0; a<=9; a++) {
            if(boardnum[a]=='X' || boardnum[a]=='O') {
                count=count+1;
            }
        }
        if(count==9) {
            return 1;
        }
}

void main() {
    int i,arr1[5],arr2[4];
    char signx= 'X', signo= 'O';
    
    board();
    for (i = 0; i <= 5; i++) {
        printf("Please Enter Number...");
        scanf(" %d", &arr1[i]);
        while (arr1[i]<1 || arr1[i]>9 || 
               boardnum[arr1[i]]=='X' ||
               boardnum[arr1[i]]=='O') {
        printf("Invalid Input\n");
        printf("Please Enter Number...");
        scanf(" %d", &arr1[i]);
        }
        boardnum[arr1[i]]=signx;
        board();
        int win1=win();
        if (win1==1) {
            printf("YOU WIN :)");
            break;
        } else {
            int draw1=draw();
            if (draw1==1) {
                printf("DRAW :(");
                break;
            }
        }
        do {
        srand(time(NULL));
        arr2[i]=rand()%9+1;
        } while (boardnum[arr2[i]]=='X' ||
               boardnum[arr2[i]]=='O');
        boardnum[arr2[i]]=signo;
        board();
        int win2=win();
        if (win2==1) {
            printf("BOT WIN :(");
            break;
        }
        
    }






}


 


    