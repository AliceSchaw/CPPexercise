//9ms
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(),nums.end());
        int temp=nums[2]+nums[1]+nums[0];
        for (int i = 0; i < nums.size()-2; i++) {
            
            
            int front = i + 1;
            int back = nums.size() - 1;
            
            while (front < back) {
                int sum = nums[front] + nums[back]+nums[i];
                
                if (sum < target)
                    front++;
                else
                    back--;

                if(sum == target) return sum;
                if(abs(sum-target)<abs(target-temp)) {
                    temp = sum;
                }
            }
            
        }
    
        return temp;

    }
};