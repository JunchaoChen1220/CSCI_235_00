#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stack>

#include "City.hpp"
#include "RouteMap.hpp"


int main(int argc, char const *argv[])
{
	std::string file_name = "sample_map.txt";
	
	RouteMap r(file_name);

	std::cout
		<< r.isRoute(r.getCity(0), r.getCity(6)) 
		<<std::endl;
	

	


	return 0;
}