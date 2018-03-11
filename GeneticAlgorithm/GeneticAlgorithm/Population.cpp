#include <iostream>
#include <iomanip>
#include "Population.hpp"
#include <vector>
using namespace std;

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

int Population::determine_fitness(std::vector<Tour> * population, int population_size)
{
	int index_of_shortest_tour = 0;
	double shortest_tour_in_population = (double)RAND_MAX;
	double candidate_distance = 0.0;

	for (int i = 0; i < population_size; ++i) {
		candidate_distance = (*population)[i].get_tour_distance(CITIES_IN_TOUR);
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
	crosses.clear();

	if (index_of_shortest != 0) {
		Tour temp(tours[0]);
		tours[0] = tours[index_of_shortest];
		tours[index_of_shortest] = temp;
	}
}

void Population::Crossover()
{
	

	for (int i = 0; i < (POPULATION_SIZE - NUMBER_OF_ELITES); ++i) {
		std::vector<Tour> parents;
		Tour child;
		select_parents(&parents);
		_crossover(&parents, &child);
		crosses.push_back(child);
	}

	for (int i = NUMBER_OF_ELITES; i < POPULATION_SIZE; ++i) {
		tours[i] = crosses[i - NUMBER_OF_ELITES];
		tours[i].setFitness(0.0);
	}
}

void Population::select_parents(std::vector<Tour> * parents)
{
	int k(0), parent_index(0);
	std::vector<Tour> parent_pool;

	for (int i = 0; i < NUMBER_OF_PARENTS; ++i) {
		for (int j = 0; j < POPULATION_SIZE; ++j) {
			k = rand() % POPULATION_SIZE;
			parent_pool.push_back(tours[k]);
		}
		parent_index = determine_fitness(&parent_pool, PARENT_POOL_SIZE);
		(*parents).push_back(parent_pool[parent_index]);
	}
	
}

void Population::_crossover(std::vector<Tour> * parents, Tour * child)
{
	int boundary_index = rand() % CITIES_IN_TOUR;
	child->setFitness(0.0);
	for (int i = 0; i < boundary_index; ++i) {

		child->permutation.push_back((*parents)[0].permutation[i]);
	}

	while (boundary_index < CITIES_IN_TOUR) {
		for (int i = 0; i < CITIES_IN_TOUR; ++i) {
		//std::cout << "a" << std::endl;;
			if (!contains_city(child, boundary_index, (*parents)[1].permutation[i])) {
				child->permutation.push_back((*parents)[1].permutation[i]);
				boundary_index++;
			}
		}
	}


}

bool Population::contains_city(Tour * candidate_tour, int length, City * candidate_city)
{
	for (int i = 0; i < length; ++i) {
		if (candidate_tour->permutation[i]->getName() == (char)candidate_city->getName() &&
			candidate_tour->permutation[i]->getX_coordinate() == (int)candidate_city->getX_coordinate() &&
			candidate_tour->permutation[i]->getY_coordinate() == (int)candidate_city->getY_coordinate()) {
			return true;
		}
	}
	return false;
}


void Population::Mutate() {
	int k(0);
	double mutates(0.0);

	for (int i = 0 + NUMBER_OF_ELITES; i < POPULATION_SIZE; ++i) {
		for (int j = 0; j < CITIES_IN_TOUR; ++j) {
			mutates = (double)rand() / (double)RAND_MAX;
			if (mutates <= MUTATION_RATE) {
				k = rand() % CITIES_IN_TOUR;
				tours[i].swap_cities(j, k);
			}
		}
	}
}

void Population::Evaluation(double & best_distance) {

	
	index_of_shortest = determine_fitness(&tours, POPULATION_SIZE);
	
	double best_iteration_distance;
	best_iteration_distance = tours[index_of_shortest].get_tour_distance(CITIES_IN_TOUR);
	if (best_iteration_distance < best_distance) {
		best_distance = best_iteration_distance;
		cout << "New distance: " << fixed << setw(8) << setprecision(3)
			<< best_iteration_distance << endl;
	}
}

void Population::PrintResult() {
	cout << "Shortest distance " << fixed << setw(8) << setprecision(3)
		<< (FITNESS_SCALER / tours[index_of_shortest].getFitness()) << endl;
}