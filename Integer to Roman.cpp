#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int len=0;
	int data[5];
	char number[7]={'I','V','X','L','C','D','M'};
	string result;
	string  intToRoman(int num){
		while(num!=0){
			data[len++]=num%10;
			num/=10;
		}
		for(int i=len-1;i>=0;i--){
			int skip=data[i]/5;
			int cur=data[i]%5;
			if(data[i]==5){
				result.push_back(number[2*i+1]);

			}
			else if(cur<4){
			    if(skip>0){
			        result.push_back(number[2*i+1]);
			    }
        		for(int j=cur;j>0;j--)
        		{
        			result.push_back(number[2*i]);
    			}


			}
			else if(cur==4){
			    if(skip>0){
			        result.push_back(number[2*i]);
			        result.push_back(number[2*i+2]);
			    }
			    else{
				    result.push_back(number[2*i]);
				    result.push_back(number[2*i+1]);
			        
			    }
			}
		}
		return result;
	}
};
int main(void)
{
	Solution s;
    int n=289;
    // << "Please input the value of int:" ;
    //cin >> n;

    string res = s.intToRoman(n);
    cout << "The roman num is: " << res<<endl;



}