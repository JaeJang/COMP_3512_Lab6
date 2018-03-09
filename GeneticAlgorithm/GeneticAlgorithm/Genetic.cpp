#include "Genetic.hpp"

void Init_Cities(vector<City> & cities_to_visit)
{
	for (int i = 0; i < CITIES_IN_TOUR; ++i) {
		cities_to_visit.push_back(
			City((char)(i + ASCII_OFFSET),
				rand() % (MAP_BOUNDARY + 1),
				rand() % (MAP_BOUNDARY + 1)
			)
		);
	}

	srand(time(NULL));

}

void Populate(vector<Tour> & population, const vector<City> & cities_to_visit)
{
	for (int i = 0; i < POPULATION_SIZE; ++i) {

		population.push_back(Tour());
		for (int j = 0; j < CITIES_IN_TOUR; ++j) {
			population[i].getPermutation().push_back(cities_to_visit[j]);
		}
		population[i].shuffle_cities(SHUFFLES, CITIES_IN_TOUR);
		population[i].setFitness(0);
	}
}

int determine_fitness(vector<Tour> & population)
{	
	int index_of_shortest_tour = 0;
	double shortest_tour_in_population = (double)RAND_MAX;
	double candidate_distance = 0.0;

	for (int i = 0; i < POPULATION_SIZE; ++i) {
		candidate_distance = population[i].get_tour_distane(CITIES_IN_TOUR);
		population[i].setFitness(FITNESS_SCALER / candidate_distance);
		if (candidate_distance <= shortest_tour_in_population) {
			index_of_shortest_tour = i;
			shortest_tour_in_population = candidate_distance;
		}
	}
	return index_of_shortest_tour;
}

void findEvolution(vector<Tour>& population)
{
	for (iterations = 0; iterations < ITERATIONS; ++iterations) {


	}
}
