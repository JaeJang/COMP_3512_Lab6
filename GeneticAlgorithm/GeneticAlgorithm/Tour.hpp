#pragma once
#include <vector>

class City;

class Tour {
public:
	std::vector<City> permutation;

	Tour() {}

	void shuffle_cities(int, int);
	void swap_cities(int, int);
	void setFitness(double value);


private:
	double fintness = 0.0;
};