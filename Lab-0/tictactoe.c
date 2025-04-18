#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#define N 3;

// bool hasFreeCell(char board[3][3]){

    

//     return value;
// }

void fillBoard(char player, int pos, char board[N][N]){

    // 0 --> X
    // 1 --> O

    assert(player == 'X' || player =='O');

    int row= pos/N;
    int col= pos%N; 

    //check if the cell is free, if it is, then cell = player, if not, "cell occupied"
    if(board[row][col] == "-"){
        board[row][col] = player;
    }else{
        printf("Celda ocupada");
    }
}

void showBoard(char board[N][N]){
    for(int i = 0; i<N;i++){
        for(int j = 0; j<N;j++){
            printf("  %c",board[i][j]);
        }
        printf("\n");
    } 
}

bool hasFreeCell(char board[N][N]){
    //We want this function to scan all the board, looking for a "-", if there isn't it will return false
    bool flagHas= false;

    for(int row = 0; row<N; row++){
        for(int col = 0; col<N && !flagHas; col++){
            if(board[row][col] == "-"){
                flagHas = true;
            }
        }
    }
    return flagHas;
}

char getWinner(char board[N][N]){
    //idea:
    // elijo un char reading = board[i][i]
    // comparo si reading = board[i+1][i] or board[i][i+1] or board[i+1][i+1]
    // si no, entonces no es elegible para el 3 en raya, 
    if(!hasFreeCell(board)){

        checkDiagonal(1, board);
        checkDiagonal(2, board);
        for(int row = 0; row<N; row++){
            checkRow(row,board);
        }
        for(int col = 0; col < N; col++){
            checkColumn(col,board);
        }
    }

}

bool checkRow(int row, char board[N][N]){
    assert(row < N && row > 0);

    bool res = true;
    for(int col = 0; col < N && res; col++){
        char reading = board[row][col];
        char next = board[row][col+1];
        if(reading != next){
            res = false;
        }
    }
    return res;
}

bool checkColumn(int col, char board[N][N]){
    assert(col < N && col >0);

    bool res = true;
    char reading = board[0][col];
    for(int row = 1; row < N && res; row++){

        char next = board[row][col];
        if(reading != next){
            res = false;
        }
    }
    return res;
}

bool checkDiagonal(int corner, char board[N][N]){
    // corner be like
    // [1 .. 2]
    // [:  \ :]
    // [3 .. 4]
    assert(corner > 0 && corner < 5);


    if(corner== 1 || corner ==4){
        char elem = board[0][0];
        for(int i = 1; i<N;i++){
            char next= board[i][i];
            if(elem != next){
                res = false;
            }
        }
    }
    else if(corner== 2 || corner ==3){
        char elem = board[0][N];
        for(int i = 1; i<N;i++){
            char next= board[i][N-i];
            if(elem != next){
                res = false;
            }
        }
    }
    return res;
}


int main(){

    char board[N][N]= {
        { '-', '-', '-' },
        { '-', '-', '-' },
        { '-', '-', '-' }
    };
    
    // fillBoard('X', 7,board);
    // fillBoard('O', 4,board);
    // fillBoard('X', 8,board);
    showBoard(board);
}