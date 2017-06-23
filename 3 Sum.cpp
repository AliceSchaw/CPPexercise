//139ms
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) {
        vector<vector<int> > res;
        //排序
        sort(num);
        //3SUM
        /*
        //for循环遍历
        vector<vector<int> > result;
        for(int i=0;i<num.size()-2;i++)
            for(int j=i+1;j<num.size()-1;j++)
                for(int k=j+1;k<num.size();k++)
                {
                    if(num[i]+num[j]+num[k]==0)
                    {
                        vector<int> num;
                        
                        num.push_back(num[i]);
                        num.push_back(num[j]);
                        num.push_back(num[k]);
                        if(result.empty()||result.back()!=num){
                            result.push_back(num);
                        }
                    }
                }
         */
        //分治法
        for (int i = 0; i < num.size(); i++) {
            
            int target = -num[i];
            int front = i + 1;
            int back = num.size() - 1;
    
            while (front < back) {
    
                int sum = num[front] + num[back];
                
                // Finding answer which start from number num[i]
                if (sum < target)
                    front++;
    
                else if (sum > target)
                    back--;
    
                else {
                    vector<int> triplet(3, 0);
                    triplet[0] = num[i];
                    triplet[1] = num[front];
                    triplet[2] = num[back];
                    res.push_back(triplet);
                    
                    // Processing duplicates of Number 2
                    // Rolling the front pointer to the next different number forwards
                    while (front < back && num[front] == triplet[1]) front++;
    
                    // Processing duplicates of Number 3
                    // Rolling the back pointer to the next different number backwards
                    while (front < back && num[back] == triplet[2]) back--;
                }
                
            }
    
            // Processing duplicates of Number 1
            while (i + 1 < num.size() && num[i + 1] == num[i]) 
                i++;
    
        }
        return res;
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
            }
    }
   
};

//126ms
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) {
        vector<vector<int> > res;
        //排序
        quick_sort(num,0,num.size()-1);

        //分治法
        for (int i = 0; i < num.size(); i++) {
            
            int target = -num[i];
            int front = i + 1;
            int back = num.size() - 1;
    
            while (front < back) {
    
                int sum = num[front] + num[back];
                
                // Finding answer which start from number num[i]
                if (sum < target)
                    front++;
    
                else if (sum > target)
                    back--;
    
                else {
                    vector<int> triplet(3, 0);
                    triplet[0] = num[i];
                    triplet[1] = num[front];
                    triplet[2] = num[back];
                    res.push_back(triplet);
                    
                    // Processing duplicates of Number 2
                    // Rolling the front pointer to the next different number forwards
                    while (front < back && num[front] == triplet[1]) front++;
    
                    // Processing duplicates of Number 3
                    // Rolling the back pointer to the next different number backwards
                    while (front < back && num[back] == triplet[2]) back--;
                }
                
            }
    
            // Processing duplicates of Number 1
            while (i + 1 < num.size() && num[i + 1] == num[i]) 
                i++;
    
        }
        return res;
    }

    void quick_sort(vector<int> &s,int l,int r)
    {
        if(l<r)
        {
            //Swap(s[l],s[(l+r)/2]);
            int i=l,j=r,x=s[l];
            while(i<j)
            {
                while(i<j&&s[j]>=x)//从右向左找第一个小于x的数
                j--;
                if(i<j)
                s[i++]=s[j];

                while(i<j&&s[i]<x)//从左向右找第一个大于等于x的数
                i++;
                if(i<j)
                s[j--]=s[i];
            }
            s[i]=x;
            quick_sort(s,l,i-1);//递归调用
            quick_sort(s,i+1,r);
        }
    }
};