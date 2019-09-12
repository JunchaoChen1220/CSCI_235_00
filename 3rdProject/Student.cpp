#include<string>
#include<iostream>
//GEN-RAND NUMS
#include <cstdlib> 
#include <ctime> 

#include"Person.hpp"
#include"Student.hpp"

/**
// Task: Create a sub class Student which will inherit
//		the protected member variables id_, first_name_,  and last_name_
//		from the base class 'Person'
**/

/*
// Task: Initialize object of class 'Student'
// Input: No expected input
// Result: New object created with empty member varaibles
// Output: N/A
*/
Student::Student():gpa_(-1), major_(""){};

/*
// Task: Initialize object of class 'Student'
// Input: Integer value for id_, string value for first_name_, string value for last_name_, 
// Result: New object created with member varaibles set to the values passed
// Output: N/A
*/
Student::Student(int id, std::string first, std::string last):Person(id, first, last){};

/*
// Task: Destruct object when out of scope 
// Input: N/A
// Result: Object is destroyed and memory is cleared
// Output: N/A
*/
Student::~Student(){};

/*
// Task: Return meber value: major_
// Input: N/A
// Result: string value returned 
// Output: value major_
*/
std::string Student::getMajor()const{return major_;};

/*
// Task: Return meber value: gpa_
// Input: N/A
// Result: double value returned 
// Output: value gpa_
*/
double Student::getGpa()const{return gpa_;};

/*
// Task: Set member varible to string value passed in by user 
// Input: String Value
// Result: Member value overridden
// Output: N/A
*/
void Student::setMajor(const std::string major){major_ = major;};

/*
// Task: Set member varible to doble value passed in by user 
// Input: double Value
// Result: Member value overridden
// Output: N/A
*/
void Student::setGpa(const double gpa){gpa_ = gpa;};

/**Declaration of polymorphed Display function from parent class
	@post Protected data is printed as following:
			“first_name_ last_name_ majors in major_ with gpa: gpa_\n”
**/
void Student::display(){
	std::cout
		<< first_name_ << " "
		<< last_name_
		<< " majors in " << major_
		<< " with gpa: " << gpa_
		<<std::endl;
};


/**
@return a number randomly sampled from
{4.0, 3.75, 3.5, 3.25, 3.0, 2.75, 2.5, 2.25, 2.0}
*/
double Student::randGpa(){
	srand((unsigned)(time(0)));
	double v[] = {4.0, 3.75, 3.5, 3.25, 3.0, 2.75, 2.5, 2.25, 2.0} ;
	return v[rand()%9];
};

/**
	{"Computer Science", "Literature", "Music", "Philosophy", "Physics","Theatre", "Computational Biology", "Mathematics", "Geography", "Linguistics"}
*/
std::string Student::randMajor(){
	srand((unsigned)(time(0)));
	std::string v[] = {"Computer Science", "Literature", "Music", "Philosophy", "Physics","Theatre", "Computational Biology", "Mathematics", "Geography", "Linguistics"};
	return v[rand()% 10];
};
