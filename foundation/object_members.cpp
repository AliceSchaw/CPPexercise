#include<iostream>
using namespace std;
class Date
{ 
	public:
	Date(){ 
		cout<<"This is Date"<<endl; 
	}  //Date的缺省构造函数
	Date(int A) { 
		cout<<"The value="<<A<<endl; 
	}
};

class Time
{ 
	public:
	Time() {
	cout<<"This is Time"<<endl;
	} //Time的缺省构造函数
	Time(int A):d2(A)
	//Time的构造函数。采用成员初始化列表的方式，成员对象d1的形参未初始化,将成员对象d2的形参初始化为A
	{
	cout<<"Hello!"<<endl;
	}
	private:
	Date d1,d2;	//在Time中声明两个数据成员d1和d2，这两个成员是Date类的两个对象，即d1和d2是成员对象
};
int main( )
{
	 Time t1,t2(6);	//注释1
	cout<<"The end"<<endl;
}
/*注释1：
主程序运行到Time t1 , t2时，会检查Time类中是否有成员对象，检查中根据Date d1 , d2;  发现有成员对象d1和d2，就先执行d1和d2对应的Date类中的构造函数，然后再执行Time中的构造函数。
具体步骤为：
（一）在创建t1对象（无参数）时，按下列步骤进行：
1、执行d1所属类Date的构造函数，因为d1在Time中未初始化，故在重载时调用缺省构造函数，输出 This is Date；
2、执行d2所属类Date的构造函数，因为d1在Time中未初始化，故在重载时调用缺省构造函数，输出 This is Date；
3、执行t1所属类Time的构造函数，因为d1在Time中未初始化，故在重载时调用缺省构造函数，输出 This is time;
（二）在创建t2对象（有参数）时，按下列步骤进行：
4、执行d1所属类Date的构造函数，因为d1在Time中未初始化，故在重载时调用缺省构造函数，输出 This is Date.
5、执行d2所属类Date的构造函数，根据Time中 Time(int A):d2(A); 发现d2已经被初始化为d2(A)，在这里即为d2(6)，由此则需要调用Date类的构造函数Date(int A)，输出 The value= .
6、执行t2所属类Time的构造函数，t2的重载函数应为Time(int A)，输出 Hello.
This is Date
This is Date
This is Time
This is Date
The value=6
Hello!
The end*/