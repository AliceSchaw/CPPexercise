//6ms o(n)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i=0;
        while(i<nums.size()){
            if(nums[i]<=0||nums[i]==nums[nums[i]-1]||nums[i]>nums.size()){
                i++;
            }
            else
                swap(nums[i],nums[nums[i]-1]);
        }
        for (i = 0; i < nums.size(); i++) if (nums[i] != i+1) break;
        return i+1;
    }
};
//6ms o(nlogn)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size()==0)
            return 1;
        sort(nums.begin(),nums.end());
        int front=0;
        while(nums[front]<=0){
            front++;
        }
        int back=nums.size()-1;
        int target=1;
        while(front<nums.size()){
            while(front<back&&nums[front]==nums[front+1])
                front++;
            if(nums[front]!=target) break;
                else front++,target++;
            
        }
        return target;
    }
};