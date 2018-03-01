#include <ctime>
#include <cmath>
#include <random>
#include <vector>

class Genetic {

public:
	// A shuffle consists of swaps
	constexpr static int SHUFFLES = 32;

	// if we cast an int with value 65 as a char, we get 'A'
	constexpr static int ASCII_OFFSET = 65;			

	// Number of loops for the algorithm
	constexpr static int ITERATIONS = 1000;		

	// Size of the map (X and Y)
	constexpr static int MAP_BOUNDARY = 1000;		

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

	Genetic() {

	};

private:
	/* Variables */
	int    i = 0, j = 0, iterations = 0;
	int    index_of_shortest_tour = 0;
	double best_distance = 0.0;
	double best_iteration_distance = 0.0;
	double improvement_factor = 0.3;

	Tour[POPULATION_SIZE] population
};