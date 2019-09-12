/*
//  City.hpp
//  City
//  A City data object designed for project 5 for Hunter College CSCI 235 00:
//		Software Analysis and Design II
//
//	Purpose: Declaration
//		Supporting data object for the RouteMap class
//			will be stored in the RouteMap object for traversal pouposes
//
//  Creates by Matthew Perez on 06/27/19
//  Design requirements provided by:
//  Tiziana Ligorio
//
*/

#ifndef CITY_HPP_
#define CITY_HPP_

#include <iostream>
#include <vector>
#include <string>

class City
{
public:
	/*
	// Default constructor is parameterized 
	//	Assumption: class object only instanciated when value is passed
	*/
	City(std::string name);
	
	/** Default destructor*/
	~City();

	/** @return city_name_ */
	std::string getName()const;

	/** @return adjacent_ contains pointers to the cities that are
	//		adjacent to the current city
	*/
	std::vector<City*> getAdjacent()const;

	/** @return return 'visited_' */
	bool getVisited()const;

	/** Add city pointer to adjacent vector
	// @post is the pointer ois not nullptr the new city will be added
	*/
	void addAdjacent(City* city_address);

	/** @return negate 'Visited_' */
	void setVisited(const bool val);

private:
	/** Returns bool after traversing the 'adjacent_' vector
	//	checks if city is already included
	//	@return true if address is found and false if not found or nullptr
	*/
	bool alreadyAdjacent(City* city);
	bool visited_ = false; // current visited status of city
	std::string city_name_; // name of city given by file input to RouteMap
	std::vector<City*> adjacent_; // List of pointers to adjacent cities provided by input file


};

#endif