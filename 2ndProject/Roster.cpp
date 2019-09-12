//  Based on file:
//	Modified by Tiziana Ligorio for CSCI 235 Hunter college 2019

/** Header file for an array-based implementation of the ADT Roster
@file Roster.hpp */
#include <vector>
#include <fstream>
#include "ArrayBag.hpp"
#include "Student.hpp"
#include "Roster.hpp"

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
	std::cout << input_file_name << std::endl;

	// declair and assign ifstream varable
	std::ifstream file; 
	file.open(input_file_name);

	//declare variables to retreive and pass data to student object
	std::string line, first, last;    int id;

	while(std::getline(file, line)){
		
		//take slice of 'line' string and cast to base 10 integer
		id = std::stoi (line.substr(0, line.find(",")), nullptr, 10);

		//take slice of 'line' string between the two commas
		first = line.substr(line.find(",")+1, line.substr(line.find(",")+1).find(",") );
		
		//take slice of 'line' string after the second comma
		last = line.substr(line.find(first)+first.length()+1);

		Student s(id, first, last);
		add(s);
	};

};
Roster::~Roster(){};

/**@post displays all students in roster, one per line
in the form "first_name_ last_name_\n"
**/
void Roster::display(){
	for(int i = 0; i < item_count_ ; i++){
		std::cout
			<<items_[i].getFirstName() << " "
			<<items_[i].getLastName() << "\n";
	};
}; 


