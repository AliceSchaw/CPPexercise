#include <iostream>
using namespace std;
class Watch;

/**
 * 定义Time类
 * 数据成员：m_iHour， m_iMinute，m_iSecond 
 * 成员函数：构造函数
 * 友元类：Watch
 */
class Time
{
    // 友元类
    friend class Watch;
public:
	Time(int hour, int min, int sec)
	{
		m_iHour = hour;
		m_iMinute = min;
		m_iSecond = sec;
	}
public:
	int m_iHour;
	int m_iMinute;
	int m_iSecond;
};

/**
 * 定义Watch类
 * 数据成员：m_tTime
 * 成员函数：构造函数
 * display用于显示时间
 */
class Watch
{
public:
//如果对象A中有对象成员B，对象B没有默认构造函数（也就是有参数传递），那么对象A必须在初始化列表中初始化对象B
	Watch(Time &t):m_tTime(t)
	{}
	
	void display()
	{
		cout << m_tTime.m_iHour << endl;
		cout << m_tTime.m_iMinute << endl;
		cout << m_tTime.m_iSecond << endl;
	}
public:
	Time m_tTime;
};

int main()
{
	Time t(6, 30, 20);
	Watch w(t);
	w.display();

	return 0;
}
