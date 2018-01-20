class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i =matrix.size()-1; int j=0;  
        while(i>=0&&j<matrix[0].size())  
        {  
            if(matrix[i][j]==target) return true; 
            else if(matrix[i][j]<target) j++;   
            else i--; 
        }  
        return false;  
    }  
};
//二分法
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(matrix.size()==0||matrix[0].size()==0) return false;
        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0, r = m * n - 1;
        while (l != r){
            int mid = (l + r - 1) >> 1;//int mid = (l + r - 1) /2;
            if (matrix[mid / m][mid % m] < target)
                l = mid + 1;
            else 
                r = mid;
        }
        return matrix[r / m][r % m] == target;
    }
};