#ifndef INSTRUCTOR_HPP_
#define INSTRUCTOR_HPP_
#include<string>
//GEN-RAND NUMS
#include <cstdlib> 
#include <ctime> 

#include"Person.hpp"

/**
// Task: Create a sub class Instructor which will inherit
//		the protected member variables id_, first_name_,  and last_name_
//		from the base class 'Person'
**/

class Instructor: public Person
{
public:
		/*
		// Task: Initialize object of class 'Instructor'
		// Input: No expected input
		// Result: New object created with empty member varaibles
		// Output: N/A
		*/
	Instructor();

		/*
		// Task: Initialize object of class 'Instructor'
		// Input: Integer value for id_, string value for first_name_, string value for last_name_, 
		// Result: New object created with member varaibles set to the values passed
		// Output: N/A
		*/
	Instructor(int id, std::string first, std::string last);

		/*
		// Task: Destruct object when out of scope 
		// Input: N/A
		// Result: Object is destroyed and memory is cleared
		// Output: N/A
		*/
	~Instructor();

		/*
		// Task: Return meber value: office_
		// Input: N/A
		// Result: string value returned 
		// Output: value office_
		*/
	std::string getOffice() const;


		/*
		// Task: Return meber value: contact_
		// Input: N/A
		// Result: string value returned 
		// Output: value contact_
		*/
	std::string getContact() const;

		/*
		// Task: Set member varible to string value passed in by user 
		// Input: String Value
		// Result: Member value overridden
		// Output: N/A
		*/
	void setOffice(const std::string office);


		/*
		// Task: Set member varible to string value passed in by user 
		// Input: String Value
		// Result: Member value overridden
		// Output: N/A
		*/
	void setContact(const std::string contact);

		/**Declaration of polymorphed Display function from parent class
			@post Protected data is printed as following: (all one line)
					“first_name_ last_name_ - office: 
					1000C, email:235Instructors@hunter.cuny.edu\n"
		**/
	void display() override;

private:
	std::string office_;
	std::string contact_;
};

#endif