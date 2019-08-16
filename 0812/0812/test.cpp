#include<iostream>
#include<string>

using namespace std;

class Person
{
public:
	void Print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
private:
	string _name = "abc";
	int _age = 18;
};
class Student :public Person
{
private:
	int _id;
};
int main()
{
	Person *p=new Student;
	p->Print();
	Student s;
	s.Print();
}