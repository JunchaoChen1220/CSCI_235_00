#include <iostream>
#include "Person.hpp"
#include"Instructor.hpp"
#include "Student.hpp"
#include "TeachingAssistant.hpp"


int main(int argc, char const *argv[])
{
	Person jon(5, "jon", "Doe");
	std::cout
		<<"ID:"<<jon.getID()<<"\n"
		<<"First:"<<jon.getFirstName()<<"\n"
		<<"Last:"<<jon.getLastName()<<"\n"
		<<std::endl;

	Instructor T(10, "Jane", "Doe");
	T.setOffice("NAC: 12345");
	T.setContact("24o852");
	std::cout
		<<"ID:"<<T.getID()<<"\n"
		<<"First:"<<T.getFirstName()<<"\n"
		<<"Last:"<<T.getLastName()<<"\n"
		<<"Office:"<<T.getOffice()<<"\n"
		<<"Contact:"<<T.getContact()<<"\n"
		<<std::endl;

	Student S(123, "Bob", "Doe");



	return 0;
}