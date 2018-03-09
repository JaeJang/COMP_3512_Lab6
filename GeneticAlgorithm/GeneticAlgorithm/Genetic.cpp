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

double getBestDistance(vector<Tour>& population)
{
	index_of_shortest_tour = determine_fitness(population);
	return FITNESS_SCALER / population[index_of_shortest_tour].getFitness();
}

void findEvolution(vector<Tour>& population)
{
	vector<Tour> corsses;

	for (iterations = 0; iterations < ITERATIONS; ++iterations) {

		if (index_of_shortest_tour != 0) {
			Tour temp(population[0]);
			population[0] = population[index_of_shortest_tour];
			population[index_of_shortest_tour] = temp;
		}

		for (int j = 0; j < (POPULATION_SIZE - NUMBER_OF_ELITES); ++j) {
			vector<Tour> parent = select_parents(population);
			Tour child = crossover(parent);
		}

	}
}

vector<Tour> select_parents(vector<Tour> & population) {
	vector<Tour> parents;
	vector<Tour> parent_pool;

	for (int i = 0; i < NUMBER_OF_PARENTS; ++i) {
		for(int j = 0; j < PARENT_POLL_SIZE; ++j) {
			int k = rand() % POPULATION_SIZE;
			parent_pool.push_back(population[k]);
		}
		int parent_index = determine_fitness(parent_pool);
		parents.push_back(parent_pool[parent_index]);
	}

	return parents;
}

Tour crossover(vector<Tour>& parent)
{
	Tour child;
	int boundary_index = rand() % CITIES_IN_TOUR;
	
	for (int i = 0; i < boundary_index; ++i) {
		child.getPermutation().push_back(parent[0].getPermutation()[i]);
	}

	while (boundary_index < CITIES_IN_TOUR) {
		for (int i = 0; i < CITIES_IN_TOUR; ++i) {

		}
	}
	return Tour();
}
