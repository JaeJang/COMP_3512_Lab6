#include "Population.hpp"

void Population::Populate(std::vector<City> * cities_to_visit)
{
	for (int i = 0; i < POPULATION_SIZE; ++i) {

		tours.push_back(Tour());
		for (int j = 0; j < CITIES_IN_TOUR; ++j) {
			tours[i].getPermutation().push_back( &(*cities_to_visit)[j]);
		}
		tours[i].shuffle_cities(SHUFFLES, CITIES_IN_TOUR);
		tours[i].setFitness(0);
	}
}

int Population::determine_fitness(std::vector<Tour> * population, int population_size)
{
	int index_of_shortest_tour = 0;
	double shortest_tour_in_population = (double)RAND_MAX;
	double candidate_distance = 0.0;

	for (int i = 0; i < population_size; ++i) {
		candidate_distance = (*population)[i].get_tour_distane(CITIES_IN_TOUR);
		(*population)[i].setFitness(FITNESS_SCALER / candidate_distance);
		if (candidate_distance <= shortest_tour_in_population) {
			index_of_shortest_tour = i;
			shortest_tour_in_population = candidate_distance;
		}
	}
	return index_of_shortest_tour;
}



double Population::getBestDistance()
{
	index_of_shortest = determine_fitness(&tours, POPULATION_SIZE);
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

void Population::select_parents()
{
	int k(0), parent_index(0);

	std::vector<Tour> parent_pool;

	for (int i = 0; i < NUMBER_OF_PARENTS; ++i) {
		for (int j = 0; j < POPULATION_SIZE; ++j) {
			k = rand() % POPULATION_SIZE;
			parent_pool[j] = tours[k];
		}
		parent_index = determine_fitness(&parent_pool, PARENT_POOL_SIZE);
		parents[i] = parent_pool[parent_index];
	}
	
}

void Population::_crossover()
{
	int boundary_index = rand() % CITIES_IN_TOUR;
	child.setFitness(0.0);
	for (int i = 0; i < boundary_index; ++i) {
		child.getPermutation().push_back(parents[0].getPermutation[i]);
	}

	while (boundary_index < CITIES_IN_TOUR) {
		for (int i = 0; i < CITIES_IN_TOUR; ++i) {
			if (!contains_city(&child, boundary_index, parents[1].getPermutation()[i])) {
				child.getPermutation()[boundary_index] = parents[1].getPermutation()[i];
				boundary_index++;
			}
		}
	}
}

bool Population::contains_city(Tour * candidate_tour, int length, City * candidate_city)
{
	for (int i = 0; i < length; ++i) {
		if (candidate_tour->getPermutation()[i]->getName() == (char)candidate_city->getName() &&
			candidate_tour->getPermutation()[i]->getX_coordinate() == (char)candidate_city->getX_coordinate() &&
			candidate_tour->getPermutation()[i]->getY_coordinate() == (char)candidate_city->getY_coordinate()) {
			return true;
		}
	}
	return false;
}
