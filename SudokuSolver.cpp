#include <bits/stdc++.h>
#include<fstream>
using namespace std;

#define UNASSIGNED 0
#define N 9
bool valid(int grid[N][N],int row,int col,int num){
    for(int i=0;i<=8;i++){
        if(grid[row][i] == num) return false;
        if(grid[i][col] == num) return false;
    }
    int srow = 3*(row/3);
    int scol = 3*(col/3);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(grid[i+srow][j+scol] == num) return false;
        }
    }
    return true;
}
bool SolveSudoku(int grid[N][N]) { 
    int row,col;
    for(row=0;row<N;row++){
        for(int col=0;col<N;col++){
            if(grid[row][col] == 0){
                for(int num = 1;num<=9;num++){
                    if(valid(grid,row,col,num)){
                        grid[row][col] = num;
                        if(SolveSudoku(grid)) return true;
                            
                        else grid[row][col] = 0;
                    }
                }
                return false;                
            }
        }
    }
    return true;
}

int main() {
    ifstream fileinput;
    fileinput.open("input.txt");
    int grid[N][N];

    int i=0,j=0,x;

    while(!fileinput.eof() && j < 9){
        fileinput>>x;
        grid[j][i] = x;
        i++;
        if(i == 9) {
            i=0;
            j++;
        }
    }
    fileinput.close();

    bool solstate =SolveSudoku(grid);

    ofstream fileout;
    fileout.open("output.txt");

    if(solstate){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                fileout<<grid[i][j]<<" ";
            }
            fileout<<endl;
        }
    }
    else {
        fileout<<"This Sudoku is Not Solvable"<<endl;
    }

    fileout.close();
    return 0;
}
