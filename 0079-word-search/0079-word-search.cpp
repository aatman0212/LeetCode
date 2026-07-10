class Solution {
public:

    bool helper(vector<vector<char>>& board,vector<vector<bool>>& visited,string word,int row,int col,int index){
        if (index == word.size()) {
            return true;
        }
        if (row<0||col<0||row>=board.size()||col>=board[0].size()){
            return false;
        }
        if (visited[row][col]){
            return false;
        }
        if (board[row][col] != word[index])
        {
            return false;
        }
        visited[row][col]=true;
        bool found =
            helper(board,visited,word,row-1,col,index+1) ||
            helper(board,visited,word,row,col-1,index+1) ||
            helper(board,visited,word,row,col+1,index+1) ||
            helper(board,visited,word,row+1,col,index+1);
            
        visited[row][col]=false;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(
            board.size(),
            vector<bool>(board[0].size(), false)
        );
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0] &&
                    helper(board, visited, word, i, j, 0)) {
                        return true;
                    }
            }
        }
        return false;
    }
};