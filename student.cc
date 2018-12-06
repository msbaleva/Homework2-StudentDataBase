#include "student.h"

Student::Student(unsigned long long fn, string first, string last, short int grade)
{
	fac_num_ = fn;
	first_name_ = first;
	last_name_ = last;
	grade_ = grade;
}

Student::Student(const Student & st)
{
	fac_num_ = st.fac_num_;
	first_name_ = st.first_name_;
	last_name_ = st.last_name_;
	grade_ = st.grade_;
}

Student & Student::operator=(const Student & st)
{
	if (this != &st) {
		fac_num_ = st.fac_num_;
		first_name_ = st.first_name_;
		last_name_ = st.last_name_;
		grade_ = st.grade_;
	}return *this;
}

unsigned long long  Student::getFacNum() const
{
	return fac_num_;
}

string Student::getFirstName() const
{
	return first_name_;
}

string Student::getLastName() const
{
	return last_name_;
}

short int Student::getGrade() const
{
	return grade_;
}

void Student::setGrade(int grade)
{
	grade_ = grade;
}



istream & operator>>(istream & is, Student & st)
{
	do {
		is >> st.fac_num_;
	} while (st.fac_num_ < 0 || st.fac_num_>pow(2, 50));
	do {
		is >> st.first_name_;
	} while (st.first_name_.length() < 0 || st.first_name_.length() > pow(2, 8));
	do {
		is >> st.last_name_;
	} while (st.last_name_.length() < 0 || st.last_name_.length() > pow(2, 8));

	do {
		is >> st.grade_;
	} while (st.grade_ < 2 || st.grade_>6);
	return is;
}

ostream & operator<<(ostream & os, Student & st)
{
	os << st.fac_num_ << " " << st.first_name_ << " " << st.last_name_ << " " << st.grade_ << "\n";
	return os;
}
