class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size()==0)
            return 0;

        int front=0,back=nums.size()-1,res;
        while(front<=back){
            int mid=(front+back)/2;
            if(nums[mid]<target){
                front=mid+1;
            }
            else{
                back=mid-1;
            }
        }
        res=front;
        return res;
    }
};

//9ms
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size()==0)
            return 0;

        int front=0,back=nums.size()-1;
        while(front<back){
            int mid=(front+back)/2;
            
            if (nums[mid] < target) {  
                front = mid + 1;   
            } else if (nums[mid] > target) {  
                back = mid - 1;  
            } else {  
                return mid;  
            } 
        }
        return target>nums[front]?front+1:front;
    }
};