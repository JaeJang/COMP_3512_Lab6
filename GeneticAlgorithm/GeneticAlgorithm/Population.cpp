#include <iostream>
#include <iomanip>
#include "Population.hpp"
#include <vector>
using namespace std;

//Populates and shuffles cities
//PRE	: the master list is set
//POST	: populates each tour
//		  ans shuffles the cities in that tours
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

//Calcuates the fitness of each tour and get 
//the index of the shortest distance of tour
//PRE	: population_size is the length of population
//POST	: The fitness of each tour is set
//RETURN: index of the shortes distance of tour
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


//Get the best distance in tours based on the index of the shortest tour
//RETURN: the best distance from the initial population in double
double Population::getBestDistance()
{
	index_of_shortest = determine_fitness(&tours, POPULATION_SIZE);
	return FITNESS_SCALER / tours[index_of_shortest].getFitness();
}

//keep the best route by moving the fittest to the front of the population
//Cleare crosses vector
//POST	: changes 0 index tour to the best tour
void Population::Selection()
{
	crosses.clear();

	if (index_of_shortest != 0) {
		Tour temp(tours[0]);
		tours[0] = tours[index_of_shortest];
		tours[index_of_shortest] = temp;
	}
}

//Get 2 tours by the shortest distance of tour 
//among 5 randomly picked tours from population.
//Mixes the permutaions of parents, stores them in child
//and replace population except the elite tour.
//PRE	: NULL
//POST	: tours in populataion have been changed except the elite tour
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

//Select 2 tours from population.
//PRE	: vector or parents instantiated
//POST	: select POPULATION_SIZE -1 tours and pick 2 shortest distance tour
void Population::select_parents(std::vector<Tour> * parents)
{
	int k(0), parent_index(0);
	std::vector<Tour> parent_pool;

	for (int i = 0; i < NUMBER_OF_PARENTS; ++i) {
		for (int j = 0; j < PARENT_POOL_SIZE; ++j) {
			k = rand() % POPULATION_SIZE;
			parent_pool.push_back(tours[k]);
		}
		parent_index = determine_fitness(&parent_pool, PARENT_POOL_SIZE);
		(*parents).push_back(parent_pool[parent_index]);
		parent_pool.clear();
	}
	
}

//Mixes the permutations of the parents tour and store it to child
//PRE	: parents are set and child is intantiated
//POST	: child tour is set
void Population::_crossover(std::vector<Tour> * parents, Tour * child)
{
	int boundary_index = rand() % CITIES_IN_TOUR;
	child->setFitness(0.0);
	for (int i = 0; i < boundary_index; ++i) {

		child->permutation.push_back((*parents)[0].permutation[i]);
	}

	while (boundary_index < CITIES_IN_TOUR) {
		for (int i = 0; i < CITIES_IN_TOUR; ++i) {
			if (!contains_city(child, boundary_index, (*parents)[1].permutation[i])) {
				child->permutation.push_back((*parents)[1].permutation[i]);
				boundary_index++;
			}
		}
	}


}

//Check the candidate tour has candidate city in its permutation
//PRE	: length <= boundary_index
//POST	: NULL
//RETURN: true if it contains the city
bool Population::contains_city(Tour * candidate_tour, int length, City * candidate_city)
{
	for (int i = 0; i < length; ++i) {
		
		if (candidate_tour->permutation[i] == candidate_city)
			return true;
	}
	return false;
}

//Swap cities in specific tour randomly
//PRE	:
//POST	: some of population's tours may have been mutated
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

//Evalute the population.
//Determine best distance for this iteration 
//and replace best_distance if it is smaller than that.
//PRE	: NULL
//POST	: get index_of_shortes from population
//		  get best distance if it's changed
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

//Print the result
void Population::PrintResult() {
	cout << "Shortest distance " << fixed << setw(8) << setprecision(3)
		<< (FITNESS_SCALER / tours[index_of_shortest].getFitness()) << endl;
}