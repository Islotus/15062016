 ///
 /// @file    type_conversion2.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-15 08:00:49
 ///

//类型转换函数（由类转换成其他类型）
//可以通过operator int() 这种类斯操作符重载函数类型转换函数来实现由自定义类型向其他类型的转换
//。如将point类型转换成int类型等。
//在类中定义类型转换函数的形式一般为：
//operator 目标类型名();
//有以下几个实用要点：
//>转换函数必须是成员函数，不能是友元形式
//>转换函数不能指定返回类型，但在函数体内必须用return语句以传值方式返回一个目标类型的变量
//>转换函数不能有参数

#include <iostream>


#if 1
using namespace std;
#endif

#if 0
using std::cin;
using std::cout;
using std::endl;
using std::ostream;
#endif
class point;

ostream & operator <<(ostream& os, const point& pt);

class anotherPoint  //define class anotherPoint
{
public:
	anotherPoint(double xx = 1.11, double yy = 1.11)  //constructor, band default parameter
	:_x(xx)
	,_y(yy)
	{
		cout << "class anotherPoint constructor called" << endl;
	}
	anotherPoint(const anotherPoint & ap)
	:_x(ap._x)
	,_y(ap._y)
	{
		cout << "copy constructor of class anotherPoint called" << endl;
	}
	void print() const  //member function，output class anotherPoint
	{
		cout << "(" << _x << ", " << _y << ")" << endl;
	}

private:  //private member list
	double _x;
	double _y;
};

class point  //define class point
{
public:
	point(int x = 0, int y = 0)  //constructor, band default parameter 
	:_xPos(x)
	,_yPos(y)
	{
		cout << "class point constructor called" << endl;
	}
	void print() const  //member function，output class point
	{
		cout << "(" << _xPos << ", " << _yPos << ")" << endl;
	}
	friend ostream& operator <<(ostream& os, const point& pt);  //重载<<运算符

	operator int()  //定义point向int型的转换函数int() 
	{
		cout << "called: point --> int" << endl;
		return _xPos;
	}

	operator double()  //定义point向double型的转换函数double()
	{
		cout << "called: point --> double" << endl;
		return _xPos * _yPos;
	}

	operator anotherPoint()  //定义point向anotherPoint型的转换函数anotherPoint()
	{
		cout << "called: point --> anotherPoint()" << endl;
		return anotherPoint(_xPos, _yPos);
	}

private:  //private member list
	int _xPos;
	int _yPos;
};

ostream& operator <<(ostream& os, const point& pt)
{
	cout << "operator << function called" << endl;
	os << (pt._xPos * 100);
	return os;
}
 

int main()
{
	point p1(4, 5);  //声明一个point类变量p1
	p1.print();  
	
	//1.point转换成int
	int x1 = p1;  //p1赋值给一个int型变量，point中的转换函数int()被隐式调用
	cout << x1 << endl;

	//2.point转换成double
	double dx = p1;  //p1赋值给一个double型变量，point中的转换函数double()被隐式调用
	cout << dx << endl;

	//3.point转换成anotherPoint
	anotherPoint p2;  //声明anotherPoint类对象p2，构造函数采用缺省值
	p2 = p1;  //p1赋值给p2,point中的转换函数anotherPoint()被隐式调用
				//等价于p2 = anotherPoint(p1._xPos, p1._yPos)
	p2.print();  //看p2是否修改成功
	
	return 0;
}
