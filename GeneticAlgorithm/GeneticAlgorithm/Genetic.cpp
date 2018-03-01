#include "Genetic.hpp"

void Genetic::Init_Cities()
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

void Genetic::Populate()
{
	for (int i = 0; i < POPULATION_SIZE; ++i) {

		population.push_back(Tour());
		for (int j = 0; j < CITIES_IN_TOUR; ++j) {
			population[i].permutation.push_back(cities_to_visit[j]);
		}
		population[i].shuffle_cities(SHUFFLES, CITIES_IN_TOUR);
		population[i].setFitness(0);
	}
}
