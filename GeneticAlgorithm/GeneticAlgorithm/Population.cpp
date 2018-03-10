#include "Population.hpp"

void Population::Populate(std::vector<City> & cities_to_visit)
{
	for (int i = 0; i < population_size; ++i) {

		tours.push_back(Tour());
		for (int j = 0; j < cities_in_tuour; ++j) {
			tours[i].getPermutation().push_back(&cities_to_visit[j]);
		}
		tours[i].shuffle_cities(shuffles, cities_in_tuour);
		tours[i].setFitness(0);
	}
}

int Population::determine_fitness(const int fitness_scaler)
{
	int index_of_shortest_tour = 0;
	double shortest_tour_in_population = (double)RAND_MAX;
	double candidate_distance = 0.0;

	for (int i = 0; i < population_size; ++i) {
		candidate_distance = tours[i].get_tour_distane(cities_in_tuour);
		tours[i].setFitness(fitness_scaler / candidate_distance);
		if (candidate_distance <= shortest_tour_in_population) {
			index_of_shortest_tour = i;
			shortest_tour_in_population = candidate_distance;
		}
	}
	return index_of_shortest_tour;
}
