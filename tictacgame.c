#include <iso646.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>



#include <math.h>
#include <stdlib.h>



#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool in(char sth, char list[]) {
    for (int i = 0; i < 9; i ++) {
        if (sth == list[i]) {
            return true;
        }

    }
        return false;




}

bool evaluatenum(int num,char  list[],int player) {
    char bo[9]={'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    if (!in(list[num-1],bo)) {
        return false;
    }

    else {

        list[num-1]=player==1 ? 'X' : 'O';
        return true;
    }
}


void print(char list[]) {

    for (int i = 0; i < sizeof(list)/sizeof(list[0]); i ++) {
        printf("%c,",list[i]);

    }
}
void createboard(char board[]) {
    for (int i = 0; i < 9; i += 3) {
        printf("%c %c %c\n", board[i], board[i + 1], board[i + 2]);
        if (i != 6)
            printf("\n");
    }
}


char whowin(char board[]) {
    if ((board[0]=='X' && board[1]=='X' && board[2]=='X') ||  (board[3]=='X' && board[4]=='X' && board[5]=='X') || (board[6]=='X' && board[7]=='X' && board[8]=='X')
        || (board[0]=='X' && board[3]=='X' && board[6]=='X') || (board[1]=='X' && board[4]=='X' && board[7]=='X')|| (board[2]=='X' && board[5]=='X' && board[8]=='X')
               || (board[0]=='X' && board[4]=='X' && board[8]=='X')|| (board[2]=='X' && board[4]=='X' && board[6]=='X') ) {
        return 'x';
    }
    else if ((board[0]=='O' && board[1]=='O' && board[2]=='O') ||  (board[3]=='O' && board[4]=='O' && board[5]=='O') || (board[6]=='O' && board[7]=='O' && board[8]=='O')
        || (board[0]=='O' && board[3]=='O' && board[6]=='O') || (board[1]=='O' && board[4]=='O' && board[7]=='O')|| (board[2]=='O' && board[5]=='O' && board[8]=='O')
               || (board[0]=='O' && board[4]=='O' && board[8]=='O')|| (board[2]=='O' && board[4]=='O' && board[6]=='O') ) {
        return 'o';
               }
    else {
        return 'n';
    }
}



    int main() {
        char board[9]={'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        int i=0;
        int value;

        while (i<9) {
            printf("    tic tac game\n");
            printf("player 1(x)  -  player 2(o)\n");
            createboard(board);



            if ( i%2==0) {
                printf("player1, enter a number\n");
                scanf("%d",&value);
                if (!evaluatenum(value,board,1)) {
                    printf("invalid number\n");

                }
                else {
                    i+=1;
                }
            }

            else {
                printf("player2, enter a number\n");
                scanf("%d",&value);
                if (!evaluatenum(value,board,2)) {
                    printf("invalid number\n");

                }


                else {

                    i+=1;
                }

                }

                switch (whowin(board)) {
                    case 'x':
                        printf("Player 1 wins\n");
                        i=9;
                        break;
                    case 'o' :
                        printf("Player 2 wins\n");
                        i=9;
                        break;

                        default:
                        break;
                }
        }


            if (whowin(board)=='n') {
                printf("cross\n");
            }








        return 0;
    }

