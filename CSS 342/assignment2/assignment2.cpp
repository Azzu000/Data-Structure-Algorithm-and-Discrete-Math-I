/*By Ruiqi Huang
* 1/24/2023
* This is the driver for our TimeSpan class. Some tests are given along with assignment and some tests are created by me. Each is labeled
* accordingly. This tests for overloading of values, negative values, decimal values, all the operators, and more, 
*/

#include <iostream>
#include <sstream>
#include<cassert>
#include <iomanip>
#include "timespan.h"
using namespace std;

//testing constructor
void test1() {
	TimeSpan ts(1, 20, 30);
	stringstream ss;
	cout << "testing <<" << endl;
	ss << ts;
	assert(ss.str() == "1:20:30");
	cout << "testing overflow and negative inputs" << endl;
	TimeSpan ts2(4, -20, -90);
	ss.str("");
	ss << ts2;
	assert(ss.str() == "3:38:30");
	TimeSpan ts3(1.5, 30.5, -90);
	ss.str("");
	ss << ts3;
	assert(ss.str() == "1:59:00");
	TimeSpan ts4(0, 0.07, 0);
	ss.str("");
	ss << ts4;
	assert(ss.str() == "0:00:04");
}

//testing equality, addition, subtraction, multiplication
void test2() {
	TimeSpan ts(1, 20, 30);
	TimeSpan ts2(1, 20, 30);
	TimeSpan ts3(0, 0, 0);
	TimeSpan ts4(0, 0, 40);
	cout << "testing ==" << endl;
	assert(ts == ts2);
	cout << "testing !=" << endl;
	assert(!(ts != ts2));
	assert(ts != ts3);
	cout << "testing + and *" << endl;
	assert((ts + ts + ts) == (ts2 * 3));
	assert((ts * 5) == (ts2 * 4) + ts2);
	assert((ts * 5) == (ts2 * 6) - ts2);
	assert((ts + ts - ts) == ((ts2 * 2) - ts));
	cout << "testing +=" << endl;
	ts += ts4;
	stringstream ss;
	ss.str("");
	ss << ts;
	assert(ss.str() == "1:21:10");
	cout << "testing -=" << endl;
	ts2 -= ts4;
	ss.str("");
	ss << ts2;
	assert(ss.str() == "1:19:50");
}

