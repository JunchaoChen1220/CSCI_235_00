#include <iostream>
//#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "ArrayBag.hpp"
#include "Roster.hpp"
#include "Person.hpp"
#include "Student.hpp"


int main(int argc, char const *argv[])
{

	std::string f_name = "data.csv";
	//Roster class_1(f_name);
	//class_1.display();
	std::ifstream file; file.open(f_name);
	std::string  line;
	while(!file.eof()){
		getline(file, line);
		std::cout
			<<line
			<<std::endl;
	};

	return 0;
}


