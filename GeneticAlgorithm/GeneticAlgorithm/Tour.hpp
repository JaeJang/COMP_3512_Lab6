#pragma once
#include <vector>
#include "City.hpp"


class Tour {
public:
	//std::vector<City> permutation;
	Tour() { }
	Tour(const Tour & rhs);

	friend void swap(Tour & lhs, Tour & rhs);
	Tour & operator=(Tour rhs);
		

	void shuffle_cities(int, int);
	void swap_cities(int, int);
	void setFitness(double value);
	std::vector<City*> getPermutation();
	double getFitness();
	double get_tour_distance(const int cities_in_tour);
	//double get_distance_between_cities(City & a, City & b);
	std::vector<City*> permutation;

private:
	double fitness = 0.0;
};