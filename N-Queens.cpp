//6ms
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        vector<string> nQueens(n,string(n, '.'));
        solveNQueens(res, nQueens, 0);
        return res;
    }
private:
    void solveNQueens(vector<vector<string> > &res,vector<string> &nQueens, int row) {
        int n=nQueens.size();
        if (row == n) {
            res.push_back(nQueens);
            return;
        }
        for (int col = 0; col != n; ++col)
            if (isValid(nQueens, row, col)) {
                nQueens[row][col] = 'Q';
                solveNQueens(res, nQueens, row + 1);
                nQueens[row][col] = '.';
            }
    }
    bool isValid(vector<string> &nQueens, int row, int col) {
        int n=nQueens.size();
        //check if the column had a queen before.
        for (int i = 0; i != row; ++i)
            if (nQueens[i][col] == 'Q')
                return false;
        //check if the 45° diagonal had a queen before.
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
            if (nQueens[i][j] == 'Q')
                return false;
        //check if the 135° diagonal had a queen before.
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
            if (nQueens[i][j] == 'Q')
                return false;
        return true;
    }
};


// DFS: Use flag vectors as bitmask, 4ms:
// The number of columns is n, the number of 45° diagonals is 2 * n - 1, the number of 135° diagonals is also 2 * n - 1. 
// When reach [row, col], the column No. is col, the 45° diagonal No. is row + col and the 135° diagonal No. is n - 1 + col - row. 
// We can use three arrays to indicate if the column or the diagonal had a queen before, if not, we can put a queen in this position and continue.
// NOTE: Please don't use vector<bool> flag to replace vector<int> flag in the following C++ code. In fact, vector<bool> is not a STL container. You should avoid to use it. 
class Solution {
public:
        vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        vector<string> nQueens(n, string(n, '.'));
        vector<int> flag_col(n, 1), flag_45(2 * n - 1, 1), flag_135(2 * n - 1, 1);
        solveNQueens(res, nQueens, flag_col, flag_45, flag_135, 0, n);
        return res;
    }
private:
    void solveNQueens(vector<vector<string> > &res, vector<string> &nQueens, vector<int> &flag_col, vector<int> &flag_45, vector<int> &flag_135, int row, int &n) {
        if (row == n) {
            res.push_back(nQueens);
            return;
        }
        for (int col = 0; col != n; ++col)
            if (flag_col[col] && flag_45[row + col] && flag_135[n - 1 + col - row]) {
                flag_col[col] = flag_45[row + col] = flag_135[n - 1 + col - row] = 0;
                nQueens[row][col] = 'Q';
                solveNQueens(res, nQueens, flag_col, flag_45, flag_135, row + 1, n);
                nQueens[row][col] = '.';
                flag_col[col] = flag_45[row + col] = flag_135[n - 1 + col - row] = 1;
            }
    }
};
// But we actually do not need to use three arrays, we just need one. 
// Now, when reach [row, col], the subscript of column is col, the subscript of 45° diagonal is n + row + col and the subscript of 135° diagonal is n + 2 * n - 1 + n - 1 + col - row.
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        vector<string> nQueens(n, string(n, '.'));
        /*
        vector<int> flag_col(n, 1), flag_45(2 * n - 1, 1), flag_135(2 * n - 1, 1);

        flag[0] to flag[n - 1] to indicate if the column had a queen before.
        flag[n] to flag[3 * n - 2] to indicate if the 45° diagonal had a queen before.
        flag[3 * n - 1] to flag[5 * n - 3] to indicate if the 135° diagonal had a queen before.
        */
        vector<int> flag(5 * n - 2, 1);
        solveNQueens(res, nQueens, flag, 0, n);
        return res;
    }
private:
    void solveNQueens(vector<vector<string> > &res, vector<string> &nQueens, vector<int> &flag, int row, int &n) {
        if (row == n) {
            res.push_back(nQueens);
            return;
        }
        for (int col = 0; col != n; ++col)
            if (flag[col] && flag[n + row + col] && flag[4 * n - 2 + col - row]) {
                flag[col] = flag[n + row + col] = flag[4 * n - 2 + col - row] = 0;
                nQueens[row][col] = 'Q';
                solveNQueens(res, nQueens, flag, row + 1, n);
                nQueens[row][col] = '.';
                flag[col] = flag[n + row + col] = flag[4 * n - 2 + col - row] = 1;
            }
    }
};