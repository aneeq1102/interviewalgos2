#include<iostream>
#include<vector>
using namespace std;

void dfs(int row,int col,vector<vector<char>>& board){
    if(board[row][col] == 'O'){
       
        board[row][col]='1';
        
        if(row+1<board.size())dfs(row+1,col,board);
        if(row>1) dfs(row-1,col,board);
        if(col+1<board[row].size()) dfs(row,col+1,board);
        if(col>1) dfs(row,col-1,board);

    }
    
}
void solve(vector<vector<char>>& board) {
    int row=board.size();
    int col=board[0].size();
    
    for(int i=0;i<row;i++){
        dfs(i,0,board);
        dfs(i,col-1,board);
    }
    
    for(int i=1;i<col-1;i++){
        dfs(0,i,board);
        dfs(row-1,i,board);
    }
    
    

    // i cant seem to index the array board here even though when printing out the 2d array using the code commented out above,I seem to have the entire grid generated
    for(int i=0;i<row;++i){
        for(int j=0;j<col;++j){
            if(board[i][j]=='O'){
                board[i][j]='X';
            }else if(board[i][j]=='1'){
                board[i][j]='O';
            }
        }
    }
    
    
}

int main(){

    vector<vector<char>> brd = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};

    solve(brd);

    for(vector<char> x:brd){
        for(char y:x){
            cout<<y<<" ";
        }
        cout<<'\n';
    }

    return 0;
}