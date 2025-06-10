#include <bits/stdc++.h>
using namespace std;
using Board = vector<vector<int>>;
const int N = 9;
Board board(N, vector<int>(N));

void inputBoard(Board& b) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> b[i][j];
        }
    }
}

void printBoard(const Board& b) {
    for (int i = 0; i < N; ++i) {
        if (i > 0 && i % 3 == 0)
            cout << "------+-------+------" << endl;
        for (int j = 0; j < N; ++j) {
            if (j > 0 && j % 3 == 0)
                cout << "| ";
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}

bool isValid(const Board& b , int row , int col , int num){
    for(int x=0;x<N;x++){
        if(b[row][x]==num || b[x][col]==num)
            return false;
        //  if (b[3 * (row / 3) + x / 3][3 * (col / 3) + x % 3] == num)
        //     return false;
    }
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (b[startRow + r][startCol + c] == num)
                return false;
        }
    }
    return true;
}

bool solve(Board &b){
    for(int row = 0;row<N;row++){
        for(int col=0;col<N;col++){
            if(b[row][col]==0){
                for(int num=1;num<=9;num++){
                    if(isValid(b,row,col,num)){
                        b[row][col] = num;
                        if(solve(b))
                            return true;
                        // if we are not able to solve the next step we will return false and remove current index and replace it with another num
                        b[row][col] = 0;
                    }
                }
                return false;
                // we were not able to find any num even after going till 9 , so retun false to backtrack
            }
        }
    }
    return true;
    // if no 0 is present then its solved
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cout << "Enter the Sudoku board (0 for empty cells):" << endl;
    inputBoard(board);
    cout << "\n\nSolving The Sudoku.....\n\n";
    if (solve(board)) {
        std::cout << "Solved Sudoku:\n";
        printBoard(board);
    } else {
        std::cout << "No solution exists." << std::endl;
    }
    return 0;
}