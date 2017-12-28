<<<<<<< HEAD
<<<<<<< HEAD
//9ms
class Solution {
public:
    int trap(vector<int>& height) {
        int maxleft=0,maxright=0,res=0;
        int left=0,right=height.size()-1;
        while(left<right){
            if(height[left]<height[right]){
                if(height[left]>=maxleft)   maxleft=height[left];
                else    res+=maxleft-height[left];
                left++;
            }
                
            else{
                if(height[right]>=maxright) maxright=height[right];
                else    res+=maxright-height[right];
                right--;
            }
        }
        
        return res;
    }
=======
//9ms
class Solution {
public:
    int trap(vector<int>& height) {
        int maxleft=0,maxright=0,res=0;
        int left=0,right=height.size()-1;
        while(left<right){
            if(height[left]<height[right]){
                if(height[left]>=maxleft)   maxleft=height[left];
                else    res+=maxleft-height[left];
                left++;
            }
                
            else{
                if(height[right]>=maxright) maxright=height[right];
                else    res+=maxright-height[right];
                right--;
            }
        }
        
        return res;
    }
>>>>>>> 76dd5de5e755fac11ea9f1568e19618b0f421cc7
=======
//9ms
class Solution {
public:
    int trap(vector<int>& height) {
        int maxleft=0,maxright=0,res=0;
        int left=0,right=height.size()-1;
        while(left<right){
            if(height[left]<height[right]){
                if(height[left]>=maxleft)   maxleft=height[left];
                else    res+=maxleft-height[left];
                left++;
            }
                
            else{
                if(height[right]>=maxright) maxright=height[right];
                else    res+=maxright-height[right];
                right--;
            }
        }
        
        return res;
    }
>>>>>>> 76dd5de5e755fac11ea9f1568e19618b0f421cc7
};