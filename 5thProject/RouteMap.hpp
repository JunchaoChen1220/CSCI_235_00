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

#ifndef ROUTE_MAP_HPP_
#define ROUTE_MAP_HPP_

#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <string>

#include "City.hpp"

class RouteMap
{
public:
	RouteMap(); // Default constructor
	RouteMap(std::string input_file_name); // Paramiterized constructor

	/** Default Destructor
	//	@post delete all cities stored in the map and deallocate pointers
	*/
	~RouteMap(); 
	
	/**
	@param input_file_name of a csv file representing a route map where the first
	 line is a comma-separated list of city names, and the remainder is a
	 comma-separated list of city-pairs of the form A-B, indicating that B
	 is adjacent to A (i.e. there is an arrow in the map going from A to B)
	@post this depends on your design, the input data representing the map must
	 have been stored. Adjacent cities must be stored and explored in the
	 same order in which they are read from the input file
	**/
	bool readMap(std::string input_file_name);

	/**
	@return a pointer to the city found at position, where
	 0 <= position <= n-1, and n is the number of cities,
	 and cities are stored in the same order in which they appear
	 in the input file
	**/
	City* getCity(size_t position);

	/**
	@return true if there is a route from origin to destination, false otherwise
	@post if a route is found from origin to destination, it will print it to
	 standard output in the form “ORIGIN -> ... -> DESTINATION\n”
	**/
	bool isRoute(City* origin, City* destination); 	

	//	REMOVE WHEN COMPLETE
	void print();
private:

	//	Helper function for 'isRoute'
	//	print contents of 'route_' accourding to project guielines
	void printRoute();	
	/** Determine if there are adjacent cities that can be visited and return pointer
	//	@param City pointer to the current city being visited
	//	@return pointer to unvisited city or nullpointer if no path forward
	*/
	City* nextCity(const City* cityptr);

	/************* PRIVATE METHODS ************/
	/** Instanciate and add cities to the 'cities_' vector
	//	@pre asumming the file input is a comma delimited list the function will work
	//	@param line one of the file
	//	@post All unique comma delimited values will be added to the 'cities_' vector
	*/
	void makeCities(const std::string fileLineOne);

	/** Take the expected input and add the adjacent cities
	//	@pre expectation is a comma deliited list as follwos:
	//	city-adjcent,city-adjcent,city-adjcent ...
	//	@param string input from primary function call
	//	@post all city and adjacent pairs provided by the line 
	//		will have the adjacent city added the 'adjacent_' vector 
	//		in the City data object
	*/
	void addAdjacentCities(const std::string fileLine);

	/** Return the index of a city if found else return -1
	//	@param takes city name 
	//	@return if city is found in 'cities_' return index else return -1
	*/
	int indexByName(const std::string city);

	/**	traverse 'cities_' vector and check if city is available
	//	@param string to be compared to city names in the 'cities_' vector
	//	@return true if city has been created already
	*/
	bool cityExists(std::string city_name); 
	
	/************* PRIVATE VARIABLES ************/

	std::vector<City*> cities_; // Vector storing all known cities
	std::stack<City*> route_;


};

#endif