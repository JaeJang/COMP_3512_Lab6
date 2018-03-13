#include "City.hpp"
#include <iostream>

//Copy constructor
City::City(const City & rhs) {
	name = rhs.name;
	x_coordinate = rhs.x_coordinate;
	y_coordinate = rhs.y_coordinate;
}

//Overloaded = operator
City & City::operator=(City lhs)
{
	swap(*this, lhs);

	return *this;
}

//Swap two passed cities object
void swap(City & lsh, City & rhs)
{
	std::swap(lsh.name, rhs.name);
	std::swap(lsh.x_coordinate, rhs.x_coordinate);
	std::swap(lsh.y_coordinate, rhs.y_coordinate);
}

//Get the distanece between two cities
//PRE	: NULL
//POST	: NULL
//RETURN: distanece between two cities in double
double City::get_distance_between_cities(City * b)
{
	return sqrt(pow((double)(x_coordinate - b->x_coordinate), 2.0) +
		pow((double) (y_coordinate - b->y_coordinate), 2.0));
}


//Overloaded == oprerator function
//PRE	: both are instance of City object
//POSRT	: NULL
//RETURN: ture if all members are same
bool operator==(const City & lhs, const City & rhs)
{
	if (lhs.name == rhs.name &&
		lhs.x_coordinate == rhs.x_coordinate &&
		lhs.y_coordinate == rhs.y_coordinate)
		return true;

	return false;
}
