class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m=matrix.size();
        if(m==0)  return res;
        int n=matrix[0].size();
        if(n==0)  return res;


        vector<vector<int> > dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> nSteps{n,m-1};
    
        int iDir = 0;   // index of direction.
        int ir = 0, ic = -1;    // initial position
        while (nSteps[iDir%2]) {
            for (int i = 0; i < nSteps[iDir%2]; ++i) {
                ir += dirs[iDir][0]; ic += dirs[iDir][1];
                res.push_back(matrix[ir][ic]);
            }
            nSteps[iDir%2]--;
            iDir = (iDir + 1) % 4;
        }
        return res;
    }

};

//0ms
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) 
            return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> spiral(m * n);
        int u = 0, d = m - 1, l = 0, r = n - 1, k = 0;
        while (true) {
            // up
            for (int col = l; col <= r; col++) 
                spiral[k++] = matrix[u][col];
            if (++u > d) break;
            // right
            for (int row = u; row <= d; row++) 
                spiral[k++] = matrix[row][r];
            if (--r < l) break;
            // down
            for (int col = r; col >= l; col--) 
                spiral[k++] = matrix[d][col];
            if (--d < u) break;
            // left
            for (int row = d; row >= u; row--) 
                spiral[k++] = matrix[row][l];
                if (++l > r) break;
        }
        return spiral;
    }
};