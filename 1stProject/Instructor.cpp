#include<string>
#include"Person.hpp"
#include"Instructor.hpp"

/**
// Task: Create a sub class Instructor which will inherit
//		the protected member variables id_, first_name_,  and last_name_
//		from the base class 'Person'
**/

/*
// Task: Initialize object of class 'Instructor'
// Input: No expected input
// Result: New object created with empty member varaibles
// Output: N/A
*/
Instructor::Instructor():office_(""), contact_(""){};

/*
// Task: Initialize object of class 'Instructor'
// Input: Integer value for id_, string value for first_name_, string value for last_name_, 
// Result: New object created with member varaibles set to the values passed
// Output: N/A
*/
Instructor::Instructor(int id, std::string first, std::string last):Person(id, first, last){}; 		

/*
// Task: Destruct object when out of scope 
// Input: N/A
// Result: Object is destroyed and memory is cleared
// Output: N/A
*/
Instructor::~Instructor(){};

/*
// Task: Return meber value: office_
// Input: N/A
// Result: string value returned 
// Output: value office_
*/
std::string Instructor::getOffice() const{return office_;};

/*
// Task: Return meber value: contact_
// Input: N/A
// Result: string value returned 
// Output: value contact_
*/
std::string Instructor::getContact() const{return contact_;};

/*
// Task: Set member varible to string value passed in by user 
// Input: String Value
// Result: Member value overridden
// Output: N/A
*/
void Instructor::setOffice(const std::string office){office_ = office;};

/*
// Task: Set member varible to string value passed in by user 
// Input: String Value
// Result: Member value overridden
// Output: N/A
*/
void Instructor::setContact(const std::string contact){contact_ = contact;};
