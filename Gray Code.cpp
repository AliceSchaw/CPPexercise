#include <iostream>
#include <vector>
using namespace std;
class Solution{
	public:  
	vector<int> result;
	vector<int> grayCode(int n) {
		int cur = 0;
		result.push_back(cur);
		grayChange(cur, n);
		return result;
	}

	void grayChange(int &cur, int dim){
		if(dim == 0){
			return;
		}

		if(dim > 1){
			grayChange(cur, dim - 1);
		}

		if((cur >> (dim - 1)) % 2 == 0){
			cur += 1 << (dim - 1);
		}
		else{
			cur -= 1 << (dim - 1);
		}
		result.push_back(cur);

		if(dim > 1){
			grayChange(cur, dim - 1);
		}
	}
};
int main(void)
{
	Solution s;
    int n;
    cout << "Please input the value of bit:" ;
    cin >> n;

    vector vec = s.grayCode(n);
    cout << "The gray code is: " << endl;
    //循环打印数字
    vector<int>::iterator itor;
    for(itor=vec.begin();itor!=vec.end();itor++)
    {
        cout<<*itor<<endl;
    }


}