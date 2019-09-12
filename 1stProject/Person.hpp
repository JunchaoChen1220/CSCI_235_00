#ifndef PERSON_HPP_
#define PERSON_HPP_
#include<string>

/**
// Task: Create a base class person from which the following classes will inherit
// 			the protected member variables id_, first_name_,  and last_name_
//
**/

class Person{
	public:
		/*
		// Task: Initialize object of class 'Person'
		// Input: No expected input
		// Result: New object created with empty member varaibles
		// Output: N/A
		*/
		Person();

		/*
		// Task: Initialize object of class 'Person'
		// Input: Integer value for id_, string value for first_name_, string value for last_name_, 
		// Result: New object created with member varaibles set to the values passed
		// Output: N/A
		*/
		Person(int id, std::string first, std::string last);

		/*
		// Task: Destruct object when out of scope 
		// Input: N/A
		// Result: Object is destroyed and memory is cleared
		// Output: N/A
		*/
		~Person();

		/*
		// Task: Return meber value: id_
		// Input: N/A
		// Result: int value returned 
		// Output: value id_
		*/
		int getID() const;

		/*
		// Task: Return meber value: first_name_
		// Input: N/A
		// Result: string value returned 
		// Output: value first_name_
		*/
		std::string getFirstName() const;

		/*
		// Task: Return meber value: last_name_
		// Input: N/A
		// Result: string value returned 
		// Output: value last_name_
		*/
		std::string getLastName() const;

	protected:
	int id_;
	std::string first_name_;
	std::string last_name_;
};

#endif