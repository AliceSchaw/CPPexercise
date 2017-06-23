// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int front=1;
        int back=n;
        while(front<=back){
            //error:front+back可能溢出
            //int mid=(front+back)/2;
            int mid=front+(back-front)/2;
            if(isBadVersion(mid)==true){
                back=mid-1;
            }
            else{
                front=mid+1;
            }
        }
        return front;
    }
};