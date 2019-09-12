#include<string>
#include"Student.hpp"
#include "TeachingAssistant.hpp"

/**
// Task: Create a sub class TeachingAssistant which will inherit
//		the protected member variables id_, first_name_,  and last_name_
//		from the subClass class 'Student' which inherited the member variables from the 
//		primary bse class 'Person' on top of the protected members major_ and gpa_ from the subclass
//		'Student'
**/

/*
// Task: Initialize object of class 'TeachingAssistant'
// Input: No expected input
// Result: New object created with empty member varaibles
// Output: N/A
*/
TeachingAssistant::TeachingAssistant():hours_per_week_(-1), role_(LAB_ASSISTANT){};

/*
// Task: Initialize object of class 'TeachingAssistant'
// Input: Integer value for id_, string value for first_name_, string value for last_name_, 
// Result: New object created with member varaibles set to the values passed
// Output: N/A
*/
TeachingAssistant::TeachingAssistant(int id, std::string first, std::string last):Student(id, first, last){};

/*
// Task: Destruct object when out of scope 
// Input: N/A
// Result: Object is destroyed and memory is cleared
// Output: N/A
*/
TeachingAssistant::~TeachingAssistant(){};

/*
// Task: Return meber value: hours_per_week_
// Input: N/A
// Result: int value returned 
// Output: value hours_per_week_
*/
int TeachingAssistant::getHours()const{return hours_per_week_;};

/*
// Task: Return meber value: role_
// Input: N/A
// Result: ta_role value returned 
// Output: value role_
*/
ta_role TeachingAssistant::getRole()const{return role_;};

/*
// Task: Set member varible to string value passed in by user 
// Input: int Value
// Result: Member value overridden
// Output: N/A
*/
void TeachingAssistant::setHours(const int hours){hours_per_week_ = hours;};

/*
// Task: Set member varible to string value passed in by user 
// Input: ta_role Value
// Result: Member value overridden
// Output: N/A
*/
void TeachingAssistant::setRole(const ta_role role){role_ = role;};
