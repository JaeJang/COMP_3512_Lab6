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
	constexpr static int PARENT_POOL_SIZE = 5;

	// Chance of being mutated
	constexpr static double MUTATION_RATE = 0.15;

	// Number of 'parents' for each cross
	constexpr static int NUMBER_OF_PARENTS = 2;

	// The number of 'fittest' that remain uncrossed and unmutated into the next gen
	constexpr static int NUMBER_OF_ELITES = 1;

	Population(){}


	void Populate(std::vector<City> * cities_to_visit);
	
	double getBestDistance();
	void Selection();
	void Crossover();
	void Mutate();
	void Evaluation();
	void PrintResult();

private:

	std::vector<Tour> tours;
	std::vector<Tour> crosses;
	int index_of_shortest;
	
	int determine_fitness(std::vector<Tour> * population, int population_size);
	void select_parents(std::vector<Tour> * parents);
	void _crossover(std::vector<Tour> * parents, Tour * child);
	bool contains_city(Tour *, int, City *);
	
};