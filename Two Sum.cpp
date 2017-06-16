//Two Sum 
class Solution {
public:
    int num1Index;
    int num2Index;
    vector<int> result;
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size()-1;i++)
        for(int j=i+1;j<nums.size();j++){
            if(nums[i]+nums[j]==target){
                num1Index=i;
                num2Index=j;
            }
        }
        result.push_back(num1Index);
        result.push_back(num2Index);
        return result;    
    }

};