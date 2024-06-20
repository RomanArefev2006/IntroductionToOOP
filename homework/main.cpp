﻿#include <iostream>
using namespace std;
#define tab "\t"
#define delimiter "\n-----------------------------------------------\n"


class String
{
	int size;
	char* str; 
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	void set_str(char* str)
	{
		this->str = str;
		this->size = strlen(str);
	}
	void set_size(int size)
	{
		this->size = size;
	}

	//		Constructors:

	String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefaultConstructor:\t" << this << endl;
	}
	String(const char str[])
	{
		//strlen(), чек С-функции 
		this->size = strlen(str) + 1;
		this->str = new char[size] {}; // инициализация {} в конце строки проставляет ноль
		for (int i = 0; str[i] != '\0'; i++) this->str[i] = str[i];
		cout << "1ArgConstructor:\t" << this << endl;
	}
	String(const char line1[], const char line2[])
	{
		this->size = strlen(line1) + strlen(line2) + 1;
		this->str = new char[size] {};
		int index = 0;
		for (int i = 0; line1[i] != '\0'; i++, index++) str[i] = line1[i];
		for (int i = 0; line2[i] != '\0'; i++, index++) str[index] = line2[i];
		cout << "Constructor:\t\t" << this << endl;
	}
	String(const String& obj)
	{
		size = obj.size;
		str = new char[obj.size] {};
		for (int i = 0; obj.str[i] != '\0'; i++) str[i] = obj.str[i];
		cout << "CopyConstructor:\t" << this << endl;
	}
	String(String&& obj)
	{
		this->str = obj.str;
		this->size = obj.size;
		obj.str = nullptr;
		obj.size = 0;
		cout << "MoveConstructor:\t" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t\t" << this << endl;
	}

	//		Operators:

	String& operator=(const String& obj)
	{
		size = obj.size;
		str = new char[obj.size] {};
		for (int i = 0; obj.str[i] != '\0'; i++) str[i] = obj.str[i];
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	String& operator=(String&& obj)
	{
		delete[] this->str;
		this->str = obj.str;
		this->size = obj.size;
		obj.str = nullptr;
		obj.size = 0;
		cout << "MoveAssignment:\t\t" << this << endl;
		return *this;
	}

	//		Methods:

	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};
String operator+(const String& left, const String& right)
{
	return String(left.get_str(), right.get_str());
}
std::ostream& operator<<(std::ostream& os, const String& obj
{
	return os << obj.get_str();
}
istream& operator>>(istream& is, String& obj)
{
	char* temp = new char[80] {};
	is >> temp;
	obj.set_str(temp);
	temp = nullptr;
	return is;
}

//#define HOME_WORK

int main()
{
	setlocale(LC_ALL, "");

#ifdef HOME_WORK
	String str1 = "Hello";
	String str2("World");
	cout << str1 << endl;
	cout << str2 << endl;

	cout << delimiter << endl;

	String temp1 = str1;
	temp1.print();
	String temp2;
	temp2 = str2;
	temp2.print();

	cout << delimiter << endl;

	cout << delimiter << endl;
	String str3 = str1 + str2;
	cout << str3 << endl;
	cout << delimiter << endl;

	cout << delimiter << endl;

	String hola = "Hola";
	String str4 = String("Hola");

	String str5;
	str5 = str4 + String("amigos");
	str5.print();

	cout << delimiter << endl;

	String input_test;
	cin >> input_test;
	input_test.print();
#endif // HOME_WORK

	String str1 = "Hello";
	String str2 = "World";
	cout << delimiter << endl;
	String str3 = str1 + str2;
	cout << delimiter << endl;
	cout << str3 << endl;
}