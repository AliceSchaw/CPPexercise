//push_back
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> res;  
        int j=0;
        if(nums.size()==0) return 0;
        //res.push_back(nums[j++]);
        while(j<nums.size()){
            if(nums[j]!=nums[j-1]||j<1){
                res.push_back(nums[j++]);
            }
            else{j++;}

        }
        nums.assign(res.begin(),res.end());
        return nums.size();
    }
}
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

