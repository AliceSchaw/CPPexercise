//push_back
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> res;  
        int j=0;
        
        if(nums.size()==0) return 0;
        //res.push_back(nums[j++]);
        while(j<nums.size()){
            if(nums[j]!=nums[j-2]||j<2){
                res.push_back(nums[j++]);
            }
            else{j++;}

        }
        nums.assign(res.begin(),res.end());
        return nums.size();
    }
};


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int n : nums)
            if (i < 2 || n > nums[i-2])
                nums[i++] = n;
        return i;
    }
};