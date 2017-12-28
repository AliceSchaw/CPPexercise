//3ms
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        vector<string> nQueens(n,string(n, '.'));
        solveNQueens(res, nQueens, 0);
        return res.size();
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

//DFS
//3ms
class Solution {
public:
    int totalNQueens(int n) {
        vector<bool> col(n, true);
        vector<bool> anti(2*n-1, true);
        vector<bool> tria(2*n-1, true);
        vector<int> row(n, 0);
        int count = 0;
        dfs(0, row, col, tria, anti, count);
        return count;
    }
    void dfs(int i, vector<int> &row, vector<bool> &col, vector<bool>& tria, vector<bool> &anti, int &count) {
            if (i == row.size()) {
                count++;
                return;
            }
            //i=row;j=col
           for (int j = 0; j < col.size(); j++) {
             if (col[j] && tria[i+j] && anti[i+col.size()-1-j]) {
                 row[i] = j; 
                 col[j] = tria[i+j] = anti[i+col.size()-1-j] = false;
                 dfs(i+1, row, col, tria, anti, count);
                 col[j] = tria[i+j] = anti[i+col.size()-1-j] = true;
          }
          /*
           for (int j = 0; j < col.size(); j++) {
             if (col[j] && tria[i+j] && anti[j+col.size()-1-i]) {
                 row[i] = j; 
                 col[j] = tria[i+j] = anti[j+col.size()-1-i] = false;
                 dfs(i+1, row, col, tria, anti, count);
                 col[j] = tria[i+j] = anti[j+col.size()-1-i] = true;
          }
          */
        }
    }

};
