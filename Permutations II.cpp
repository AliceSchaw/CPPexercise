//recursive solution
//23ms
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> >res;
        recursion(num, 0, num.size(), res);
        return res;
    }
    void recursion(vector<int> num, int i, int j, vector<vector<int> > &res) {
        if (i == j-1) {
            res.push_back(num);
            return;
        }
        for (int k = i; k < j; k++) {
            if (i != k && num[i] == num[k]) continue;
            swap(num[i], num[k]);
            recursion(num, i+1, j, res);
        }
    }


};


//DFS-based recursive solution
//26ms
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         vector<vector<int>> permutations;
        if(nums.size() == 0) //invalid corner case check
            return permutations;
        vector<int> curr;
        vector<bool> isVisited(nums.size(), false); //using this bool type array to check whether or not the elments has been visited
        backTracking(permutations,curr,isVisited,nums);
        return permutations;
    }
    void backTracking(vector<vector<int>>& ret, vector<int> curr, vector<bool> isVisited, vector<int> num)
    {
        if(curr.size() == num.size())
        {
            ret.push_back(curr);
            return;
        }
        
        for(int i = 0; i < num.size(); ++i)
        {
            
            if(isVisited[i] == false)
            {
                isVisited[i] = true;
                curr.push_back(num[i]);
                backTracking(ret,curr,isVisited,num);
                isVisited[i] = false;
                curr.pop_back();
                while(i < num.size()-1 && num[i] == num[i+1]) //we use this while loop to skip the duplication value in the input array.
                    ++i;
            }
        }
    }

};