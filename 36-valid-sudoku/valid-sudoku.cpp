class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    continue;
                }
                for(int k=i+1;k<9;k++){
                    if(board[k][j]==board[i][j]){
                        return false;
                    }
                }
                for(int k=j+1;k<9;k++){
                    if(board[i][k]==board[i][j]){
                        return false;
                    }
                }
                int r=(i/3)*3;
                int c=(j/3)*3;
                for(int a=r;a<r+3;a++){
                    for(int b=c;b<c+3;b++){
                        if(a==i && b==j){
                            continue;
                        }
                        if(board[a][b]==board[i][j]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};