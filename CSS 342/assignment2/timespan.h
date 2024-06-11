/* By Ruiqi Huang
*  1/24/2023
*  This program is created to imitate the time. You can set the time, add to time, subtract from the time, check if time is equal or not equal, 
*  multiply time by an int, and compare and contrast two times. This class is created with operator overloads therefore making it easy
*  to use these functions. 
*/

#pragma once
#ifndef TIME_SPAN_H_
#define TIME_SPAN_H_
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class TimeSpan
{
public:
	//Constructors
	TimeSpan();
	TimeSpan(double seconds);
	TimeSpan(double minutes, double seconds);
	TimeSpan(double hours, double minutes, double seconds);

	//Getters & Setters
	int hours() const;
	int minutes() const;
	int seconds() const;

	//Sets the time 
	void SetTime(double hours, double minutes, double seconds);

	//Operator Overloads(
	//Display our time
	friend ostream& operator<<(ostream& out, const TimeSpan& time);
	
	//Check if our time is equal, return trie is equal and false if not equal
	bool operator==(const TimeSpan& time) const;
	//Check if our time is not equal, return true is not equal and false if equal
	bool operator!=(const TimeSpan& time) const;

	//Check if our time is smaller than another time
	bool operator<(const TimeSpan& time) const;
	//Check if our time is smaller or equal to the other time
	bool operator<=(const TimeSpan& time) const;
	//Check if our time is bigger than another time
	bool operator>(const TimeSpan& time) const;
	//Check if our tine is bigger or equal to another time
	bool operator>=(const TimeSpan& time) const;

	//Add our times
	TimeSpan operator+(const TimeSpan& time) const;
	//Add to our time
	TimeSpan& operator+=(const TimeSpan& time);
	//Subtract our times
	TimeSpan operator-(const TimeSpan& time) const;
	//Subtract to our time
	TimeSpan& operator-=(const TimeSpan& time);

	//Multiply our time with an integer
	TimeSpan operator*(int number) const;

private:
	int hour = 0;
	int minute = 0;
	int second = 0;
};
#endif

