#ifndef STUDENTDATABASE_STUDENTDATABASE_STUDENT_H_
#define STUDENTDATABASE_STUDENTDATABASE_STUDENT_H_
#include <iostream>
#include <string>
using namespace std;

class Student {
	unsigned long long fac_num_;
	string first_name_;
	string last_name_;
	unsigned short int grade_;
public:
	Student(unsigned long long = 0, string = "", string = "", short int = 0);
	Student(const Student&);
	Student& operator=(const Student&);
	unsigned long long getFacNum() const;
	string getFirstName() const;
	string getLastName() const;
	short int getGrade() const;
	void setGrade(int);
	friend istream& operator>>(istream& is, Student& st);
	friend ostream& operator<<(ostream& os, Student& st);
};
#endif