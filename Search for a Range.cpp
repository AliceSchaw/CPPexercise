//12ms
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> res(2, -1);
        
        if(nums.size()==0){
            return res;
        }
        int left = 0, right = nums.size() - 1;
        //找左边界
        while (left < right) {
            int mid = (right + left) / 2;
            if (nums[mid] < target) 
                left = mid + 1;
            else 
                right = mid;
        }
        if (nums[right] != target) 
            return res;
        //error:输入为[0,4],target=4时会输出0
        // res[0] = mid;
        res[0] = right;
        //找右边界
        right = nums.size();
        while (left < right) {
            int mid = (right + left) / 2;
            if (nums[mid] <= target) 
                left = mid + 1;
            else 
                right= mid;
        }
        //error:输入为[0],target=0时会输出-1
        // res[0] = mid-1;
        res[1] = left - 1;
        return res;
    }
};