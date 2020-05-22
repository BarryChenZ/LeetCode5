class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board[click[0]][click[1]] == 'M'){
            board[click[0]][click[1]] = 'X';
            return board;
        }
        dfs(board, click[0], click[1]);
        return board;
    }
    void dfs(vector<vector<char>>& board, int x, int y){//dfs
        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) return;
        if(board[x][y] != 'E') return;
        
        int num = 0;
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                if(x+i >= 0 && y+j >= 0 && x+i < board.size() && y+j < board[0].size())
                    if(board[x+i][y+j] == 'M') 
                        num++;        
            }
        }
        if(num){
            board[x][y] = '0' + num;
            return;
        }
        
        board[x][y] = 'B';
        dfs(board, x-1, y);
        dfs(board, x+1, y);
        dfs(board, x, y-1);
        dfs(board, x, y+1);
        dfs(board, x-1, y-1);
        dfs(board, x+1, y+1);
        dfs(board, x+1, y-1);
        dfs(board, x-1, y+1);
    }
};
