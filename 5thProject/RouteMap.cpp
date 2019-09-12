/*
//  RouteMap.cpp
//  RouteMap
//  A RouteMap data object designed for project 5 for Hunter College CSCI 235 00:
//		Software Analysis and Design II
//
//	Purpose: Declaration
//		Container data object holding 'City' objects
//			will be used for traversal and manipulations
//
//  Creates by Matthew Perez on 06/27/19
//  Design requirements provided by:
//  Tiziana Ligorio
//
*/
#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
#include <sstream>
#include <string>

#include "City.hpp"
#include "RouteMap.hpp"


RouteMap::RouteMap(){}; // Default constructor

RouteMap::RouteMap(std::string input_file_name){ // Paramiterized constructor
	readMap(input_file_name);
};

/** Default Destructor
//	@post delete all cities stored in the map and deallocate pointers
*/
RouteMap::~RouteMap(){
	for (int i = 0; i < cities_.size(); ++i)delete cities_[i];
	for (int i = 0; i < route_.size(); ++i)route_.pop();
	}; 

/**
@param input_file_name of a csv file representing a route map where the first
 line is a comma-separated list of city names, and the remainder is a
 comma-separated list of city-pairs of the form A-B, indicating that B
 is adjacent to A (i.e. there is an arrow in the map going from A to B)
@post this depends on your design, the input data representing the map must
 have been stored. Adjacent cities must be stored and explored in the
 same order in which they are read from the input file
**/
bool RouteMap::readMap(std::string input_file_name){
	std::fstream file(input_file_name);
	std::string line;
	if (file.is_open())
	{
		getline(file, line);
		// Create and adD cities to 'cities_' vector
		makeCities(line);

		//	Read the rest of the file line by line
		//	expected input is comma delimited list of:
		//	city followed by a hyphin and the adjacent city
		while(getline(file, line)){
			addAdjacentCities(line);
		};
		//TRUE RETURN WHEN FILE OPENED SUCCESSFULLY AND DATA INSTANCIATED
		return true;
	}

	// FALSE RETURN IF FILE NOT OPENED
	return false;
};

/**
@return a pointer to the city found at position, where
 0 <= position <= n-1, and n is the number of cities,
 and cities are stored in the same order in which they appear
 in the input file
**/
City* RouteMap::getCity(size_t position){
	if(position >=0 && position < cities_.size()){
		return cities_[position];
	}
	return nullptr;
};

/**
@return true if there is a route from origin to destination, false otherwise
@post if a route is found from origin to destination, it will print it to
 standard output in the form “ORIGIN -> ... -> DESTINATION\n”
**/
bool RouteMap::isRoute(City* origin, City* destination){
	route_.push(origin);
	origin -> setVisited(true);
	City* currentCity = origin;

	while(currentCity != destination && route_.size() > 0){
		if (nextCity(route_.top()) == nullptr){ 

			route_.pop(); 

		} else if (nextCity(route_.top()) != nullptr){

			route_.push( nextCity( route_.top() ) );
			route_.top() -> setVisited(true);
			currentCity = route_.top();

			if (route_.top() == destination){

				printRoute();
				return true;

			} 
		}
	};

	return false;

};

/************* PRIVATE METHODS ************/

//	Helper function for 'isRoute'
//	print contents of 'route_' accourding to project guielines
void RouteMap::printRoute(){
	std::stack<City*> output;
	while(!route_.empty()){
		output.push(route_.top()); 
		route_.pop();
	}
	while(!output.empty()){
		if(output.size() == 1){
			std::cout << output.top()->getName() << std::endl;
		}else{
			std::cout << output.top()->getName() << " -> ";
		}
		output.pop();
	}
};

/** Determine if there are adjacent cities that can be visited and return pointer
//	@param City pointer to the current city being visited
//	@return pointer to unvisited city or nullpointer if no path forward
*/
City* RouteMap::nextCity(const City* cityptr){
	for (int i = 0; i < cityptr->getAdjacent().size(); ++i)
	{
		if (! cityptr->getAdjacent()[i]->getVisited()) return cityptr->getAdjacent()[i];
	}
	return nullptr;
};

/** Instanciate and add cities to the 'cities_' vector
//	@pre asumming the file input is a comma delimited list the function will work
//	@param line one of the file
//	@post All unique comma delimited values will be added to the 'cities_' vector
*/
void RouteMap::makeCities(const std::string fileLineOne){
	std::stringstream line(fileLineOne);
	std::string city;
	// Take each comma delimited value
	while(getline(line, city, ',')){		
		// Confirm if the city is already in the 'cities_' vector
		if (!cityExists(city)){
			// Instanciate and add the new city to the 'cities_' vector
			City* c = new City(city); 
			cities_.push_back(c);
		}
	};
};

/** Take the expected input and add the adjacent cities
//	@pre expectation is a comma deliited list as follwos:
//	city-adjcent,city-adjcent,city-adjcent ...
//	@param string input from primary function call
//	@post all city and adjacent pairs provided by the line 
//		will have the adjacent city added the 'adjacent_' vector 
//		in the City data object
*/
void RouteMap::addAdjacentCities(const std::string fileLine){
	std::stringstream line(fileLine);
	std::string city = "", adjacent = "";
	while(getline(line, city, '-') && getline(line, adjacent, ',')){
		cities_[indexByName(city)] -> addAdjacent(cities_[indexByName(adjacent)]); 
	};
};

/** Return the index of a city if found else return -1
//	@param takes city name 
//	@return if city is found in 'cities_' return index else return -1
*/
int RouteMap::indexByName(const std::string city){
	if (cityExists(city))
	{
		for (int i = 0; i < cities_.size(); ++i)
		{
			if (city == cities_[i]->getName())return i;
		}
	}
	return -1;
};

/**	traverse 'cities_' vector and check if city is available
//	@param string to be compared to city names in the 'cities_' vector
//	@return true if city has been created already
*/
bool RouteMap::cityExists(std::string city_name){
	for (int i = 0; i < cities_.size(); ++i)
	{
		if (cities_[i] -> getName() == city_name) return true;
	}
	return false;
};