void test3() {
	//comparison operators
	TimeSpan ts1(1, 20, 30);
	TimeSpan ts2(2, 0, 0);
	TimeSpan ts3(1, 20, 30);

	cout << "testing comparison operators" << endl;
	
	assert(ts1 < ts2);
	assert(!(ts2 < ts1));
	assert(ts2 > ts1);
	assert(!(ts1 > ts2));
	assert(ts1 <= ts2);
	assert(ts1 <= ts3);
	assert(ts2 >= ts1);
	assert(ts1 >= ts3);
}
//Any test named MyTest is created by me.
void MyTest1() {
	//Overloading test
	TimeSpan t1(1, 60, 88);
	cout << t1 << endl;

	//Testing operators
	TimeSpan t3(2, 4, 2);
	TimeSpan t4(1, 1, 1);

	cout << "Testing + " << endl;
	cout << t1;
	cout << " + ";
	cout << t4 << endl;
	cout << t1 + t4 << endl;
	cout << endl;

	cout << "Testing += " << endl;
	cout << t4;
	cout << " += ";
	cout << t1 << endl;
	t4 += t1;
	cout << t4 << endl;
	cout << endl;

	TimeSpan t5(2, 2, 2);
	TimeSpan t6(1, 1, 1);
	cout << "Testing - " << endl;
	cout << t5;
	cout << " -= ";
	cout << t6 << endl;
	cout << t5 - t6 << endl;
	cout << endl;

	cout << "Testing -= " << endl;
	cout << t5;
	cout << " -= ";
	cout << t6 << endl;
	t5 -= t6;
	cout << t5 << endl;
	cout << endl;

	TimeSpan t10(5, 3, 4);
	cout << "Testing * " << endl;
	cout << t10;
	cout << " * 2" << endl;
	cout << t10 * 2 << endl;
	cout << endl;

	//Comparison tests starts here
	//NOTE: syntax is always "Comparing left hand side and right hand side" so operator is replaced with and. 
	TimeSpan t13(1, 1, 1);
	TimeSpan t14(1, 1, 1);
	TimeSpan t15(-1, -1, -1);
	TimeSpan t16(2, 1, 1);
	cout << "Testing == " << endl;
	cout << "Comparing..." << endl;
	cout << t13;
	cout << " and ";
	cout << t14 << endl;
	if (t13 == t14) {
		cout << "t13 == t14" << endl;
		cout << endl;
	}
	else {
		cout << "t13 != t14" << endl;
		cout << endl;
	}

	//Here we want to make sure the negative value does not equal the positive values.
	cout << "Comparing..." << endl;
	cout << t13;
	cout << " and ";
	cout << t15 << endl;
	if (t13 == t15) {
		cout << "t13 == t14" << endl;
		cout << endl;
	}
	else {
		cout << "t13 != t15" << endl;
		cout << endl;
	}

	cout << "Testing != " << endl;
	cout << "Comparing..." << endl;
	cout << t16;
	cout << " and ";
	cout << t13 << endl;
	if (t16 != t13) {
		cout << "t16 != t13" << endl;
		cout << endl;
	}
	else {
		cout << "t16 == t13" << endl;
		cout << endl;
	}

	cout << "Testing <" << endl;
	cout << "Comparing..." << endl;
	cout << t15;
	cout << " and ";
	cout << t13 << endl;
	if (t15 < t13) {
		cout << "t15 < t13 is true" << endl;
		cout << endl;
	}
	else {
		cout << "t15 < t13 is false" << endl;
		cout << endl;
	}

	cout << "Comparing..." << endl;
	cout << t13;
	cout << " and ";
	cout << t15 << endl;
	if (t13 < t15) {
		cout << "t13 < t15 is true" << endl;
		cout << endl;
	}
	else {
		cout << "t13 < t15 is false" << endl;
		cout << endl;
	}

	cout << "Testing <=" << endl;
	//Testing the = part of <=
	cout << "Comparing..." << endl;
	cout << t13;
	cout << " and ";
	cout << t14 << endl;
	if (t13 <= t14) {
		cout << "t13 <= t14 is true" << endl;
		cout << endl;
	}
	else {
		cout << "t13 <= t14 is false" << endl;
		cout << endl;
	}

	//Testing < part of <=
	cout << "Comparing..." << endl;
	cout << t15;
	cout << " and ";
	cout << t13 << endl;
	if (t15 < t13) {
		cout << "t15 < t13 is true" << endl;
		cout << endl;
	}
	else {
		cout << "t15 < t13 is false" << endl;
		cout << endl;
	}

	cout << "Testing >" << endl;
	cout << "Comparing..." << endl;
	cout << t15;
	cout << " and ";
	cout << t13 << endl;
	if (t15 > t13) {
		cout << "t15 > t13 is true" << endl;
		cout << endl;
	}
	else {
		cout << "t15 > t13 is false" << endl;
		cout << endl;
	}

	cout << "Comparing..." << endl;
	cout << t13;
	cout << " and ";
	cout << t15 << endl;
	if (t13 > t15) {
		cout << "t13 > t15 is true" << endl;
		cout << endl;
	}
	else {
		cout << "t13 > t15 is false" << endl;
		cout << endl;
	}

	cout << "Testing >=" << endl;
	//Testing the = part of >=
	cout << "Comparing..." << endl;
	cout << t13;
	cout << " and ";
	cout << t14 << endl;
	if (t13 <= t14) {
		cout << "t13 >= t14 is true" << endl;
		cout << endl;
	}
	else {
		cout << "t13 >= t14 is false" << endl;
		cout << endl;
	}

	//Testing the > part of >=
	cout << "Comparing..." << endl;
	cout << t13;
	cout << " and ";
	cout << t15 << endl;
	if (t13 > t15) {
		cout << "t13 >= t15 is true" << endl;
		cout << endl;
	}
	else {
		cout << "t13 >= t15 is false" << endl;
		cout << endl;
	}

}

void MyTest2() {
	//negative values
	TimeSpan t7;
	TimeSpan t8(1, 1, 1);
	TimeSpan t9(2, 2, 2);
	cout << "Testing negative values" << endl;
	cout << t8;
	cout << " - ";
	cout << t9 << endl;
	t7 = t8 - t9;
	cout << t7 << endl;
	cout << endl;

	cout << "Putting in negative values" << endl;
	TimeSpan t11(-1, -1, -1);
	cout << t11 << endl;
	cout << endl;
}

void MyTest3() {
	//Decimal values
	TimeSpan t12(0, 0.09, 0);
	cout << "The value should be 5 seconds" << endl;
	cout << t12 << endl;
	cout << endl;
}

void testAll() {
	cout << "Given Tests" << endl;
	test1();
	test2();
	test3();
	cout << endl;

	cout << "My Tests: " << endl;
	MyTest1();
	MyTest2();
	MyTest3();
	cout << "SUCCESSFULLY PASS ALL TESTS!" << endl;
}

int main() {
	cout << "Begin" << endl;
	testAll();
	cout << "Done." << endl;


	return 0;
}