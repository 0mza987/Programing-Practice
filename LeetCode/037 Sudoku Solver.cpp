//https://leetcode.com/problems/sudoku-solver/

// res cost an extra O(n^2) space, I know it can be solved in-space, but whatever, i did it this way.

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if(board.empty()) return;
        int m=board.size(), n=board[0].size();
        vector<vector<char>> res;
        ancillary(board,res,m,n,0,0);
        board=res;
    }
    void ancillary(vector<vector<char>>& board,vector<vector<char>>& res, int row, int col,int m, int n){
        if(m==row){
            res=board;
            return;
        }
        if(board[m][n]=='.'){
            for(int k=1; k<10; ++k){
                if(!isConf(board,row,col,m,n,k+'0')){
                    board[m][n]=k+'0';
                    if(n==col-1) ancillary(board,res,row,col,m+1,0);
                    else ancillary(board,res,row,col,m,n+1);
                    board[m][n]='.';
                }
            }
        }
        else{
            if(n==col-1) ancillary(board,res,row,col,m+1,0);
            else ancillary(board,res,row,col,m,n+1);
        }
    }
    bool isConf(vector<vector<char>>& board,int row, int col, int i, int j, char k){
        for(int m=0; m<row; ++m){
            if(board[m][j]==k) return true;
        }
        for(int m=0; m<col; ++m){
            if(board[i][m]==k) return true;
        }
        for(int m=i/3*3; m<i/3*3+3; ++m){
            for(int n=j/3*3; n<j/3*3+3; ++n){
                if(board[m][n]==k) return true;
            }
        }
        return false;
    }
};


// update for no extra space version, but this method is a bit slower than the first one on leetcode

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if(board.empty()) return;
        int m=board.size(), n=board[0].size();
        ancillary(board,m,n);
    }
    bool ancillary(vector<vector<char>>& board, int row, int col){
        for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                if(board[i][j]=='.'){
                    for(int k =1; k<10; ++k){
                        board[i][j]=k+'0';
                        if(!isConf(board,row,col,i,j) && ancillary(board,row,col)) return true;
                        board[i][j]='.';
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isConf(vector<vector<char>>& board,int row, int col, int i, int j){
        for(int m=0; m<row; ++m){
            if(m==i) continue;
            if(board[m][j]==board[i][j]) return true;
        }
        for(int m=0; m<col; ++m){
            if(m==j) continue;
            if(board[i][m]==board[i][j]) return true;
        }
        for(int m=i/3*3; m<i/3*3+3; ++m){
            for(int n=j/3*3; n<j/3*3+3; ++n){
                if(m==i && n==j) continue;
                if(board[m][n]==board[i][j]) return true;
            }
        }
        return false;
    }
};