#ifndef STUDENTDATABASE_STUDENTDATABASE_OPERATIONS_H_
#define STUDENTDATABASE_STUDENTDATABASE_OPERATIONS_H_
#include <fstream>
#include "student.h"



void update() {
	fstream file;
	file.open("StudentsGrades.db");
	if (!file) { cerr << "File couldn't be opened!\n"; }
	Student st;
	unsigned long long fn;
	unsigned short int grade;
	do { cin >> fn; } while (fn<0 || fn>pow(2, 50));
	do { cin >> grade; } while (grade < 2 || grade >6);
	bool found = false;
	file.seekg(0, ios::beg);
	streampos getPosition = file.tellg(); 
	while (file >> st) {
		
		if (st.getFacNum() == fn) { 
			found = true; 
			file.seekp(getPosition, ios::beg);
			st.setGrade(grade);
			file << st.getFacNum() << " " << st.getFirstName() << " " << st.getLastName() << " " << st.getGrade();
			
			cout << "Record saved!\n";
			break; 
		}
		file.ignore();
		getPosition = file.tellg();
	}
	if (!found) { cout << "Record not found!\n"; }
	file.close();
}


void del() {
	ifstream iFile;
	iFile.open("StudentsGrades.db");
	if (!iFile) { cerr << "File couldn't be opened!\n"; }
	Student st;
	unsigned long long fn;
	do { cin >> fn; } while (fn<0 || fn>pow(2, 50));
	bool found = false;
	
	ofstream oFile;
	oFile.open("tempFile.db",ios::out);
	if (!oFile) { cerr << "File couldn't be opened!\n"; }
	while (iFile >> st) {
		
		
		if (st.getFacNum() != fn) { 
			oFile << st;
		}
		else{found = true;}
		
		
	}
	iFile.close();
	oFile.close();

	if (found) {
		oFile.open("StudentsGrades.db", ios::out);
		if (!oFile) { cerr << "File couldn't be opened!\n"; }
		iFile.open("tempFile.db");
		if (!iFile) { cerr << "File couldn't be opened!\n"; }
	
		while (iFile >> st) {
			oFile << st;
		}
	
		oFile.close();
		iFile.close();
		
		cout << "Record deleted!\n";
	}
	else if (!found) { 
		cout << "Record not found!\n"; 
	}
	
}

void sequentialSearch() {
	fstream file;
	file.open("StudentsGrades.db", ios::in);
	if (!file) { cerr << "File couldn't be opened!\n"; }
	Student st;
	unsigned long long fn;
	do { cin >> fn; } while (fn<0 || fn>pow(2, 50));
	bool found = false;
	file.seekg(0, ios::beg);
	while (file >> st) {

		if (st.getFacNum() == fn) { cout << st; found = true; break; }

	}
	if (!found) { cout << "Record not found!\n"; }
	file.close();

}
void operationParser() {
	string input;
	cin >> input;
	while (input != "exit") {

		if (input == "sequentialSearch") {
			sequentialSearch();
		}
		else if (input == "update") {
			update();
		}
		else if (input == "delete") {
			del();
		}
		else { cout << "Invalid operation!\n"; }
		cin >> input;
	}
}

void generateDataBase() {
	fstream nameFile;
	fstream familyFile;
	nameFile.open("names.db", ios::in | ios::out);
	if (!nameFile) { cerr << "File couldn't be opened!\n"; }
	familyFile.open("familyNames.db", ios::in | ios::out);
	if (!familyFile) { cerr << "File couldn't be opened!\n"; }
	fstream file;
	file.open("StudentsGrades.db", ios::app);
	if (!file) { cerr << "File couldn't be opened!\n"; }
	unsigned long long fn;
	string name;
	string family;
	unsigned short int grade;
	for (int i = 100000; i < 200000; i++) {
		fn = i;
		nameFile >> name;
		familyFile >> family;
		grade = rand() % 5 + 2;
		Student st(fn, name, family, grade);
		file << st;
		
	}
	
	nameFile.close();
	familyFile.close();
	file.close();
}
#endif