//公司今天招聘了5个员工，5名员工进入公司之后，需要指派员工在那个部门工作
//人员信息有: 姓名 年龄 电话 工资等组成
//通过Multimap进行信息的插入 保存 显示
//分部门显示员工信息 显示全部员工信息
#include "pch.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

enum Department{Wei , Shu  , Wu  };

class Employee
{
public:
	Employee()
	{

	}

	Employee(string name, int age, string telephone_nummer, int salary)
	{
		this->name = name;
		this->age = age;
		this->telephone_number = telephone_number;
		this->salary = salary;
	}
	inline string get_name()
	{
		return name;
	}

	inline int get_age()
	{
		return age;
	}

	inline string get_telephone_number()
	{
		return telephone_number;
	}

	inline int get_salary()
	{
		return salary;
	}

private:
	string name;
	int age;
	string telephone_number;
	int salary;
};

struct PrintStuffInfo
{
	inline void operator()(pair<const Department, Employee>& stuff_info)
	{
		cout << stuff_info.first << " " << stuff_info.second.get_name() << " " << stuff_info.second.get_age() << " " << stuff_info.second.get_telephone_number() << " " << stuff_info.second.get_salary() << ";" << endl;
	}
};

class AbstructPrint
{
public:
	virtual void operator()(pair<const Department, Employee>& stuff_info) = 0;
};

class PrintStuffWei :public AbstructPrint
{
public:
	virtual void operator()(pair<const Department, Employee>& stuff_info)
	{
		if(stuff_info.first == Wei)
			cout << stuff_info.first << " " << stuff_info.second.get_name() << " " << stuff_info.second.get_age() << " " << stuff_info.second.get_telephone_number() << " " << stuff_info.second.get_salary() << ";" << endl;
	}
};

class PrintStuffShu : public AbstructPrint
{
public:
	virtual void operator()(pair<const Department, Employee>& stuff_info)
	{
		if(stuff_info.first == Shu)
			cout << stuff_info.first << " " << stuff_info.second.get_name() << " " << stuff_info.second.get_age() << " " << stuff_info.second.get_telephone_number() << " " << stuff_info.second.get_salary() << ";" << endl;
	}
};

class PrintStuffWu : public AbstructPrint
{
public:
	virtual void operator()(pair<const Department, Employee>& stuff_info)
	{
		if(stuff_info.first == Wu)
			cout << stuff_info.first << " " << stuff_info.second.get_name() << " " << stuff_info.second.get_age() << " " << stuff_info.second.get_telephone_number() << " " << stuff_info.second.get_salary() << ";" << endl;
	}
};

void init_employee(multimap<Department, Employee>& stuff_info)
{
	stuff_info.insert(make_pair(Shu,Employee("Guan, Yu", 30, "13000000001", 3000)));
	stuff_info.insert(make_pair(Wei,Employee("Xu, Chu", 30, "13100000001", 3000)));
	stuff_info.insert(make_pair(Wu,Employee("Gan, Ning", 30, "13200000001", 3000)));
	stuff_info.insert(make_pair(Shu,Employee("Zhang, Fei", 30, "13000000002", 3000)));
	stuff_info.insert(make_pair(Wei,Employee("Xiahou, Dun", 30, "13100000002", 3000)));
	stuff_info.insert(make_pair(Wu,Employee("Zhou, Yu", 30, "13200000002", 3000)));
}


void test01()
{


	multimap<Department, Employee> stuff_info;
	init_employee(stuff_info);
	for_each(stuff_info.begin(), stuff_info.end(), PrintStuffInfo());
	//for (multimap<Department, Employee>::iterator it = stuff_info.begin(); it != stuff_info.end(); it++)
	//{
	//	cout << it->first << "-" << it->second.get_age() << "-" << it->second.get_name() << "-" << it->second.get_salary() << "-" << it->second.get_telephone_number() << endl;
	//}
	cout << "----------------Wei----------------" << endl;
	for_each(stuff_info.begin(), stuff_info.end(), PrintStuffWei());
	cout << "----------------Shu----------------" << endl;
	for_each(stuff_info.begin(), stuff_info.end(), PrintStuffShu());
	cout << "----------------Wu-----------------" << endl;
	for_each(stuff_info.begin(), stuff_info.end(), PrintStuffWu());
	cout << "----------------End----------------" << endl;

	cout << "----------------Show Stuff----------------" << endl;
}


int main()
{
	int && i = 0;
	test01();

    std::cout << "Hello World!\n"; 
}

