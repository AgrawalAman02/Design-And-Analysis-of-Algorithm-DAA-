#include<stdio.h>
// n matlab no. of rows or cols in the chessboard... 
int n;

int isSafe(int board[n][n], int rows , int cols){
    // up direction
    for(int i = rows-1; i>= 0; i-- ){
        if(board[i][cols] == 1) return 0;
    }
    // vertical left 
    for(int i = rows-1 , j = cols-1; i>=0 && j>=0; i--, j--){
        if(board[i][j] == 1) return 0;
    }
    // vertical right....
    for(int i = rows-1, j = cols+1; i>=0 && j<n;i--,j++){
        if(board[i][j] == 1) return 0;

    }

    return 1;
}

void nqueen(int board[][n], int rows){
    if(rows == n){
        printf("\nThe chess board with %d queen is : \n", n);
        for(int i = 0 ; i<n; i++){
            for(int j = 0 ; j <n; j++){
                printf("%d\t",board[i][j]);
            }
            printf("\n");
        }
        return;
    }
    for(int j = 0 ; j < n; j++){
        if(isSafe(board, rows, j) == 1){
            board[rows][j] = 1;
            nqueen(board, rows+1);
            board[rows][j] = 0;

        }
    }

}

int main(){
    printf("Enter the no. of the rows or column of the chess board : ");
    scanf("%d", &n);
    int board[n][n];
    for(int i = 0 ; i<n; i++){
        for(int j = 0 ; j <n; j++){
            board[i][j] = 0;
        }
    }

    nqueen(board, 0);
}