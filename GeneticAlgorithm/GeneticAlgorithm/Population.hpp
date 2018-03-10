#pragma once

#include <vector>
#include "Tour.hpp"

class Population {

public:

	constexpr static int POPULATION_SIZE = 30;

	constexpr static int CITIES_IN_TOUR = 20;

	// A shuffle consists of swaps
	constexpr static int SHUFFLES = 32;

	// Scales the fitness to move the decimal place to a reasonable spot
	constexpr static double FITNESS_SCALER = 10000.0;

	// Number of members randomly selected from the population, from which the
	// fittest is made a 'parent'
	constexpr static int PARENT_POLL_SIZE = 5;

	// Chance of being mutated
	constexpr static double MUTATION_RATE = 0.15;

	// Number of 'parents' for each cross
	constexpr static int NUMBER_OF_PARENTS = 2;

	// The number of 'fittest' that remain uncrossed and unmutated into the next gen
	constexpr static int NUMBER_OF_ELITES = 1;

	Population(){}


	void Populate(std::vector<City> * cities_to_visit);
	int determine_fitness();
	double getBestDistance();

private:

	std::vector<Tour> tours;
	int index_of_shortest;
		
};