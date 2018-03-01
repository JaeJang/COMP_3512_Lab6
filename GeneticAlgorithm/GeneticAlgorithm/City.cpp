#include "City.hpp"
#include <iostream>
City & City::operator=(City lhs)
{
	swap(*this, lhs);

	return *this;
}

void swap(City & lsh, City & rhs)
{
	std::swap(lsh.name, rhs.name);
	std::swap(lsh.x_coordinate, rhs.x_coordinate);
	std::swap(lsh.y_coordinate, rhs.y_coordinate);
}
