class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxglobal=nums[0];
        int maxnow=nums[0];
        for(int i=1;i<nums.size();i++){
            maxnow=max(nums[i],nums[i]+maxnow);
            maxglobal=max(maxglobal,maxnow);
        }
        return maxglobal;
    }
};

//9ms
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0],i,j,sum=0;
        for(i=0;i<nums.size();i++){
            sum+=nums[i];
            ans=max(sum,ans);
            sum=max(sum,0);
        }
        return ans;       
    }
};