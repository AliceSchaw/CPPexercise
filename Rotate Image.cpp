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
			for(int j=0;j<n-1-i;j++)
			{
				int x=i,y=j;
				int temp=matrix[i][j];
				matrix[x][y]=matrix[n-1-y][x];
				matrix[n-1-y][x]=matrix[n-1-x][n-1-y];
				matrix[n-1-x][n-1-y]=matrix[y][n-1-x];
				matrix[y][n-1-x]=temp;

			}
		}
	}
};
int main(void)
{

    int MAX=3;
    vector<vector<int> > matrix(MAX,vector<int> (MAX));
    matrix[0][0]=1;
    matrix[0][1]=2;
    matrix[1][0]=3;
    matrix[1][1]=4; 
    matrix[2][0]=5;
    matrix[2][1]=6; 
    matrix[2][2]=7;
    matrix[0][2]=8;
    matrix[1][2]=9;


    Solution *p=new Solution;
    p->retateImage(matrix);
    for(int i=0;i<MAX;i++)
    	for(int j=0;j<MAX;j++){
            cout<<i<<","<<j<<" "<<matrix[i][j]<<endl;
    	    
    	}
}