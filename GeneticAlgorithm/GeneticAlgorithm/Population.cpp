#include "Population.hpp"

void Population::Populate(std::vector<City> * cities_to_visit)
{
	for (int i = 0; i < POPULATION_SIZE; ++i) {

		tours.push_back(Tour());
		for (int j = 0; j < CITIES_IN_TOUR; ++j) {
			tours[i].permutation.push_back( &(*cities_to_visit)[j]);
		}
		tours[i].shuffle_cities(SHUFFLES, CITIES_IN_TOUR);
		tours[i].setFitness(0);
	}
}

int Population::determine_fitness()
{
	int index_of_shortest_tour = 0;
	double shortest_tour_in_population = (double)RAND_MAX;
	double candidate_distance = 0.0;

	for (int i = 0; i < POPULATION_SIZE; ++i) {
		candidate_distance = tours[i].get_tour_distane(CITIES_IN_TOUR);
		tours[i].setFitness(FITNESS_SCALER / candidate_distance);
		if (candidate_distance <= shortest_tour_in_population) {
			index_of_shortest_tour = i;
			shortest_tour_in_population = candidate_distance;
		}
	}
	return index_of_shortest_tour;
}

double Population::getBestDistance()
{
	index_of_shortest = determine_fitness();
	return FITNESS_SCALER / tours[index_of_shortest].getFitness();
}

void Population::Selection()
{
	if (index_of_shortest != 0) {
		Tour temp(tours[0]);
		tours[0] = tours[index_of_shortest];
		tours[index_of_shortest] = temp;
	}
}

void Population::Crossover()
{
	for (int i = 0; i < (POPULATION_SIZE - NUMBER_OF_ELITES); ++i) {
		select_parents();
		_crossover();
	}
}
