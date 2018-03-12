#include "City.hpp"
#include <iostream>

City::City(const City & rhs) {
	name = rhs.name;
	x_coordinate = rhs.x_coordinate;
	y_coordinate = rhs.y_coordinate;
}

City & City::operator=(City lhs)
{
	swap(*this, lhs);

	return *this;
}

//Get the distanece between two cities
//RETURN: distanece between two cities in double
double City::get_distance_between_cities(City * b)
{
	return sqrt(pow((double)(x_coordinate - b->x_coordinate), 2.0) +
		pow((double) (y_coordinate - b->y_coordinate), 2.0));
}

void swap(City & lsh, City & rhs)
{
	std::swap(lsh.name, rhs.name);
	std::swap(lsh.x_coordinate, rhs.x_coordinate);
	std::swap(lsh.y_coordinate, rhs.y_coordinate);
}
