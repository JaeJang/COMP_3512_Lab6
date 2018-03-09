#pragma once
#include <vector>

class City;

class Tour {
public:
	//std::vector<City> permutation;

	Tour() :  {}
	Tour(const Tour & rhs);

	void shuffle_cities(int, int);
	void swap_cities(int, int);
	void setFitness(double value);
	std::vector<City> getPermutation();
	double getFitness();
	double get_tour_distane(const int cities_in_tour);
	//double get_distance_between_cities(City & a, City & b);

private:
	double fitness = 0.0;
	std::vector<City> permutation;
};