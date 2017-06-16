/*
error:未修改nums
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0,j=0;
        if(!nums.empty()&&nums.size()>=1){
            std::sort(nums.begin(),nums.end());
    
            while(nums[i]!=val&&i<nums.size()){
                i++;
            }
            if(i<nums.size()){
                for(j;nums[i]==nums[i+j];j++);
                
            }
            cout<<nums.size()-j;

        }
        nums.assign(res.begin(),res.end());
        return nums.size()-j;
        
    }
};*/
int removeElement(vector<int>& nums, int val) {
    int cnt = 0;
    for(int i = 0 ; i < nums.size() ; ++i) {
        if(nums[i] == val)
            cnt++;
        else
            nums[i-cnt] = nums[i];
    }
    return nums.size()-cnt;
}