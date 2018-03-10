#pragma once

#include <vector>
#include "Tour.hpp"

class Population {

public:
	Population(const int population_size, const int cities_in_tuour, const int shuffles)
		:population_size(population_size),
		 cities_in_tuour(cities_in_tuour),
		shuffles(shuffles)
	{}


	void Populate(std::vector<City> & cities_to_visit);


private:

	std::vector<Tour> tours;
	const int population_size;
	const int cities_in_tuour;
	const int shuffles
};