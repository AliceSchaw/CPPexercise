class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        if(nums.size()==0){
            return false;
        }
        int hi = nums.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] == target) return true;
            
            if (nums[lo] < nums[mid]) {//左半有序
                if (target >= nums[lo] && target < nums[mid]) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            } 
            else if((nums[lo] > nums[mid])){//右半有序
                if (target > nums[mid] && target <= nums[hi]) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            else{lo++;}//相等的情况无法判断左右，逐个移动
        }
        return nums[lo] == target ? true : false;
    }
};


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size()==0) return false;
        int lo =0, hi = nums.size()-1;
        int mid = 0;
        while(lo<hi){
              mid=(lo+hi)/2;
              if(nums[mid]==target) return true;
              if(nums[mid]>nums[hi]){
                  if(nums[mid]>target && nums[lo] <= target) hi = mid;
                  else lo = mid + 1;
              }else if(nums[mid] < nums[hi]){
                  if(nums[mid]<target && nums[hi] >= target) lo = mid + 1;
                  else hi = mid;
              }else{
                  hi--;
              }

        }
        return nums[lo] == target ? true : false;
    }
};
