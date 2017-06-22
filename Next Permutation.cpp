//19 ms
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int setindex=-1,numindex;
        if(nums.size()<2)
        return;
        for(int i=nums.size()-1;i>0;i--){
            if((nums[i-1]<nums[i])&&setindex==-1){
                setindex=i-1;
                numindex=nums[i-1];
                break;
            }
        }
        //条件1：不存在前一个数比后一个数小，反转，即调整为正序
        if(setindex==-1){
            reverse(nums.begin(), nums.end());
            return;
        }
        //条件2：寻找下一个字典顺序
        //找出的分界线值右侧的值始终是逆序的
        //把大于分界线值的最小值与分界线替换
        for (int i = nums.size()-1; i > 0; --i){
            if (nums[i] > numindex){
                swap(nums[i], nums[setindex]);
                break;
            }
        }
        //调整分界线右侧为正序，即最小
        vector <int>::iterator iter=nums.begin();
        iter+=setindex+1;
        reverse(iter, nums.end());
        return;
    }
};