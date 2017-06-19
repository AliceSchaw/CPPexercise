//pop/push
//error1:未修改nums
//error2:会去除为0但并不是重复的点
/*
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
            vector<int> res;  
            int temp=0;
            while(!nums.empty()){
                    if(nums.back()!=temp){
                        res.push_back(nums.back());
                        cout<<nums.back();
                        temp=nums.back();
                        
                        nums.pop_back();
                        
                    }
                    else{
                        nums.pop_back();
                    }

                }
            nums.assign(res.begin(),res.end());
            //cout<<res.size();
            return nums.size();
    }
};*/
//iterator(219ms)
/*
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(!nums.empty()&&nums.size()>1){
            vector <int>::iterator Iter=nums.begin();
            int temp=*Iter,count=0;
            for(Iter = nums.begin()+1; Iter != nums.end(); Iter++)
            {
                if(*Iter == temp)
                {
                    nums.erase(Iter);
                    Iter = nums.begin(); 
                    count++;
                }
                temp=*Iter;
            }
        }
        cout<<nums.size()<<endl;
        return nums.size();
    }
};
*/
//49ms
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]) count++;
            else nums[i-count] = nums[i];
        }
        return nums.size()-count;
    }
};

