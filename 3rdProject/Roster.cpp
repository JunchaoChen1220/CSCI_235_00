//  Based on file:
//	Modified by Tiziana Ligorio for CSCI 235 Hunter college 2019

/** Header file for an array-based implementation of the ADT Roster
@file Roster.hpp */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "List.hpp"
#include "Node.hpp"
#include "Roster.hpp"


#include "Person.hpp"
#include "Student.hpp"
#include "TeachingAssistant.hpp"
#include "Instructor.hpp"



Roster::Roster(){};
/**parameterized constructor
@pre the input file is expected to be in CSV
(comma separated value) where each line has format:
“id,first_name_,last_name\n"
@param input_file_name the name of the input csv file
@post Student objects are added to roster as per the data
in the input file
**/
Roster::Roster(std::string input_file_name){
	/* Solution based on responce provided by user: Martin York on StackOverflow to:
	** How can I read and parse CSV files in C++?
	** https://stackoverflow.com/questions/1120140/how-can-i-read-and-parse-csv-files-in-c?page=1&tab=votes#tab-top
	** Modified by Matthew Perez for purpose of project 3 for  
	** CSCI 23500 Hunter College Summer 2019
	*/

	// declair and assign ifstream varable
	std::ifstream file(input_file_name);

	//declare variables to retreive and pass data to pointers of person type object
	std::string id, first, last, position, line;

	// Read lines from file into 'line' string
	while(file.is_open() && std::getline(file, line)){
		// define string stream by current line in the file
		std::stringstream stream(line);
		
		// use delimiter to take slices of line and pass to strings
		std::getline(stream, id, ',');
		std::getline(stream, first, ',');
		std::getline(stream, last, ',');
		std::getline(stream, position);

//		std::cout<< id << " " << first << " " << last << " " << position<<std::endl;

		if(position == "student"){
			// Instanciate student object if position is student
			// Randomly generate and assign protected member variables
			Student* S = new Student(std::stoi(id), first, last);
			S->setGpa(S->randGpa());
			S->setMajor(S->randMajor());

			// Insert pointer to new student object
			Person* P = S;
			insert(item_count_, P);
		}else if(position == "teaching_assistant"){
			// Instanciate TeachingAssistant object if position is teaching assistant
			// Randomly generate and assign protected member variables
			TeachingAssistant* TA = new TeachingAssistant(std::stoi(id), first, last);
			TA->setGpa(TA->randGpa());
			TA->setMajor(TA->randMajor());
			TA->setRole(TA->randRole());
			TA->setHours(TA->randHoursPerWeek());
	
			// Insert pointer to new teaching assistant object
			Person* P = TA;
			insert(item_count_, P);

		}else if(position == "instructor"){
			// Instanciate Instructor object if position is instructor
			// Assign protected member variables accordig to project guidelines
			Instructor* I = new Instructor(std::stoi(id), first, last);
			I->setContact("235Instructors@hunter.cuny.edu");
			I->setOffice("1000C");

			// Insert pointer to new instructor object
			Person* P = I;
			insert(item_count_, P);
		}
	};

};

Roster::~Roster(){
	// Define pointer to first node for traversal process
	Node<Person*>* temp = first_;
	
	while(temp!=nullptr){
		delete temp->getItem();
		temp = temp->getNext();
	}
	temp = nullptr;
};

/**@post displays all students in roster, one per line
in the form "first_name_ last_name_\n"
**/
void Roster::display(){
	Node<Person*>* temp = first_;
	
	while(temp!=nullptr){
		temp->getItem()->display();
		temp = temp->getNext();
	}
	temp = nullptr;

}; 


