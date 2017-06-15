class Solution {
public:
    vector<int> sortnums;   
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > result;
        sort(nums);
        
        //for循环遍历
        // for(int i=0;i<sortnums.size()-2;i++)
        //     for(int j=i+1;j<sortnums.size()-1;j++)
        //         for(int k=j+1;k<sortnums.size();k++)
        //         {
        //             if(sortnums[i]+sortnums[j]+sortnums[k]==0)
        //             {
        //                 vector<int> num;
                        
        //                 num.push_back(sortnums[i]);
        //                 num.push_back(sortnums[j]);
        //                 num.push_back(sortnums[k]);
        //                 if(result.empty()||result.back()!=num){
        //                     result.push_back(num);
        //                 }
        //             }
        //         }

        for(int i=0;i<sortnums.size();i++){
            int target=-sortnums[i];
            int front=i+1;
            int back=sortnums.size()-1;
            while(back>front){
                int sum=sortnums[front]+sortnums[back];
                if(sum>target)
                {
                    back--;
                }
                else if(sum<target)
                {
                    front++;
                }
                else{
                 
                    vector<int> num;
                        
                    num.push_back(sortnums[i]);
                    num.push_back(sortnums[back]);
                    num.push_back(sortnums[front]);
                    if(result.empty()||result.back()!=num){
                    result.push_back(num);
                    }
                }
            }
        }
        
        return result;
    }
    void sort(vector<int>& nums){

        for(int i=0;i<nums.size();i++)
            {
                for(int j=i+1;j<nums.size();j++)
                {
                    if(nums[i]>nums[j]){
                        int temp=nums[i];
                        nums[i]=nums[j];
                        nums[j]=temp;
                        
                    }
                    
                }
             
                sortnums.push_back(nums[i]);
            }

        
    }
};