#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	void retateImage(vector <vector <int> > &matrix){
	    if(matrix.size()<=0)
        return;	
		int n=matrix.size();
		for(int i=0;i<n/2;i++){
			for(int j=0;j<n-1-i;i++)
			{
				int x=i,y=j;
				int temp=matrix[i][j];
				matrix[x][y]=matrix[-y+n-1][x];
				matrix[-y+n-1][x]=matrix[-x+n-1][-y+n-1];
				matrix[-x+n-1][-y+n-1]=matrix[y][-x+n-1];
				matrix[y][-x+n-1]=temp;
			}
		}
	}
};
int main(void)
{
    vector<vector <int> > matrix(2);
    matrix.push_back[0,1]=1;
    matrix.push_back[0,1]=1;
    matrix.push_back[1,0]=1;
    matrix.push_back[1,1]=1; 


    Solution *p=new Solution;
    p->retateImage(matrix);

    
}