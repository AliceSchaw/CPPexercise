class Solution {
    public:
        vector<vector<int> > generateMatrix(int n) {
            vector<vector<int> > ret( n, vector<int>(n) );
        	int k = 1, i = 0;
        	while( k <= n * n )
        	{
        		int j = i;
                    // four steps
        		while( j < n - i )             // 1. horizonal, left to right
        			ret[i][j++] = k++;
        		j = i + 1;
        		while( j < n - i )             // 2. vertical, top to bottom
        			ret[j++][n-i-1] = k++;
        		j = n - i - 2;
        		while( j > i )                  // 3. horizonal, right to left 
        			ret[n-i-1][j--] = k++;
        		j = n - i - 1;
        		while( j > i )                  // 4. vertical, bottom to  top 
        			ret[j--][i] = k++;
        		i++;      // next loop
        	}
        	return ret;
        }
};


class Solution {
    public:
        vector<vector<int>> generateMatrix(int n) {
            // Declaration
            vector<vector<int> > matrix( n, vector<int>(n) );
            
            // Edge Case
            if (n == 0) {
                return matrix;
            }
            
            // Normal Case
            int rowStart = 0;
            int rowEnd = n-1;
            int colStart = 0;
            int colEnd = n-1;
            int num = 1; //change
            
            while (rowStart <= rowEnd && colStart <= colEnd) {
                for (int i = colStart; i <= colEnd; i ++) {
                    matrix[rowStart][i] = num ++; //change
                }
                rowStart ++;
                
                for (int i = rowStart; i <= rowEnd; i ++) {
                    matrix[i][colEnd] = num ++; //change
                }
                colEnd --;
                
                for (int i = colEnd; i >= colStart; i --) {
                    if (rowStart <= rowEnd)
                        matrix[rowEnd][i] = num ++; //change
                }
                rowEnd --;
                
                for (int i = rowEnd; i >= rowStart; i --) {
                    if (colStart <= colEnd)
                        matrix[i][colStart] = num ++; //change
                }
                colStart ++;
            }
            
            return matrix;
        }
};