#include "Person.hpp"
#include<string>
#include <iostream>
/**
// Task: Create a base class person from which the following classes will inherit
// 			the protected member variables id_, first_name_,  and last_name_
//
**/

/*
// Task: Initialize object of class 'Person'
// Input: No expected input
// Result: New object created with empty member varaibles
// Output: N/A
*/
Person::Person():id_(-1), first_name_(""), last_name_(""){};

/*
// Task: Initialize object of class 'Person'
// Input: Integer value for id_, string value for first_name_, string value for last_name_, 
// Result: New object created with member varaibles set to the values passed
// Output: N/A
*/
Person::Person(int id, std::string first, std::string last):id_(id), first_name_(first), last_name_(last){};

/*
// Task: Destruct object when out of scope 
// Input: N/A
// Result: Object is destroyed and memory is cleared
// Output: N/A
*/
Person::~Person(){};

/*
// Task: Return meber value: id_
// Input: N/A
// Result: int value returned 
// Output: value id_
*/
int Person::getID() const{return id_;};

/*
// Task: Return meber value: first_name_
// Input: N/A
// Result: string value returned 
// Output: value first_name_
*/
std::string Person::getFirstName() const{return first_name_;};

/*
// Task: Return meber value: last_name_
// Input: N/A
// Result: string value returned 
// Output: value last_name_
*/
std::string Person::getLastName() const{return last_name_;};

/*
// Task: Overload comparative oporator to compare atributes of Person class
// Input: two Person type objects
// Result: return boolean value based on comparison
// Output: boolean value
*/
 bool operator==(const Person& a, const Person& b){
	return (
		a.id_ == b.id_ && 
		a.first_name_ == b.first_name_ && 
		a.last_name_ == b.last_name_ );
};

/*
// Task: Overload output stream oporator to define print format
// Input: Person type objects
// Result: print Person object first_name_ and last_name_ values followed by new line
// Output: "first_name_ last_name_ \n"
*/
std::ostream& operator<<(std::ostream& os, const Person& p){
    os << p.first_name_ << " " << p.last_name_ << "\n";
    return os;
};

