
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

//GEN-RAND NUMS
#include <cstdlib> 
#include <ctime> 

#include "Person.hpp"
#include "Student.hpp"
#include "TeachingAssistant.hpp"
#include "Instructor.hpp"

#include "List.hpp"
#include "Node.hpp"
#include "PrecondViolatedExcep.hpp"
#include "Roster.hpp"



int main(int argc, char const *argv[])
{
//	srand((unsigned)time(0));



	Roster r("data_full.csv");
	//std::cout << "\n\n" <<std::endl;
	//r.getItem(22)-> display();
	r.display();



	return 0;
}



