//Accepted 16ms c++ solution use backtracking for Combination Sum:
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        vector<int> combination;
        combinationSum(candidates, target, res, combination, 0);
        return res;
    }
private:
    void combinationSum(vector<int> &candidates, int target, vector<vector<int> > &res, vector<int> &combination, int begin) {
        //!target
        if (target==0) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i);
            combination.pop_back();
        }
    }
};



//Accepted 12ms c++ solution use backtracking for Combination Sum II:
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        vector<int> combination;
        combinationSum2(candidates, target, res, combination, 0);
        return res;
    }
private:
    void combinationSum2(vector<int> &candidates, int target, vector<vector<int> > &res, vector<int> &combination, int begin) {
        if (target==0) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i)
            if (i == begin || candidates[i] != candidates[i - 1]) {
                combination.push_back(candidates[i]);
                combinationSum2(candidates, target - candidates[i], res, combination, i + 1);
                combination.pop_back();
            }
    }
};


//Accepted 0ms c++ solution use backtracking for Combination Sum III:
class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > res;
        vector<int> combination;
        combinationSum3(n, res, combination, 1, k);
        return res;
    }
private:
    void combinationSum3(int target, vector<vector<int> > &res, vector<int> &combination, int begin, int need) {
        if (target==0) {
            res.push_back(combination);
            return;
        }
        else if (!need)
            return;
        for (int i = begin; i != 10 && target >= i * need + need * (need - 1) / 2; ++i) {
            combination.push_back(i);
            combinationSum3(target - i, res, combination, i + 1, need - 1);
            combination.pop_back();
        }
    }
};