//256 ms
//插入后检查全表
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solveSudoku(board, 0, 0);
    }
    bool solveSudoku(vector<vector<char>> &board, int i, int j)
    {
        if(i==9) return true;
        if(j==9) return solveSudoku(board, i+1, 0);
        if(board[i][j] != '.') return solveSudoku(board, i, j+1);
    
        for(char c='1'; c<='9'; c++)
        {
            board[i][j] = c;
            if(isValidSudoku(board, i, j))
            {
                if(solveSudoku(board, i, j+1)) return true;
                
            }
            board[i][j] = '.';
        }
            
        return false;
    }
    bool isValidSudoku(vector<vector<char>>& board,int i,int j) {
        int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};
        
        for(int i = 0; i < board.size(); ++ i)
            for(int j = 0; j < board[i].size(); ++ j)
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                    if(used1[i][num] || used2[j][num] || used3[k][num])
                        return false;
                    used1[i][num] = used2[j][num] = used3[k][num] = 1;
                }
        
        return true;
    }
};

//9ms
//检查当前行/列/块后再插入
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solveSudoku(board, 0, 0);
    }
    bool solveSudoku(vector<vector<char>> &board, int i, int j)
    {
        if(i==9) return true;
        if(j==9) return solveSudoku(board, i+1, 0);
        if(board[i][j] != '.') return solveSudoku(board, i, j+1);
    
        for(char c='1'; c<='9'; c++)
        {
           
            if(isValidSudoku(board, i, j, c))
            {
                board[i][j] = c;
                if(solveSudoku(board, i, j+1)) return true;
                board[i][j] = '.';
            }
            
        }
            
        return false;
    }
    bool isValidSudoku(vector<vector<char>>& board,int i,int j,char val) {
        int row = i - i%3, column = j - j%3;
        for(int x=0; x<9; x++) if(board[x][j] == val) return false;
        for(int y=0; y<9; y++) if(board[i][y] == val) return false;
        for(int x=0; x<3; x++)
        for(int y=0; y<3; y++)
            if(board[row+x][column+y] == val) return false;
        return true;
    }
};