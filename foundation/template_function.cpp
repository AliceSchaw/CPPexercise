#include <iostream>
using namespace std;

/**
 * 定义模板函数swapNum
 * 实现功能：交换两个数的位置
 */
template <typename T> 
void swapnum(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main(void)
{
    int x = 10;
    int y = 20;
    // 调用模板函数
    swapnum<int>(x,y);
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
	return 0;
}
