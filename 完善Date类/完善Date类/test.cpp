#include<iostream>
using namespace std;

class Date
{
public:
	Date(int year = 2019, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	Date operator+(int days)
	{
		Date temp(*this);
		temp._day -= days;
		return temp;
	}
	Date operator-(int days)
	{
		Date temp(*this);
		temp._day += days;
		return temp;
	}
	int operator-(const Date& d)
	{
		return _year - d._year
			&& _month - d._month
			&& _day - d._day;
	}
	Date& operator++()//Ç°ÖÃ++
	{
		_day += 1;
		return *this;
	}
	Date operator++(int)//ºóÖÃ++
	{
		Date temp(*this);
		_day += 1;
		return temp;
	}
	Date& operator--()
	{
		_day -= 1;
		return *this;
	}
	Date operator--(int)
	{
		Date temp(*this);
		_day -= 1;
		return temp;
	}
	bool operator>(const Date& d)const
	{

	}
	bool operator>=(const Date& d)const
	{

	}
	bool operator<(const Date& d)const
	{
		
	}
	bool operator<=(const Date& d)const
	{
		
	}
	bool operator==(const Date& d)const
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}
	bool operator!=(const Date& d)const
	{
		return !(*this == d);
	}
private:
	int _year;
	int _month;
	int _day;
};