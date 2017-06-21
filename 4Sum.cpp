//19ms
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::sort(nums.begin(),nums.end());
        vector<vector<int> >result;
        int n=nums.size();
        if (nums.size() <4) 
          return result;
        for(int i=0;i<n-3;i++){
            //Processing duplicates of Number 1
            if(i>0&&nums[i]==nums[i-1]) continue;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;
            for(int j=i+1;j<n-2;j++){
                //Processing duplicates of Number 2
                //error:不能选出[0,0,0,0]
                //if(j>0&&nums[j]==nums[j-1]) continue;
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;
                int front = j + 1;
                int back = n - 1;                
                
                while(front<back){
                int sum=nums[i]+nums[j]+nums[front]+nums[back];
                if (sum < target)
                    front++;
    
                else if (sum > target)
                    back--;
    
                else {
                    vector<int> triplet(4, 0);
                    triplet[0] = nums[i];
                    triplet[1] = nums[j];
                    triplet[2] = nums[front];
                    triplet[3] = nums[back];
                    result.push_back(triplet);
                    
                    // Processing duplicates of Number 3
                    // Rolling the front pointer to the next different number forwards
                    while (front < back && nums[front] == triplet[2]) front++;
    
                    // Processing duplicates of Number 4
                    // Rolling the back pointer to the next different number backwards
                    while (front < back && nums[back] == triplet[3]) back--;
                    
                                    
                    }
                }
            }
        }
        return result;
    }
};