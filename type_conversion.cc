 ///
 /// @file    type_conversion.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-15 07:26:29
 ///

//由其他类型转换到自定义类型

#include <iostream>
using namespace std;

class point;  //
 
class anotherPoint  //define class anotherPoint
{
public:
	anotherPoint(double xx = 1, double yy = 1)  //constructor,band default parameter 
	:_x(xx)
	,_y(yy)
	{
		cout << "class anotherPoint constructor called" << endl;
	}
	void print() const  //output class information of class anotherPoint
	{
		cout << "(" << _x << ", " << _y << ")" << endl;
	}
	friend class point;  
		//使point类成为本类的友元类，这样point类就可以访问anotherPoint类的private变量了

private:  //private member list
	double _x;
	double _y;
};

class point  //define class point
{
public:
//	explicit  //如果在构造函数前加上explicit，就不允许point pt1 = 5这种隐式转换了
	point(int x = 0, int y = 0)  //constructor, band default parameter constructor
	:_xPos(x)
	,_yPos(y)
	{
		cout << "class point constructor called " << endl;
	}
	point(anotherPoint ap)  //构造函数，参数为anotherPoint类对象
		//constructor which band parameter ,a object of class anotherPoint
	:_xPos(ap._x)  //由于point类是anotherPoint类的友元类
	,_yPos(ap._y)  //因此这里可以访问anotherPoint的私有变量_x和_y
	{
		cout << "constructor, band object of class anotherPoint" << endl;
	}
	void print() const  //output class point
	{
		cout << "(" << _xPos << ", " << _yPos << ")" << endl;
	}

private:  //private member list
	int _xPos;
	int _yPos;
};

int main()
{
	//1.将int类型数字5转换成point类型
	point p1;  //创建point类对象p1,采用带缺省参数的构造函数，即x=0,y=0
	cout << "p1: " << endl;
	p1.print();
	cout << 5 << "转换成: ";
	p1 = 5;  //等价于p1 = point(5, 0)
	p1.print();  //输出点p1的信息

	//2.将double类型变量dx转换成point类型
	double dx = 1.2;  //声明一个double变量dx
	cout << dx << "转换成";
	p1 = dx;  //等价于p1 = point(int(dx), 0)
	p1.print();  //输出点p1的信息

	//3.将anotherPoint类型转换成point类型
	anotherPoint p2(12.34, 56.78);  //创建anotherPoint类的对象p2
	p2.print();
	cout << "转换成: ";
	p1 = p2;  //等价于p1 = point(p2)
	p1.print();  //输出点p1的信息

	//4.测试在point构造函数前加上explicit以阻止隐形转换的情况
	
	return 0;

}
