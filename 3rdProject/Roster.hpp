//  Based on file:
//	Modified by Tiziana Ligorio for CSCI 235 Hunter college 2019

/** Header file for an array-based implementation of the ADT Roster
 @file Roster.hpp */

#ifndef ROSTER_HPP_
#define ROSTER_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "List.hpp"

#include "Person.hpp"
#include "Student.hpp"
#include "TeachingAssistant.hpp"
#include "Instructor.hpp"

class Roster: public List<Person*>
{
public:
	Roster();
	/**parameterized constructor
	@pre the input file is expected to be in CSV
	(comma separated value) where each line has format:
	“id,first_name_,last_name\n"
	@param input_file_name the name of the input csv file
	@post Student objects are added to roster as per the data
	in the input file
	**/
	Roster(std::string input_file_name);
	virtual ~Roster();


	/**@post displays all students in roster, one per line
	in the form "first_name_ last_name_\n"
	**/
	void display(); 

};

#endif