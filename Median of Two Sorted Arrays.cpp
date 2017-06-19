//105ms
class Solution {
public:
    double findMedianSortedArrays(vector<int>& num1, vector<int>& num2) {
        
        int index;
        double res;

        num2.insert(num2.end(), num1.begin(), num1.end()); ;
         

        std::sort(num2.begin(),num2.end());
        cout<<num2.size();
        if(num2.size()%2==0){
            
                index=num2.size()/2;
                res=(double(num2[index])+double(num2[index-1]))/2;
                
        }
        else{
            index=num2.size()/2;
            res=num2[index];
            
        }
        return res;
    }
   
};