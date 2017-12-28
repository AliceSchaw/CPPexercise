//recursive solution
//9ms
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
	    vector<vector<int> > result;
	    
	    permuteRecursive(num, 0, result);
	    return result;
    }
    
    // permute num[begin..end]
    // invariant: num[0..begin-1] have been fixed/permuted
	void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)	{
		if (begin == num.size()) {	//等效于if (begin == num.size()-1) {
		    // one permutation instance
		    result.push_back(num);
		    return;
		}
		
		for (int i = begin; i < num.size(); i++) {
		    swap(num[begin], num[i]);
		    permuteRecursive(num, begin + 1, result);
		    // reset
		    swap(num[begin], num[i]);
		}
    }
};

//recursive solution
//9ms
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        //sort(num.begin(), num.end());
        vector<vector<int> >res;
        recursion(num, 0, res);
        return res;
    }
    void recursion(vector<int> num, int begin,vector<vector<int> > &res) {//num参数不使用引用，则不需要还原。
        if (begin == num.size()-1) {
            res.push_back(num);
            return;
        }
        for (int k = begin; k < num.size(); k++) {
            //if (begin != k && num[begin] == num[k]) continue;
            swap(num[begin], num[k]);
            recursion(num, begin+1,res);
        }
    }


};
//DFS-based recursive solution
//19ms
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> permutations;
        if(num.size() == 0) //invalid corner case check
            return permutations;
        vector<int> curr;
        vector<bool> isVisited(num.size(), false); //using this bool type array to check whether or not the elments has been visited
        backTracking(permutations,curr,isVisited,num);
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
            }
        }
    }


};