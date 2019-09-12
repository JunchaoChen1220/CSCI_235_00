/*
//  City.cpp
//  City
//  A City data object designed for project 5 for Hunter College CSCI 235 00:
//		Software Analysis and Design II
//
//	Purpose: Implimentation
//		Supporting data object for the 'RouteMap' class
//			will be stored in the 'RouteMap' object for traversal pouposes
//
//  Creates by Matthew Perez on 06/27/19
//  Design requirements provided by:
//  Tiziana Ligorio
//
*/
#include <iostream>
#include <vector>
#include <string>

#include "City.hpp"


/*
// Default constructor is parameterized 
//	Assumption: class object only instanciated when value is passed
*/
City::City(std::string name): city_name_(name){};

/** Default destructor
//	@post all pointers in the 'adjacent' vector will be set to nullptr
*/
City::~City(){
	for (int i = 0; i < adjacent_.size(); ++i)
	{
		adjacent_[i] = nullptr;
	}
};

/** @return city_name_ */
std::string City::getName()const{
	return city_name_;
};

/** @return adjacent_ contains pointers to the cities that are
//		adjacent to the current city
*/
std::vector<City*> City::getAdjacent()const{
	return adjacent_;
};

/** @return return 'visited_' */
bool City::getVisited()const{
	return visited_;
};

/** Add city pointer to adjacent vector
// @post is the pointer ois not nullptr the new city will be added
*/
void City::addAdjacent(City* city_address){
	if (!alreadyAdjacent(city_address))adjacent_.push_back(city_address);
};

/** @return negate 'Visited_' */
void City::setVisited(const bool val){
	visited_ = val;
};

/************* PRIVATE METHODS ************/


/** Returns bool after traversing the 'adjacent_' vector
//	checks if city is already included
//	@return true if address is found and false if not found or nullptr
*/
bool City::alreadyAdjacent(City* city){
	for (int i = 0; i < adjacent_.size(); ++i){
		if (adjacent_[i] == city)return true;
	}
	return false;
};
