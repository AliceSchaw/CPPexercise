//16ms
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;
        int n=nums.size();
        for (int reach = 0; i < n && i <= reach; ++i)
            {
            	reach = max(i + nums[i], reach);
            	if(i==n-1) return true;
            }
        return false;
        /*
        for (int reach = 0; i < n && i <= reach; ++i)
            {
            	reach = max(i + nums[i], reach);
            }
        return i==n;
        */
    }
};
//19ms
//从最后一个开始判断
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int last=n-1;
        for(int i=n-2;i>=0;i--){
            if(i+nums[i]>=last)
                last=i;
        }
        return last<=0;

    }
};