//3ms
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count=0,i=0;
            if(!nums.empty()){
                std::sort(nums.begin(),nums.end());
                
                while(nums[i]!=val&&i<nums.size()){
                    i++;
                }
                for(i;i<nums.size();i++)
                {
                    if(nums[i]==val)
                    {
                        count++;
                    }
                    else{
                        nums[i-count]=nums[i];
                    }
                    
                }
                cout<<nums.size()-count;
            
            
            }
        
        return nums.size()-count;
        
    }
};
/*
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
*/